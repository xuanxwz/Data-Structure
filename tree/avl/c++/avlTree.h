//
// Created by xuan on 19-2-17.
//

#ifndef CDS_AVLTREE_H
#define CDS_AVLTREE_H

#include <iostream>

using namespace std;

template<typename T>
class AVLTree {
    struct Node {
        T data;
        Node *left, *right;
        int height;

        Node(const T &key, Node *l, Node *r, int h = 0) {
            data = key;
            left = l;
            right = r;
            height = h;
        }
    };

    Node *root;


public:
    AVLTree(Node *t = NULL) { root = t; }

    ~AVLTree() {
        if (root)
            clear(root);
        root = NULL;
    }

    bool search(const T &k) const {
        Node *t = root;
        while (t != NULL && t->data != k)
            t->data > k ? t = t->left : t = t->right;
        return t != NULL;
    }

    void remove(const T &k) { remove(root, k); }

    void insert(const T &k) { insert(k, root); }

    void inOrderTraverse() const { inorder(root); }

private:
    void clear(Node *&t) {

    }

    int height(Node *t) const {
        return t ? t->height : -1;
    }

    int getBf(const Node *t) { // 求平衡因子
        return height(t->left) - height(t->height);
    }

    int max(int a, int b) {
        return (a > b) ? a : b;
    }

    T maxLeftTree(Node *root) const { // 求左子树的最大值
        while (root->right != NULL)
            root = root->right;
        return root->data;
    }

    T minRightTree(Node *root) const { // 求右子树的最大值
        while (root->left != NULL)
            root = root->left;
        return root->data;
    }

    void reBalance(Node *&t) { // 调整旋转
        int bf = getBf(t);
        if (bf > 1)
            getBf(t->left) > 0 ? LL(t) : LR(t);
        else if (bf < -1)
            getBf(t->right) > 0 ? RL(t) : RR(t);
    }

//    void LL(Node *&t) {
//        Node *temp = t->left;
//        t->left = temp->right;
//        temp->right = t;
//        t->height = max(height(t->left), height(t->right)) + 1;
//        temp->height = max(height(temp->left), height(temp->right)) + 1;
//        t = temp;
//    }
    void LL(Node *&A) {
        Node *B = A->left;
        A->left = B->right;
        B->right = A;
        A->height = max(height(A->left), height(A->right)) + 1;
        B->height = max(height(B->left), height(B->right)) + 1;
        A = B;
    }

//    void LR(Node *&A) {
//        Node *C, *B;
//        B = A->left;
//        C = B->right;
//        A->left = C->right;
//        B->right = C->left;
//        C->left = B;
//        C->right = A;
//
//        A = C;
//    }
    void LR(Node *&t) {
        RR(t->left);
        LL(t);
    }

    void RR(Node *&t) {
        Node *temp = t->right;
        t->right = temp->right;
        temp->right = t;
        t->height = max(height(t->left), height(t->height)) + 1;
        temp->height = max(height(temp->left), height(temp->right)) + 1;
        t = temp;
    }

    void RL(Node *&t) {
        LL(t->right);
        RR(t);
    }

    void insert(const T &k, Node *&t) {
        if (t == NULL)
            t = new Node(k, NULL, NULL);
        else if (k < t->data)
            insert(k, t->left);
        else if (t->data < k)
            insert(k, t->right);

        reBalance(t);
        t->height = max(height(t->left), height(t->right)) + 1;
    }

    void remove(Node *&t, const T &k) {
        if (t == NULL)
            return;

        if (k == t->data) {

            if (t->left != NULL && t->right != NULL) {

                if (getBf(t) > 0) {
                    t->data = maxLeftTree(t->left);
                    remove(t->left, t->data);
                } else {
                    t->data = minRightTree(t->right);
                    remove(t->right, t->data);
                }

            } else {
                Node *temp = t;
                t = t->left ? t->left : t->right;
                delete temp;
                temp = NULL;
            }


        } else if (k < t->data) {
            remove(t->left, k);
            reBalance(t);
        } else {
            remove(t->right, k);
            reBalance(t);
        }
    }

    void inOrder(Node *t) const {

    }
};

#endif //CDS_AVLTREE_H
