#include <iostream>
#include <string>
using namespace std;

class node
{
public:
	int data;
	node* next;

	node(int x)						//������
	{
		data = x;
		next = NULL;
	}
};

class SLinkedList
{
public:
	node* f;
	node* r;

	SLinkedList()				//�����ڸ� �̿��Ͽ� f,r�� �ʱ�ȭ
	{
		f = NULL;
		r = NULL;
	}

	int front()					//�� �տ� �ִ� ����� data ���� ��ȯ
	{

	}

	int end()					//�� �ڿ� �ִ� ����� data ���� ��ȯ
	{

	}

	int addEnd(int x)			//�� �ڿ� x���� ���� ��带 �߰�
	{
		node* v = new node(x);	//���ο� ��带 �߰�

		if (f == NULL)			//���� ����Ʈ�� ��� �߰��� ó���̶��
		{

		}
		else					//ó���� �ƴ� ���
		{

		}
	}

	void removeFront()			//�� ���� ��� ����
	{

	}
};

int main()
{




	return 0;
}