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
		if (arr[idx] == 0)
			return 0;

		return arr[idx];
	}

	void set(int idx, int x)
	{
		if (arr[idx] == 0)
		{
			cout << 0 << endl;
			return;
		}
		
		arr[idx] = x;
	}

	void add(int idx, int x)
	{
		int sw = 0;						//arr[idx] = 0일 때 모든 배열에 원소가 없다면 sw=0, 있다면 sw=1 

		if (arr[idx] == 0)				//원소가 없는 인덱스 i값인 경우
		{
			for (int i = n - 1; i >= 0; i--) //뒤에서부터 살펴보기 -> 마지막 원소가 있는 바로 다음 인덱스에 양의 정수 X를 삽입
			{
				if (arr[i] != 0)
				{
					arr[i + 1] = x;
					sw = 1;
					break;
				}
			}

			if (sw == 0)
				arr[0] = x;						//원소가 없다면 맨 앞에 0을 대입

			return;
		}

		for (int i = n - 1; i >= idx; i--)
			arr[i + 1] = arr[i];

		arr[idx] = x;
	}
};

int main()
{
	int m;							//명령어의 수 
	string s;						//명령어를 저장
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
	}


	return 0;
}