#include <iostream>
#include <vector>
#include <string>
using namespace std;

enum direction { MIN = 1, MAX = -1 };	//max-heap과 min-heap을 결정

class minHeap							//min-Heap
{
private:
	vector<int> v;
	int heap_size;
	int root_idx;
	int direction;					//min,max에 따라 heap의 종류가 결정됨
public:
	minHeap(int direction)
	{
		v.push_back(-1);			//최소값으로 넣어서 영향을 주지 않도록 한다
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
		else if (left <= heap_size)
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

	bool isEmpty()					//힙이 비어 있으면 1, 비어 있지 않으면 0을 출력
	{
		return (heap_size == 0);
	}

	int at(int idx)					//힙의 원소를 출력
	{
		return v[idx];
	}

	void clear()					//초기화
	{
		v.clear();
		heap_size = 0;
		v.push_back(-1);
	}
};

class maxHeap
{
private:
	vector<int> v;					
	int heap_size;
	int root_idx;
	int direction;					//min,max에 따라 heap의 종류가 결정됨
public:
	maxHeap(int direction)
	{
		v.push_back(21);			//최댓값으로 넣어서 영향을 주지 않도록 한다
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
		else if (left <= heap_size)
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

	bool isEmpty()					//힙이 비어 있으면 1, 비어 있지 않으면 0을 출력
	{
		return (heap_size == 0);
	}

	int at(int idx)					//힙의 원소를 출력
	{
		return v[idx];
	}

	void clear()					//초기화
	{
		v.clear();
		heap_size = 0;
		v.push_back(21);
	}
};

int main()
{
	int t;							//테스트 케이스 갯수
	int n, p;						//n : 입력할 숫자 갯수, p : 인덱스
	int x;							//입력할 노드 번호

	minHeap h1(MIN);					//min-Heap
	maxHeap h2(MAX);					//max-Heap

	cin >> t;

	while (t--)
	{
		cin >> n >> p;

		for (int i = 1; i <= n; i++)
		{
			cin >> x;

			h1.insert(x);
			h2.insert(x);
		}

		cout << h1.at(p) << endl;

		for (int i = 1; i < p; i++)	//(p-1)개를 삭제
			h1.pop();

		cout << h1.pop() << endl;	//p번째를 삭제하면서 출력



		cout << h2.at(p) << endl;

		for (int i = 1; i < p; i++)	//(p-1)개를 삭제
			h2.pop();

		cout << h2.pop() << endl;	//p번째를 삭제하면서 출력


		h1.clear();
		h2.clear();
	}


	return 0;
}