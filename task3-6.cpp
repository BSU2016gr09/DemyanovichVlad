#include <iostream>
#include <clocale>
#include <ctime>
void initA(char A[], int N);
void printA(char A[], int N);
void push(double A[], int N, char element);
char pop(double A[], int N);
double culc(double a, double b, char symb);
using namespace std;
int main()
{
	setlocale(LC_ALL, "Russian");
	const int size = 10;
	char  polishNotation[size];
	double stack[size],topElementOfStack,secondElementOfStack;
	int i = 0,top=size-1;
	cout << "введите польскую запись числа\n";
	cin >> polishNotation;
	
	
	while (polishNotation[i] != 0)
	{
		if (polishNotation[i] != '-' && polishNotation[i] != '+' && polishNotation[i] != '*' && polishNotation[i] != '/')
			push(stack, size, (polishNotation[i]-48));
				else
					{
						topElementOfStack = pop(stack, size); secondElementOfStack = pop(stack, size); push(stack, size, culc(topElementOfStack, secondElementOfStack, polishNotation[i]));
					}
		i++;
	}


	cout <<"Ответ:"<< stack[top];
	system("pause");
}
void push(double A[], int N, char element)
{
	int i = 0;
	while (i <N - 1)
	{
		swap(A[i], A[i%N + 1]);
		i++;
	}
	A[N - 1] = element;
}
char pop(double A[], int N)
{
	int i = N - 1, tmp;
	while (i > 0)
	{
		swap(A[i], A[i%N - 1]);
		i--;
	}
	tmp = A[0];
	A[0] = 0;
	return(tmp);
}
void initA(char A[], int N)
{
	int i = 0;
	while (i<N)
	{
		A[i++] = 0;
	}
}
void printA(char A[], int N)
{
	int i = 0;
	while (i < N)
	{
		cout << A[i++] << " ";
	}
	cout << "\n\n";
}
double culc(double a, double b, char symb)
{   
	double rez;
	switch (symb)
	{
	case ('*'): rez = a*b; break;
	case('+'): rez = a + b; break;
	case('-'): rez = b-a; break;
	case('/'): rez = b/a; break;
	};
	return(rez);
}
