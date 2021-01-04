#include <iostream>
#include <string>
using namespace std;

class node
{
public:
	int data;
	node* next;

	node(int x)
	{
		data = x;
		next = NULL;
	}
};

class CLinkedList
{
public:
	node* head;
	node* tail;
	node* cursor;

	CLinkedList()
	{
		head = tail = cursor = NULL;
	}

	void push(int x)
	{
		node* v = new node(x);

		if (empty())
		{
			v->next = v;
			head = v;
			tail = v;
			cursor = v;
		}
		else
		{
			v->next = head;
			cursor->next = v;
			tail = v;
			cursor = v;
		}
	}

	void Delete(int idx)
	{
		node* old = new node(0);
		cursor = head;
		int cnt = 0;

		while (cnt < idx - 1)
		{
			cursor = cursor->next;
			cnt++;
		}

		if (idx == 0)
			old = cursor;
		else
			old = cursor->next;

		cursor->next = old->next;

		if (old == head)
			head = cursor->next;

		if (old == tail)
			tail = cursor;

		delete old;
	}

	bool empty()
	{
		return (head == NULL);
	}

	void showList()
	{
		cursor = head;

		cout << cursor->data << ' ';
		cursor = cursor->next;

		while (cursor != tail->next)
		{
			cout << cursor->data << ' ';
			cursor = cursor->next;
		}

		cout << endl;
	}
};

int main()
{
	int n;
	int x;

	cin >> n;

	while (n--)
	{
		CLinkedList cll;
		string s;
		int all = 10;

		for (int i = 0; i < 10; i++)
		{
			cin >> x;

			cll.push(x);
		}

		for (int i = 0; i < 3; i++)
		{
			cin >> s >> x;

			cll.Delete(x%all);

			all--;
		}

		cll.showList();
	}

	return 0;
}