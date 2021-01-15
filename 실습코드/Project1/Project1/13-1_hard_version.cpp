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

	edge(vertex* a, vertex* b)
	{
		this->source = a;
		this->destination = b;
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

int edgecnt = 0;					//������ ����

class graph
{
public:
	edge*** edgeMatrix;						//edge ������ �����ϴ� matrix->������ �迭 
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

	void insert_edge(int indirectSource, int indirectDestination)	//�׷����� �ش� edge�� ����
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

		edge* newEdge = new edge(findVertex(indirectSource), findVertex(indirectDestination));
		edgeMatrix[source][destination] = newEdge;		//matrix�� �ش� edge�� ����
		edgeMatrix[destination][source] = newEdge;

		findVertex(indirectSource)->increase_degree();
		findVertex(indirectDestination)->increase_degree();

		EdgeList->insert(newEdge);						//EdgeList�� �ش� edge�� ����
	}
};

int arr[2001][2001];				//arr[x][y] : ���� x,y�� ���� ���� ����(1 : ����, 0 : ����x)

int main()
{
	int n;							//������ ����
	int m;							//������ ����
	int k;							//���� ���� ���� ����
	int x, y;						//�Է��� ����

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

		if (g.isfindVertex(x) == true && g.isfindVertex(y) == true)	//x,y�� �׷����� �� �� �ִ� ��� -> ���� ����
		{
			arr[x][y] = 1;
			arr[y][x] = 1;
		}
	}

	cout << n << ' ' << m - edgecnt << endl;

	for (int i = 0; i < k; i++)
	{
		cin >> x >> y;

		if (g.isfindVertex(x) == false || g.isfindVertex(y) == false)	//���� x,y�� ����x ��� -1�� ���
			cout << -1 << endl;
		else if (arr[x][y])
			cout << 1 << endl;
		else
			cout << 0 << endl;
	}


}