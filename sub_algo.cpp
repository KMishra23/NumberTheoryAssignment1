#include "arithmetic.hpp"

number subtract(number *x, number *y)
{
    number res;

    number newX, newY;

    int decimalPosDiff;
    if(x->num.size() - x->basePower > y->num.size() - y->basePower) {
        decimalPosDiff = x->num.size() - x->basePower - y->num.size() + y->basePower;
        newX.base = x->base;
        newY.base = x->base;
        newX.basePower = x->basePower;
        newY.basePower = y->basePower;

        for(int i = 0; i < decimalPosDiff; i++) 
            newY.num.push_back(0);
        for(int i = 0; i < x->num.size(); i++)
            newX.num.push_back(x->num[i]);
        for(int i = 0; i < y->num.size(); i++) 
            newY.num.push_back(y->num[i]);
    }
    else {
        decimalPosDiff = y->num.size() - y->basePower - x->num.size() + x->basePower;
        newX.base = x->base;
        newY.base = x->base;
        newX.basePower = x->basePower;
        newY.basePower = y->basePower;

        for(int i = 0; i < decimalPosDiff; i++) 
            newX.num.push_back(0);
        for(int i = 0; i < x->num.size(); i++)
            newX.num.push_back(x->num[i]);
        for(int i = 0; i < y->num.size(); i++) 
            newY.num.push_back(y->num[i]);
    }
    //037.1347->basePower = 4 
    //128.12->basePower = 2

    if(x->basePower > y->basePower) {
        int powerDiff = x->basePower - y->basePower;
        for(int i = 0; i < powerDiff; i++)
            newY.num.push_back(0);
        newY.basePower = x->basePower;
    }
    else {
        int powerDiff = y->basePower - x->basePower;
        for(int i = 0; i < powerDiff; i++) 
            newX.num.push_back(0);
        newX.basePower = y->basePower;
    } 
    //012.3456
    //165.2547
    //036.3670

    res.base = x->base;
    res.basePower = newX.basePower;
    int temp, flag, carry = 0;
    for(int i = 0; i < newX.num.size(); i++)
        res.num.push_back(0);
    for(int i = newX.num.size() - 1; i >= 0; i--) {
        //printf("newX = %d\tnewY = %d\n",newX.num[i], newY.num[i]);
        if(newX.num[i] < newY.num[i]) { //if carry is required to progress
            temp = newX.num[i] + newX.base - newY.num[i] + carry;
            carry = -1;   
        }
        else if(carry == -1){
            temp = newX.num[i] - 1 - newY.num[i];
            carry = 0;
        }
        else {
            temp = newX.num[i] - newY.num[i];
            carry = 0;
        }
        res.num[i] = temp;
    }

    return res;
}