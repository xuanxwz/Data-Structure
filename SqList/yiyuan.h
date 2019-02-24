//
// Created by xuan on 19-2-11.
//

#ifndef CDS_YIYUAN_H
#define CDS_YIYUAN_H

#include <cstdlib>
#include <cstdio>

typedef struct Polynode {
    int coef;
    int exp;
    Polynode *next;
} Polynode, *Polylist;

Polylist polycreate() {
    // 建立一元多项式链式存储算法

    Polynode *head, *rear, *s;
    head = (Polynode *) malloc(sizeof(Polynode));
    rear = head;
    int c, e;
    scanf("%d %d", &c, &e);// 多项式系数和指数
    while (c != 0) {
        s = (Polynode *) malloc(sizeof(Polynode));
        s->coef = c;
        s->exp = e;
        rear->next = s;
        rear = s;
        scanf("%d %d", &c, &e);
    }
    rear->next = NULL;
    return head;
}

void polyadd(Polylist polylista, Polylist polylistb) {
    // 两个多项式相加, 存在a中
    Polynode *p, *q, *tail, *temp;
    int sum;
    p = polylista->next;
    q = polylistb->next;
    tail = polylista;

    while (p != NULL && q != NULL) {
        if (p->exp < q->exp) {
            tail->next = p;
            tail = p;
            p = p->next;
        } else if (p->exp == q->exp) {
            sum = p->coef + q->coef;
            if (sum != 0) {
                p->coef = sum;
                tail->next = p;
                tail = p;
                p = p->next;
                temp = q;
                q = q->next;
                free(temp);

            } else {
                temp = p;
                p = p->next;
                free(temp);
                temp = q;
                q = q->next;
                free(temp);
            }
        } else {
            tail->next = q;
            tail = q;
            q = q->next;

        }
    }

    if (p!=NULL)
        tail->next = p;
    else
        tail->next = q;
}

#endif //CDS_YIYUAN_H
