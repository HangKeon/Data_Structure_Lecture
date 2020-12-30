#include <iostream>
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

	void addFront(int x)			//리스트의 가장 앞에 노드를 삽입
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

	int removeFront()				//리스트의 가장 앞 노드를 삭제 후 원소를 반환
	{
		if (empty())				//리스트가 비어있을 때
		{
			return 0;
		}
		else
		{
			Node* old = head;		//임시노드 old 생성

			head = old->next;

			delete old;				//맨 앞 노드인 old 삭제

			return head->data;
		}

	}

	int front()						//리스트의 가장 앞 노드의 원소값 반환
	{
		if (empty())				//리스트가 비어있을 때
		{
			return 0;
		}
		else
		{
			return head->data;
		}

	}

	int empty()						//리스트가 비어있는지 확인하는 값 반환
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
		if (empty())				//리스트가 비어있을 때
		{
			cout << 0 << endl;
		}
		else
		{
			Node* current = head;

			while (current->next != NULL)
			{
				cout << current->data << ' ';
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
			tail->next = v;
			tail = v;
		}
	}
};

int main()
{



	return 0;
}