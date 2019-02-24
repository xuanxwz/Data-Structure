#include <stdio.h>
#include <string>

#include "string/c++/kmp.h"
#include "graph/c++/DenseGraph.h"
#include "graph/c++/SparseGraph.h"
#include "graph/c++/ReadGraph.h"

using namespace std;

int main() {

//    string s = "good";
//    int n = s.size();
//    int *next = new int[n];
//    getNext(s, next);
//    for (int i = 0; i < n; ++i) {
//        cout << next[i] << " " << endl;
//
//    }

    string filename = "testG1.txt";
    SparseGraph g1(13, false);
    ReadGraph<SparseGraph> readGraph(g1, filename);
    g1.show();
    return 0;
}