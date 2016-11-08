#include <iostream>
#include <clocale>
#include <cmath>
#include <iomanip>
using namespace std;
int calcspace(double y);
int main()
{
	setlocale(LC_ALL, "Russian");
	double x, y;
	x = -6;
	while (x<=6)
	{
		y = calcspace(x);
		cout << right << setw(y) << "*" << '\n';
		x = x + 0.1;
	}
	system("PAUSE");
}
int calcspace(double x)
{
	if (x == 0)  return(40); else return(sin(2*x)*20 / x)+20 ;
}