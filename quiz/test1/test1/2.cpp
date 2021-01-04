#include <iostream>
#include <string>
using namespace std;

class Array
{
public:
	int n;
	int* arr;

	Array()
	{
		this->n = 10000;
		this->arr = new int[n];

		for (int i = 0; i < n; i++)
			arr[i] = 0;
	}

	int at(int idx)
	{
		if (arr[idx] == 0)
			return 0;
		else
		{
			return arr[idx];
		}
	}

	void set(int idx, int x)
	{
		if (arr[idx] == 0)
		{
			cout << 0 << endl;
		}
		else
		{
			arr[idx] = x;
		}
	}

	void add(int idx, int x)
	{
		int sw = 0;

		if (arr[idx] == 0)
		{
			for (int i = n - 1; i >= 0; i--)
			{
				if (arr[i] != 0)
				{
					arr[i + 1] = x;
					sw = 1;
					break;
				}
			}

			if (sw == 0)
				arr[0] = x;

			return;
		}

		for (int i = n - 1; i > idx; i--)
			arr[i] = arr[i - 1];

		arr[idx] = x;
	}

	int remove(int idx)
	{
		if (arr[idx] == 0)
			return 0;
		else
		{
			int value = arr[idx];

			for(int i=idx;i<n;i++)
				if (arr[i] != 0 && arr[i + 1] != 0)
					arr[i] = arr[i + 1];
				

			for (int i = n - 1; i >= 0; i--)
			{
				if (arr[i] != 0)
				{
					arr[i] = 0;
					break;
				}
			}

			return value;
		}
	}

	void printArray()
	{
		int sw = 0;

		for (int i = 0; i < n; i++)
		{
			if (arr[i] != 0)
			{
				sw = 1;
				break;
			}
		}

		if (sw == 0)
			cout << 0 << endl;

		for (int i = 0; i < n; i++)
			if (arr[i] != 0)
				cout << arr[i] << ' ';

		cout << endl;
	}

};

int main()
{
	int m;
	int x, y;
	string s;

	Array array;

	cin >> m;

	while (m--)
	{
		cin >> s;

		if (s == "at")
		{
			cin >> x;

			cout << array.at(x) <<"\n";
		}
		else if (s == "set")
		{
			cin >> x >> y;

			array.set(x, y);
		}
		else if (s == "add")
		{
			cin >> x >> y;

			array.add(x, y);
		}
		else if (s == "remove")
		{
			cin >> x;

			cout << array.remove(x) << endl;
		}
		else if (s == "printArray")
		{
			array.printArray();
		}
	}


	return 0;
}