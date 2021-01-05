#include <iostream>
#include <string>
using namespace std;

int queue[100];						//0은 원소가 없다고 가정
int f = 0;							//큐의 가장 앞의 인덱스(가장 오래된 것)
int r = -1;							//큐의 가장 뒤의 인덱스(최신)
int m;								//큐가 담을 수 있는 원소의 갯수

void enqueue(int x)					//정수 X를 큐의 뒤에 삽입. 큐가 가득차서 넣을 수 없는 경우 'Full'을 출력
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

bool empty()						//큐가 비어 있으면 1, 비어 있지 않으면 0을 출력
{
	return queue[f] == 0;
}

void dequeue()	// 큐에서 가장 앞에 있는 정수를 삭제하고, 그 수를 출력. 만약 큐가 비어 있는 경우, 'Empty'를 출력.
{
	if (empty())
	{
		cout << "Empty" << endl;
	}
	else
	{
		cout << queue[f] << endl;

		for (int i = 0; i < m; i++)		//queue[f]는 삭제되므로 모두 왼쪽으로 한 칸 이동!
			queue[i] = queue[i + 1];

		queue[m - 1] = 0;				//가장 끝에 있던 친구는 0으로 초기화!
		
		r--;							//모든 원소가 왼쪽으로 한 칸 옮겨졌으므로 r을 1 감소


		//queue[f++] = 0;				//queue[f] = 0을 한 뒤 f를 1 증가

		//m++;						//f가 1증가했지만 채울 수 있는 배열의 크기는 m을 유지해야 하기 때문!
		//							//즉, f가 증가했는데 m이 고정된다면 큐의 범위는 (f-m)으로 감소!
	}
}

int size()							//큐에 저장되어있는 정수의 개수를 출력
{
	return (r - f + 1);
}



void front()						//큐의 가장 앞에 저장된 정수를 출력.만약 큐가 비어 있는 경우, Empty를 출력.
{
	if (empty())
	{
		cout << "Empty" << endl;
	}
	else
	{
		cout << queue[f] << endl;
	}
}

void rear()							// 큐의 가장 뒤에 저장된 정수를 출력. 만약 큐가 비어 있는 경우, Empty를 출력
{
	if (empty())
	{
		cout << "Empty" << endl;
	}
	else
	{
		cout << queue[r] << endl;
	}
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
		else if (s == "dequeue")
		{
			dequeue();
		}
		else if (s == "size")		//큐에 저장되어있는 정수의 개수를 출력
		{
			cout << size() << endl;
		}
		else if (s == "isEmpty")	//큐가 비어 있으면 1, 비어 있지 않으면 0을 출력
		{
			cout << empty() << endl;
		}
		else if (s == "front")
		{
			front();
		}
		else if (s == "rear")
		{
			rear();
		}
	}



	return 0;
}