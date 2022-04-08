#include "arithmetic.hpp"

number::number(vector<int>& x, int basepower, int base)
{
    this->num = x;
    this->basePower = basepower;
    this->base = base;
}

number::number(long double x, int base)
{

}

number::number()
{}

number::~number()
{}

void number::removeZeroes() 
{
    int flag = 0;
    for(int i=0; i < num.size(); i++)
    {
        if(num[i]!=0)
        {
            flag = 1;
        }
    }
    if(flag != 0)
    {
        while(num[0]==0)
        {
            vector<int>::iterator it;
            it = num.begin();
            num.erase(it);
        }
    }    
}


void number::truncateDecimal(int precision) {
    if(precision >= basePower) return;
    int decStartIndex = num.size()-basePower;
    int decPrecisionReqd = decStartIndex + precision;
    for(int i = decPrecisionReqd; i < num.size(); i++) {
        num.pop_back();
        basePower--;
    }
}

void number::makeLengthEqual(number *x, number *y) {
    int diff = x->num.size() - y->num.size();
    if(diff > 0) {
        for(int i = 0; i < diff; i++) {
            y->num.push_back(0);
            y->basePower++;
        }
    }
    else {
        diff = -diff;
        for(int i = 0; i < diff; i++) {
            x->num.push_back(0);
            x->basePower++;
        }
    }
}

void number::removeDecZeroes() {
    int t = num.size()-1;
    for(int i = t; i >= 0; i--) {
        if(num[i] != 0) {
            break;
        }
        if(basePower == 0) break;
        basePower--;
        num.pop_back();
    }
}