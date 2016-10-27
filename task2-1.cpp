/*ћассив целых чисел размера N проинициализировать случайными числами из промежутка от 1 до N.
"ѕеревернуть" массив (последний элемент станет первым, 1-й станет последним, 2-й помен€етс€ с предпоследним и т.д.)
¬нимательно проверьте случай нечетного N*/
#include <iostream>
#include <clocale>
#include <ctime>
int random(int N);
void initA(int A[], int N);
void printA(int A[], int N);
void turnA(int A[], int N); 
using namespace std;
int main()
{
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));
	const int N = 9;
	int A[N];
	initA(A, N);
	cout << "первоначально заполненный массив"<<'\n';
	printA(A, N);
	turnA(A, N);
	cout <<'\n'<< "перевЄрнутый массив" << '\n';
	printA(A, N);
	system("pause");

}
int random(int N)
{
	return (rand() % N + 1);
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
void turnA(int A[], int N)
{
	int i = 0;
	while (i + i < N)
	{
		swap(A[i], A[N - i - 1]);
		i++;
	}
}