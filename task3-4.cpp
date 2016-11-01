#include <iostream>
#include <clocale>
#include <ctime>
void popDouble(double A[], int size);
void pushDouble(double A[], int size, int element);
void initADouble(double A[], int N);
void printADouble(double A[], int N);
void pushChar(char A[], int size, char element);
void popChar(char A[], int size);
void initAChar(char A[], int N);
void printAChar(char A[], int N);
using namespace std;
int main()
{
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));
	const int size = 10;
	double A[size],element1;
	char B[size], element = 40;
	element1 = (rand() % 100) / 10.0 + 1.0;
	cout << "\nмассив символов:\n";
	initAChar(B, size);
	printAChar(B, size);
	cout << "\nпосле 2 пуша:\n";
	pushChar(B, size, element);
	pushChar(B, size, 60);
    printAChar(B, size);
	cout << "\nпосле 2 pop'a:\n";
	popChar(B, size);
	popChar(B, size);
	printAChar(B, size);
	cout << "\nмассив вещественных чисел:\n";
	initADouble(A, size);
	printADouble(A,size);
	cout << "\nпосле 2 пуша:\n";
	pushDouble(A, size, element1);
	pushDouble(A, size, element1);
	printADouble(A, size);
	cout << "\nпосле 2 pop'a:\n";
	popDouble(A, size);
	popDouble(A, size);
	printADouble(A, size);
	system("PAUSE");
}
void popDouble(double A[], int size)
{
	int top = size-1, i = size - 1;
	if (top = 0) {
		cout << "стэк пуст"; return;
	}
	while (i >= 0)
	{
		swap(A[i%(size-1) + 1], A[i]);
		i--;
	}
	A[0] = 0;
}
void pushDouble(double A[], int size, int element)
{
	int i = 0, top = size - 1;
	while (i < size)
	{
		swap(A[i%top + 1], A[i]);
		i++;
	}
	A[top] = element;
}
void initADouble(double A[], int N)
{
	int i = 0;
	while (i < N)
	{
		A[i] = (rand() % 1000 + 1) / 100.0;
		i++;
	}
}
void printADouble(double A[], int N)
{
	int i = 0;
	while (i<N)
	{
		if (A[i] != 0) { cout << A[i] << "  "; }
		i++;
	}
}
void popChar(char A[], int size)
{
	int top = size-1, i = size - 1;
	if (top = 0) {
		cout << "стэк пуст"; return;
	}
	while (i >= 0)
	{
		swap(A[i%(size-1) + 1], A[i]);
		i--;
	}
	A[0] = 0;
}
void pushChar(char A[], int N, char element)
{
	int i = 0;
	while (i <N)
	{
		swap(A[i], A[i%(N-1) + 1]);
		i++;
	}
	A[N - 1] = element;
}
void initAChar(char A[], int N)
{
	int i = 0;
	while (i < N)
	{
		A[i] = rand() % 256 + 1;
		i++;
	}
}
void printAChar(char A[], int N)
{
	int i = 0;
	while (i<N)
	{
		cout << A[i] << "  ";
		i++;
	}
}
