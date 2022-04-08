#pragma once

#ifndef arithmetic_hpp
#define arithmetic_hpp

#include <stdio.h>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;

class number
{
    public: 
        number(vector<int> &x, int basepower, int base);
        number(long double x, int base);
        number();
        ~number();
        void removeDecZeroes();
        void truncateDecimal(int precision);

        vector<int> num;
        int basePower;
        int base;
};

number convertToBase256(long double x);
number add(number *x, number *y);
number subtract(number *x, number *y);
number divide(number *x, number *y, int precision);
number sqrt(number *x, int precision);
number karatsuba(number *x, number *y);
void set_number(number *x, number *y);
void remove_zeroes(number *x);


#endif