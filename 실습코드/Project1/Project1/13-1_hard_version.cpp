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

	edge(vertex* a, vertex* b)
	{
		this->source = a;
		this->destination = b;
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
};

int edgecnt = 0;					//간선의 개수

class graph
{
public:
	edge*** edgeMatrix;						//edge 정보를 관리하는 matrix->이차원 배열 
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

	void insert_edge(int indirectSource, int indirectDestination)	//그래프에 해당 edge를 삽입
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

		edge* newEdge = new edge(findVertex(indirectSource), findVertex(indirectDestination));
		edgeMatrix[source][destination] = newEdge;		//matrix에 해당 edge를 삽입
		edgeMatrix[destination][source] = newEdge;

		findVertex(indirectSource)->increase_degree();
		findVertex(indirectDestination)->increase_degree();

		EdgeList->insert(newEdge);						//EdgeList에 해당 edge를 삽입
	}
};

int arr[2001][2001];				//arr[x][y] : 정점 x,y의 간선 존재 여부(1 : 존재, 0 : 존재x)

int main()
{
	int n;							//정점의 개수
	int m;							//간선의 개수
	int k;							//인접 유무 질의 개수
	int x, y;						//입력할 정점

	graph g;

	cin >> n >> m >> k;

	for (int i = 0; i < n; i++)
	{
		cin >> x;

		g.insert_vertex(x);
	}

	for (int i = 0; i < m; i++)
	{
		cin >> x >> y;

		g.insert_edge(x, y);

		if (g.isfindVertex(x) == true && g.isfindVertex(y) == true)	//x,y가 그래프에 둘 다 있는 경우 -> 간선 존재
		{
			arr[x][y] = 1;
			arr[y][x] = 1;
		}
	}

	cout << n << ' ' << m - edgecnt << endl;

	for (int i = 0; i < k; i++)
	{
		cin >> x >> y;

		if (g.isfindVertex(x) == false || g.isfindVertex(y) == false)	//정점 x,y가 존재x 경우 -1을 출력
			cout << -1 << endl;
		else if (arr[x][y])
			cout << 1 << endl;
		else
			cout << 0 << endl;
	}


}