#include <iostream>
using namespace std;

int main()
{
	int Min = 2e9;
	int idx;
	int arr[] = { 2,3,4,1,5,6,7 };

	for (int i = 0; i < 7; i++)
	{
		Min = 2e9;

		for (int j = i; j < 7; j++)
		{
			if (Min > arr[j])
			{
				Min = arr[j];
				idx = j;
			}
		}

		int temp = arr[i];
		arr[i] = arr[idx];
		arr[idx] = temp;
	}

	for (int i = 0; i < 7; i++)
		cout << arr[i] << ' ';

	cout << endl;

	return 0;
}