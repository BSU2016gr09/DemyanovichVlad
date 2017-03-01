#include <iostream>
#include <ctime>;
using namespace std;
static unsigned long int pivot=1;
const int size=100;
void srandom(unsigned int start);
void initA(int * ptr, int size);
void printA(int * ptr, int size);
int Mrandom();
int main() {
    srandom(time(NULL));
    int * p;
    p= new int [size];
    
    initA(p, size);
    printA(p, size);
    return 0;
}

void srandom(unsigned int start) {
    pivot=start;
}

int Mrandom() {
    pivot=pivot*221261+3530373;
    return pivot % 4425200;
}
void initA(int * ptr, int size) {
    
    for (int i=0; i<size; i++) {
        
        ptr[i]=Mrandom()%100+1;
    }
}
void printA(int * ptr, int size) {
    
    for (int i=0; i<size; i++) {
        
        cout<<ptr[i]<<"  ";
    }
    
}
