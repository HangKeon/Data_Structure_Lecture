#include <iostream>
#include <string>
using namespace std;

int stack[101] = { 0, };
int top = 0;

void push(int x)
{
	stack[top++] = x;
}

int pop()
{
	return stack[--top];
}

int main()
{
	int n;

	cin >> n;

	while (n--)
	{
		string s;

		cin >> s;

		int len = s.length();

		for (int i = 0; i < len; i++)
		{
			if (s[i] == '+' || s[i] == '-' || s[i] == '*')
			{
				int a = pop();
				int b = pop();

				switch (s[i])
				{
				case '+':
					push(b + a);
					break;

				case '-':
					push(b - a);
					break;

				case '*':
					push(b*a);
					break;
				}
			}
			else
			{
				push(s[i] - '0');
			}

		}

		cout << stack[0] << endl;

		for (int i = 0; i < 100; i++)
			stack[i] = 0;

		top = 0;
		
	}



	return 0;
}