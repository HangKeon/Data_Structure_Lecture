#include <iostream>
#include <string>
using namespace std;

#define MappingSize 501

class vertex
{
public:
	vertex* prev;					//이전 정보
	vertex* next;					//다음 정보
	int degree;						//인접한 간선 수
	int data;						//정점 노드의 정보

	vertex(int data)
	{
		this->degree = 0;
		this->data = data;
	}

	void increase_degree()
	{
		this->degree++;
	}

	void decrease_degree()
	{
		this->degree--;
	}
};

class edge
{
public:
	edge* prev;
	edge* next;
	vertex* source;
	vertex* destination;
	string data;

	edge(vertex* a, vertex* b, string data)
	{
		this->source = a;
		this->destination = b;
		this->data = data;
	}
};

class DoublyVertexLinkedList		//vertex로 이루어진 DLL
{
public:
	vertex* head;
	vertex* tail;

	DoublyVertexLinkedList()
	{
		head = NULL;
		tail = NULL;
	}

	void insert(vertex* insertVertex)
	{
		if (this->head == NULL)
		{
			head = insertVertex;
			tail = insertVertex;
		}
		else
		{
			tail->next = insertVertex;
			insertVertex->prev = tail;
			tail = insertVertex;
		}
	}

	void remove(vertex* delVertex)
	{
		if (delVertex == head || delVertex == tail)
		{
			if (delVertex == head && delVertex == tail)
			{
				vertex* temp = head;
				head = head->next;
				head->prev = NULL;
				delete temp;
			}
			else if (delVertex == tail && delVertex != head)
			{
				vertex* temp = tail;
				tail = tail->prev;
				tail->next = NULL;
				delete temp;
			}
			else
				head = tail = NULL;
		}
		else
		{
			delVertex->prev->next = delVertex->next;
			delVertex->next->prev = delVertex->prev;
			delete delVertex;
		}
	}
};

class DoublyEdgeLinkedList
{
public:
	edge* head;
	edge* tail;

	DoublyEdgeLinkedList()
	{
		head = NULL;
		tail = NULL;
	}

	void insert(edge* insertEdge)
	{
		if (this->head == NULL)
		{
			head = insertEdge;
			tail = insertEdge;
		}
		else
		{
			tail->next = insertEdge;
			insertEdge->prev = tail;
			tail = insertEdge;
		}
	}

	void remove(edge* delEdge)
	{
		if (delEdge == head || delEdge == tail)
		{
			if (delEdge == head && delEdge != tail)
			{
				edge* temp = head;
				head = head->next;
				head->prev = NULL;
				delete temp;
			}
			else if (delEdge == tail && delEdge != head)
			{
				edge* temp = tail;
				tail = tail->prev;
				tail->next = NULL;
				delete temp;
			}
			else
				head = tail = NULL;
		}
		else
		{
			delEdge->prev->next = delEdge->next;
			delEdge->next->prev = delEdge->prev;
		}
	}
};

int edgecnt = 0;

class graph
{
public:
	edge*** edgeMatrix;						//edge 정보를 관리하는 matrux->이차원 배열 
	DoublyVertexLinkedList* VertexList;		//전체 vertex 정보를 관리하는 DLL
	DoublyEdgeLinkedList* EdgeList;			//전체 edge 정보를 관리하느 DLL
	int vertexSize;							//그래프에 존재하는 vertex의 개수
	int mappingTable[MappingSize];			//vertex의 고유한 번호와 해당 vertex의 matrix에서 index로 매핑

	graph()
	{
		this->VertexList = new DoublyVertexLinkedList();
		this->EdgeList = new DoublyEdgeLinkedList();
		this->vertexSize = 0;
		for (int i = 0; i < MappingSize; i++)
			mappingTable[i] = -1;
		this->edgeMatrix = new edge**[1];
		this->edgeMatrix[0] = new edge*[1];
		this->edgeMatrix[0][0] = NULL;
	}

	bool isfindVertex(int n)				//VertexList에서 고유한 번호가 n인 vertex의 존재 유무 검사
	{
		bool flag = false;
		vertex* temp = VertexList->head;
		while (temp != NULL)
		{
			if (temp->data == n)
			{
				flag = true;
				break;
			}

			temp = temp->next;
		}
		return flag;
	}

	vertex* findVertex(int n)				//VertexLsit에서 고유한 번호가 n인
	{
		vertex* temp = VertexList->head;	//vertex의 주소 반환

		while (temp != NULL)
		{
			if (temp->data == n)
				break;

			temp = temp->next;
		}

		return temp;
	}

	void insert_vertex(int n)				//그래프의 고유한 번호가 n인 vertex 삽입
	{
		if (isfindVertex(n) == true)
			return;
		else
		{
			edge*** tempMatrix = new edge**[vertexSize + 1];	//정점이 1개 추가될 때마다

			for (int i = 0; i < vertexSize + 1; i++)			//기존 matrix보다 가로, 세로 길이가 1만큼
			{
				tempMatrix[i] = new edge*[vertexSize + 1];		//더 큰 tempMatrix 생성

				for (int j = 0; j < vertexSize + 1; j++)
					tempMatrix[i][j] = NULL;
			}

			for (int i = 0; i < vertexSize; i++)
				for (int j = 0; j < vertexSize; j++)
					tempMatrix[i][j] = this->edgeMatrix[i][j];	//element들을 copy

			this->edgeMatrix = tempMatrix;						//이전 matrix를 새로운 matrix에 접근

			vertex* newVertex = new vertex(n);
			VertexList->insert(newVertex);						//VertexList에 고유번호가 n인 vertex 추가
			this->vertexSize++;
			mappingTable[vertexSize - 1] = n;					//mappingTable에 vertex 자신이
																//matrix의 어느 index인지 저장
		}
	}

	void erase_vertex(int n)									//그래프에 고유한 번호가 n인 vertex 제거
	{
		if (isfindVertex(n) == false || vertexSize == 0)		//삭제할 정점이 x거나 정점이 x는 경우
			return;
		else
		{
			edge*** tempMatrix = new edge**[vertexSize - 1];	//정점이 1개 삭제될 때마다

			for (int i = 0; i < vertexSize - 1; i++)			//기존 matrix보다 가로, 세로 길이가 1만큼
			{
				tempMatrix[i] = new edge*[vertexSize - 1];		//더 작은 tempMatrix 생성

				for (int j = 0; j < vertexSize - 1; j++)
					tempMatrix[i][j] = NULL;
			}

			int middleIdx = 0;

			for (int i = 0; i < vertexSize; i++)
				if (mappingTable[i] == n)
					middleIdx = i;					//middleIdx : 삭제할 vertex의 matrix에서의 인덱스

			for (int i = middleIdx; i < vertexSize; i++)
				mappingTable[i] = mappingTable[i + 1];	//mappingTable update

			for (int i = 0; i < vertexSize; i++)	//EdgeList에서 고유번호가 n인 vertex와 연결된 모든 edge들을 제거
				if (this->edgeMatrix[middleIdx] != NULL)
					EdgeList->remove(this->edgeMatrix[middleIdx][i]);

			for (int i = 0; i < vertexSize; i++)	//middleIdx를 기점으로 element들을 적절히 copy
			{
				for (int j = 0; j < vertexSize; j++)
				{
					if (i < middleIdx&&j < middleIdx)
						tempMatrix[i][j] = this->edgeMatrix[i][j];
					else if (i > middleIdx&&j > middleIdx)
						tempMatrix[i - 1][j - 1] = this->edgeMatrix[i][j];
					else if (j > middleIdx)
						tempMatrix[i][j - 1] = this->edgeMatrix[i][j];
					else if (i > middleIdx)
						tempMatrix[i - 1][j] = this->edgeMatrix[i][j];
				}
			}

			this->edgeMatrix = tempMatrix;
			VertexList->remove(findVertex(n));		//VertexList에 고유번호가 n인 vertex 제거
			this->vertexSize--;
		}
	}

	void insert_edge(int indirectSource, int indirectDestination, string data)	//그래프에 해당 edge를 삽입
	{
		if (isfindVertex(indirectSource) == false || isfindVertex(indirectDestination) == false)
		{
			cout << -1 << endl;
			edgecnt++;
			return;
		}

		int destination = -1;
		int source = -1;

		for (int i = 0; i <= vertexSize; i++)
		{
			if (mappingTable[i] == indirectDestination)	//IndirectSource는 vertex의 고유번호
				destination = i;

			if (mappingTable[i] == indirectSource)		//source는 해당 vertex의 matrix에서의 인덱스
				source = i;

			if (source != -1 && destination != -1)
				break;
		}

		if (edgeMatrix[source][destination] != NULL || edgeMatrix[destination][source] != NULL)
		{
			cout << -1 << endl;							//삽입하려는 edge가 이미 존재하는 경우
			edgecnt++;
			return;
		}

		edge* newEdge = new edge(findVertex(indirectSource), findVertex(indirectDestination), data);
		edgeMatrix[source][destination] = newEdge;		//matrix에 해당 edge를 삽입
		edgeMatrix[destination][source] = newEdge;

		findVertex(indirectSource)->increase_degree();
		findVertex(indirectDestination)->increase_degree();

		EdgeList->insert(newEdge);						//EdgeList에 해당 edge를 삽입
	}

	void erase_edge(int indirectSource, int indirectDestionation)	//그래프에 해당 edge를 제거
	{
		int destination = -1;
		int source = -1;

		for (int i = 0; i <= vertexSize; i++)
		{
			if (mappingTable[i] == indirectDestionation)
				destination = i;

			if (mappingTable[i] == indirectSource)		//source는 해당 vertex의 matrix에서의 인덱스
				source = i;

			if (source != -1 && destination != -1)
				break;
		}

		if (edgeMatrix[source][destination] == NULL || edgeMatrix[destination][source] == NULL)
			return;				//제거하려고 하는 edge가 이미 존재하지 않는 경우

		findVertex(indirectSource)->decrease_degree();
		findVertex(indirectDestionation)->decrease_degree();

		edge* delEdge = edgeMatrix[source][destination];	//해당 edge의 주소값을 matrix에서 얻어옴
		EdgeList->remove(delEdge);							//EdgeList에서 해당 edge를 제거

		edgeMatrix[source][destination] = NULL;				//matrix에서 해당 edge를 제거
		edgeMatrix[destination][source] = NULL;
	}
};

int main()
{
	int n;							//정점의 개수
	int m;							//간선의 개수
	int k;							//삭제할 정점 개수
	int x, y;						//입력할 정점
	string s;						//입력할 문자열
	int arr[501], brr[501];
	int a = 0;

	graph g;

	cin >> n >> m >> k;

	for (int i = 0; i < n; i++)
	{
		cin >> x;

		g.insert_vertex(x);
	}

	for (int i = 0; i < m; i++)
	{
		cin >> arr[a] >> brr[a] >> s;

		g.insert_edge(arr[a], brr[a], s);

		a++;
	}

	cout << n << ' ' << m - edgecnt << endl;

	for (int i = 0; i < k; i++)
	{
		cin >> x;

		if (g.isfindVertex(x) == false)
			cout << -1 << endl;
		else
		{
			g.erase_vertex(x);
			cout << g.vertexSize << ' ';

			for (int j = 0; j < a; j++)
				cout << g.edgeMatrix[arr[i]][brr[i]]->data << ' ';
		}
		cout << endl;
	}


	return 0;
}