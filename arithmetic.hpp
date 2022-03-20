#pragma once

#ifndef arithmetic_hpp
#define arithmetic_hpp

#include <stdio.h>
#include <vector>
#include <math.h>

using namespace std;

class number
{
    public: 
        number(vector<int> &x, int basepower, int base);
        number(long double x, int base);
        number();
        ~number();

        vector<int> num;
        int basePower;
        int base;
};

number convertToBase256(long double x);
number add(number *x, number *y);
number subtract(number *x, number *y);
number multiply(number *x, number *y);
number divide(number *x, number *y);
number squrt(number *x);


#endif