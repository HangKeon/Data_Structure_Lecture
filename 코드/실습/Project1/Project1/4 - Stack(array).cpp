#include <iostream>
using namespace std;

class arrayStack
{
public:
	int* s;						//�迭
	int capacity;				//�迭�� ũ��
	int t;						//top�� �ε���

	arrayStack(int capacity)
	{
		this->capacity = capacity;
		this->s = new int[capacity];
		this->t = -1;
	}

	int size()					//������ ������ ����
	{
		return (t + 1);
	}

	bool empty()				//������ ��� ������ 0, ���Ұ� ������ 1
	{
		return (t == -1);
	}

	int top()					//������ �� �� ���� Ȯ��
	{
		if (!empty())			//���ÿ� ���Ұ� �ִ� ���				
		{
			return s[t];
		}
		else					//���ÿ� ���Ұ� ���� ���
		{
			return -1;
		}
	}

	void push(int e)			//���ÿ� element�� ����
	{
		if (t == capacity - 1)	//���ܻ��� -> ������ �� �� ���
		{

		}
		else
		{
			t++;

			s[t] = e;
		}
	}

	int pop()					//���� element�� ���� & ��ȯ
	{
		if(empty())				//���ܻ��� -> ������ ����ִ� ���
		{
			return -1;
		}
		
		t--;

		return s[t + 1];
	}
};

int main()
{





	return 0;
}