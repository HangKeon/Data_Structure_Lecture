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
		arr = new int[n];

		for (int i = 0; i < n; i++)
			arr[i] = 0;
	}

	int at(int idx)
	{
		if (arr[idx] == 0)				//���Ұ� ���� �ε��� i���� ���
			return 0;

		return arr[idx];
	}

	void set(int idx, int x)
	{
		if (arr[idx] == 0)				//���Ұ� ���� �ε��� i���� ���
		{
			cout << 0 << endl;
			return;
		}

		arr[idx] = x;
	}

	void add(int idx, int x)
	{
		int sw = 0;						//arr[idx] = 0�� �� ��� �迭�� ���Ұ� ���ٸ� sw=0, �ִٸ� sw=1 

		if (arr[idx] == 0)				//���Ұ� ���� �ε��� i���� ���
		{
			for (int i = n - 1; i >= 0; i--) //�ڿ������� ���캸�� -> ������ ���Ұ� �ִ� �ٷ� ���� �ε����� ���� ���� X�� ����
			{
				if (arr[i] != 0)
				{
					arr[i + 1] = x;
					sw = 1;
					break;
				}
			}

			if(sw==0)
				arr[0] = x;						//���Ұ� ���ٸ� �� �տ� 0�� ����

			return;
		}

		for (int i = n - 1; i >= idx; i--)	//���������� ���ҵ��� �̵� 
			arr[i + 1] = arr[i];

		arr[idx] = x;
	}

	int remove(int idx)
	{
		if (arr[idx] == 0)					//���Ұ� ���� �ε��� idx���� ���
			return 0;

		int value = arr[idx];				//�����ϰ� �ش� �� ���

		for (int i = idx; i < n - 1; i++)	//�������� ���ҵ��� �̵�
			if(arr[i] != 0 && arr[i + 1] != 0)
				arr[i] = arr[i+1];

		for (int i = n - 1; i > 0; i--)		
		{
			if (arr[i] != 0)
			{
				arr[i] = 0;						
				break;
			}
		}


		return value;
	}

	void printArray()
	{
		int sw = 0;							//�迭�� ��� �ִ� ��� : 0, ���Ұ� �ִ� ��� : 1

		for (int i = 0; i < n; i++)
		{
			if (arr[i] != 0)				//���Ұ� �ִ� ��� sw=1
			{
				sw = 1;
				break;
			}
		}

		if (sw == 0)
		{
			cout << 0 << endl;
			return;
		}

		for (int i = 0; i < n; i++)
			if (arr[i] != 0)
				cout << arr[i] << ' ';

		cout << endl;
	}
};

int main()
{
	int m;							//��ɾ��� �� 
	string s;						//��ɾ ����
	int x, y;

	cin >> m;

	Array array;

	for (int i = 0; i < m; i++)
	{
		cin >> s;
		if (s == "at")
		{
			cin >> x;

			cout << array.at(x) << endl;
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