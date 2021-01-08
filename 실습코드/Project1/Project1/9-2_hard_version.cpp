#include <iostream>
#include <vector>
#include <string>
using namespace std;

enum direction { MIN = 1, MAX = -1 };	//max-heap�� min-heap�� ����

class minHeap							//min-Heap
{
private:
	vector<int> v;
	int heap_size;
	int root_idx;
	int direction;					//min,max�� ���� heap�� ������ ������
public:
	minHeap(int direction)
	{
		v.push_back(-1);			//�ּҰ����� �־ ������ ���� �ʵ��� �Ѵ�
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

	void upHeap(int idx)			//idx�� �ڽ��� ��� ��ȣ
	{
		if (direction*v[idx / 2] > direction*v[idx])	//�θ��� ��� ��ȣ > �ڽ��� ��� ��ȣ
		{
			swap(idx / 2, idx);
			upHeap(idx / 2);
		}
	}


	void downHeap(int idx)			//idx�� �θ��� ��� ��ȣ
	{
		int right = 2 * idx + 1;	//������ �ڽ��� ��� ��ȣ
		int left = 2 * idx;			//���� �ڽ��� ��� ��ȣ
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

	void insert(int e)				//�ڿ��� e�� �켱���� ť�� ����.
	{
		v.push_back(e);
		heap_size++;

		upHeap(heap_size);
	}


	int pop()						//�켱������ ���� ���� ���Ҹ� ��� �� ���� ����
	{
		if (isEmpty())				//���� ��� �ִ� ���, -1�� ���
			return -1;

		int temp = v[heap_size];
		int ret = v[root_idx];

		v.erase(v.begin() + heap_size);

		v[root_idx] = temp;
		heap_size--;

		downHeap(root_idx);

		return ret;
	}

	bool isEmpty()					//���� ��� ������ 1, ��� ���� ������ 0�� ���
	{
		return (heap_size == 0);
	}

	int at(int idx)					//���� ���Ҹ� ���
	{
		return v[idx];
	}

	void clear()					//�ʱ�ȭ
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
	int direction;					//min,max�� ���� heap�� ������ ������
public:
	maxHeap(int direction)
	{
		v.push_back(21);			//�ִ����� �־ ������ ���� �ʵ��� �Ѵ�
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

	void upHeap(int idx)			//idx�� �ڽ��� ��� ��ȣ
	{
		if (direction*v[idx / 2] > direction*v[idx])	//�θ��� ��� ��ȣ > �ڽ��� ��� ��ȣ
		{
			swap(idx / 2, idx);
			upHeap(idx / 2);
		}
	}


	void downHeap(int idx)			//idx�� �θ��� ��� ��ȣ
	{
		int right = 2 * idx + 1;	//������ �ڽ��� ��� ��ȣ
		int left = 2 * idx;			//���� �ڽ��� ��� ��ȣ
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

	void insert(int e)				//�ڿ��� e�� �켱���� ť�� ����.
	{
		v.push_back(e);
		heap_size++;

		upHeap(heap_size);
	}


	int pop()						//�켱������ ���� ���� ���Ҹ� ��� �� ���� ����
	{
		if (isEmpty())				//���� ��� �ִ� ���, -1�� ���
			return -1;

		int temp = v[heap_size];
		int ret = v[root_idx];

		v.erase(v.begin() + heap_size);

		v[root_idx] = temp;
		heap_size--;

		downHeap(root_idx);

		return ret;
	}

	bool isEmpty()					//���� ��� ������ 1, ��� ���� ������ 0�� ���
	{
		return (heap_size == 0);
	}

	int at(int idx)					//���� ���Ҹ� ���
	{
		return v[idx];
	}

	void clear()					//�ʱ�ȭ
	{
		v.clear();
		heap_size = 0;
		v.push_back(21);
	}
};

int main()
{
	int t;							//�׽�Ʈ ���̽� ����
	int n, p;						//n : �Է��� ���� ����, p : �ε���
	int x;							//�Է��� ��� ��ȣ

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

		for (int i = 1; i < p; i++)	//(p-1)���� ����
			h1.pop();

		cout << h1.pop() << endl;	//p��°�� �����ϸ鼭 ���



		cout << h2.at(p) << endl;

		for (int i = 1; i < p; i++)	//(p-1)���� ����
			h2.pop();

		cout << h2.pop() << endl;	//p��°�� �����ϸ鼭 ���


		h1.clear();
		h2.clear();
	}


	return 0;
}