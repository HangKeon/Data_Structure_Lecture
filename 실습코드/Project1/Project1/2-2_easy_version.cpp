#include <iostream>
using namespace std;

int main()
{
	int m;						//명령어 조합 수
	int n;						//금고 크기
	
	cin >> m;

	for (int i = 0; i < m; i++)
	{
		int arr[10001] = { 0, };	//금고에 들어있는 돈의 액수 
		int sum[3] = { 0, };		//각 나라별 금고의 합

		cin >> n;

		for (int j = 0; j < n; j++)
		{
			cin >> arr[j];

			sum[j % 3] += arr[j];
		}

		for (int j = 0; j < 3; j++)
			cout << sum[j] << ' ';

		cout << endl;
	}



	return 0;
}