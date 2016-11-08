#include <iostream>
#include <clocale>
#include <ctime>
void initA(int A[], int N);
void initA(int A[], int N, int k);
void printA(int A[], int N);
void inputArray(int A[], int N);
void printNumber(int A[], int N);
void sum(int rez[], int A[], int B[], int N);
void numberInA(int n, int A[],int N);
void AInNumber(int rez[],int N);
void changeA(int A[], int B[], int N);
using namespace std;
int main()
{
	setlocale(LC_ALL, "Russian");
	const int maxCount = 100;
	int A[maxCount], B[maxCount], rez[maxCount],n;
	initA(A, maxCount); initA(B, maxCount); initA(rez, maxCount);
	cin >> n;
	numberInA(n, A, maxCount);
	cin >> n;
	numberInA(n, B, maxCount);
	while (rez[0] == 0)
	{
		sum(rez, A, B, maxCount);
		changeA(A, B, maxCount);
		changeA(B, rez, maxCount);
    }
	AInNumber(rez, maxCount);
	system("PAUSE");
}
void initA(int A[], int N)
{
	int i = 0;
	while (i < N)	A[i++] = 0;
}
void initA(int A[], int N, int k)
{
	int i = 0;
	while (i < N)	A[i++] = k;
}
void printA(int A[], int N)
{
	int i = 0;
	while (i<N)	 cout << A[i++] << "  ";
}
void inputArray(int A[], int N)
{
	int i = N-1;
	while (i>=0) cin >> A[i--];
}
void printNumber(int A[], int N)
{
	int i = 0;

	while (i<N) cout << A[i++];
	cout << '\n';
}
void sum(int rez[], int A[], int B[], int N)
{
	int i = N-1, tmp = 0;
	while (i>=0)
	{  
		rez[i] =((A[i]+B[i])% 10)+tmp;
		tmp = (A[i] + B[i]) / 10;
		i--; 
	}
}
void numberInA(int n, int A[], int N)
{
	int i = N-1;
	while (n > 0)
	{
		A[i] = n % 10;
		n = n / 10;
		i--;
	}
}
void AInNumber(int rez[], int N)
{
	int i = 0,k=0,j=0;
	while (i < N)
	{
		while (k == 0)
		{
			if (rez[j] != 0) { k++; i = j; }
			j++;
		}
		cout << rez[i];
		i++;
	}
}
void changeA(int A[], int B[], int N)
{
	int i = 0;
	while (i < N)
	{
		A[i] = B[i];
		i++;
	}
}