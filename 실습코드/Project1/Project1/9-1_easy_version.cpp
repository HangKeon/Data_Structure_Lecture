#include <iostream>
#include <vector>
#include <string>
using namespace std;

enum direction { MIN = 1, MAX = -1 };	//max-heap�� min-heap�� ����

class heap
{
private:
	vector<int> v;
	int heap_size;
	int root_idx;
	int direction;					//min,max�� ���� heap�� ������ ������
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

	void upHeap(int idx)			//idx�� �ڽ��� ��� ��ȣ
	{
		if (direction*v[idx / 2] > direction*v[idx])
		{
			swap(idx / 2, idx);
			upHeap(idx / 2);
		}
	}

	void insert(int e)				//�ڿ��� e�� �켱���� ť�� ����.
	{
		v.push_back(e);
		heap_size++;

		upHeap(heap_size);
	}

	bool isEmpty()					//���� ��� ������ 1, ��� ���� ������ 0�� ���
	{
		return (heap_size == 0);
	}

	int size()						//���� ����Ǿ��ִ� �ڿ����� ������ ���
	{
		return heap_size;
	}

	void print()					//���� ���Ҹ� ���ʷ� ��� ���
	{
		if (isEmpty())				//����ִ� ��� -1�� ���
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
	int n;							//��ɾ� ����
	int e;							//������ ���
	string s;

	heap h(MIN);

	cin >> n;

	while (n--)
	{
		cin >> s;

		if(s=="insert")
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
		else if (s == "print")
		{
			h.print();
		}
	}

	return 0;
}