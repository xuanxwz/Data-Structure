//
// Created by xuan on 19-2-26.
//

#ifndef CDS_BUBBLESORT_H
#define CDS_BUBBLESORT_H

#include <iostream>


void bubbleSort(int *arr, int n) {
    bool isSorted = true;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n - 1 - i; ++j) {
            if (arr[j] > arr[j + 1]) {
                isSorted = false;
                std::swap(arr[j], arr[j + 1]);
            }
        }
        if (isSorted) {
            return;
        }
        isSorted = true;
    }
}

#endif //CDS_BUBBLESORT_H
