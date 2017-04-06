#include <iostream>
#include <cmath>
using namespace std;

class triangle {
	public:
		int x[3];
		int y[3];

		void culcSides() {//глагол ВЫЧИСЛИТЬ пишется как cAlculate
			int j = 0;
			for (int i = 0; i < 3; i++) {
				if (i < 2) j = i+1; else j = 0;
				side[i] = sqrt((this->x[j] - this->x[i])*(this->x[j] - this->x[i]) + (this->y[j] - this->y[i])*(this->y[j] - this->y[i]));
			}
		}

		void culcPerimeter() {//глагол ВЫЧИСЛИТЬ пишется как cAlculate
			p = 0;
			for (int i = 0; i < 3; i++) {
				p += side[i];
			}
		}
		void square() {//Площадь называется AREA
			int halfP = p / 2;

			s = sqrt(halfP*(halfP-side[0])*(halfP-side[1])*(halfP-side[2]));
		}
		void printT() {//Зачем в названии метода буква Т?????
			cout << "first: "<< side[0] << "  second:  "<< side[1] << "  third:  "<< side[2]<<"square: "<< s;
		}
	private:
		float s;
		float side[3];
		int p;
};

int main() {
	triangle v;//объяви несколько треугольников. Присвой одному из них - другой. и т.п....
	for (int i = 0; i < 3; i++) {
		cin >> v.x[i] >> v.y[i];
	}
	v.culcSides();
	v.culcPerimeter();
	v.square();
	v.printT();
	system("PAUSE");
	return 0;
}
