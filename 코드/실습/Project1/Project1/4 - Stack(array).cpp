#include <iostream>
using namespace std;

class arrayStack
{
public:
	int* s;						//배열
	int capacity;				//배열의 크기
	int t;						//top의 인덱스

	arrayStack(int capacity)
	{
		this->capacity = capacity;
		this->s = new int[capacity];
		this->t = -1;
	}

	int size()					//스택의 원소의 개수
	{
		return (t + 1);
	}

	bool empty()				//스택이 비어 있으면 0, 원소가 있으면 1
	{
		return (t == -1);
	}

	int top()					//스택의 맨 위 원소 확인
	{
		if (!empty())			//스택에 원소가 있는 경우				
		{
			return s[t];
		}
		else					//스택에 원소가 없는 경우
		{
			return -1;
		}
	}

	void push(int e)			//스택에 element를 삽입
	{
		if (t == capacity - 1)	//예외사항 -> 스택이 꽉 찬 경우
		{

		}
		else
		{
			t++;

			s[t] = e;
		}
	}

	int pop()					//스택 element를 삭제 & 반환
	{
		if(empty())				//예외사항 -> 스택이 비어있는 경우
		{
			return -1;
		}
		
		t--;

		return s[t + 1];
	}
};

int main()
{





	return 0;
}