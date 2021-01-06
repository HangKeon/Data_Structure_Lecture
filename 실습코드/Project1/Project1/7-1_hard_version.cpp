#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> v[100001];				//루트 노드 1이 존재
int depth = 1;						//search할 때의 깊이
int sw = 0;

int search(int x, int y)			//노드 x의 존재 여부 탐색 ->search(탐색할 노드, 부모 노드)
{
	sw = 0;

	if (x == 1)						//노드 1은 무조건 존재!
		return 1;

	for(int i=0;i<v[y].size();i++)
	{
		if (v[y][i] == x)			//노드 x가 존재한다면 1을 반환
		{
			sw = 1;
			break;
		}
		else if (v[y][i] != x)		//v[k]에 x가 존재하지 않는다면 계속 들어가서 탐색!
		{
			depth++;				//depth 1증가
			search(x, v[y][i]);

			if (sw == 1)
				break;

			depth--;				//못 찾으면 이전으로 돌아가야 하므로 1 감소
		}
	}

	if (sw == 1)
		return 1;
	
	return 0;						//노드 x가 존재하지 않는다면 0을 반환
}

int main()
{
	int n;							//명령어의 갯수
	int x, y;						//입력값
	string s;						//명령어


	cin >> n;

	while (n--)
	{
		depth = 1;						//새로 시작할 때 depth를 초기화		

		cin >> s;

		if (s == "insert")				//부모 노드 X의 자식으로 Y 노드를 삽입. 
		{
			cin >> x >> y;

			if (search(x, 1) == 0)		//부모 노드 X가 없을 경우 -1을 출력
				cout << -1 << endl;
			else
				v[x].push_back(y);
		}
		else if (s == "printChild")		//노드 X의 자식을 출력(입력된 순서) 
		{
			cin >> x;

			if (search(x, 1) == 0)		//노드 X가 없을 경우 -1을 출력
				cout << -1 << endl;
			else if (v[x].size() == 0)	//노드 x의 자식이 없는 경우 0을 출력
				cout << 0 << endl;
			else						//노드 x가 존재하고 자식이 있는 경우
			{
				for (auto i : v[x])
					cout << i << ' ';

				cout << endl;
			}
		}
		else if (s == "printDepth")		//해당 노드 X의 depth를 출력한다.
		{
			cin >> x;

			if (search(x, 1) == 0)			//노드 X가 없을 경우 - 1을 출력
				cout << -1 << endl;
			else if (x == 1)				//노드가 1일 때는 depth는 0이다.
				cout << 0 << endl;
			else
				cout << depth << endl;
		}
	}

	return 0;
}