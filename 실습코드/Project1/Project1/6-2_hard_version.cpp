#include <iostream>
using namespace std;

int main()
{
	int t;						//�׽�Ʈ ���̽� ��
	int n;						//ī���� ����
	int q1[21];
	int q2[21];

	cin >> t;

	while (t--)
	{
		int score1 = 0, score2 = 0;

		cin >> n;

		for (int i = 0; i < n; i++)
		{
			cin >> q1[i];
		}

		for (int i = 0; i < n; i++)
		{
			cin >> q2[i];
		}

		for (int i = 0; i < n; i++)		// ��� �Ŀ� (���� ĳ������ ü�� - 1)�� ������ ����� ĳ���Ϳ� �߰��ȴ�
		{
			if (q1[i] > q2[i])
			{
				score1++;

				q1[i + 1] += q1[i] - q2[i] - 1;
			}
			else if (q1[i] < q2[i])
			{
				score2++;

				q2[i + 1] += q2[i] - q1[i] - 1;
			}
		}

		if (score1 == score2)
			cout << 0 << endl;
		else if (score1 > score2)
			cout << 1 << endl;
		else if (score1 < score2)
			cout << 2 << endl;
	}


	return 0;
}