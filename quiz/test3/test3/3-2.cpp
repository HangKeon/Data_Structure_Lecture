#include <iostream>
using namespace std;

#define MAX 353333
#define NOITEM 0
#define ISITEM 1
#define AVAILABLE 2

class cell
{
public:
	int key;
	int value;
	int flag;

	cell()
	{
		key = -1;
		value = -1;
		flag = NOITEM;
	}
};

cell hashtable[MAX];
int sz = 0;

int hashfunction(int key)
{
	return key % MAX;
}

int hashfunction2(int key)
{
	return(17 - (key % 17));
}

void DoubleInsert(int key)
{
	int probing = 1;

	while (hashtable[hashfunction(key + (probing - 1)*hashfunction2(key))].flag)
		probing++;

	hashtable[hashfunction(key + (probing - 1)*hashfunction2(key))].flag = ISITEM;
	hashtable[hashfunction(key + (probing - 1)*hashfunction2(key))].key = key;

	sz++;
}

void DoubleSearch(int key)
{
	int probing = 1;

	while (hashtable[hashfunction(key + (probing - 1)*hashfunction2(key))].flag)
	{
		if (hashtable[hashfunction(key + (probing - 1)*hashfunction2(key))].key == key)
		{
			cout << 1 << ' ' << probing << endl;
			return;
		}

		probing++;
	}

	cout << 0 << ' ' << probing << endl;
}

int main()
{
	int t;
	int n;
	int m;
	int x, y;

	cin >> t;

	while (t--)
	{
		for (int i = 0; i < MAX; i++)
		{
			hashtable[i].key = -1;
			hashtable[i].value - 1;
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