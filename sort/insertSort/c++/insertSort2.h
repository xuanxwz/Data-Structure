//
// Created by xuan on 19-3-2.
//

#ifndef CDS_INSERTSORT2_H
#define CDS_INSERTSORT2_H

void insertSort2(int *arr, int n) {
    int j;
    for (int i = 1; i < n; ++i) {
        int temp = arr[i];
        for (j = i - 1; arr[j] > temp && j >= 0; j--) {
            arr[j+1] = arr[j];
        }
        arr[j+1] = temp;
    }
}

#endif //CDS_INSERTSORT2_H
