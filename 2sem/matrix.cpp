/*В каждом столбце массива А(N,М) после первого отрицательного элемента вставить максимальную цепочку из положительных элементов данного столбца. 
 Расположить столбцы в порядке возрастания по количеству вставленных элементов.*/

#include <iostream>
#include <ctime>
#include <iomanip>
using namespace std;
void give_memory(int ** & ptr, int lines, int columns) {
    try {
        ptr= new int * [lines];
        for(int i=0; i<lines; i++) {
            ptr[i]=new int[columns];
        }
    } catch (...) {
        cout<<"Failed";
    }
}
void free_memory(int ** & ptr, int lines, int columns){
    for(int i=0; i<lines; i++) {
        delete  [] ptr[i];
    }
    delete [] ptr;
}
void init(int ** ptr, int lines, int columns) {
    for(int i=0; i<lines; i++) {
        for(int j=0; j<columns; j++) {
            ptr[i][j]=rand()%20-5;
        }
    }
}
void print(int ** ptr, int lines, int columns){
    for(int i=0; i<lines; i++) {
        for(int j=0; j<columns; j++) {
            cout<<setw(4)<<ptr[i][j];
        }
        cout<<endl;
        cout<<endl;
    }
}
int maxlenght(int ** ptr, int lines, int column, int & start) {
    int size=0;
    int tmp=0;
    int numbOfEl=0;
    int tmpNumb=0;
    for (int i=0; i<lines; i++) {
        tmpNumb=i;
        while(i<lines && ptr[i][column]>=0) {
            i++;
            tmp++;
        }
        if (tmp>size) {
            numbOfEl=tmpNumb;
            size=tmp;
        }
        tmp=0;
    }
    start=numbOfEl;
    return size;
}
void pasteMax(int ** ptr, int lines, int column, int start){
    int i=0;
    while(i<lines && ptr[i][column]>=0 ) {
        i++;
    }
    i++;
    maxlenght(ptr, lines, column, start);
    int j=start;
    while (i<lines && j<lines && ptr[j][column]>0) {
        ptr[i][column]=ptr[j][column];
        i++;
        j++;
    }
}
int main() {
    srand(time(NULL));
    int ** ptr;
    int lines=0;
    int columns=0;
    int start=0;
    cout<<"count of lines: ";
    cin>>lines;
    cout<<endl<<"count of columns: ";
    cin>>columns;
    cout<<endl;
    give_memory(ptr, lines, columns);
    init(ptr, lines, columns);
    print(ptr, lines, columns);
    cout<<endl;
    for(int i=0; i<columns; i++) {
        pasteMax(ptr, lines, i, start);
    }
    print(ptr, lines, columns);
    free_memory(ptr, lines, columns);
    return 0;
}
