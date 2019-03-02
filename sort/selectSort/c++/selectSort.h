//
// Created by xuan on 19-2-26.
//

#ifndef CDS_SELECT_H
#define CDS_SELECT_H

#include <iostream>

// 每次选择最小的
void selectSort(int *arr, int n){
    for (int i = 0; i < n-1; ++i) {
        int k = i;
        for (int j = i+1; j < n; ++j) {
            if( arr[j] < arr[k])
                k = j;
        }
        if( k != i){
            std::swap(arr[k], arr[i]);
        }
    }
}

// 每次选择最大的
void selectSortFromR(int *arr, int n){
    for (int i = n-1; i >= 0; i--) {
        int k = i;
        for (int j = 0; j < i-1; ++j) {
            if( arr[j] > arr[k])
                k = j;
        }
        if( k != i){
            std::swap(arr[k], arr[i]);
        }
    }
}
#endif //CDS_SELECT_H
