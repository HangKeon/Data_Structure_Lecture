#include <iostream>
#include <string>
using namespace std;

class Node
{
public:
	int data;					//����� ����
	Node* next;					//���� �ּ�

	Node(int e)					//������
	{
		this->data = e;
		this->next = NULL;
	}
};

class CLinkedList				//ȯ�� ��ũ�� ����Ʈ
{
public:
	Node* head;
	Node* tail;
	Node* cursor;

	CLinkedList()				//������
	{
		cursor = NULL;
	}

	void addBack(int x)			//�ڿ������� x���� �߰�
	{
		Node* v = new Node(x);

		if (empty())
		{
			v->next = v;
			head = v;
			tail = head;
			cursor = head;
		}
		else
		{
			v->next = head;			//�ֳ��ϸ� ȯ�� ��ũ�� ����Ʈ�̹Ƿ�
			cursor->next = v;
			cursor = v;
			tail = v;
		}
	}

	void Delete(int x)				//head�κ��� x�� °�� �ִ� ���Ҹ� ����
	{
		Node* old = new Node(0);	//x�� ° ��带 ����Ŵ
		cursor = head;				//cursor�� head���� ����
		int cnt = 0;				//x�� ���� ���� �Ǳ� ������ ����

		while (cnt < x - 1)			//x�� ° �������� �̵�
		{
			cursor = cursor->next;
			cnt++;
		}

		if (x == 0)
			old = cursor;
		else
			old = cursor->next;

		cursor->next = old->next;

		if (old == head)			// head�� �����Ǵ� ���, head�� ���� ��忴�� ��尡 head�� �ȴ�
			head = cursor->next;

		if (old == tail)			//Tail�� �����Ǵ� ���, tail�� ���� ��忴�� ��尡 tail�� �ȴ�.
			tail = cursor;
		
		delete old;
	}

	int empty()						//����ִ��� ���� Ȯ��, 0 : ��� ���� ����, 1 : ��� ����
	{
		return head == NULL;
	}

	void showList()
	{
		Node* current = head;

		cout << current->data << ' ';
		current = current->next;

		while (current != tail->next)
		{
			cout << current->data << ' ';
			current = current->next;
		}

		cout << endl;
	}
};

int main()
{
	int n;						//���� ����
	string s;					//��ɾ�
	int x;						//��ɾ �ʿ��� ����

	

	cin >> n;

	while (n--)
	{
		CLinkedList* cll = new CLinkedList;

		int cnt = 0;			//Delete�� ������ ����
		int all = 10;			//��ü ������ ����

		for (int i = 0; i < 10; i++)
		{
			cin >> x;

			cll->addBack(x);
		}

		while (cnt < 3)
		{
			cin >> s;

			if (s == "Delete")
			{
				cin >> x;
				cll->Delete(x % all);	//x�� all���� Ŀ�� �� ������ ���ܼ� �̷��� ��ġ��!

				cnt++;
				all--;
			}
		}

		cll->showList();
	}


	return 0;
}