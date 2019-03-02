//
// Created by xuan on 19-3-2.
//

#ifndef CDS_MERGESORT_H
#define CDS_MERGESORT_H

// 自顶向下
void merge(int *arr, int *temp, int l, int mid, int r) {
    for (int i = l; i <= r; ++i)
        temp[i] = arr[i];
    int i = l, j = mid;
    int per = l;
    while (i < mid && j <= r)
        arr[per++] = (temp[i] < temp[j]) ? temp[i++] : temp[j++];
    while (i < mid)
        arr[per++] = temp[i++];
    while (j <= r)
        arr[per++] = temp[j++];
}

void _mergeSort(int *arr, int *temp, int l, int r) {
    if (l >= r)
        return;
    int mid = (l + r) / 2;
    _mergeSort(arr, temp, l, mid);
    _mergeSort(arr, temp, mid + 1, r);
    merge(arr, temp, l, mid + 1, r);
}

void mergeSort(int *arr, int n) {
    int *temp = new int[n];
    _mergeSort(arr, temp, 0, n - 1);
    delete[] temp;
}


// TODO 自底向上的归并排序
#endif //CDS_MERGESORT_H
