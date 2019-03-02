//
// Created by xuan on 19-2-26.
//

#ifndef CDS_SORTHELPER_H
#define CDS_SORTHELPER_H

#include <iostream>

using namespace std;


int *createArray(int n) {
    srand(time(NULL));
    int *arr = new int[n];
    for (int i = 0; i < n; ++i) {
        arr[i] = rand() % n;
    }
    return arr;
}

void printArray(int *arr, int n) {
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
bool isSorted(int *arr, int n){
    for (int i = 1; i < n; ++i) {
        if(arr[i-1] > arr[i])
            return false;
    }
    return true;
}
template<typename T>
void delArray(T *arr) {
    delete[] arr;
}

#endif //CDS_SORTHELPER_H
