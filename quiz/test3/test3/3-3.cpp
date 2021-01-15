#include <iostream>
#include <vector>
using namespace std;

vector<int> v[2001];
int visited[2001][2001];

int main()
{
	int n, m, k;
	int x, y;
	int edge = 0;
	int arr[2001];
	int sw1 = 0, sw2 = 0;
	int sw3 = 0;

	cin >> n >> m >> k;

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}


	for (int i = 0; i < m; i++)
	{
		cin >> x >> y;

		for (int i = 0; i < n; i++)
		{
			if (x == arr[i])
				sw1 = 1;

			if (y == arr[i])
				sw2 = 1;
		}

		if (sw1 == 0 || sw2 == 0)
		{
			cout << -1 << endl;
			
		}
		else
		{
			if (visited[x][y] || visited[y][x])
			{
				cout << -1 << endl;
			}
			else
			{
				v[x].push_back(y);
				v[y].push_back(x);
				visited[x][y] = 1;
				visited[y][x] = 1;
				edge++;
			}
		}

		sw1 = 0;
		sw2 = 0;
	}

	cout << n << ' ' << edge << endl;

	for (int i = 0; i < k; i++)
	{
		cin >> x >> y;

		for (int i = 0; i < n; i++)
		{
			if (x == arr[i])
				sw1 = 1;

			if (y == arr[i])
				sw2 = 1;
		}

		if (sw1 == 0 || sw2 == 0)
		{
			cout << -1 << endl;
			
		}
		else
		{
			for (auto i : v[x])
			{
				if (i == y)
				{
					cout << 1 << endl;
					sw3 = 1;
					break;
				}
			}

			if (sw3 == 0)
				cout << 0 << endl;

			
		}

		sw1 = 0;
		sw2 = 0;
		sw3 = 0;
	}


	return 0;
}