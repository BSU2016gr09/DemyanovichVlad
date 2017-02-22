#include <iostream>
#include <clocale>
#include <ctime>
#include <cmath>
using namespace std;
void giveMemory(int * & ptr, int size);
void initA(int * ptr, int size);
void printA(int * ptr, int size);
int isPrime(int digit);
void sortPrime(int * ptr, int size);
int main() {
    int * ptr=nullptr;
    int size=10;
    ptr= new int [size];
    initA(ptr, size);
    printA(ptr, size);
    sortPrime(ptr, size);
    printA(ptr, size);
    delete [] ptr;
    return 0;
}

void initA(int * ptr, int size) {
    
    for (int i=0; i<size; i++) {
        
       // ptr[i]=rand()%200-100;
        cin>>ptr[i];
        
    }
}

void printA(int * ptr, int size) {
    
    for (int i=0; i<size; i++) {
        
        cout<< ptr[i]<<"  ";
        
    }
    
    cout<<endl;
}

int isPrime(int digit) {
    
    int check=sqrt(digit);
    if (digit==1) return 0;
    if ((digit%2)==0) return 0;
    for(int i=3; i<=check; i+=2) {
        if ((digit % i)==0) return 0;
    }
    return 1;
}

void sortPrime(int * ptr, int size) {
    int j=0, tmp=0;
    
    for (int i=0; i<size; i++) {
        
        if (isPrime(ptr[i])) {
            
            j=0;
            tmp=i;
            while (j<size) {
                
                while (!isPrime(ptr[j]) && j<size) {
                    
                    j++;
            
                }
                if (ptr[tmp]>ptr[j] && i<size) {
                    
                    swap(ptr[tmp], ptr[j]);
                    tmp=j;
                }
                j++;
            }
        }
    }
}

void giveMemory(int * & ptr, int size) {
    ptr= new int[size];
}
