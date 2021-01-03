#include <iostream>
#include <string>
using namespace std;

class Node
{
public:
	int data;						//원소값
	Node* next;						//다음 노드 주소

	Node(int e)
	{
		this->data = e;
		this->next = NULL;
	}
};

class SLinkedList
{
public:
	Node* head;						//리스트의 head
	Node* tail;						//리스트의 tail

	SLinkedList()					//생성자 -> 처음에는 아무런 노드가 저장x => NULL로 초기화!
	{
		head = NULL;
		tail = NULL;
	}

	void addFront(int x)			//정수 X를 리스트의 가장 앞에 삽입
	{
		Node* v = new Node(x);		//new Node를 할당

		if (empty())				//리스트가 비어있을 때
		{
			head = v;
		}
		else
		{
			v->data = x;
			v->next = head;
			head = v;
		}
	}

	int removeFront()				//리스트에서 가장 앞에 있는 정수를 삭제하고, 삭제된 수를 출력.
	{
		if (empty())				//리스트가 비어있을 때 -1을 출력
		{
			return -1;
		}
		else
		{
			Node* old = head;		//임시노드 old 생성
			int value = old->data;

			head = old->next;

			delete old;				//맨 앞 노드인 old 삭제

			return value;
		}

	}

	int front()						//리스트의 가장 앞 노드의 원소값 출력
	{
		if (empty())				//리스트가 비어있을 때 -1을 출력
		{
			return -1;
		}
		else
		{
			return head->data;
		}

	}

	int empty()						//리스트가 비어있는지 확인하는 값 출력
	{
		//if (head == NULL)			//비어있는 경우
		//{
		//	return 1;
		//}
		//else						//비어있지 않은 경우
		//{
		//	return 0;
		//}

		return head == NULL;

	}

	void showList()					//리스트에 저장되어 있는 정수들을 앞에서부터 차례대로 출력
	{
		if (empty())				//리스트가 비어있을 때, -1을 출력.
		{
			cout << -1 << endl;
		}
		else
		{
			Node* current = head;

			while (current != NULL)
			{
				cout << current->data << ' ';
				current = current->next;
			}

			cout << endl;
		}
	}

	void addBack(int x)				//리스트의 가장 뒤에 노드를 삽입
	{
		Node* v = new Node(x);		//new Node 할당

		if (empty())				//리스트가 비어있을 때
		{
			head = tail = NULL;
		}
		else
		{
			Node* current = head;	//head부터 탐색 시작

			while (current->next != NULL)	//현재 가장 끝 노드를 찾음
				current = current->next;

			current->next = v;		//current가 v를 가리킴
			tail = v;				//tail이 v로 바뀜
		}
	}
};


int main()
{
	int n;						//명령어의 수
	int x;						//addFront에서 입력할  data
	string s;					//명령어

	SLinkedList sll;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> s;

		if (s == "addFront")
		{
			cin >> x;

			sll.addFront(x);
		}
		else if (s == "removeFront")
		{
			cout << sll.removeFront() << endl;
		}
		else if (s == "front")
		{
			cout << sll.front() << endl;
		}
		else if (s == "empty")
		{
			cout << sll.empty() << endl;
		}
		else if (s == "showList")
		{
			sll.showList();
		}
		else if (s == "addBack")
		{
			cin >> x;

			sll.addBack(x);
		}
	}


	return 0;
}