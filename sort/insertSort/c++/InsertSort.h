//
// Created by xuan on 19-2-26.
//

#ifndef CDS_INSERTSORT_H
#define CDS_INSERTSORT_H

#include "../../sortHelper.h"

// 稳定
// 适合小规模数据
// 返回逆序对的数目
int insertSort(int *arr, int n) {
    int count = 0;
    for (int i = 1; i < n; ++i) {
        int temp = arr[i], j;
        for (j = i - 1; temp < arr[j] && j >= 0; j--) {
            arr[j + 1] = arr[j];
            count++;
        }
        arr[j + 1] = temp;
    }
    return count;
}

#endif //CDS_INSERTSORT_H
