#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> v[100001];

int main()
{
	int n;							//��ɾ��� ����
	int x, y;						//�Է°�
	string s;						//��ɾ�
	

	cin >> n;

	while (n--)
	{
		cin >> s;

		if (s == "insert")
		{
			cin >> x >> y;

			v[x].push_back(y);
		}
		else if (s == "printChild")
		{
			cin >> x;

			for (auto i : v[x])
				cout << i << ' ';

			cout << endl;
		}
	}

	return 0;
}