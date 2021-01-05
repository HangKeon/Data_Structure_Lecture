#include <iostream>
#include <string>
using namespace std;

class arrQueue					//원형큐로 구현(공간을 효과적으로 사용할 수 있음)
{
public:
	int* Q;							//동적으로 만들 큐
	int capacity;					//큐의 용량
	int f;							//front의 위치
	int r;							//rear의 위치

	arrQueue(int size)				//생성자
	{
		this->Q = new int[size];	//r=f-1인 경우를 empty로 정의하기 위해 1칸은 비워둠
		this->capacity = size;
		this->f = 0;				//f가 가리키는 곳부터 큐의 원소 존재
		this->r = -1;				//r이 가리키는 곳까지 큐의 원소 존재

		for (int i = 0; i < size; i++)	//0을 배열의 원소가 없는 것으로 판단! -> 초기화
			Q[i] = 0;
	}

	int size()						//큐 안의 원소의 갯수
	{
		return (r + capacity - f + 1) % capacity;
	}

	bool isEmpty()					//큐가 비어있는지 확인
	{
		return (Q[f] == 0);
	}

	int front()						//가장 오래전에 입력된 큐의 원소 출력
	{
		if (isEmpty())				//배열에 원소가 없는 경우
			return 0;

		return Q[f];
	}

	int rear()						//가장 최근에 입력된 큐의 원소 출력
	{
		if (isEmpty())				//배열에 원소가 없는 경우
			return 0;

		return Q[r];
	}

	void enqueue(int data)			//큐에 원소 입력
	{
		r++;						//r을 1증가

		if (r == capacity)			//r이 배열의 끝에 도달한 경우
			r %= capacity;			//처음으로 되돌림

		Q[r] = data;
	}
		
	void dequeue()					//오래된 원소 제거
	{
		if (isEmpty())				//원소가 없는 경우
			cout << "Empty" << endl;
		else
		{
			int value = Q[f];		//이전 값 저장

			Q[f] = 0;				//원소 제거
			f++;

			if (f == capacity)		//f가 배열의 끝에 도달한 경우
				f %= capacity;		//처음으로 되돌림

			cout << value << endl;
		}
	}

		
};

int main()
{
	int qsize;

	cin >> qsize;

	arrQueue q(qsize);

	int cmdNum;

	cin >> cmdNum;

	while (cmdNum--)
	{
		string cmd;

		cin >> cmd;

		if (cmd == "enqueue")
		{
			int input;

			cin >> input;

			q.enqueue(input);

		}
		else if (cmd == "dequeue")
		{
			q.dequeue();

		}
		else if (cmd == "size")
		{
			cout << q.size() << endl;
		}
		else if (cmd == "empty")
		{
			cout << q.isEmpty() << endl;
		}
		else if (cmd == "isEmpty")
		{
			cout << q.isEmpty() << endl;
		}
		else if (cmd == "front")
		{
			if (q.front() == 0)
				cout << "Empty" << endl;
			else
				cout << q.front() << endl;
		}
		else if (cmd == "rear")
		{
			if (q.rear() == 0)
				cout << "Empty" << endl;
			else
				cout << q.rear() << endl;
		}
	}

	return 0;
}