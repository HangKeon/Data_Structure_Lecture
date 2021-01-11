#include <iostream>
#include <vector>
#include <string>
using namespace std;

enum direction{MIN=1,MAX=-1};

class heap
{
private:
	vector<int> v;
	int heap_size;
	int root_idx;
	int direction;
public:
	heap(int dir)
	{
		v.push_back(-1);
		heap_size = 0;
		root_idx = 1;
		direction = dir;
	}

	void swap(int i, int j)
	{
		int temp = v[i];
		v[i] = v[j];
		v[j] = temp;
	}

	void upHeap(int idx)
	{
		if (direction*v[idx / 2] > direction*v[idx])
		{
			swap(idx / 2, idx);
			upHeap(idx / 2);
		}
	}

	void downHeap(int idx)
	{
		int right = 2 * idx + 1;
		int left = 2 * idx;
		int small = right;

		if (right <= heap_size)
		{
			if (direction*v[left] <= direction * v[right])
				small = left;
		}
		else if (left <= heap_size)
		{
			small = left;
		}
		else
			return;

		if (direction*v[idx] > direction*v[small])
		{
			swap(idx, small);
			downHeap(small);
		}
	}

	void insert(int e)
	{
		v.push_back(e);
		heap_size++;
		upHeap(heap_size);
	}

	int pop()
	{
		int temp = v[heap_size];
		int ret = v[root_idx];

		v.erase(v.begin() + heap_size);

		v[root_idx] = temp;
		heap_size--;

		downHeap(root_idx);

		return ret;
	}

	int at(int idx)
	{
		return v[idx];
	}

	void clear()
	{
		v.clear();
		v.push_back(-1);
		root_idx = 1;
		heap_size = 0;
	}
};

int main()
{
	int t;
	int n, p;
	int x;

	heap h(MIN);

	cin >> t;

	while (t--)
	{
		cin >> n >> p;

		for (int i = 0; i < n; i++)
		{
			cin >> x;

			h.insert(x);
		}

		cout << h.at(p) << endl;

		for (int i = 1; i < p; i++)
			h.pop();

		cout << h.pop() << endl;

		h.clear();

	}


	return 0;
}