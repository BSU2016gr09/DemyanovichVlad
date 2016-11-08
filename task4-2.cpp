#include <iostream>
#include <clocale>
#include <ctime>
int pop(int A[], int size, int & count);
void push(int A[], int size, int element1, int element2, int & count);
void pushSame(int A[], int size, int element, int & count);
void printA(int A[], int N);
void initCards(int A[], int N);
void mixA(int A[], int N);
void handingOutCards(int A[], int PL1[],int PL2[], int N);
void clean(int A[], int N);
using namespace std;
int main()
{   srand(time(NULL));
	setlocale(LC_ALL, "Russian");
	const int N = 52;
	int A[N],PL1[N],PL2[N],count1=N/2,count2=N/2,stepPl1,stepPl2, i=0,winPL1=0;
	long long int countOfSteps = 0, countOfSteps1 = 0;
	while (i < 5000)
	{
		initCards(A, N);
	    mixA(A, N);
	    handingOutCards(A, PL1, PL2, N);
		count1 = N / 2; count2 = N / 2;
		while (count1 > 0 && count2 > 0)
		{
			stepPl1 = pop(PL1, N, count1);
			stepPl2 = pop(PL2, N, count2);
			if (stepPl1 == 6 && stepPl2 == 14) { push(PL1, N, stepPl1, stepPl2, count1); }
			else if (stepPl2 == 6 && stepPl1 == 14)  push(PL2, N, stepPl1, stepPl2, count2);  
					else if (stepPl1 == 7 && stepPl2 == 13) push(PL1, N, stepPl1, stepPl2, count1);
						else if (stepPl2 == 7 && stepPl1 == 13) push(PL2, N, stepPl1, stepPl2, count2);
							else if (stepPl1 > stepPl2) push(PL1, N, stepPl1, stepPl2, count1);
								else if (stepPl1 == stepPl2) { pushSame(PL1, N, stepPl1, count1); pushSame(PL2, N, stepPl2, count2); }
									else if (stepPl1 < stepPl2) { push(PL2, N, stepPl1, stepPl2, count2); }
									countOfSteps1++;
			if (countOfSteps1 > 10000) {
				countOfSteps1 = 0;
				break;
			}  
			
		}
		if (count1 != 0) winPL1++;
		i++;
		clean(PL1, N);
		clean(PL2, N);
		clean(A, N);
		countOfSteps += countOfSteps1;
		countOfSteps1 = 0;
	}
	winPL1 = winPL1 / 50;
	countOfSteps /= 5000;
	cout << "среднее количество ходов=" << countOfSteps;
	cout << "\nпроцент побед первого игрока= " << winPL1 << '%';
	system("PAUSE");	
}
int pop(int A[], int size,int & count)
{
	int top = size - 1, i = size - 1,tmp;
	tmp = A[top];
	while (i >= 1)
	{
		A[i] = A[i - 1];
		i--;
	}
	A[0] = 0;
	count--;
	return(tmp);
}
void push(int A[], int size, int element1,int element2, int & count)
{
	int i = size-count-1;
	A[i] = element1;
	A[i - 1] = element2;
	count +=2;
}
void printA(int A[], int N)
{
	int i = 0, j=1;
	while (i < N)
	{
		cout << A[i] << "  ";
		if (j == 4) {cout << '\n'; j = 0;}
		i++; j++;
	}
}
void initCards(int A[], int N)
{
	int i = 0,j,count=2;
	while (count <= 14)
	{
		j = 0;
		while (j < 4)
		{
			A[i] = count;
			j++;
			i++;
		}
		
		count++;
	}
}
void mixA(int A[], int N)
{
	int i = 0;
	while (i < N) 
	{
		swap(A[i], A[rand() % N]);
		i++;
	}
}
void handingOutCards(int A[], int PL1[], int PL2[], int N)
{
	int i = N-1,j=N-1;
	while (i > (N / 2)-1)
	{
		PL1[j] = A[i];
		i--; j--;
	}
	j = N-1;
	while (i >=0)
	{
		PL2[j] = A[i];
		i--; j--;
	}
}
void pushSame(int  A[], int size, int element, int & count)
{
	int i = size - count - 1;
	A[i] = element;
	count++;
}
void clean(int A[], int N)
{
	int i = 0;
	while (i < N)
	{
		A[i] = 0;
		i++;
	}
}