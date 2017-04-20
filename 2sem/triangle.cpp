#include <iostream>
#include <cmath>
using namespace std;

class triangle {
public:
    int x[3];
    int y[3];
    triangle () {
        s=0;
        for (int i=0; i<3; i++) {
            side[i]=0;
        }
        p=0;
        cout<<"constructor is worked"<<endl;
    }
    ~triangle() {
        cout<<"destructor is worked"<<endl;
    }
    void calcSides() {//глагол ВЫЧИСЛИТЬ пишется как cAlculate
        int j = 0;
        for (int i = 0; i < 3; i++) {
            if (i < 2) j = i+1; else j = 0;
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
        
        s = sqrt(abs(halfP*(halfP-side[0])*(halfP-side[1])*(halfP-side[2])));
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
