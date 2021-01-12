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
		else if(child->data < data)	//���� �ڽĿ� �߰�
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
			return;

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

	Node* findNode(int data)				//����� Ž�� ����(data = ã���� �ϴ� ������) -> leaf��� ���� ������ ����
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

		while (temp->right != NULL)
			temp = temp->right;

		return temp;
	}

	void insert(int data)					//���ο� ���� ����
	{
		Node* v = new Node(data);

		if (root == NULL)
			root = v;
		else
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
			u->parent->left = u;
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
	}
};

int main()
{
	


	return 0;
}