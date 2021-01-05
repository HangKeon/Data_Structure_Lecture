#include <iostream>
#include <string>
using namespace std;

class node
{
public:
	int data;
	node* next;

	node(int x)						//생성자
	{
		data = x;
		next = NULL;
	}
};

class SLinkedList
{
public:
	node* f;
	node* r;

	SLinkedList()				//생성자를 이용하여 f,r을 초기화
	{
		f = NULL;
		r = NULL;
	}

	int front()					//맨 앞에 있는 노드의 data 값을 반환
	{

	}

	int end()					//맨 뒤에 있는 노드의 data 값을 반환
	{

	}

	int addEnd(int x)			//맨 뒤에 x값을 갖는 노드를 추가
	{
		node* v = new node(x);	//새로운 노드를 추가

		if (f == NULL)			//만약 리스트에 노드 추가가 처음이라면
		{

		}
		else					//처음이 아닌 경우
		{

		}
	}

	void removeFront()			//맨 앞의 노드 제거
	{

	}
};

int main()
{




	return 0;
}