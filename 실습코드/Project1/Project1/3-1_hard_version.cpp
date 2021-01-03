#include <iostream>
#include <string>
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

	void addFront(int x)			//���� X�� ����Ʈ�� ���� �տ� ����
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

	int removeFront()				//����Ʈ���� ���� �տ� �ִ� ������ �����ϰ�, ������ ���� ���.
	{
		if (empty())				//����Ʈ�� ������� �� -1�� ���
		{
			return -1;
		}
		else
		{
			Node* old = head;		//�ӽó�� old ����
			int value = old->data;

			head = old->next;

			delete old;				//�� �� ����� old ����

			return value;
		}

	}

	int front()						//����Ʈ�� ���� �� ����� ���Ұ� ���
	{
		if (empty())				//����Ʈ�� ������� �� -1�� ���
		{
			return -1;
		}
		else
		{
			return head->data;
		}

	}

	int empty()						//����Ʈ�� ����ִ��� Ȯ���ϴ� �� ���
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
		if (empty())				//����Ʈ�� ������� ��, -1�� ���.
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

	void addBack(int x)				//����Ʈ�� ���� �ڿ� ��带 ����
	{
		Node* v = new Node(x);		//new Node �Ҵ�

		if (empty())				//����Ʈ�� ������� ��
		{
			head = tail = NULL;
		}
		else
		{
			Node* current = head;	//head���� Ž�� ����

			while (current->next != NULL)	//���� ���� �� ��带 ã��
				current = current->next;

			current->next = v;		//current�� v�� ����Ŵ
			tail = v;				//tail�� v�� �ٲ�
		}
	}
};


int main()
{
	int n;						//��ɾ��� ��
	int x;						//addFront���� �Է���  data
	string s;					//��ɾ�

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