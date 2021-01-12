#include <iostream>
using namespace std;

class Node
{
public:
	Node* parent;
	Node* left;						//왼쪽 자식
	Node* right;					//오른쪽 자식
	int data;						//key 값

	Node()							//생성자
	{
		data = NULL;
		parent = NULL;
		left = NULL;
		right = NULL;
	}

	Node(int data)					//인자가 있는 생성자
	{
		this->data = data;
		parent = NULL;
		left = NULL;
		right = NULL;
	}

	~Node() {}						//소멸자

	void insert(Node* child)		//노드의 자식을 결정
	{
		if (child->data > data)		//오른쪽 자식에 추가
		{
			right = child;
			child->parent = this;
		}
		else if (child->data < data)	//왼쪽 자식에 추가
		{
			left = child;
			child->parent = this;
		}
	}

	int degree()					//해당 노드의 자식 노드 수 반환
	{
		int deg = 0;

		if (left != NULL)
			deg++;
		if (right != NULL)
			deg++;

		return deg;
	}

	int depth()						//해당 노드의 깊이 반환
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

	void treeDestructor(Node* node)		//트리 제거 함수 -> dfs방식으로 가장 안쪽 리프 노드부터 제거(PostOrder)
	{
		if (node == NULL)
			return;

		if (node->right != NULL)
			treeDestructor(node->right);

		if (node->left != NULL)
			treeDestructor(node->left);

		delete node;
	}

	void printHeight()					//트리의 깊이를 출력
	{
		cout << height << endl;
	}

	void insert(int data)					//새로운 값을 삽입
	{
		Node* v = new Node(data);

		if (root == NULL)					//empty tree인 경우
			root = v;
		else								//empty tree가 아닌 경우
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

			if (height < v->depth())		//입력하면서 height를 구함
				height = v->depth();
		}
	}
};

int main()
{
	int t;							//테스트 케이스 수 
	int n;							//이진 탐색 트리를 구성할 노드의 수
	int x;							//입력할 노드 번호
	int depth = 0;					// 이진 탐색 트리의 높이

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