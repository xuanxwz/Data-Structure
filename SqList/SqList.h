//
// Created by xuan on 19-2-11.
//

#ifndef CDS_SQLIST_H
#define CDS_SQLIST_H

#include <cstdlib>
#include "../config.h"

#define LIST_INIT_SIZE 100
#define LIST_INCREMENT 10

typedef int ElemType;
typedef struct {
    ElemType *elem;
    int length;
    int list_size;
} SqList;

Status InitList_sq(SqList &L) {
    L.elem = (ElemType *) malloc(LIST_INIT_SIZE * sizeof(ElemType));
    if (!L.elem)exit(OVERFLOW);
    L.length = 0;
    L.list_size = LIST_INIT_SIZE;
    return OK;
}

Status ListInsert_Sq(SqList &L, int i, ElemType e) {
    if (i < 1 || i > L.length + 1)
        return ERROR;
    // 扩容
    if (L.length > L.list_size) {
        auto *newbase = (ElemType *) realloc(L.elem, (L.list_size + LIST_INCREMENT) * sizeof(ElemType));
        if(!newbase)
            return OVERFLOW;
        L.elem = newbase;
        L.list_size += LIST_INCREMENT;
    }

    auto q = &(L.elem[i-1]);
    for (auto p=&(L.elem[L.length-1]); p>=q;--p)
        *(p+1) = *p;
    *q = e;
    ++L.length;
    return OK;
}


#endif //CDS_SQLIST_H
