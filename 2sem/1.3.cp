#include <iostream>
#include <clocale>
#include <ctime>
void give_memory(int * & ptr, int size);
void delete_memory(int * & ptr);
void initA(int * ptr, int size);
void printA(int * ptr, int size);
void posToEnd(int * ptr, int size);
void sortNegative(int * ptr, int size);
using namespace std;
int main() {
    setlocale(LC_ALL, "Russian");
    srand(time(NULL));
    int size=10;
    int * ptr;
    give_memory(ptr, size);
    initA(ptr, size);
    printA(ptr, size);
    posToEnd(ptr, size);
    sortNegative(ptr, size);
    printA(ptr, size);
    delete_memory(ptr);
    return 0;
}

void initA(int * ptr, int size) {
    
    for (int i=0; i<size; i++) {
        
        ptr[i]=rand()%200-100;
        
        
    }
}

void printA(int * ptr, int size) {
    
    for (int i=0; i<size; i++) {
        
        cout<< ptr[i]<<"  ";
        
    }
    
    cout<<endl;
}

void posToEnd(int * ptr, int size) {

    int j=0;
    
    for (int i=(size-1); i>=0; i--) {
        if (ptr[i]<0) {
            j=i;
            while (ptr[j]<0 && j>=0) {
                j--;
            }
            if (j>=0) {
                swap(ptr[i], ptr[j]);
            }
        }
    }
}

void sortNegative(int * ptr, int size) {
    
    int i=0, j=0;
    while (ptr[i+1]<0 && i<size) {
        j=0;
        while (ptr[j+1]<0 && i<size) {
        
            if (ptr[j]<ptr[j+1]) swap(ptr[j], ptr[j+1]);
            j++;
        }
        i++;
    }
}

void give_memory(int * & ptr, int size) {
    try {
        ptr= new int [size];
    } catch (...) {
        cout<<"Failed";
    }
}
void delete_memory(int * & ptr) {
    delete [] ptr;
}
