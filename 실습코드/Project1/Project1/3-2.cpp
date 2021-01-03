#include <iostream>
#include <string>
using namespace std;

class Node
{
public:
	int data;					//노드의 원소
	Node* next;					//다음 주소

	Node(int e)					//생성자
	{
		this->data = e;
		this->next = NULL;
	}
};

class CLinkedList				//환형 링크드 리스트
{
public:
	Node* head;
	Node* tail;
	Node* cursor;

	CLinkedList()				//생성자
	{
		cursor = NULL;
	}

	void addBack(int x)			//뒤에서부터 x값을 추가
	{
		Node* v = new Node(x);

		if (empty())
		{
			v->next = v;
			head = v;
			tail = head;
			cursor = head;
		}
		else
		{
			v->next = head;			//왜냐하면 환형 링크드 리스트이므로
			cursor->next = v;
			cursor = v;
			tail = v;
		}
	}

	void Delete(int x)				//head로부터 x번 째에 있는 원소를 삭제
	{
		Node* old = new Node(0);	//x번 째 노드를 가리킴
		cursor = head;				//cursor를 head부터 시작
		int cnt = 0;				//x와 같은 값이 되기 전까지 세줌

		while (cnt < x - 1)			//x번 째 직전까지 이동
		{
			cursor = cursor->next;
			cnt++;
		}

		if (x == 0)
			old = cursor;
		else
			old = cursor->next;

		cursor->next = old->next;

		if (old == head)			// head가 삭제되는 경우, head의 다음 노드였던 노드가 head가 된다
			head = cursor->next;

		if (old == tail)			//Tail이 삭제되는 경우, tail의 이전 노드였던 노드가 tail이 된다.
			tail = cursor;
		
		delete old;
	}

	int empty()						//비어있는지 여부 확인, 0 : 비어 있지 않음, 1 : 비어 있음
	{
		return head == NULL;
	}

	void showList()
	{
		Node* current = head;

		cout << current->data << ' ';
		current = current->next;

		while (current != tail->next)
		{
			cout << current->data << ' ';
			current = current->next;
		}

		cout << endl;
	}
};

int main()
{
	int n;						//묶음 개수
	string s;					//명령어
	int x;						//명령어에 필요한 원소

	

	cin >> n;

	while (n--)
	{
		CLinkedList* cll = new CLinkedList;

		int cnt = 0;			//Delete의 갯수를 세줌
		int all = 10;			//전체 갯수를 세줌

		for (int i = 0; i < 10; i++)
		{
			cin >> x;

			cll->addBack(x);
		}

		while (cnt < 3)
		{
			cin >> s;

			if (s == "Delete")
			{
				cin >> x;
				cll->Delete(x % all);	//x가 all보다 커질 때 문제가 생겨서 이렇게 조치함!

				cnt++;
				all--;
			}
		}

		cll->showList();
	}


	return 0;
}