/* Массив целых чисел размера N проинициализировать случайными числами из промежутка от -N до N.
Циклически сдвинуть элементы массива вправо на 1 элемент (последний элемент станет первым, 1-й станет 2-м, 2-й станет 3-м и т.д.)
потом циклически сдвинуть элементы массива влево на 1 элемент (первый элемент станет последним, 2-й станет 1-м и т.д)*/
#include <iostream>
#include <clocale>
#include <ctime>
int random(int N);
void initA(int A[], int N);
void printA(int A[], int N);
void moveRightA(int A[], int N);
using namespace std;
int main()
{
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));
	const int N = 9;
	int A[N];
	initA(A, N);
	cout << "первоначально заполненный массив" << '\n';
	printA(A, N);
	moveRightA(A, N);
	cout << '\n' << "сдвинутый массив" << '\n';
	printA(A, N);
	system("pause");

}
int random(int N)
{
	return (rand() % (2*N+1)-N);
}
void initA(int A[], int N)
{
	int i = 0;
	while (i < N)
	{
		A[i] = random(N);
		i++;
	}

}
void printA(int A[], int N)
{
	int i = 0;
	while (i < N)
	{
		cout << A[i] << "  ";
		i++;
	}
}
void moveRightA(int A[], int N)
{
	int i = 1;
	while (i <N)
	{
		swap(A[N - i], A[N - 1 - i]);
		i++;
	}

}
