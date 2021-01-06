#include <iostream>
#include <vector>
using namespace std;

vector<int> v[100001];				//루트 노드 1이 존재
int visited[100001];				//방문처리
int visited2[100001];				//방문처리

void  preorder(int x)		//전위 순회(노드 번호)
{
	if (visited[x])					//이미 방문한 경우 탈출! 
		return;

	visited[x] = 1;					//방문처리

	cout << x << ' ';

	for (int i = 0; i < v[x].size(); i++)
	{
		int y = v[x][i];

		preorder(y);
	}
}

void postorder(int x)		//후위 순회(노드 번호)
{
	if (visited2[x])				//이미 방문한 경우 탈출! 
	{
		return;
	}

	visited2[x] = 1;				//방문처리

	for (int i = 0; i < v[x].size(); i++)
	{
		int y = v[x][i];

		postorder(y);

		cout << y << ' ';
	}
}

int main()
{
	int n;							//트리의 개수
	int m;							//데이터의 수
	int x, y;						//x : 부모 노드, y : 자식 노드

	cin >> n;

	while (n--)
	{
		for (int i = 0; i < 100001; i++)	//초기화
		{
			visited[i] = 0;
			visited2[i] = 0;
			v[i].clear();
		}

		cin >> m;

		for (int i = 0; i < m; i++)
		{
			cin >> x >> y;

			v[x].push_back(y);
		}

		preorder(1);
		cout << endl;

		postorder(1);
		cout << 1 << endl;			//postorder의 경우 노드 1이 출력이 안되기 때문에 따로 출력!
	}


	return 0;
}