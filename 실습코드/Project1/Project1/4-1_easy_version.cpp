#include <iostream>
#include <string>
using namespace std;

int stack[10001];

int main()
{
	int n;							//명령어 수
	int x;							//입력값
	string s;						//명령어
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
//	bool empty()					//스택이 비어 있으면 0, 원소가 있으면 1
//	{
//		return (t == -1);
//	}
//
//	int top()						//스택의 가장 위에 저장된 정수를 출력
//	{
//		if (empty())				//스택에 원소가 없는 경우				
//		{
//			return -1;
//		}
//		else						//스택에 원소가 있는 경우
//		{
//			return s[t];
//		}
//	}
//
//	void push(int e)				//스택에 element를 삽입
//	{
//		t++;
//
//		s[t] = e;
//	}
//};
//
//int main()
//{
//	int n;							//명령어 수
//	int x;							//입력값
//	string s;						//명령어
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