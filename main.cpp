#include <stdio.h>
#include <string>
#include <cstring>

#include "string/c++/kmp.h"
#include "graph/c++/DenseGraph.h"
#include "graph/c++/SparseGraph.h"
#include "graph/c++/ReadGraph.h"

#include "sort/sortHelper.h"
#include "sort/insertSort/c++/InsertSort.h"
#include "sort/insertSort/c++/insertSort2.h"
#include "sort/BinaryInsertSort/c++/BinaryInsertSort.h"
#include "sort/bubbleSort/c++/bubbleSort.h"
#include "sort/selectSort/c++/selectSort.h"
#include "sort/quickSort/c++/quickSort.h"
#include "sort/mergeSort/c++/mergeSort.h"

using namespace std;

int *buildNext(char *p) {
    size_t m = strlen(p), j = 0;
    int *next = new int[m];
    int t = next[0] = -1;
    while (j < m - 1) {
        if (t < 0 || p[j] == p[t])
            next[++j] = ++t;
        else
            t = next[t];
    }

    return next;
}

void testSort(){
    int n = 10;
    int *arr = createArray(n);
    // binaryInsertSort(arr, n);
    printArray(arr, n);
    // cout << insertSort(arr, n) << endl;
    mergeSort(arr, n);
    printArray(arr, n);
    delete[] arr;

}


int main() {

//    string s = "good";
//    int n = s.size();
//    int *next = new int[n];
//    getNext(s, next);
//    for (int i = 0; i < n; ++i) {
//        cout << next[i] << " " << endl;
//
//    }

//    string filename = "testG1.txt";
//    SparseGraph g1(13, false);
//    ReadGraph<SparseGraph> readGraph(g1, filename);
//    g1.show();
//    return 0;


//    char *p = "good";
//    buildNext(p);

    testSort();
}