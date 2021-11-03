#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;
void Creation(int* b, const int size, const int A, const int B,int i)
{
	if (i < size)
	{
		b[i] = A + rand() % (B - A + 1);
		return Creation(b, size, A, B, i + 1);
	}
}

void cmd(int* b, const int size,int i)
{
	if (i < size)
	{
		if (i == 0)
		
			cout << "{";
		cout << b[i];
		if (i != size - 1)
				cout << ", ";
		else cout << "}" << endl;
		return cmd(b, size, i + 1);
		
	}
}

int S(const int* const b, const int size,int i)
{
	if (i < size)
	{
		if (b[i] % 2 != 0 || b[i] < 0)
			return  b[i] + S(b, size, i + 1);
		else
			return S(b, size, i + 1);
	}
	else return 0;
}

int cmdout(const int* b, const int size,int i)
{
	if (i < size)
	{
		if (b[i] % 2 != 0 || b[i] < 0)
			return 1 + cmdout(b, size, i + 1);
		else
			return cmdout(b, size, i + 1);
	}
	else return 0;
}
void Creation2(int b[], const int size,int i)
{
	if (i < size)
	{
		if (b[i] % 2 != 0 || b[i] < 0)
			b[i] = 0;
			return Creation2(b, size,i + 1);
	}
}

int main()
{
	srand((unsigned)time(NULL));
	const int size = 25;
	int b[size];
	int A = -20;
	int B = 30;
	Creation(b, size, A, B,0);
	cmd(b, size,0);
	cout << "The sum of the elements that satisfy the condition = " << S(b, size,0) << endl;
	cout << "The number of elements that satisfy the condition = " << cmdout(b, size,0) << endl;
	Creation2(b, size,0);
	cmd(b, size,0);
	return 0;
}