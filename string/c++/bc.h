//
// Created by xuan on 19-2-28.
//

#ifndef CDS_BC_H
#define CDS_BC_H

#include <cstring>

int *buildBC(char *p){
    int *bc = new int[256];
    for (int j = 0; j < 256; ++j) {
        bc[j] = -1;
    }
    int m = (int)strlen(p);
    for (int i = 0; i < m; ++i) {
        bc[p[i]] = i;
    }
    return bc; // 画家算法
}

#endif //CDS_BC_H
