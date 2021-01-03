#include <iostream>
#include <string>
using namespace std;

//class Stack
//{
//public:
//	int* s;							//�迭
//	int capacity;					//�迭�� ũ��
//	int t;							//top�� �ε���
//
//	Stack(int e)
//	{
//		this->s = new int(e);
//		this->capacity = e;
//		this->t = -1;
//	}
//
//	bool empty()					//������ ��� ������ 1, ���Ұ� ������ 0
//	{
//		return (t == -1);
//	}
//
//	int top()						//������ ���� ���� ����� ������ ���
//	{
//		if (!empty())				//���ÿ� ���Ұ� �ִ� ���				
//		{
//			return s[t];
//		}
//		else						//���ÿ� ���Ұ� ���� ���
//		{
//			return -1;
//		}
//	}
//
//	void push(int e)				//���ÿ� element�� ����
//	{
//		t++;
//
//		s[t] = e;
//	}
//
//	int pop()						//���ÿ��� ���� ���� �ִ� ������ �����ϰ�, ������ ���� ���
//	{
//		if (empty())
//		{
//			return -1;				//������ ��� �ִ� ���, -1�� ���
//		}
//
//		t--;
//
//		return s[t + 1];
//	}
//
//	int size()						//���ÿ� ����Ǿ� �ִ� ������ ������ ���
//	{
//		return (t + 1);
//	}
//};

int stack[10002];
//string stack;
int top = 0;


void push(int x)
{
	stack[top] = x;
	top++;
}

int pop()
{	
	top--;

	return stack[top];
}

int postfix(string str)
{
	int a, b, value;
	int len = str.length();
	char symbol;

	for (int i = 0; i < len; i++)
	{
		symbol = str[i];

		if (symbol != '+' && symbol != '-' && symbol != '*') 
		{
			value = symbol - '0';
			push(value);
		}
		else 
		{
			a = pop();
			b = pop();
			switch (symbol) 
			{
			case '+': push(a + b); break;
			case '-': push(a - b); break;
			case '*': push(a * b); break;
			}
		}
	}

	return pop();
}

int main()
{
	int n;						//������ ����
	string s;					//����

	cin >> n;

	

	while (n--)
	{
		cin >> s;

		cout << postfix(s) << endl;
	}


	return 0;
}