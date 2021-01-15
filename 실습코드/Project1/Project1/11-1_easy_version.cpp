#include <iostream>
using namespace std;

class Node
{
public:
	Node* parent;
	Node* left;						//���� �ڽ�
	Node* right;					//������ �ڽ�
	int data;						//key ��

	Node()							//������
	{
		data = 0;	
		parent = NULL;
		left = NULL;
		right = NULL;
	}

	Node(int data)					//���ڰ� �ִ� ������
	{
		this->data = data;
		parent = NULL;
		left = NULL;
		right = NULL;
	}

	~Node() {}						//�Ҹ���

	void insert(Node* child)		//����� �ڽ��� ����
	{
		if (child->data > data)		//������ �ڽĿ� �߰�
		{
			right = child;
			child->parent = this;
		}
		else if (child->data < data)	//���� �ڽĿ� �߰�
		{
			left = child;
			child->parent = this;
		}
	}

	int degree()					//�ش� ����� �ڽ� ��� �� ��ȯ
	{
		int deg = 0;

		if (left != NULL)
			deg++;
		if (right != NULL)
			deg++;

		return deg;
	}

	int depth()						//�ش� ����� ���� ��ȯ
	{
		if (parent == NULL)
			return 0;

		return parent->depth() + 1;
	}
};

class BST
{
public:
	Node* root;

	BST()
	{
		root = NULL;
	}

	~BST()
	{
		this->treeDestructor((this->root));
	}

	void treeDestructor(Node* node)		//Ʈ�� ���� �Լ� -> dfs������� ���� ���� ���� ������ ����(PostOrder)
	{
		if (node == NULL)
			return;

		if (node->right != NULL)
			treeDestructor(node->right);

		if (node->left != NULL)
			treeDestructor(node->left);

		delete node;
	}

	Node* findNode(int data)			//����� Ž�� ����(data = ã���� �ϴ� ������) -> leaf��� ���� ������ ����
	{
		Node* node = root;

		while (node != NULL)
		{
			if (node->data == data)			//���ϴ� �����͸� ã�� ���
				return node;
			else if (node->data < data)		//ã���� �ϴ� ������ > ���� ����� ������
				node = node->right;
			else							//ã���� �ϴ� ������ < ���� ����� ������
				node = node->left;
		}

		return NULL;						//ã�� ���� ���
	}

	void printDegree(int x)					//���x�� �ڽ��� ���� ���
	{
		if (findNode(x) != NULL)
			cout << findNode(x)->degree() << ' ';
	}

	void printHeight(int x)					//���x�� ���̸� ���
	{
		if (findNode(x) == NULL)
			cout << 0 << endl;
		else
			cout << findNode(x)->depth() << endl;
	}

	void insert(int data)					//���ο� ���� ����
	{
		Node* v = new Node(data);

		if (root == NULL)					//empty tree�� ���
			root = v;
		else								//empty tree�� �ƴ� ���
		{
			Node* temp = root;

			while (1)
			{
				if (temp->data < data)
				{
					if (temp->right == NULL)
						break;

					temp = temp->right;
				}
				else if (temp->data > data)
				{
					if (temp->left == NULL)
						break;

					temp = temp->left;
				}
			}

			temp->insert(v);
		}
	}
};

int main()
{
	int t;							//�׽�Ʈ ���̽� �� 
	int n;							//���� Ž�� Ʈ���� ������ ����� ��
	int m;							//Ž���� ��� ��
	int x;							//�Է��� ��� ��ȣ

	cin >> t;

	while (t--)
	{
		BST bst;

		cin >> n;;

		for (int i = 0; i < n; i++)
		{
			cin >> x;

			bst.insert(x);
		}

		cin >> m;

		for (int i = 0; i < m; i++)
		{
			cin >> x;

			bst.printDegree(x);
			bst.printHeight(x);
		}
	}


	return 0;
}