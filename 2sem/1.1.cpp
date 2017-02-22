#include <iostream>
#include <clocale>
#include <ctime>
using namespace std;
void initA(int * ptr, int size);
 void printA(int * ptr, int size);
void sortA(int * ptr, int size, int k);
int main() {
    
    setlocale(LC_ALL, "Russian");
    srand(time(NULL));
    int * ptr;
    int size, k;
    cout<<"Введите количество элементов:";
    cin>>size;
    cout<<endl;
    ptr= new int[size];
    initA(ptr, size);
    printA(ptr, size);
    cout<<"введите с какого элемента нчаинать сортировку:";
    cin>>k;
    cout<<endl;
    sortA(ptr, size, k);
     printA(ptr, size);
    delete [] ptr;
    return 0;
}

void initA(int * ptr, int size) {
 
    for (int i=0; i<size; i++) {
 
        ptr[i]=rand()%(2*size);
 
    }
 
 }
 
 void printA(int * ptr, int size) {
 
     for (int i=0; i<size; i++) {
 
        cout<<ptr[i]<<"  ";
 
     }
     
     cout<<endl;
 }

void sortA(int * ptr, int size, int k) {
    
    k--;
    
 for (int i=k; i<size; i++) {
     
     for (int j=k; j<(size-1); j++) {
         
         if (ptr[j]>ptr[j+1]) swap(ptr[j], ptr[j+1]);
         
     }
     
 }
 
}
