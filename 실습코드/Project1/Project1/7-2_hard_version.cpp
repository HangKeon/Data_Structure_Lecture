#include <iostream>
#include <vector>
using namespace std;

vector<int> v[100001];				//루트 노드 1이 존재
int visited[100001];				//방문처리
int visited2[100001];				//방문처리
int depth = 0;

void  preorder(int x, int d)		//전위 순회(노드 번호, 트리의 높이)
{
	if (visited[x])					//이미 방문한 경우 탈출! 
		return;

	if (depth < d)					//트리의 높이를 저장(최댓값)
		depth = d;

	visited[x] = 1;					//방문처리

	cout << x << ' ';

	for (int i = 0; i < v[x].size(); i++)
	{
		int y = v[x][i];

		preorder(y, d + 1);
	}
}

void postorder(int x, int d)		//후위 순회(노드 번호, 트리의 높이)
{
	if (visited2[x])				//이미 방문한 경우 탈출! 
	{
		return;
	}

	if (depth < d)					//트리의 높이를 저장(최댓값)
		depth = d;

	visited2[x] = 1;				//방문처리

	for (int i = 0; i < v[x].size(); i++)
	{
		int y = v[x][i];

		postorder(y, d + 1);

		cout << y << ' ';
	}

	if (x == 1)						//위의 반복문에서 x==1인 경우는 출력이 안되므로 따로 출력!
		cout << x << endl;
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

		depth = 0;							//초기화

		cin >> m;

		for (int i = 0; i < m; i++)
		{
			cin >> x >> y;

			v[x].push_back(y);
		}

		preorder(1, 0);
		cout << endl;

		postorder(1, 0);

		cout << depth << endl;
	}

	return 0;
}