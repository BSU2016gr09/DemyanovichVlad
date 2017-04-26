#include <iostream>
#include <cmath>
using namespace std;
class triangle {
public:
	int x[3];//�����, ��� ��� public //� ������ ���������� ������ ���� private?
	int y[3];//�����, ��� ��� public //� ������ ���������� ������ ���� private?
	triangle() {//� ������ ��� ������������ � �����������? ��� ��� ��� ���� � main ������� ������, ��������, �������������?//��������
		s = 0;
		for (int i = 0; i<3; i++) {
			side[i] = 0;
		}
		p = 0;
		cout << "constructor is worked" << endl;
	}
	triangle(int x0, int x1, int x2, int y0, int y1, int y2) {
		s = 0;
		p = 0;
		x[0] = x0; x[1] = x1; x[2] = x2;
		y[0] = y0; y[1] = y1; y[2] = y2;
		cout << "constructor with parametres is worked" << endl;
	}
	triangle& operator =(triangle &other) {
		this->s = other.s;
		this->p = other.p;
		for (int i = 0; i<3; i++) {
			this->side[i] = other.side[i];
		}
		return *this;
	}
	~triangle() {
		cout << "destructor is worked" << endl;
	}
	void calcSides() {
		int j = 0;
		for (int i = 0; i < 3; i++) {
			if (i < 2) j = i + 1; else j = 0; // � ��������. ��� ����������� ����������???? //��� �� ���, �� ��� ��� �� �����: ��� �������� ��� ����� ��� 3 ������� (������� ���������� �� �� ��������� ������), � ��� �-��� � ������� ��� �������.
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
			int halfP = p / 2;
			s = sqrt(abs(halfP*(halfP - side[0])*(halfP - side[1])*(halfP - side[2])));// � ��������. ��� ����������� ����������???? //�� ������� //TBD ��������
		}
		else cout << "triangle not exist" << endl;
	}
	void print() {
		if (isExist()) {
			cout << "first: " << side[0] << "  second:  " << side[1] << "  third:  " << side[2] << " perimeter: " << p << " area: " << s;
		}
		else cout << "triangle not exist"<<endl;
	}
private:
	float s;
	float side[3];
	float p;
};

int main() {
	triangle v;//������ ��������� �������������. ������� ������ �� ��� - ������. � �.�....
	triangle a;
	triangle triangles[] = { {1,2,3,4,5,6}, {1,2,3,2,5,8} };
	for (int i = 0; i < 3; i++) {
		cin >> v.x[i] >> v.y[i];
	}
	v.calcSides();
	v.calcPerimeter();
	v.area();
	v.print();
	a = v;
	cout << endl;
	a.print();
	system("PAUSE");
	return 0;
}
