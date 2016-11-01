#include <iostream>
#include <clocale>
#include <ctime>
void push(char A[], int size, char element);
void pop(char A[], int size);
int trueOrfalseBrackets(char line[],int size);
using namespace std;
int main()
{
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));
	char line[] = "(aa[b(c)ddd]e{ee})";
	int size = strlen(line);
	if (trueOrfalseBrackets(line, size) == 1) cout << "правильно"; else cout << "не правильно";;
	system("PAUSE");
}

void pop(char A[], int size)
{
	int top = size-1, i = size - 1;
	if (top = 0) {
		cout << "стэк пуст"; return;
	}
	while (i >= 0)
	{
		swap(A[i % (size - 1) + 1], A[i]);
		i--;
	}
	A[0] = 0;
}
void push(char A[], int N, char element)
{
	int i = 0;
	while (i <N)
	{
		swap(A[i], A[i % (N - 1) + 1]);
		i++;
	}
	A[N - 1] = element;
}
int trueOrfalseBrackets(char line[], int size)
{   
	const int N = 20;
	char test[N];
	int top = N-1, i = 0;
	while (i < size)
	{
		if (line[i] == '(' || line[i] == '[' || line[i] == '{')
		{
			push(test, N, line[i]);
		}
		    else if (test[top]!=0) {
			if (line[i] == ')' || line[i] == ']' || line[i] == '}') {
                        if ((test[top] == '('&&line[i] == ')') || (test[top] == '{'&&line[i] == '}') || (test[top] == '['&&line[i] == ']'))
							pop(test, N);
																		}
			                                  
			}
			else { if (line[i] == ')' || line[i] == ']' || line[i] == '}') return(0); }
				i++; }
				
				
	
	if (test[top]> 0) return(0); else return(1);

}
