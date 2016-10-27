/* ������ ����� ����� ������� N ������������������� ���������� ������� �� ���������� �� -N �� N.
���������� �������� �������� ������� ������ �� 1 ������� (��������� ������� ������ ������, 1-� ������ 2-�, 2-� ������ 3-� � �.�.)
����� ���������� �������� �������� ������� ����� �� 1 ������� (������ ������� ������ ���������, 2-� ������ 1-� � �.�)*/
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
	cout << "������������� ����������� ������" << '\n';
	printA(A, N);
	moveRightA(A, N);
	cout << '\n' << "��������� ������" << '\n';
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