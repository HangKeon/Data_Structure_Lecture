#include <iostream>
#include <string>
using namespace std;

typedef string Elem;

class StringNode
{
private:
	Elem elem;
	StringNode* next;

	friend class StringLinkedList;
};

class StringLinkedList
{
private:
	StringNode* head;
	StringNode* tail;
public:
	StringLinkedList() {}
	~StringLinkedList() {}
	bool empty() const;
	Elem front() const;
	void addFront(const Elem& e);
	void removeFront();
	void addBack(const Elem& e);
	void removeBack();
};

bool StringLinkedList::empty() const
{
	/*if (head == NULL)
		return true;

	return false;*/

	return head == NULL;
}

Elem StringLinkedList::front() const
{
	return head->elem;
}

void StringLinkedList::addFront(const Elem& e)
{
	StringNode* v = new StringNode;

	if (empty())
		tail = v;

	v->elem = e;
	v->next = head;

	head = v;
}

void StringLinkedList::removeFront()
{
	if (empty())
		return;

	StringNode* old = head;

	head = old->next;
	
	delete old;

	if (empty())
		tail = NULL;
}

void StringLinkedList::addBack(const Elem& e)
{
	StringNode* v = new StringNode;

	v->next = NULL;
	v->elem = e;

	if (empty())
		head = tail = NULL;
	else
	{
		tail->next = v;
		tail = v;
	}
}

void StringLinkedList::removeBack()
{
	if (empty())
		return;

	StringNode* current = head;

	if (current == tail)
	{
		head = tail = NULL;
		delete current;
	}
	else
	{
		while (current->next != tail)
		{
			current = current->next;
		}

		tail = current;
		delete tail->next;
		tail->next = NULL;
	}
}

int main()
{




	return 0;
}