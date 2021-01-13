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

	~cell(){}						//�Ҹ���
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

void LinearInsert(int key)			//Linear Probing ����
{
	int probing = 1;				//Ž�� Ƚ��

	while (hashtable[hashfunc(key + probing - 1)].flag)		//�ؽ� ���̺��� �ִ� ���
	{
		probing++;					//Ž�� Ƚ���� 1 ����	
	}

	hashtable[hashfunc(key + probing - 1)].key = key;
	hashtable[hashfunc(key + probing - 1)].flag = ISITEM;

	sz++;							//��ü �ؽ��� ���� ����
}

void LinearSearch(int key)			//Linear Probing Ž��
{
	int probing = 1;				//Ž�� Ƚ��

	while (hashtable[hashfunc(key + probing - 1)].flag)		//�ؽ� ���̺��� �ִ� ���
	{
		if (hashtable[hashfunc(key + probing - 1)].key == key)	//�ش� key ���� ã�� key ���� �����ϴٸ�
		{
			cout << 1 << ' ' << probing << endl;
			return;
		}

		probing++;					//Ž�� Ƚ���� 1 ����	
	}

	cout << 0 << ' ' << probing << endl;
}

void LinearDelete(int key)			//Linear Probing ����
{
	int probing = 1;				//Ž�� Ƚ��

	while (hashtable[hashfunc(key + probing - 1)].flag)		//�ؽ� ���̺��� �ִ� ���
	{
		if (hashtable[hashfunc(key + probing - 1)].key == key)	//�ش� key ���� ã�� key ���� �����ϴٸ�
		{
			hashtable[hashfunc(key + probing - 1)].flag = AVAILABLE;
			hashtable[hashfunc(key + probing - 1)].key = -1;

			cout << 1 << ' ' << probing << endl;
			sz--;
			return;
		}

		probing++;					//Ž�� Ƚ���� 1 ����	
	}

	sz--;							//��ü �ؽ� ���� ����

	cout << 0 << ' ' << probing << endl;
}

void DoubleInsert(int key)			//Double Hashing ����
{
	int probing = 1;				//Ž�� Ƚ��

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
	int probing = 1;				//Ž�� Ƚ��

	while (hashtable[hashfunc(key + (probing - 1)*hashfunc2(key))].flag) //�ؽ� ���̺��� �ִ� ���
	{
		if (hashtable[hashfunc(key + (probing - 1)*hashfunc2(key))].key == key)	//�ش� key ���� ã�� key ���� �����ϴٸ�
		{
			cout << 1 << ' ' << probing << endl;
			return;
		}

		probing++;					//Ž�� Ƚ���� 1 ����	
	}

	cout << 0 << ' ' << probing << endl;
}

void tableClear()					//���̺� �޸� ����
{
	for (int i = 0; i < MAX; i++)
	{
		if (hashtable[i].flag)
		{
			hashtable[i].key = -1;
			hashtable[i].flag = NOITEM;
			hashtable[i].key = -1;

			sz--;					//��ü �ؽ� ���� ����
		}

		if (sz == 0)				//�ؽð� ���ٸ�
			break;
	}
}


int main()
{

	return 0;
}