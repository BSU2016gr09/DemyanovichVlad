//В массиве размера N, заполненного случ.числами от 0 до 10, подсчитать количество элементов, встречающихся более одного раза.
#include <iostream>
#include <ctime>
#include <clocale>
void printA(int A[], int N);
void initA(int A[], int N);
int checkA(int A[], int N);
using namespace std;
int main()
{
	const int N = 10;
	int A[N];
	srand(time(NULL));
	setlocale(LC_ALL, "Russian");
	initA(A, N);
	printA(A, N);
	cout << "\nколичество повторяющихся элементов="<<checkA(A,N)<<'\n';
	system("PAUSE");
}
void printA(int A[], int N)
{
	int i = 0;
	while (i<N)
	{
		cout << A[i++] << "  ";
	}
}
void initA(int A[], int N)
{
	int i = 0;
        while (i<N)
	{
		A[i++] = rand() % 10;
	}
}
int checkA(int A[], int N)
{
    int countOfDiffElements=0,i=0,j;
	while (i < N)
	{
		j = i + 1;
		while (j<N)
		{
			if (A[i] >= 0 && A[i] == A[j])
			{
				countOfDiffElements++;
				while (j < N)
				{
					if (A[i] == A[j]) A[j] = -1;
					j++;
				}
			}
			j++;
		}
		i++;
	}
	return (countOfDiffElements);
}
