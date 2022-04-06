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
    aNum.push_back(1);
    aNum.push_back(2);
    aNum.push_back(8);
    aNum.push_back(1);
    aNum.push_back(2);

    number *a = new number(aNum, 2, 10);

    vector<int> bNum;
    bNum.push_back(3);
    bNum.push_back(7);
    bNum.push_back(1);
    bNum.push_back(3);
    bNum.push_back(4);
    bNum.push_back(7);
    number *b = new number(bNum, 4, 10);

    vector<int> cNum;
    cNum.push_back(4);
    cNum.push_back(6);
    cNum.push_back(3);
    cNum.push_back(6);
    cNum.push_back(7);
    number *c = new number(cNum, 3, 10);

    vector<int> dNum;
    dNum.push_back(3);
    dNum.push_back(7);
    dNum.push_back(1);
    dNum.push_back(3);
    dNum.push_back(4);
    dNum.push_back(7);
    number *d = new number(dNum, 4, 10);

    number res1 = add(a, b);
    number res = subtract(&res1, c);

    int decPoint = res.num.size() - res.basePower;
    printf("res BasePower = %d\tBase = %d\n", res.basePower, res.base);
    for(int i = 0; i < res.num.size(); i++) {
        if(i == decPoint) printf(". ");
        printf("%d ",res.num[i]);
    }
    printf("\n");
}
