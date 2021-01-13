#include <iostream>
using namespace std;

#define MAX 353333					//해시 테이블의 크기 -> 큰 소수
#define NOITEM 0					//저장한 값이 없는 경우
#define ISITEM 1					//저장한 값이 있는 경우
#define AVAILABLE 2					//삭제시 넣어줄 값

class cell							//해시 테이블의 각 셀에 저장한 데이터 타입
{
public:
	int key;						//key값 -> 인덱스
	int value;						//저장할 값
	int flag;						//NOITEM, ISITEM, AVAILABLE 중 하나를 저장

	cell()							//생성자
	{
		key = -1;
		value = -1;
		flag = NOITEM;
	}

	~cell() {}						//소멸자
};

cell hashtable[MAX];
int sz = 0;							//해시의 실제 저장되어 있는 원소의 크기

int hashfunc(int key)				//1차 해시 함수
{
	return key % MAX;
}

void LinearInsert(int key)			//Linear Probing 삽입
{
	int probing = 1;				//탐색 횟수(충돌이 없는 경우를 probing 1회)

	while (hashtable[hashfunc(key + probing - 1)].flag)		//해시 테이블이 있는 경우
	{
		probing++;					//탐색 횟수를 1 증가	
	}

	hashtable[hashfunc(key + probing - 1)].key = key;
	hashtable[hashfunc(key + probing - 1)].flag = ISITEM;

	sz++;							//전체 해시의 개수 증가
}

void LinearDelete(int key)			//Linear Probing 삭제
{
	int probing = 1;				//탐색 횟수(충돌이 없는 경우를 probing 1회)

	while (hashtable[hashfunc(key + probing - 1)].flag)		//해시 테이블이 있는 경우
	{
		if (hashtable[hashfunc(key + probing - 1)].key == key)	//주어진 입력이 해시 테이블에 존재하면
		{
			hashtable[hashfunc(key + probing - 1)].flag = AVAILABLE;
			hashtable[hashfunc(key + probing - 1)].key = -1;

			cout << 1 << ' ' << probing << endl;			//삭제 후, 1과 probing 횟수를 출력
			sz--;
			return;
		}

		probing++;					//탐색 횟수를 1 증가	
	}

	sz--;							//전체 해시 개수 감소

	cout << 0 << ' ' << probing << endl;					//존재하지 않으면 0과 probing 횟수를 출력
}

int main()
{
	int t;							//테스트 케이스 수
	int n;							//해시 테이블을 구성할 수 있는 자연수의 수
	int m;							//해시 테이블에서 삭제할 자연수의 수
	int x;							//입력할 노드

	cin >> t;

	while (t--)
	{
		for (int i = 0; i < MAX; i++)		//초기화
		{
			hashtable[i].key = -1;
			hashtable[i].flag = NOITEM;
			sz = 0;
		}

		cin >> n;

		for (int i = 0; i < n; i++)
		{
			cin >> x;

			LinearInsert(x);
		}

		cin >> m;

		for (int i = 0; i < m; i++)
		{
			cin >> x;

			LinearDelete(x);
		}
	}


	return 0;
}