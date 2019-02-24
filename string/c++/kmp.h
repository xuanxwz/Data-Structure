//
// Created by xuan on 19-2-23.
//

#ifndef CDS_KMP_H
#define CDS_KMP_H

#include <iostream>
#include <string>

using namespace std;

void getNext(const string &t, int *next) {
    int i = 0, j = -1;
    next[0] = -1;
    while (i < t.size() - 1) {
        if ((j == -1) || (t[i] == t[j])) {
            ++i, ++j;
//            if(t[i] != t[j])
//                next[i] = j;
//            else
//                next[i] = next[j];
            next[i] = j;
        } else {
            j = next[j];
        }
    }
}

int kmpFind(const string &s, const string &t, int pos) {
    if (t.empty())
        return 0;
    if (s.length() < t.length())
        return -1;
    int i = 0, j = 0;
    int *next = new int[t.size()];
    getNext(t, next);
    while (i < s.length() && j < t.size()) {
        if (j == -1 || s[i] == t[i]) {
            i++;
            j++;
        } else
            j = next[j];
    }
    delete[] next;
    return (j >= t.size()) ? i - t.size() : -1;

}

#endif //CDS_KMP_H
