#include <iostream>
#include <string>
using namespace std;

int queue[51];						//0�� ���Ұ� ���ٰ� ����
int f = 0;							//ť�� ���� ���� �ε���(���� ������ ��)
int r = -1;							//ť�� ���� ���� �ε���(�ֽ�)
int capacity = 50;					//�迭�� ũ��
int m;								//ť�� ���� �� �ִ� ������ ����

void enqueue(int x)
{
	r++;

	if (r == m)						//r�� m�� ������ ���
	{
		cout << "Full" << endl;
		r--;						//�̰� �� ���ָ� r�� ��� ����
	}
	else
	{
		queue[r] = x;
	}
}

int size()
{
	return (r - f + 1);
}

bool empty()
{
	return (r == -1);
}

int main()
{
	 
	int n;							//��ɾ��� ����
	int x;							//1 �� 9�� �ڿ���
	string s;						//��ɾ�

	cin >> m >> n;

	while (n--)
	{
		cin >> s;

		if (s == "enqueue")			//���� X�� ť�� �ڿ� ����. ť�� �������� ���� �� ���� ��� 'Full'�� ���
		{
			cin >> x;
			
			enqueue(x);
			
		}
		else if (s == "size")		//ť�� ����Ǿ��ִ� ������ ������ ���
		{
			cout << size() << endl;
		}
		else if (s == "isEmpty")	//ť�� ��� ������ 1, ��� ���� ������ 0�� ���
		{
			cout << empty() << endl;
		}
	}



	return 0;
}