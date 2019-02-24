//
// Created by xuan on 19-2-23.
//

#ifndef CDS_CALCULATOR_H
#define CDS_CALCULATOR_H

#include <iostream>
#include <stack>
#include <string>
#include <cstring>

using namespace std;

class calculator {
private:
    stack<char> optr;
    stack<double> opnd;
    string infix;
    string postfix;
    int size;
public:
    calculator(const string &s) {
        size = s.size();
        postfix = "";
        infix = s;
    }
    calculator(char* s) {
        size_t siz = strlen(s);
        postfix = "";
        infix = s;
    }

    double getNum(string s, int &i){
        double num1=0, num2 = 0, num;
        int j=0;

    }
};

class divideByZero : public exception {
public:
    const char *what() const throw() {
        return "error! DIVIDE by zero!";
    }
};

#endif //CDS_CALCULATOR_H
