#include <iostream>
#include <string>
using namespace std;

//class Stack
//{
//public:
//	int* s;							//배열
//	int capacity;					//배열의 크기
//	int t;							//top의 인덱스
//
//	Stack(int e)
//	{
//		this->s = new int(e);
//		this->capacity = e;
//		this->t = -1;
//	}
//
//	bool empty()					//스택이 비어 있으면 1, 원소가 있으면 0
//	{
//		return (t == -1);
//	}
//
//	int top()						//스택의 가장 위에 저장된 정수를 출력
//	{
//		if (!empty())				//스택에 원소가 있는 경우				
//		{
//			return s[t];
//		}
//		else						//스택에 원소가 없는 경우
//		{
//			return -1;
//		}
//	}
//
//	void push(int e)				//스택에 element를 삽입
//	{
//		t++;
//
//		s[t] = e;
//	}
//
//	int pop()						//스택에서 가장 위에 있는 정수를 삭제하고, 삭제된 수를 출력
//	{
//		if (empty())
//		{
//			return -1;				//스택이 비어 있는 경우, -1을 출력
//		}
//
//		t--;
//
//		return s[t + 1];
//	}
//
//	int size()						//스택에 저장되어 있는 정수의 개수를 출력
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
	int n;						//수식의 갯수
	string s;					//수식

	cin >> n;

	

	while (n--)
	{
		cin >> s;

		cout << postfix(s) << endl;
	}


	return 0;
}