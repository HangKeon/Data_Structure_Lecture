#include <iostream>
#include <string>
using namespace std;

int queue[51];						//0은 원소가 없다고 가정
int f = 0;							//큐의 가장 앞의 인덱스(가장 오래된 것)
int r = -1;							//큐의 가장 뒤의 인덱스(최신)
int capacity = 50;					//배열의 크기
int m;								//큐가 담을 수 있는 원소의 갯수

void enqueue(int x)
{
	r++;

	if (r == m)						//r이 m에 도달한 경우
	{
		cout << "Full" << endl;
		r--;						//이걸 안 해주면 r이 계속 증가
	}
	else
	{
		queue[r] = x;
	}
}

int size()
{
	return (r - f + 1);
}

bool empty()
{
	return (r == -1);
}

int main()
{
	 
	int n;							//명령어의 갯수
	int x;							//1 ∼ 9의 자연수
	string s;						//명령어

	cin >> m >> n;

	while (n--)
	{
		cin >> s;

		if (s == "enqueue")			//정수 X를 큐의 뒤에 삽입. 큐가 가득차서 넣을 수 없는 경우 'Full'을 출력
		{
			cin >> x;
			
			enqueue(x);
			
		}
		else if (s == "size")		//큐에 저장되어있는 정수의 개수를 출력
		{
			cout << size() << endl;
		}
		else if (s == "isEmpty")	//큐가 비어 있으면 1, 비어 있지 않으면 0을 출력
		{
			cout << empty() << endl;
		}
	}



	return 0;
}