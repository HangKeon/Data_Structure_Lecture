#include <iostream>
#include <cmath>
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
		int average[3] = { 0, };	//각 나라별 금고의 평균
		int cnt[3] = { 0, };		//각 나라별 사람 수

		cin >> n;

		for (int j = 0; j < n; j++)
		{
			cin >> arr[j];

			sum[j % 3] += arr[j];

			if(arr[j])				//금고에 돈이 있는 경우만 사람 수를 셈
				cnt[j % 3]++;
		}

		for (int j = 0; j < 3; j++)
			if(cnt[j]!=0)						//사람 수가 0인 경우는 제외
				average[j] = sum[j] / cnt[j];

		for (int j = 0; j < 3; j++)
			cout << sum[j] << ' ';

		cout << endl;
		for (int j = 0; j < 3; j++)
			cout << average[j] << ' ';

		cout << endl;
	}



	return 0;
}