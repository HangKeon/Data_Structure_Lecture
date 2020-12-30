#include <iostream>
using namespace std;

class Array
{
public:
	int n;								//�迭 �� ���� �� 
	int* arr;							//�迭

	Array(int size)
	{
		this->n = 0;					//�迭 �� ���� ���� 0���� �ʱ�ȭ
		this->arr = new int[size];		//ũ�Ⱑ size �� �迭�� �Ҵ�

		for (int i = 0; i < size; i++)	//�迭�� ���� 0���� �ʱ�ȭ
			arr[i] = 0;
	}

	int at(int idx)						//�ش� idx�� ����� ���� ��ȯ
	{
		if (idx >= this->n)				//���Ұ� ���� idx ���� �־����� ��
		{
			cerr << "Out of range\n";
			return;
		}

		return arr[idx];
	}

	void set(int idx, int x)			//�ش� idx�� ����� ���� ������
	{
		if (idx < this->n)
		{
			this->arr[idx] = x;
		}
		else							//���Ұ� ���� idx�� �־����� ��
		{	 
			cerr << "Out of range\n";
			return;
		}
	}

	void add(int idx, int num)			//�ش� idx�� num�� ����
	{
		if (idx >= this->n)				// ���Ұ� ���� idx�� �־����� ��
		{
			cerr << "Out of range\n";
			return;
		}
		else
		{
			for (int i = this->n - 1; i > idx; i--)
				arr[i + 1] = arr[i];

			arr[idx] = num;
		}
	}

	int remove(int idx)					//�ش� idx�� ���� �����ϰ� �� ���� ��ȯ
	{
		if (idx >= this->n)				// ���Ұ� ���� idx�� �־����� ��
		{
			cerr << "Out of range\n";
			return;
		}

		int value = arr[idx];
		
		for (int i = idx; i < this->n - 1; i++)
			arr[i] = arr[i + 1];

		return value;
	}

	void printArray()					//�迭�� ����Ǿ� �ִ� ���� ���ʷ� ���
	{
		if (this->n == 0)				//�迭�� ������� �� 
		{
			cout << "�迭�� ����ֽ��ϴ�.\n";
		}
		else
		{
			for (int i = 0; i < this->n; i++)
				cout << arr[i] << ' ';

			cout << endl;
		}
	}
};

int main()
{
	

	return 0;
}