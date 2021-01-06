#include <iostream>
#include <vector>
using namespace std;

vector<int> v[100001];				//��Ʈ ��� 1�� ����
int visited[100001];				//�湮ó��
int visited2[100001];				//�湮ó��
int depth = 0;

void  preorder(int x, int d)		//���� ��ȸ(��� ��ȣ, Ʈ���� ����)
{
	if (visited[x])					//�̹� �湮�� ��� Ż��! 
		return;

	if (depth < d)					//Ʈ���� ���̸� ����(�ִ�)
		depth = d;

	visited[x] = 1;					//�湮ó��

	cout << x << ' ';

	for (int i = 0; i < v[x].size(); i++)
	{
		int y = v[x][i];

		preorder(y, d + 1);
	}
}

void postorder(int x, int d)		//���� ��ȸ(��� ��ȣ, Ʈ���� ����)
{
	if (visited2[x])				//�̹� �湮�� ��� Ż��! 
	{
		return;
	}

	if (depth < d)					//Ʈ���� ���̸� ����(�ִ�)
		depth = d;

	visited2[x] = 1;				//�湮ó��

	for (int i = 0; i < v[x].size(); i++)
	{
		int y = v[x][i];

		postorder(y, d + 1);

		cout << y << ' ';
	}

	if (x == 1)						//���� �ݺ������� x==1�� ���� ����� �ȵǹǷ� ���� ���!
		cout << x << endl;
}

int main()
{
	int n;							//Ʈ���� ����
	int m;							//�������� ��
	int x, y;						//x : �θ� ���, y : �ڽ� ���

	cin >> n;

	while (n--)
	{
		for (int i = 0; i < 100001; i++)	//�ʱ�ȭ
		{
			visited[i] = 0;
			visited2[i] = 0;
			v[i].clear();
		}

		depth = 0;							//�ʱ�ȭ

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