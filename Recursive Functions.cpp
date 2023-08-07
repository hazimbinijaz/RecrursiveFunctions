#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

//QUESTION # 1
int Fib_Memory_Helper(vector<int>& A, int N)
{
	if (A[N] != -1)
		return A[N];

	A[N] = Fib_Memory_Helper(A, N - 1) + Fib_Memory_Helper(A, N - 2);
	return A[N];

}

int Fib_With_Memory_Saving(int N)
{
	vector<int> A(N + 1, { -1 });
	A[0] = 0;
	A[1] = 1;

	return Fib_Memory_Helper(A, N);
}

int Fibonacci_Number_Recursive(int N)
{
	if (N == 0 || N == 1)
		return N;

	return Fibonacci_Number_Recursive(N - 1) + Fibonacci_Number_Recursive(N - 2);
}

int Fibonacci_Number_Iterative(int N)
{
	int x = 0, y = 1, z = 0;
	for (int i = 0; i < N; i++)
	{
		z = x + y;
		x = y;
		y = z;
	}
	return x;
}

//Question # 2
int TriSum_Recursive(int N)
{
	if (N == 0 || N == 1 || N == 2)
		return N;

	return TriSum_Recursive(N - 1) + TriSum_Recursive(N - 2) + TriSum_Recursive(N - 3);
}



//Question # 3

int Normal(int N)
{
	if (N == 1 || N == 0)
		return N;

	return N + Normal(N - 1);
}

int OddSeriesSum(int N)
{
	if (N == 1)
		return N;

	return N + OddSeriesSum(N - 2);
}

int TwoNSum(int N)
{
	if (N == 0)
		return 1;

	return pow(2, N) + TwoNSum(N - 1);
}

int ThreeNSum(int N)
{
	if (N == 0)
		return 1;

	return pow(3, N) + ThreeNSum(N - 1);
}

int NbyThree(int N)
{
	if (N <= 1)
		return 1;

	return N + NbyThree(N / 3);
}

int NbyTwo(int N)
{
	if (N <= 1)
		return 1;

	return N + NbyThree(N / 2);
}
//Question # 5

int LinearSearchR2L(vector<int> A, int Size, int Value)
{
	if (Size == 0)
		return -1;

	if (A[Size - 1] == Value)
		return Size - 1;
	return LinearSearchR2L(A, Size - 1, Value);
}

int SearchHelper(vector<int> A, int si, int ei, int Value)
{
	if (si > ei)
		return -1;

	if (A[si] == Value)
		return si;
	return SearchHelper(A, si + 1, ei, Value);
}

int LinearSearchL2R(vector<int> A, int Val)
{
	return SearchHelper(A, 0, A.size() - 1, Val);
}

//Question # 6
int RecursiveBSHelper(vector<int> A, int mid, int Val, int si, int ei)
{
	if (A[mid] == Val)
		return mid;

	if (ei <= si)
		return -1;

	else if (A[mid] > Val)
		return RecursiveBSHelper(A, ceil((si + (mid - 1)) / 2.0), Val, si, mid - 1);

	else
		return RecursiveBSHelper(A, (ei + (mid + 1)) / 2, Val, mid + 1, ei);
}

int RecursiveBinarySearch(vector<int> A, int Val)
{
	return RecursiveBSHelper(A, (A.size() - 1) / 2, Val, 0, A.size() - 1);
}

//Question # 7

long long SlowPower(int x, int y)
{
	if (y == 0)
		return 1;

	return x * SlowPower(x, y - 1);
}

long long FastPower(int x, int y)
{
	if (y == 0)
		return 1;

	if (y % 2 == 0)
		return 	pow(FastPower(x, y / 2), 2);

	return x * FastPower(x, y - 1);

}

//Question # 8

int SlowMult(int x, int y)
{
	if (y == 0)
		return 0;

	return x + (SlowMult(x, y - 1));
}

int FastMult(int x, int y)
{
	if (y == 0)
		return 0;

	int Total = x, AddCount = 1;
	while (AddCount + AddCount <= y)
	{
		Total += Total;
		AddCount += AddCount;
	}
	return Total + FastMult(x, y - AddCount);

}

//Question # 9

int FastDiv(int x, int y, int& re)
{
	if (y > x)
	{
		re = x;
		return 0;
	}

	int Total = y, Count = 1;
	while (Total + Total <= x)
	{
		Total += Total;
		Count += Count;
	}
	return Count + FastDiv(x - Total, y, re);

}

//QUESTION # 10

void Swap(int& V1, int& V2)
{
	int temp = V1;
	V1 = V2;
	V2 = temp;
}

bool BubbleUpRecursive(vector<int>& A, int S)
{
	if (S <= 0)
		return false;

	bool SH1 = false;
	SH1 = BubbleUpRecursive(A, S - 1);
	if (A[S - 2] > A[S - 1])
	{
		Swap(A[S - 2], A[S - 1]);
		SH1 = true;
	}


	return SH1;
}

void BubbleSort(vector<int>& a)
{
	if (BubbleUpRecursive(a, a.size()))
		return BubbleSort(a);
}

//Question # 11

int MinSearchRecursive(vector<int>& A, int si, int ei)
{
	if (si == ei)
		return si;

	int mi;
	mi = MinSearchRecursive(A, si + 1, ei);

	if (A[si] < A[mi])
		mi = si;

	return mi;
}


void SelectionSortHelper(vector<int>& A, int si, int ei)
{
	if (si == ei)
		return;

	int mi;
	mi = MinSearchRecursive(A, si, ei);
	Swap(A[mi], A[si]);
	SelectionSortHelper(A, si + 1, ei);
}

void SelectionSortRecursive(vector<int>& A)
{
	SelectionSortHelper(A, 0, A.size() - 1);
}

void main()
{
	int rem = 0;
	/*cout << Fibonacci_Number_Recursive(6) << endl;
	cout << Fibonacci_Number_Iterative(6) << endl;
	cout << Fib_With_Memory_Saving(6) << endl;*/
	//cout << Fibonacci_Number_Iterative(6);
	//cout << NbyThree(9);
	vector<int> x;
	/*for (int i = 0; i < 200; i++)
	{
		x.push_back(i);
	}
	cout << RecursiveBinarySearch(x, 29) << endl;*/
	/*cout << FastDiv(78, 4, rem) << "\n";
	cout << rem;*/

}