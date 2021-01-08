#include <iostream>
#include <vector>
#include <string>
using namespace std;

enum direction { MIN = 1, MAX = -1 };	//max-heap과 min-heap을 결정

class heap
{
private:
	vector<int> v;
	int heap_size;
	int root_idx;
	int direction;					//min,max에 따라 heap의 종류가 결정됨
public:
	heap(int direction)
	{
		v.push_back(-1);
		this->heap_size = 0;
		this->root_idx = 1;
		this->direction = direction;
	}

	void swap(int idx1, int idx2)
	{
		int temp = v[idx1];
		v[idx1] = v[idx2];
		v[idx2] = temp;
	}

	void upHeap(int idx)			//idx는 자식의 노드 번호
	{
		if (direction*v[idx / 2] > direction*v[idx])	//부모의 노드 번호 > 자식의 노드 번호
		{
			swap(idx / 2, idx);
			upHeap(idx / 2);
		}
	}

	void downHeap(int idx)			//idx는 부모의 노드 번호
	{
		int right = 2 * idx + 1;	//오른쪽 자식의 노드 번호
		int left = 2 * idx;			//왼쪽 자식의 노드 번호
		int small = right;

		if (right <= heap_size)
		{
			if (direction*v[left] <= direction * v[right])
			{
				small = left;
			}
		}
		else if(left<=heap_size)
		{
			small = left;
		}
		else
		{
			return;
		}

		if (direction*v[idx] > direction*v[small])
		{
			swap(idx, small);
			downHeap(small);
		}
	}

	void insert(int e)				//자연수 e를 우선순위 큐에 삽입.
	{
		v.push_back(e);
		heap_size++;

		upHeap(heap_size);
	}

	int pop()						//우선순위가 가장 높은 원소를 출력 후 원소 제거
	{
		if (isEmpty())				//힙이 비어 있는 경우, -1을 출력
			return -1;

		int temp = v[heap_size];
		int ret = v[root_idx];

		v.erase(v.begin() + heap_size);

		v[root_idx] = temp;
		heap_size--;

		downHeap(root_idx);

		return ret;
	}

	int top()						//우선순위가 가장 높은 원소를 출력
	{
		if (isEmpty())				//힙이 비어 있는 경우, -1을 출력
			return -1;
		else
			return v[root_idx];
	}

	bool isEmpty()					//힙이 비어 있으면 1, 비어 있지 않으면 0을 출력
	{
		return (heap_size == 0);
	}

	int size()						//힙에 저장되어있는 자연수의 개수를 출력
	{
		return heap_size;
	}

	void print()					//힙의 원소를 차례로 모두 출력
	{
		if (isEmpty())				//비어있는 경우 -1을 출력
			cout << -1 << endl;
		else
		{
			for (int i = 1; i <= heap_size; i++)
				cout << v[i] << ' ';

			cout << endl;
		}
	}


};

int main()
{
	int n;							//명령어 갯수
	int e;							//삽입할 노드
	string s;

	heap h(MIN);

	cin >> n;

	while (n--)
	{
		cin >> s;

		if (s == "insert")
		{
			cin >> e;

			h.insert(e);
		}
		else if (s == "size")
		{
			cout << h.size() << endl;
		}
		else if (s == "isEmpty")
		{
			cout << h.isEmpty() << endl;
		}
		else if (s == "pop")
		{
			cout << h.pop() << endl;
		}
		else if (s == "top")
		{
			cout << h.top() << endl;
		}
		else if (s == "print")
		{
			h.print();
		}
	}

	return 0;
}