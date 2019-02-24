//
// Created by xuan on 19-2-11.
//

#ifndef CDS_SSTRING_H
#define CDS_SSTRING_H

#include <stdio.h>
#include <malloc.h>

#define MAXLEN 40
typedef struct {
    char ch[MAXLEN];
    int len;
} SString; //顺序串

int StrInsert(SString *s, int pos, SString t) {
    if (pos < 0 || pos > s->len)
        return 0;
    int i;
    if (s->len + t.len <= MAXLEN) {
        for (i = s->len + t.len - 1; i >= t.len; i--)
            s->ch[i] = s->ch[i - t.len];
        for (i = 0; i < t.len; i++)
            s->ch[i + pos] = t.ch[i];
        s->len += t.len;
    } else if (pos + t.len <= MAXLEN) {

    } else {

    }
}

int StrDelete(SString *s, int pos, int len) {
    if (pos < 0 || (pos + len) > s->len)
        return 0;
    for (int i = pos + len; i < s->len; ++i) {
        s->ch[i - len] = s->ch[i];
    }
    s->len -= len;
    return 1;
}

int StrIndex1(SString s, int pos, SString t) {
    // brute-force算法  暴力解法  双循环
}


typedef struct {
    char *ch;
    int len;
} HString;  // 堆串

int StrInsertH(HString *s, int pos, HString *t) {
    int i;
    char *temp;
    if (pos < 0 || pos > s->len || s->len == 0)
        return 0;
    temp = (char *) malloc(s->len + t->len);
    if (temp == NULL)
        return 0;
    for (i = 0; i < pos; i++)
        temp[i] = s->ch[i];
    for (i = 0; i < t->len; i++)
        temp[i + pos] = t->ch[i];
    for (i = pos; i < s->len; i++)
        temp[i + t->len] = s->ch[i];
    s->len += t->len;
    free(s->ch);
    s->ch = temp;
    return 1;
}

int StrDeleteH(HString *s, int pos, int len) {
    int i;
    char *temp;
    if (pos < 0 || (pos + len) < s->len)
        return 0;
    temp = (char *) malloc(s->len - len);
    if (temp == NULL)
        return 0;
    for (i = 0; i < pos; i++)
        temp[i] = s->ch[i];
    for (i = pos; i < s->len - len; i++)
        temp[i] = s->ch[i + len];
    s->len -= len;
    free(s->ch);
    s->ch = temp;
    return 1;
}

#endif //CDS_SSTRING_H
