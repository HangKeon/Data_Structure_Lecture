#include <iostream>
#include <string>
using namespace std;
//
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

int stack[10001];

int main()
{
	int n;							//��ɾ� ��
	int x;							//�Է°�
	string s;						//��ɾ�
	int top = 0;

	cin >> n;

	//Stack str(n + 2);

	for (int i = 0; i < n; i++)
	{
		cin >> s;

		if (s == "empty")
		{
			//cout << str.empty() << endl;

			if (top <= 0)
				cout << 1 << endl;
			else
				cout << 0 << endl;
		}
		else if (s == "top")
		{
			//cout << str.top() << endl;

			if (top <= 0)
				cout << -1 << endl;
			else
				cout << stack[top - 1] << endl;
		}
		else if (s == "push")
		{
			cin >> x;

			//str.push(x);

			stack[top] = x;
			top++;
		}
		else if (s == "pop")
		{
			//cout << str.pop() << endl;

			if (top <= 0)
				cout << "-1" << endl;
			else
			{
				cout << stack[top - 1] << endl;

				top--;
			}
		}
		else if (s == "size")
		{
			//cout << str.size() << endl;

			cout << top << endl;
		}
	}


	return 0;
}