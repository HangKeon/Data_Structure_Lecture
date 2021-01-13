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

int hashfunc2(int key)				//2차 해시 함수
{
	return (17 - (key % 17));
}

void DoubleInsert(int key)			//Double Hashing 삽입
{
	int probing = 1;				//탐색 횟수(충돌이 없는 경우를 probing 1회)

	while (hashtable[hashfunc(key + (probing - 1)*hashfunc2(key))].flag) //해시 테이블이 있는 경우
	{
		probing++;					//탐색 횟수를 1 증가
	}

	hashtable[hashfunc(key + (probing - 1)*hashfunc2(key))].flag = ISITEM;
	hashtable[hashfunc(key + (probing - 1)*hashfunc2(key))].key = key;

	sz++;							//전체 해시 개수 증가
}

void DoubleSearch(int key)			//Double Hashing 탐색
{
	int probing = 1;				//탐색 횟수(충돌이 없는 경우를 probing 1회)

	while (hashtable[hashfunc(key + (probing - 1)*hashfunc2(key))].flag) //해시 테이블이 있는 경우
	{
		if (hashtable[hashfunc(key + (probing - 1)*hashfunc2(key))].key == key)	//주어진 입력이 해시 테이블에 존재하면
		{
			cout << 1 << ' ' << probing << endl;	 //1과 probing 횟수를 출력
			return;
		}

		probing++;					//탐색 횟수를 1 증가	
	}

	cout << 0 << ' ' << probing << endl;			//존재하지 않으면 0과 probing 횟수
}

int main()
{
	int t;							//테스트 케이스 수
	int n;							//해시 테이블을 구성할 수 있는 자연수의 수
	int m;							//해시 테이블에서 탐색할 자연수의 수
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

			DoubleInsert(x);
		}

		cin >> m;

		for (int i = 0; i < m; i++)
		{
			cin >> x;

			DoubleSearch(x);
		}
	}

	return 0;
}