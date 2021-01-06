#include <iostream>
#include <vector>
using namespace std;

class node
{
public:
	int data;						//저장할 데이터
	node* parent;					//부모 노드를 가리킬 포인터
	vector<node*> child;			//자식을 가리킬 포인터

	node()
	{
		this->data = NULL;
		this->parent = NULL;
	}

	node(int x)
	{
		this->data = x;
		this->parent = NULL;
	}

	~node(){}

	void insertChild(node* c)
	{
		this->child.push_back(c);
		return;
	}

	void delChild(node* c)
	{
		for(int i=0;i<this->child.size();i++)
			if (this->child[i] == c)
			{
				this->child.erase(this->child.begin() + i);
				break;
			}

		return;
	}
};

class GeneralTree
{
private:
	node* root;
	vector<node*> node_list;
public:
	GeneralTree()
	{
		root = NULL;
	}

	GeneralTree(int x)
	{
		root = new node(x);
		node_list.push_back(root);
	}
	
	~GeneralTree() {}

	void setRoot(int x)
	{
		root = new node(x);
		node_list.push_back(root);
	}

	node* getRoot()
	{
		return root;
	}

	void insertNode(int parent_data, int x)
	{

	}

	void delNode(int x)
	{

	}

	node* findNode(int x)
	{

	}

	void printChild(int x)
	{

	}

	int countDepth(int x)
	{

	}

	void preorder(node* n)
	{

	}

	void postorder(node* n)
	{

	}
};

int main()
{


	return 0;
}