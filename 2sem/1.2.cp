#include <iostream>
#include <clocale>
#include <ctime>
#include <cmath>
void initRandA(int * ptr, int size);
void printA(int * ptr, int size);
double mode(double digit);
double culcdist(int a, int b, int c, int x, int y);
void sortA(int * x, int * y, int a, int b, int c, int size);
using namespace std;
int main() {
    setlocale(LC_ALL, "Russian");
    srand(time(NULL));
    
    int count;
    int * x;
    int * y;
    int a, b, c; //прямая ax+by=0
    
    cout<<"Введите количество строчек: ";
    cin>>count;//количество строчек
    cout<<endl;
    x= new int [count];
    y= new int [count];
    cout<<"Введите коэфиценты для прямой ax+by+c=0";
    cout<<endl<<"Введите коэфицент а:";
    cin>>a;
    cout<<endl<<"Введите коэфицент b:";
    cin>>b;
    cout<<endl<<"Введите коэфицент c:";
    cin>>c;
    cout<<endl;
    initRandA(x, count);
    initRandA(y, count);
    printA(x, count);
    printA(y, count);
    sortA(x, y, a, b, c, count);
    printA(x, count);
    printA(y, count);
    delete [] x;
    delete [] y;
    return 0;
}
void initRandA(int * ptr, int size) {
    
    for (int i=0; i<size; i++) {
        
        ptr[i]=rand()%100+1;
       
        
    }
}

void printA(int * ptr, int size) {
    
    for (int i=0; i<size; i++) {
        
        cout<< ptr[i]<<"  ";

    }
    
    cout<<endl;
}
double culcdist(int a, int b, int c, int x, int y) {
    
    double distation;
    
    distation= (x*a+y*b+c)/sqrt((a*a)+(b*b));
    
    return mode(distation);
}

void sortA(int * x, int * y, int a, int b, int c, int size) {
    
    for (int i=0; i<(size-1); i++) {
        
        for (int j=0; j<(size-1); j++) {
            
            if (culcdist(a, b, c, x[j], y[j])>culcdist(a, b, c, x[j+1], y[j+1])) {
             
                swap(x[j], x[j+1]);
                swap(y[j], y[j+1]);
                
            }
            
        }
        
    }
    
}

double mode(double digit) {
    
    if (digit < 0) digit*=-1;
    
    return digit;
}
