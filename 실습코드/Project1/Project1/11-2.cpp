#include <iostream>
#include <vector>
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

	Node* findMin(Node* node)				//�־��� ��带 ��Ʈ�� �ϴ� �κ� Ʈ���� �ּ� ��带 Ž��
	{
		Node* temp = node;

		while (temp->left != NULL)
			temp = temp->left;

		return temp;
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

	void transplant(Node* u, Node* v)			//�ڽ��� ��������� �θ� �̽�
	{
		if (u->parent == NULL)
			this->root = v;
		else if (u == u->parent->left)
			u->parent->left = v;
		else
			u->parent->right = v;

		if (v != NULL)
			v->parent = u->parent;
	}

	void delNode(int data)						//��� ���� ���� 
	{
		Node* temp = findNode(data);

		if (temp->left == NULL)					//case1
			transplant(temp, temp->right);
		else if (temp->right == NULL)			//case1
			transplant(temp, temp->left);
		else									//case2 -> �켱 ���� ���� ��带 �������ְ� ������ ����
		{
			Node* min = findMin(temp->right);

			if (min->parent != temp)
			{
				transplant(min, min->right);
				min->right = temp->right;
				min->right->parent = min;
			}

			transplant(temp, min);
			min->left = temp->left;
			min->left->parent = min;
		}

		delete temp;							//�̰� ������ run time error�� ����.
	}

	void preorder(Node* root)					//������ȸ�� ���
	{
		if (root == NULL)
			return;
		else
		{
			cout << root->data << ' ';

			preorder(root->left);
			preorder(root->right);
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

		cin >> n;

		for (int i = 0; i < n; i++)			//�Է�
		{
			cin >> x;

			bst.insert(x);
		}

		cin >> m;

		for (int i = 0; i < m; i++)			//����
		{
			cin >> x;

			bst.delNode(x);
		}

		if (bst.root == NULL)				//����� ��尡 ���� ��� 0�� ���
			cout << 0 << endl;
		else
		{
			bst.preorder(bst.root);
			cout << endl;
		}
	}

	return 0;
}