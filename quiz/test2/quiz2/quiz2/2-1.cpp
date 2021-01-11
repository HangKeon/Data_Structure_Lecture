#include <iostream>
using namespace std;

int main()
{
	int t;
	int n;
	int v[21], v2[21];

	cin >> t;

	while (t--)
	{
		int a = 0, b = 0;

		cin >> n;

		for (int i = 0; i < n; i++)
			cin >> v[i];

		for (int i = 0; i < n; i++)
			cin >> v2[i];

		for (int i = 0; i < n; i++)
		{
			if (v[i] > v2[i])
			{
				a++;
				v[i + 1] += v[i] - v2[i] - 1;
			}
			else if (v[i] < v2[i])
			{
				b++;
				v2[i + 1] += v2[i] - v[i] - 1;
			}
		}

		if (a == b)
			cout << 0 << endl;
		else if (a > b)
			cout << 1 << endl;
		else
			cout << 2 << endl;


	}


	return 0;
}