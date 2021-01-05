#include <iostream>
#include <string>
using namespace std;

int queue[100];						//0�� ���Ұ� ���ٰ� ����
int f = 0;							//ť�� ���� ���� �ε���(���� ������ ��)
int r = -1;							//ť�� ���� ���� �ε���(�ֽ�)
int m;								//ť�� ���� �� �ִ� ������ ����

void enqueue(int x)					//���� X�� ť�� �ڿ� ����. ť�� �������� ���� �� ���� ��� 'Full'�� ���
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

bool empty()						//ť�� ��� ������ 1, ��� ���� ������ 0�� ���
{
	return queue[f] == 0;
}

void dequeue()	// ť���� ���� �տ� �ִ� ������ �����ϰ�, �� ���� ���. ���� ť�� ��� �ִ� ���, 'Empty'�� ���.
{
	if (empty())
	{
		cout << "Empty" << endl;
	}
	else
	{
		cout << queue[f] << endl;

		for (int i = 0; i < m; i++)		//queue[f]�� �����ǹǷ� ��� �������� �� ĭ �̵�!
			queue[i] = queue[i + 1];

		queue[m - 1] = 0;				//���� ���� �ִ� ģ���� 0���� �ʱ�ȭ!
		
		r--;							//��� ���Ұ� �������� �� ĭ �Ű������Ƿ� r�� 1 ����


		//queue[f++] = 0;				//queue[f] = 0�� �� �� f�� 1 ����

		//m++;						//f�� 1���������� ä�� �� �ִ� �迭�� ũ��� m�� �����ؾ� �ϱ� ����!
		//							//��, f�� �����ߴµ� m�� �����ȴٸ� ť�� ������ (f-m)���� ����!
	}
}

int size()							//ť�� ����Ǿ��ִ� ������ ������ ���
{
	return (r - f + 1);
}



void front()						//ť�� ���� �տ� ����� ������ ���.���� ť�� ��� �ִ� ���, Empty�� ���.
{
	if (empty())
	{
		cout << "Empty" << endl;
	}
	else
	{
		cout << queue[f] << endl;
	}
}

void rear()							// ť�� ���� �ڿ� ����� ������ ���. ���� ť�� ��� �ִ� ���, Empty�� ���
{
	if (empty())
	{
		cout << "Empty" << endl;
	}
	else
	{
		cout << queue[r] << endl;
	}
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
		else if (s == "dequeue")
		{
			dequeue();
		}
		else if (s == "size")		//ť�� ����Ǿ��ִ� ������ ������ ���
		{
			cout << size() << endl;
		}
		else if (s == "isEmpty")	//ť�� ��� ������ 1, ��� ���� ������ 0�� ���
		{
			cout << empty() << endl;
		}
		else if (s == "front")
		{
			front();
		}
		else if (s == "rear")
		{
			rear();
		}
	}



	return 0;
}