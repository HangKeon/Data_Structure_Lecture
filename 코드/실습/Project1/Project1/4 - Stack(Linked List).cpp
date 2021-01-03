#include <iostream>
using namespace std;

class Node
{
public:
	int data;
	Node* next;

	Node(int e)
	{
		this->data = e;
		this->next = NULL;
	}
};

class SLinkedList
{
public:
	Node* head;
	Node* tail;

	SLinkedList()
	{
		head = NULL;
		tail = NULL;
	}

	int front()
	{
		return head->data;
	}

	void addFront(int e)
	{
		Node* v = new Node(e);

		if (head == NULL)
		{
			head = tail = v;
		}
		else
		{
			v->next = head;
			head = v;
		}
	}

	int removeFront()
	{
		Node* temp = head;

		head = head->next;

		return temp->data;
	}
};

class linkedStack
{
public:
	int n;							//스택의 원소의 개수
	SLinkedList* s;					//링크드 리스트

	linkedStack()
	{
		this->n = 0;
		this->s = new SLinkedList;
	}

	int size()						//현재 스택의 원소의 개수 확인
	{
		return n;
	}

	bool empty()					//스택이 비어 있으면 1, 아니면 0
	{
		return (n == 0);
	}

	int top()						//스택의 맨 위 원소 확인
	{
		if (empty())				//스택이 비어 있는 경우
		{
			return -1;
		}
		else
		{
			return s->front();
		}
	}

	void push(int e)				//스택 element 삽입
	{
		s->addFront(e);
	}

	int pop()
	{
		if (empty())				//스택이 비어 있는 경우
		{
			return -1;
		}
		else
		{
			s->removeFront();
		}
	}
};

int main()
{



	return 0;
}