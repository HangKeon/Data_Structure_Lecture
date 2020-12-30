#include <iostream>
using namespace std;

class Node
{
public:
	int data;						//���Ұ�
	Node* next;						//���� ��� �ּ�

	Node(int e)
	{
		this->data = e;
		this->next = NULL;
	}
};

class SLinkedList
{
public:
	Node* head;						//����Ʈ�� head
	Node* tail;						//����Ʈ�� tail

	SLinkedList()					//������ -> ó������ �ƹ��� ��尡 ����x => NULL�� �ʱ�ȭ!
	{
		head = NULL;
		tail = NULL;
	}

	void addFront(int x)			//����Ʈ�� ���� �տ� ��带 ����
	{
		Node* v = new Node(x);		//new Node�� �Ҵ�

		if (empty())				//����Ʈ�� ������� ��
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

	int removeFront()				//����Ʈ�� ���� �� ��带 ���� �� ���Ҹ� ��ȯ
	{
		if (empty())				//����Ʈ�� ������� ��
		{
			return 0;
		}
		else
		{
			Node* old = head;		//�ӽó�� old ����

			head = old->next;

			delete old;				//�� �� ����� old ����

			return head->data;
		}

	}

	int front()						//����Ʈ�� ���� �� ����� ���Ұ� ��ȯ
	{
		if (empty())				//����Ʈ�� ������� ��
		{
			return 0;
		}
		else
		{
			return head->data;
		}

	}

	int empty()						//����Ʈ�� ����ִ��� Ȯ���ϴ� �� ��ȯ
	{
		//if (head == NULL)			//����ִ� ���
		//{
		//	return 1;
		//}
		//else						//������� ���� ���
		//{
		//	return 0;
		//}

		return head == NULL;

	}

	void showList()					//����Ʈ�� ����Ǿ� �ִ� �������� �տ������� ���ʴ�� ���
	{
		if (empty())				//����Ʈ�� ������� ��
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

	void addBack(int x)				//����Ʈ�� ���� �ڿ� ��带 ����
	{
		Node* v = new Node(x);		//new Node �Ҵ�

		if (empty())				//����Ʈ�� ������� ��
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