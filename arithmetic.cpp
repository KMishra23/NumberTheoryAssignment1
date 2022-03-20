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
