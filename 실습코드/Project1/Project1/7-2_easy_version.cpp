#include <iostream>
#include <vector>
using namespace std;

vector<int> v[100001];				//��Ʈ ��� 1�� ����
int visited[100001];				//�湮ó��
int visited2[100001];				//�湮ó��

void  preorder(int x)		//���� ��ȸ(��� ��ȣ)
{
	if (visited[x])					//�̹� �湮�� ��� Ż��! 
		return;

	visited[x] = 1;					//�湮ó��

	cout << x << ' ';

	for (int i = 0; i < v[x].size(); i++)
	{
		int y = v[x][i];

		preorder(y);
	}
}

void postorder(int x)		//���� ��ȸ(��� ��ȣ)
{
	if (visited2[x])				//�̹� �湮�� ��� Ż��! 
	{
		return;
	}

	visited2[x] = 1;				//�湮ó��

	for (int i = 0; i < v[x].size(); i++)
	{
		int y = v[x][i];

		postorder(y);

		cout << y << ' ';
	}
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

		cin >> m;

		for (int i = 0; i < m; i++)
		{
			cin >> x >> y;

			v[x].push_back(y);
		}

		preorder(1);
		cout << endl;

		postorder(1);
		cout << 1 << endl;			//postorder�� ��� ��� 1�� ����� �ȵǱ� ������ ���� ���!
	}


	return 0;
}