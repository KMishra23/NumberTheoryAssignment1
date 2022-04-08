#pragma once

#ifndef arithmetic_hpp
#define arithmetic_hpp

#include <stdio.h>
#include <vector>
#include <math.h>
#include <algorithm>
#include <iostream>

using namespace std;

class number
{
    public: 
        number(vector<int> &x, int basepower, int base);
        number(long double x, int base);
        number();
        ~number();
        void removeZeroes();
        void removeDecZeroes();
        void truncateDecimal(int precision);
        static void makeLengthEqual(number *x, number *y);
        void print();

        vector<int> num;
        int basePower;
        int base;
};

number convertToBase256(long double x);
number add(number *x, number *y);
number subtract(number *x, number *y);
number divide(number *x, number *y, int precision);
number sqrt1(number *x, int precision);
number karatsuba(number *x, number *y);
number piEst(int precision, int base);
void set_number(number *x, number *y);
void remove_zeroes(number *x);


#endif