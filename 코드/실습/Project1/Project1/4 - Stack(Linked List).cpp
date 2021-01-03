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
	int n;							//������ ������ ����
	SLinkedList* s;					//��ũ�� ����Ʈ

	linkedStack()
	{
		this->n = 0;
		this->s = new SLinkedList;
	}

	int size()						//���� ������ ������ ���� Ȯ��
	{
		return n;
	}

	bool empty()					//������ ��� ������ 1, �ƴϸ� 0
	{
		return (n == 0);
	}

	int top()						//������ �� �� ���� Ȯ��
	{
		if (empty())				//������ ��� �ִ� ���
		{
			return -1;
		}
		else
		{
			return s->front();
		}
	}

	void push(int e)				//���� element ����
	{
		s->addFront(e);
	}

	int pop()
	{
		if (empty())				//������ ��� �ִ� ���
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