//
// Created by xuan on 19-2-28.
//

#ifndef CDS_KMP3_H
#define CDS_KMP3_H

#include <cstring>

int *buildNext(char *p) {
    size_t m = strlen(p), j = 0;
    int *next = new int[m];
    int t = next[0] = -1;
    while (j < m - 1) {
        if (t < 0 || p[j] == p[t]) {
            ++j, ++t;
            next[j] = (p[j] != p[t]) ? t : next[t]; // 优化
        } else
            t = next[t];
    }

    return next;
}

int match(char *P, char *T) {
    int *next = buildNext(P);
    int n = (int) strlen(T), i = 0; // 长
    int m = (int) strlen(P), j = 0; // 短
    while (j < m && i < n) {
        if (j < 0 || T[i] == P[j]) {
            i++;
            j++;
        } else {
            j = next[j];
        }
    }
    delete[] next;
    return i - j;
}

#endif //CDS_KMP3_H
