#include <iostream>
#include <string>
using namespace std;

int stack[101];					//����
int top = 0;					//�ε���

void push(int x)
{
	stack[top++] = x;
}

int pop()
{
	/*int value = stack[top - 1];
	top--;*/

	return stack[--top];
}

int main()
{
	int n;						//������ ���� 
	int len;					//���ڿ��� ���� 
	string s;

	cin >> n;

	while (n--)
	{
		cin >> s;

		len = s.length();

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
			else				//������ ���
			{
				push(s[i]-'0');
			}
		}


		cout << stack[0] << endl;

		for (int i = 0; i < 101; i++)
			stack[i] = 0;

		top = 0;
	}


	return 0;
}