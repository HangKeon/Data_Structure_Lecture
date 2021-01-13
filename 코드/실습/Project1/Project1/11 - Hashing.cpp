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

	~cell(){}						//소멸자
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

void LinearInsert(int key)			//Linear Probing 삽입
{
	int probing = 1;				//탐색 횟수

	while (hashtable[hashfunc(key + probing - 1)].flag)		//해시 테이블이 있는 경우
	{
		probing++;					//탐색 횟수를 1 증가	
	}

	hashtable[hashfunc(key + probing - 1)].key = key;
	hashtable[hashfunc(key + probing - 1)].flag = ISITEM;

	sz++;							//전체 해시의 개수 증가
}

void LinearSearch(int key)			//Linear Probing 탐색
{
	int probing = 1;				//탐색 횟수

	while (hashtable[hashfunc(key + probing - 1)].flag)		//해시 테이블이 있는 경우
	{
		if (hashtable[hashfunc(key + probing - 1)].key == key)	//해당 key 값이 찾는 key 값과 동일하다면
		{
			cout << 1 << ' ' << probing << endl;
			return;
		}

		probing++;					//탐색 횟수를 1 증가	
	}

	cout << 0 << ' ' << probing << endl;
}

void LinearDelete(int key)			//Linear Probing 삭제
{
	int probing = 1;				//탐색 횟수

	while (hashtable[hashfunc(key + probing - 1)].flag)		//해시 테이블이 있는 경우
	{
		if (hashtable[hashfunc(key + probing - 1)].key == key)	//해당 key 값이 찾는 key 값과 동일하다면
		{
			hashtable[hashfunc(key + probing - 1)].flag = AVAILABLE;
			hashtable[hashfunc(key + probing - 1)].key = -1;

			cout << 1 << ' ' << probing << endl;
			sz--;
			return;
		}

		probing++;					//탐색 횟수를 1 증가	
	}

	sz--;							//전체 해시 개수 감소

	cout << 0 << ' ' << probing << endl;
}

void DoubleInsert(int key)			//Double Hashing 삽입
{
	int probing = 1;				//탐색 횟수

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
	int probing = 1;				//탐색 횟수

	while (hashtable[hashfunc(key + (probing - 1)*hashfunc2(key))].flag) //해시 테이블이 있는 경우
	{
		if (hashtable[hashfunc(key + (probing - 1)*hashfunc2(key))].key == key)	//해당 key 값이 찾는 key 값과 동일하다면
		{
			cout << 1 << ' ' << probing << endl;
			return;
		}

		probing++;					//탐색 횟수를 1 증가	
	}

	cout << 0 << ' ' << probing << endl;
}

void tableClear()					//테이블 메모리 해제
{
	for (int i = 0; i < MAX; i++)
	{
		if (hashtable[i].flag)
		{
			hashtable[i].key = -1;
			hashtable[i].flag = NOITEM;
			hashtable[i].key = -1;

			sz--;					//전체 해시 개수 감소
		}

		if (sz == 0)				//해시가 없다면
			break;
	}
}


int main()
{

	return 0;
}