#include <iostream>
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