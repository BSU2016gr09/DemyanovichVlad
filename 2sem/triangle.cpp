#include <iostream>
#include <cmath>
using namespace std;

class triangle {
public:
    int x[3];//Плохо, что это public
    int y[3];//Плохо, что это public
    triangle () {//А почему нет конструктора с параметрами? Как мне без него в main создать массив, например, треугольников?
        s=0;
        for (int i=0; i<3; i++) {
            side[i]=0;
        }
        p=0;
        cout<<"constructor is worked"<<endl;
    }
        triangle& operator =(triangle &other) {
        cout << "Operator of equality is working\n";
        this->s = other.s;
        this->p = other.p;
        for (int i=0; i<3; i++) {
            this->side[i]=other.side[i];
        }
        return *this;
    }
        triangle& operator +(triangle other) {//вот интересно мне как математику - что такое сумма треугольников в вашей интерпретации????
        cout << "Operator of addition is working\n";
        this->s += other.s;
        this->p += other.p;
        for (int i=0; i<3; i++) {
            this->side[i]+=other.side[i];
        }
        return *this;
    }
        triangle& operator -(triangle other) {//вот интересно мне как математику - что такое разность треугольников в вашей интерпретации????
        cout << "Operator of subtraction is working\n";
        this->s -= other.s;
        this->p -= other.p;
        for (int i=0; i<3; i++) {
            this->side[i]-=other.side[i];
        }
        return *this;
    }
    ~triangle() {
        cout<<"destructor is worked"<<endl;
    }
    void calcSides() {//глагол ВЫЧИСЛИТЬ пишется как cAlculate
        int j = 0;
        for (int i = 0; i < 3; i++) {
            if (i < 2) j = i+1; else j = 0; // а проверка. что треугольник существует????
            side[i] = sqrt((this->x[j] - this->x[i])*(this->x[j] - this->x[i]) + (this->y[j] - this->y[i])*(this->y[j] - this->y[i]));
        }
    }
    
    void calcPerimeter() {//глагол ВЫЧИСЛИТЬ пишется как cAlculate
        p = 0;
        for (int i = 0; i < 3; i++) {
            p += side[i];
        }
    }
    void area() {//Площадь называется AREA
        int halfP = p / 2;
        
        s = sqrt(abs(halfP*(halfP-side[0])*(halfP-side[1])*(halfP-side[2])));// а проверка. что треугольник существует????
    }
    void print() {//Зачем в названии метода буква Т?????
        cout << "first: "<< side[0] << "  second:  "<< side[1] << "  third:  "<< side[2]<<" perimeter: "<<p<<" area: "<< s;
    }
    
private:
    float s;
    float side[3];
    float p;
};

int main() {
    triangle v;//объяви несколько треугольников. Присвой одному из них - другой. и т.п....
    triangle a;
    for (int i = 0; i < 3; i++) {
        cin >> v.x[i] >> v.y[i];
    }
    v.calcSides();
    v.calcPerimeter();
    v.area();
    v.print();
    a=v;
    cout<<endl;
    a.print();
    return 0;
}
