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
		data = NULL;
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
	int height;

	BST()
	{
		root = NULL;
		height = 0;
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

	void printHeight()					//Ʈ���� ���̸� ���
	{
		cout << height << endl;
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

			if (height < v->depth())		//�Է��ϸ鼭 height�� ����
				height = v->depth();
		}
	}
};

int main()
{
	int t;							//�׽�Ʈ ���̽� �� 
	int n;							//���� Ž�� Ʈ���� ������ ����� ��
	int x;							//�Է��� ��� ��ȣ
	int depth = 0;					// ���� Ž�� Ʈ���� ����

	cin >> t;

	while (t--)
	{
		BST bst;

		cin >> n;

		for (int i = 0; i < n; i++)
		{
			cin >> x;

			bst.insert(x);
		}

		bst.printHeight();
	}

	return 0;
}