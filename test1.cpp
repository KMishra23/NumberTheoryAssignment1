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

    // vector<int> aNum = {3,4,1,4,5,8,3,3,7,1,9,4,1,8,3,0,3,0,2,4,3,6,2,6,9,3,1,8,0,4,3,2,7,9,3,2,6,9,4,2,5,8,9,4,2,4,6,8,8,5,4,7,9,4,8};
    // number *a = new number(aNum, 0, 10);

    // vector<int> bNum;
    // bNum.push_back(3);
    // bNum.push_back(7);
    // bNum.push_back(1);
    // bNum.push_back(3);
    // bNum.push_back(4);
    // bNum.push_back(7);
    // number *b = new number(bNum, 4, 10);

    // vector<int> cNum = {1,3,4};
    // number *c = new number(cNum, 0, 10);

    // vector<int> dNum = {1,3,0,0};
    // number *d = new number(dNum, 2, 10);

    // vector<int> cNum = {2 ,8, 2, 8, 4, 3, 1, 3, 7 ,2, 5, 4, 9, 0, 1, 9, 6, 0, 7 ,8 ,4 ,3 ,1 ,3 ,7 ,2 ,5 ,4 ,9 ,0 ,1 ,9 ,6 ,0 ,7 ,8 ,4};
    // number *c = new number(cNum, 0, 10);

    // vector<int> dNum = {5};
    // number *d = new number(dNum, 0, 10);

    //number temp = *d;

    // vector<int> fNum = {3};
    // number *f = new number(fNum, 0, 10);

    // number temp;
    // temp = *f;

    // number res = add(c, d);
    // number res = subtract(c, d);

    //number res = divide(c, d, 10);
    //res.removeZeroes();

    // printf("Num c basePower: %d\t",c->basePower);
    // for(int i = 0; i < c->num.size(); i++) {
    //     if(i == c->num.size()-c->basePower) printf(".");
    //     printf("%d",c->num[i]);
    // }
    // printf("\n");
    // printf("Num d basePower: %d\t",d->basePower);
    // for(int i = 0; i < d->num.size(); i++) {
    //     if(i == d->num.size()-d->basePower) printf(".");
    //     printf("%d",d->num[i]);
    // }
    // printf("\n");

    // number res;
    // set_number(d, c);
    // res = karatsuba(d, c);
    // res.basePower = c->basePower + d->basePower;
    
    number res;
    int a,b,c;
    cin >> a >> b >> c;
    if(a == 1) {
        res = piEst(b, 10);
    } 

    else if (a == 2) {
        //c = pow(2,c);
        vector<int> eNum = {2};
        number *e = new number(eNum, 0, 10);
        res = sqrt1(e, b);
    }

    
    

    int decPoint = res.num.size() - res.basePower;
    // printf("res BasePower = %d\tBase = %d\n", res.basePower, res.base);
    for(int i = 0; i < res.num.size(); i++) {
        if(i == decPoint) printf(".");
        printf("%d",res.num[i]);
    }
    printf("\n");
}
