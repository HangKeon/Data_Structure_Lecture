#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> v[100001];				//��Ʈ ��� 1�� ����
int depth = 1;						//search�� ���� ����
int sw = 0;

int search(int x, int y)			//��� x�� ���� ���� Ž�� ->search(Ž���� ���, �θ� ���)
{
	sw = 0;

	if (x == 1)						//��� 1�� ������ ����!
		return 1;

	for(int i=0;i<v[y].size();i++)
	{
		if (v[y][i] == x)			//��� x�� �����Ѵٸ� 1�� ��ȯ
		{
			sw = 1;
			break;
		}
		else if (v[y][i] != x)		//v[k]�� x�� �������� �ʴ´ٸ� ��� ���� Ž��!
		{
			depth++;				//depth 1����
			search(x, v[y][i]);

			if (sw == 1)
				break;

			depth--;				//�� ã���� �������� ���ư��� �ϹǷ� 1 ����
		}
	}

	if (sw == 1)
		return 1;
	
	return 0;						//��� x�� �������� �ʴ´ٸ� 0�� ��ȯ
}

int main()
{
	int n;							//��ɾ��� ����
	int x, y;						//�Է°�
	string s;						//��ɾ�


	cin >> n;

	while (n--)
	{
		depth = 1;						//���� ������ �� depth�� �ʱ�ȭ		

		cin >> s;

		if (s == "insert")				//�θ� ��� X�� �ڽ����� Y ��带 ����. 
		{
			cin >> x >> y;

			if (search(x, 1) == 0)		//�θ� ��� X�� ���� ��� -1�� ���
				cout << -1 << endl;
			else
				v[x].push_back(y);
		}
		else if (s == "printChild")		//��� X�� �ڽ��� ���(�Էµ� ����) 
		{
			cin >> x;

			if (search(x, 1) == 0)		//��� X�� ���� ��� -1�� ���
				cout << -1 << endl;
			else if (v[x].size() == 0)	//��� x�� �ڽ��� ���� ��� 0�� ���
				cout << 0 << endl;
			else						//��� x�� �����ϰ� �ڽ��� �ִ� ���
			{
				for (auto i : v[x])
					cout << i << ' ';

				cout << endl;
			}
		}
		else if (s == "printDepth")		//�ش� ��� X�� depth�� ����Ѵ�.
		{
			cin >> x;

			if (search(x, 1) == 0)			//��� X�� ���� ��� - 1�� ���
				cout << -1 << endl;
			else if (x == 1)				//��尡 1�� ���� depth�� 0�̴�.
				cout << 0 << endl;
			else
				cout << depth << endl;
		}
	}

	return 0;
}