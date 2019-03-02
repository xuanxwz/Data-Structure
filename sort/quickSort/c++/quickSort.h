//
// Created by xuan on 19-2-27.
//

#ifndef CDS_QUICKSORT_H
#define CDS_QUICKSORT_H

#include <iostream>

// 2路排序
int partition(int *arr, int l, int r) {
    int temp = arr[l]; // 可以先将arr[l]与任一位置的数据交换 来避免最坏的的情况
    while (l < r) {
        while (l < r && arr[r] > temp)
            r--;
        if (l < r)
            arr[l++] = arr[r];
        while (l < r && arr[l] < temp)
            l++;
        if (l < r)
            arr[r--] = arr[l];
    }
    return l;
}

// [0, n)
void _quickSort(int *arr, int l, int r) {
    if (l >= r)
        return;
    int p = partition(arr, l, r);
    _quickSort(arr, l, p - 1);
    _quickSort(arr, p + 1, r);

}

void quickSort(int *arr, int n) {
    _quickSort(arr, 0, n - 1);
}


#endif //CDS_QUICKSORT_H
