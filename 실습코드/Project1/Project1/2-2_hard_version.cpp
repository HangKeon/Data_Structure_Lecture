#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int m;						//��ɾ� ���� ��
	int n;						//�ݰ� ũ��

	cin >> m;

	for (int i = 0; i < m; i++)
	{
		int arr[10001] = { 0, };	//�ݰ� ����ִ� ���� �׼� 
		int sum[3] = { 0, };		//�� ���� �ݰ��� ��
		int average[3] = { 0, };	//�� ���� �ݰ��� ���
		int cnt[3] = { 0, };		//�� ���� ��� ��

		cin >> n;

		for (int j = 0; j < n; j++)
		{
			cin >> arr[j];

			sum[j % 3] += arr[j];

			if(arr[j])				//�ݰ� ���� �ִ� ��츸 ��� ���� ��
				cnt[j % 3]++;
		}

		for (int j = 0; j < 3; j++)
			if(cnt[j]!=0)						//��� ���� 0�� ���� ����
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