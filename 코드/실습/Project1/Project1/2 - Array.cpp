#include <iostream>
using namespace std;

class Array
{
public:
	int n;								//배열 내 원소 수 
	int* arr;							//배열

	Array(int size)
	{
		this->n = 0;					//배열 내 원소 수를 0으로 초기화
		this->arr = new int[size];		//크기가 size 인 배열을 할당

		for (int i = 0; i < size; i++)	//배열을 원소 0으로 초기화
			arr[i] = 0;
	}

	int at(int idx)						//해당 idx에 저장된 값을 반환
	{
		if (idx >= this->n)				//원소가 없는 idx 값이 주어졌을 때
		{
			cerr << "Out of range\n";
			return;
		}

		return arr[idx];
	}

	void set(int idx, int x)			//해당 idx에 저장된 값을 덮어씌우기
	{
		if (idx < this->n)
		{
			this->arr[idx] = x;
		}
		else							//원소가 없는 idx가 주어졌을 때
		{	 
			cerr << "Out of range\n";
			return;
		}
	}

	void add(int idx, int num)			//해당 idx에 num을 삽입
	{
		if (idx >= this->n)				// 원소가 없는 idx가 주어졌을 때
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

	int remove(int idx)					//해당 idx의 값을 삭제하고 그 값을 반환
	{
		if (idx >= this->n)				// 원소가 없는 idx가 주어졌을 때
		{
			cerr << "Out of range\n";
			return;
		}

		int value = arr[idx];
		
		for (int i = idx; i < this->n - 1; i++)
			arr[i] = arr[i + 1];

		return value;
	}

	void printArray()					//배열에 저장되어 있는 값을 차례로 출력
	{
		if (this->n == 0)				//배열이 비어있을 때 
		{
			cout << "배열이 비어있습니다.\n";
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