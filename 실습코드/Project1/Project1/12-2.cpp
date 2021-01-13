#include <iostream>
using namespace std;

#define MAX 353333					//�ؽ� ���̺��� ũ�� -> ū �Ҽ�
#define NOITEM 0					//������ ���� ���� ���
#define ISITEM 1					//������ ���� �ִ� ���
#define AVAILABLE 2					//������ �־��� ��

class cell							//�ؽ� ���̺��� �� ���� ������ ������ Ÿ��
{
public:
	int key;						//key�� -> �ε���
	int value;						//������ ��
	int flag;						//NOITEM, ISITEM, AVAILABLE �� �ϳ��� ����

	cell()							//������
	{
		key = -1;
		value = -1;
		flag = NOITEM;
	}

	~cell() {}						//�Ҹ���
};

cell hashtable[MAX];
int sz = 0;							//�ؽ��� ���� ����Ǿ� �ִ� ������ ũ��

int hashfunc(int key)				//1�� �ؽ� �Լ�
{
	return key % MAX;
}

int hashfunc2(int key)				//2�� �ؽ� �Լ�
{
	return (17 - (key % 17));
}

void DoubleInsert(int key)			//Double Hashing ����
{
	int probing = 1;				//Ž�� Ƚ��(�浹�� ���� ��츦 probing 1ȸ)

	while (hashtable[hashfunc(key + (probing - 1)*hashfunc2(key))].flag) //�ؽ� ���̺��� �ִ� ���
	{
		probing++;					//Ž�� Ƚ���� 1 ����
	}

	hashtable[hashfunc(key + (probing - 1)*hashfunc2(key))].flag = ISITEM;
	hashtable[hashfunc(key + (probing - 1)*hashfunc2(key))].key = key;

	sz++;							//��ü �ؽ� ���� ����
}

void DoubleSearch(int key)			//Double Hashing Ž��
{
	int probing = 1;				//Ž�� Ƚ��(�浹�� ���� ��츦 probing 1ȸ)

	while (hashtable[hashfunc(key + (probing - 1)*hashfunc2(key))].flag) //�ؽ� ���̺��� �ִ� ���
	{
		if (hashtable[hashfunc(key + (probing - 1)*hashfunc2(key))].key == key)	//�־��� �Է��� �ؽ� ���̺� �����ϸ�
		{
			cout << 1 << ' ' << probing << endl;	 //1�� probing Ƚ���� ���
			return;
		}

		probing++;					//Ž�� Ƚ���� 1 ����	
	}

	cout << 0 << ' ' << probing << endl;			//�������� ������ 0�� probing Ƚ��
}

int main()
{
	int t;							//�׽�Ʈ ���̽� ��
	int n;							//�ؽ� ���̺��� ������ �� �ִ� �ڿ����� ��
	int m;							//�ؽ� ���̺��� Ž���� �ڿ����� ��
	int x;							//�Է��� ���

	cin >> t;

	while (t--)
	{
		for (int i = 0; i < MAX; i++)		//�ʱ�ȭ
		{
			hashtable[i].key = -1;
			hashtable[i].flag = NOITEM;
			sz = 0;
		}

		cin >> n;

		for (int i = 0; i < n; i++)
		{
			cin >> x;

			DoubleInsert(x);
		}

		cin >> m;

		for (int i = 0; i < m; i++)
		{
			cin >> x;

			DoubleSearch(x);
		}
	}

	return 0;
}