#include <iostream>
#include <string>
using namespace std;

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
	}


	return 0;
}














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
//	bool empty()					//������ ��� ������ 0, ���Ұ� ������ 1
//	{
//		return (t == -1);
//	}
//
//	int top()						//������ ���� ���� ����� ������ ���
//	{
//		if (empty())				//���ÿ� ���Ұ� ���� ���				
//		{
//			return -1;
//		}
//		else						//���ÿ� ���Ұ� �ִ� ���
//		{
//			return s[t];
//		}
//	}
//
//	void push(int e)				//���ÿ� element�� ����
//	{
//		t++;
//
//		s[t] = e;
//	}
//};
//
//int main()
//{
//	int n;							//��ɾ� ��
//	int x;							//�Է°�
//	string s;						//��ɾ�
//
//	cin >> n;
//
//	Stack str(n+10);
//
//	for (int i = 0; i < n; i++)
//	{
//		cin >> s;
//
//		if (s == "empty")
//		{
//			cout << str.empty() << endl;
//		}
//		else if (s == "top")
//		{
//			cout << str.top() << endl;
//		}
//		else if (s == "push")
//		{
//			cin >> x;
//
//			str.push(x);
//		}
//	}
//
//
//	return 0;
//}