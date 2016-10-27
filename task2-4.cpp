/*������ ����� ����� ������� N ������������������� ���������� ������� �� ���������� �� 1 �� N.
"������������" �������� ������� ����� ���������, ������������� �� ����: � �������������� ���.������� 
� ������ ����� ������� ��������� ��������*/
#include <iostream>
#include <clocale>
#include <ctime>
int random(int N);
void initA(int A[], int N);
void printA(int A[], int N);
void randomMixA1(int A[], int N);
void randomMixA2(int A[],int B[], int N);
using namespace std;
int main()
{
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));
	const int N = 9;
	int A[N],B[N];
	initA(A, N);
	cout << "������������� ����������� ������" << '\n';
	printA(A, N);
	cout << '\n' << "������������ ������1" << '\n';
	randomMixA1(A, N);
	printA(A, N);
	cout <<'\n'<< "������������ ������2" << '\n';
	randomMixA2(A, B, N);
	printA(A, N);
	system("pause");
}
int random(int N)
{
	return (rand() % N +1);
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
void randomMixA1(int A[], int N)
{
	int i = 0;
	while (i < N)
	{
		swap(A[i], A[rand() % N]);
		i++;
	}
}
void randomMixA2(int A[],int B[], int N)
{
	int i = 0,j=0;
	initA(B, N);
	while (i < N)
	{  
		j = i + 1;
		while (j < N)
		{
			if (B[i] < B[j]) { swap(B[i], B[j]); swap(A[i], A[j]); }
			j++;
		}
		i++;
	}
}
