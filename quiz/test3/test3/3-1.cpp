#include <iostream>
using namespace std;

class Node
{
public:
	Node* parent;
	Node* left;
	Node* right;
	int data;

	Node()
	{
		parent = NULL;
		left = NULL;
		right = NULL;
		data = 0;
	}

	Node(int x)
	{
		parent = NULL;
		left = NULL;
		right = NULL;
		data = x;
	}

	void insert(Node* child)
	{
		if (child->data > data)
		{
			right = child;
			child->parent = this;
		}
		else if (child->data < data)
		{
			left = child;
			child->parent = this;
		}
	}

	int depth()
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
		this->treeDestructor(this->root);
	}

	void treeDestructor(Node* node)
	{
		if (node == NULL)
			return;
		if (node->right != NULL)
			treeDestructor(node->right);
		if (node->left != NULL)
			treeDestructor(node->left);

		delete node;
	}

	void printHeight()
	{
		cout << height << endl;
	}

	void insert(int data)
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

			if (height < v->depth())
				height = v->depth();
		}
	}

};

int main()
{
	int t;
	int n;
	int x;
	
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