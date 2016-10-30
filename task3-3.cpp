//¬ массиве размера N, заполненного случ.числами от 0 до 10, определить максимальную длину последовательности равных элементов.
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
	cout << "\nсама€ длинна€ последовательность из одинаковых элементов=" << checkA(A, N) << '\n';
	system("PAUSE");
}
void printA(int A[], int N)
{
	int i = 0;
	while (i<N)
	{
		cout << A[i] << "  ";
		i++;
	}
}
void initA(int A[], int N)
{
	int i = 0;

	while (i<N)
	{
		A[i] = rand() % 10;
		i++;
	}
}
int checkA(int A[], int N)
{
	int countOfSimpleElements = 0, i = 0, j;
	while (i < N)
	{  
		int lenght=1;
		j = i +1;
		while (j < N)
		{
			    if (A[i] != A[j]) break;
				else lenght++;
				j++;
        }
		if (lenght > countOfSimpleElements) countOfSimpleElements = lenght;
		i++;
	}
	return (countOfSimpleElements);
}