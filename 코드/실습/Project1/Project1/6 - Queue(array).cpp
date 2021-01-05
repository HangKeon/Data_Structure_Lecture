#include <iostream>
#include <string>
using namespace std;

class arrQueue					//����ť�� ����(������ ȿ�������� ����� �� ����)
{
public:
	int* Q;							//�������� ���� ť
	int capacity;					//ť�� �뷮
	int f;							//front�� ��ġ
	int r;							//rear�� ��ġ

	arrQueue(int size)				//������
	{
		this->Q = new int[size];	//r=f-1�� ��츦 empty�� �����ϱ� ���� 1ĭ�� �����
		this->capacity = size;
		this->f = 0;				//f�� ����Ű�� ������ ť�� ���� ����
		this->r = -1;				//r�� ����Ű�� ������ ť�� ���� ����

		for (int i = 0; i < size; i++)	//0�� �迭�� ���Ұ� ���� ������ �Ǵ�! -> �ʱ�ȭ
			Q[i] = 0;
	}

	int size()						//ť ���� ������ ����
	{
		return (r + capacity - f + 1) % capacity;
	}

	bool isEmpty()					//ť�� ����ִ��� Ȯ��
	{
		return (Q[f] == 0);
	}

	int front()						//���� �������� �Էµ� ť�� ���� ���
	{
		if (isEmpty())				//�迭�� ���Ұ� ���� ���
			return 0;

		return Q[f];
	}

	int rear()						//���� �ֱٿ� �Էµ� ť�� ���� ���
	{
		if (isEmpty())				//�迭�� ���Ұ� ���� ���
			return 0;

		return Q[r];
	}

	void enqueue(int data)			//ť�� ���� �Է�
	{
		r++;						//r�� 1����

		if (r == capacity)			//r�� �迭�� ���� ������ ���
			r %= capacity;			//ó������ �ǵ���

		Q[r] = data;
	}
		
	void dequeue()					//������ ���� ����
	{
		if (isEmpty())				//���Ұ� ���� ���
			cout << "Empty" << endl;
		else
		{
			int value = Q[f];		//���� �� ����

			Q[f] = 0;				//���� ����
			f++;

			if (f == capacity)		//f�� �迭�� ���� ������ ���
				f %= capacity;		//ó������ �ǵ���

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