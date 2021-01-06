#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> v[100001];

int main()
{
	int n;							//명령어의 갯수
	int x, y;						//입력값
	string s;						//명령어
	

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