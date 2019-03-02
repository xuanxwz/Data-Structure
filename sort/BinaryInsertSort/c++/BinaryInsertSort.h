//
// Created by xuan on 19-2-26.
//

#ifndef CDS_BINARYINSERTSORT_H
#define CDS_BINARYINSERTSORT_H

#include <iostream>

using namespace std;

#include "../../sortHelper.h"

void binaryInsertSort(int *arr, int n) {
    for (int i = 1; i < n; ++i) {
        int temp = arr[i];
        int l = 0, r = i - 1;
        while (l <= r) {
            // 原先写法 int mid = l + (r - l) >> 1
            // 想斗个机灵 结果出bug了  运算符优先级 问题
            int mid = l + ((r - l) >> 1);

            if (temp < arr[mid])
                r = mid - 1;
            else
                l = mid + 1;
        }
        for (int j = i - 1; j >= l; j--) {
            arr[j + 1] = arr[j];
        }
        arr[l] = temp;
        printArray(arr, n);
    }
}

#endif //CDS_BINARYINSERTSORT_H
