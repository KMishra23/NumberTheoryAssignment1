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

void number::removeDecZeroes() 
{
    //printf("BasePower: %d\t Size: %d\n",t->basePower, t->num.size());
    for(int i = num.size()-1; i >= num.size()-basePower; i--) {
        if(num[i] != 0) {
            break;
        }
        num.pop_back();
        basePower--;
    }
}


void number::truncateDecimal(int precision) {
    for(int i = num.size()-1; i >= num.size() - basePower + precision; i--) {
        num.pop_back();
    }
}