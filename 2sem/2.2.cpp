#include <iostream>
#include <ctime>;
using namespace std;
static unsigned long int pivot=1;
const int size=100;
void srandom(unsigned int start);
void initA(int * ptr, int size);
void printA(int * ptr, int size);
int XORrandom();
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

int XORrandom() {
    unsigned long int tmp;
    int a=15, b=13, c=5;
    
    tmp = pivot^ (pivot << a) ;
    
    tmp = tmp^ (tmp>>b) ;
    
    pivot=tmp^(tmp<<c);
    
    return pivot;
}

void initA(int * ptr, int size) {
    
    for (int i=0; i<size; i++) {
        
        ptr[i]=XORrandom()%100+1;
    }
}
void printA(int * ptr, int size) {
    
    for (int i=0; i<size; i++) {
        
        cout<<ptr[i]<<"  ";
    }

}
