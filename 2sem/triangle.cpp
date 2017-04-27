#include <iostream>
#include <cmath>
using namespace std;



class triangle {
public:
	int x[3];
	int y[3];
	triangle() {
		s = p = 0;
		for (int i = 0; i<3; i++) side[i] = x[i] =y[i]= 0;
		cout << "default constructor is worked" << endl;
	}
	triangle(int x0, int x1, int x2=0, int y0=0, int y1=0, int y2=0) {
		x[0] = x0; x[1] = x1; x[2] = x2;
		y[0] = y0; y[1] = y1; y[2] = y2;
		calcSides();
		calcPerimeter();
		area();
		cout << "constructor with 6 parametres is worked" << endl;
	}
	triangle(int x0) {
		x[0] = x0; x[1] = x0; x[2] = x0;
		y[0] = 0; y[1] = 0; y[2] = 0;
		calcSides();
		calcPerimeter();
		area();
		cout << "constructor with 1 parametres is worked" << endl;
	}
	triangle(int x0[3], int y0[3]) {
		x[0] = x0[0]; x[1] = x0[1]; x[2] = x0[2];
		y[0] = y0[0]; y[1] = y0[1]; y[2] = y0[2];
		calcSides();
		calcPerimeter();
		area();
		cout << "constructor with array is worked" << endl;
	}
	triangle(triangle & other) {
		s =other.s;
		p = other.p;
		for (int i = 0; i<3; i++) {
			side[i]= other.side[i];
			x[i]= other.x[i];
			y[i]= other.y[i];
		}
		cout<<"copy constructor is worked";
	}
	//triangle(triangle && other){cout<<"move constructor is worked";}
	triangle& operator =(triangle &other) {
		triangle tmp(other);
		mySwap(tmp, *this);
		return *this;
	}
	~triangle() {
		cout <<'\n'<< "destructor is worked" << endl;
	}
	void mySwap(triangle left, triangle right){
		for (int i=0; i<3; i++) {
		swap(left.x[i],right.x[i]);
		swap(left.y[i],right.y[i]);
		swap(left.side[i], right.side[i]);
		}
		swap(left.s, right.s);
		swap(left.p, right.p);
	}
private:
	void calcSides() {
		int j = 0;
		for (int i = 0; i < 3; i++) {
			if (i < 2) j = i + 1; else j = 0; 
			side[i] = sqrt((this->x[j] - this->x[i])*(this->x[j] - this->x[i]) + (this->y[j] - this->y[i])*(this->y[j] - this->y[i]));
		}
	}
	int isExist() {
		if (side[0] > side[1]); else swap(side[0], side[1]);
		if (side[0] > side[2]); else swap(side[0], side[2]);
		if (side[0] < (side[1] + side[2])) return 1; else return 0;
	}
	void calcPerimeter() {
		if (isExist()) {
			p = 0;
			for (int i = 0; i < 3; i++) {
				p += side[i];
			}
		}
		else cout << "triangle not exist" << endl;
	}
	void area() {
		if (isExist()) {
			float halfP = p / 2;
			s = sqrt(abs(halfP*(halfP - side[0])*(halfP - side[1])*(halfP - side[2])));
		}
		else cout << "triangle not exist" << endl;
	}
public:
	void print() {
		if (isExist()) {
			cout << "first: " << side[0] << "  second:  " << side[1] << "  third:  " << side[2] << " perimeter: " << p << " area: " << s<<endl;
		}
		else cout << "triangle not exist"<<endl;
	}
private:
	float s;
	float side[3];
	float p;
};



int main() {
	int tmpX[3]={1,2,3};
	int tmpY[3]={0,0,3};
	triangle v;
	triangle a(tmpX,tmpY);
	triangle b[5] = { triangle(1,2,3,2,5,8) } ;
	triangle c[6] = { 1,2,3,2,5,8 } ;

	for (int i = 0; i < 3; i++) {
		c[i].print();
	}
	
	v.print();
	v = a;
	cout << endl;
	a.print();
	system("PAUSE");
	return 0;
}
