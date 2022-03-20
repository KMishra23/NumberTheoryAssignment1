#include <iostream>
#include <stdio.h>
#include <vector>
#include <math.h>
#include "arithmetic.hpp"

using namespace std;

int main()
{
    // long double a = sqrt(2);
    // long double b = 0;
    // long double p = 2 + a;

    // for(int i = 0; i < 5; i++)
    // {
    //     long double anew, bnew, pnew;
    //     anew = (sqrt(a) + 1/sqrt(a))/2;
    //     bnew = ((1 + b)*sqrt(a))/(a + b);
    //     pnew = ((1 + anew)*p*bnew)/(1 + bnew);
    //     printf("%.16Lf\n", pnew);

    //     a = anew;
    //     b = bnew;
    //     p = pnew;
    // }

    vector<int> aNum;
    aNum.push_back(2);
    aNum.push_back(1);
    aNum.push_back(8);
    aNum.push_back(2);
    aNum.push_back(1);
    aNum.push_back(2);
    aNum.push_back(5);
    aNum.push_back(6);
    number *a = new number(aNum, 2, 10);

    vector<int> bNum;
    bNum.push_back(7);
    bNum.push_back(4);
    bNum.push_back(3);
    bNum.push_back(1);
    bNum.push_back(7);
    bNum.push_back(3);
    bNum.push_back(1);
    number *b = new number(bNum, 4, 10);

    number res = add(a, b);
}
