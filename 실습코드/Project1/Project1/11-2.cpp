#include <iostream>
#include <vector>
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
		data = 0;
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

	Node* findNode(int data)			//노드의 탐색 연산(data = 찾고자 하는 데이터) -> leaf노드 만날 때까지 수행
	{
		Node* node = root;

		while (node != NULL)
		{
			if (node->data == data)			//원하는 데이터를 찾은 경우
				return node;
			else if (node->data < data)		//찾고자 하는 데이터 > 현재 노드의 데이터
				node = node->right;
			else							//찾고자 하는 데이터 < 현재 노드의 데이터
				node = node->left;
		}

		return NULL;						//찾지 못한 경우
	}

	Node* findMin(Node* node)				//주어진 노드를 루트로 하는 부분 트리의 최소 노드를 탐색
	{
		Node* temp = node;

		while (temp->left != NULL)
			temp = temp->left;

		return temp;
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
		}
	}

	void transplant(Node* u, Node* v)			//자식을 삭제노드의 부모에 이식
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

	void delNode(int data)						//노드 삭제 연산 
	{
		Node* temp = findNode(data);

		if (temp->left == NULL)					//case1
			transplant(temp, temp->right);
		else if (temp->right == NULL)			//case1
			transplant(temp, temp->left);
		else									//case2 -> 우선 가장 작은 노드를 저장해주고 삭제를 진행
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

		delete temp;							//이거 없으면 run time error가 난다.
	}

	void preorder(Node* root)					//전위순회로 출력
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
	int t;							//테스트 케이스 수 
	int n;							//이진 탐색 트리를 구성할 노드의 수
	int m;							//탐색할 노드 수
	int x;							//입력할 노드 번호

	cin >> t;

	while (t--)
	{
		BST bst;

		cin >> n;

		for (int i = 0; i < n; i++)			//입력
		{
			cin >> x;

			bst.insert(x);
		}

		cin >> m;

		for (int i = 0; i < m; i++)			//삭제
		{
			cin >> x;

			bst.delNode(x);
		}

		if (bst.root == NULL)				//출력할 노드가 없는 경우 0을 출력
			cout << 0 << endl;
		else
		{
			bst.preorder(bst.root);
			cout << endl;
		}
	}

	return 0;
}