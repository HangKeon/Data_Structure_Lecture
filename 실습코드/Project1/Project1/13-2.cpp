#include <iostream>
#include <string>
using namespace std;

#define MappingSize 501

class vertex
{
public:
	vertex* prev;					//���� ����
	vertex* next;					//���� ����
	int degree;						//������ ���� ��
	int data;						//���� ����� ����

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

class DoublyVertexLinkedList		//vertex�� �̷���� DLL
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
	edge*** edgeMatrix;						//edge ������ �����ϴ� matrux->������ �迭 
	DoublyVertexLinkedList* VertexList;		//��ü vertex ������ �����ϴ� DLL
	DoublyEdgeLinkedList* EdgeList;			//��ü edge ������ �����ϴ� DLL
	int vertexSize;							//�׷����� �����ϴ� vertex�� ����
	int mappingTable[MappingSize];			//vertex�� ������ ��ȣ�� �ش� vertex�� matrix���� index�� ����

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

	bool isfindVertex(int n)				//VertexList���� ������ ��ȣ�� n�� vertex�� ���� ���� �˻�
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

	vertex* findVertex(int n)				//VertexLsit���� ������ ��ȣ�� n��
	{
		vertex* temp = VertexList->head;	//vertex�� �ּ� ��ȯ

		while (temp != NULL)
		{
			if (temp->data == n)
				break;

			temp = temp->next;
		}

		return temp;
	}

	void insert_vertex(int n)				//�׷����� ������ ��ȣ�� n�� vertex ����
	{
		if (isfindVertex(n) == true)
			return;
		else
		{
			edge*** tempMatrix = new edge**[vertexSize + 1];	//������ 1�� �߰��� ������

			for (int i = 0; i < vertexSize + 1; i++)			//���� matrix���� ����, ���� ���̰� 1��ŭ
			{
				tempMatrix[i] = new edge*[vertexSize + 1];		//�� ū tempMatrix ����

				for (int j = 0; j < vertexSize + 1; j++)
					tempMatrix[i][j] = NULL;
			}

			for (int i = 0; i < vertexSize; i++)
				for (int j = 0; j < vertexSize; j++)
					tempMatrix[i][j] = this->edgeMatrix[i][j];	//element���� copy

			this->edgeMatrix = tempMatrix;						//���� matrix�� ���ο� matrix�� ����

			vertex* newVertex = new vertex(n);
			VertexList->insert(newVertex);						//VertexList�� ������ȣ�� n�� vertex �߰�
			this->vertexSize++;
			mappingTable[vertexSize - 1] = n;					//mappingTable�� vertex �ڽ���
																//matrix�� ��� index���� ����
		}
	}

	void erase_vertex(int n)									//�׷����� ������ ��ȣ�� n�� vertex ����
	{
		if (isfindVertex(n) == false || vertexSize == 0)		//������ ������ x�ų� ������ x�� ���
			return;
		else
		{
			edge*** tempMatrix = new edge**[vertexSize - 1];	//������ 1�� ������ ������

			for (int i = 0; i < vertexSize - 1; i++)			//���� matrix���� ����, ���� ���̰� 1��ŭ
			{
				tempMatrix[i] = new edge*[vertexSize - 1];		//�� ���� tempMatrix ����

				for (int j = 0; j < vertexSize - 1; j++)
					tempMatrix[i][j] = NULL;
			}

			int middleIdx = 0;

			for (int i = 0; i < vertexSize; i++)
				if (mappingTable[i] == n)
					middleIdx = i;					//middleIdx : ������ vertex�� matrix������ �ε���

			for (int i = middleIdx; i < vertexSize; i++)
				mappingTable[i] = mappingTable[i + 1];	//mappingTable update

			for (int i = 0; i < vertexSize; i++)	//EdgeList���� ������ȣ�� n�� vertex�� ����� ��� edge���� ����
				if (this->edgeMatrix[middleIdx] != NULL)
					EdgeList->remove(this->edgeMatrix[middleIdx][i]);

			for (int i = 0; i < vertexSize; i++)	//middleIdx�� �������� element���� ������ copy
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
			VertexList->remove(findVertex(n));		//VertexList�� ������ȣ�� n�� vertex ����
			this->vertexSize--;
		}
	}

	void insert_edge(int indirectSource, int indirectDestination, string data)	//�׷����� �ش� edge�� ����
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
			if (mappingTable[i] == indirectDestination)	//IndirectSource�� vertex�� ������ȣ
				destination = i;

			if (mappingTable[i] == indirectSource)		//source�� �ش� vertex�� matrix������ �ε���
				source = i;

			if (source != -1 && destination != -1)
				break;
		}

		if (edgeMatrix[source][destination] != NULL || edgeMatrix[destination][source] != NULL)
		{
			cout << -1 << endl;							//�����Ϸ��� edge�� �̹� �����ϴ� ���
			edgecnt++;
			return;
		}

		edge* newEdge = new edge(findVertex(indirectSource), findVertex(indirectDestination), data);
		edgeMatrix[source][destination] = newEdge;		//matrix�� �ش� edge�� ����
		edgeMatrix[destination][source] = newEdge;

		findVertex(indirectSource)->increase_degree();
		findVertex(indirectDestination)->increase_degree();

		EdgeList->insert(newEdge);						//EdgeList�� �ش� edge�� ����
	}

	void erase_edge(int indirectSource, int indirectDestionation)	//�׷����� �ش� edge�� ����
	{
		int destination = -1;
		int source = -1;

		for (int i = 0; i <= vertexSize; i++)
		{
			if (mappingTable[i] == indirectDestionation)
				destination = i;

			if (mappingTable[i] == indirectSource)		//source�� �ش� vertex�� matrix������ �ε���
				source = i;

			if (source != -1 && destination != -1)
				break;
		}

		if (edgeMatrix[source][destination] == NULL || edgeMatrix[destination][source] == NULL)
			return;				//�����Ϸ��� �ϴ� edge�� �̹� �������� �ʴ� ���

		findVertex(indirectSource)->decrease_degree();
		findVertex(indirectDestionation)->decrease_degree();

		edge* delEdge = edgeMatrix[source][destination];	//�ش� edge�� �ּҰ��� matrix���� ����
		EdgeList->remove(delEdge);							//EdgeList���� �ش� edge�� ����

		edgeMatrix[source][destination] = NULL;				//matrix���� �ش� edge�� ����
		edgeMatrix[destination][source] = NULL;
	}
};

int main()
{
	int n;							//������ ����
	int m;							//������ ����
	int k;							//������ ���� ����
	int x, y;						//�Է��� ����
	string s;						//�Է��� ���ڿ�
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