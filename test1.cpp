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

    vector<int> aNum = {3,4,1,4,5,8,3,3,7,1,9,4,1,8,3,0,3,0,2,4,3,6,2,6,9,3,1,8,0,4,3,2,7,9,3,2,6,9,4,2,5,8,9,4,2,4,6,8,8,5,4,7,9,4,8};
    number *a = new number(aNum, 0, 10);

    vector<int> bNum;
    bNum.push_back(3);
    bNum.push_back(7);
    bNum.push_back(1);
    bNum.push_back(3);
    bNum.push_back(4);
    bNum.push_back(7);
    number *b = new number(bNum, 4, 10);

    // vector<int> cNum = {2,4,1,7,3,8,3,5,1,8,3,9,2};
    // number *c = new number(cNum, 0, 10);

    // vector<int> dNum = {4,1,5,2,7,4,5,6,2,6,1};
    // number *d = new number(dNum, 0, 10);

    vector<int> cNum = {2};
    number *c = new number(cNum, 0, 10);

    vector<int> dNum = {1,4,1,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,5};
    number *d = new number(dNum, 20, 10);

    // vector<int> fNum = {3};
    // number *f = new number(fNum, 0, 10);

    // number temp;
    // temp = *f;

    //number res = add(a, b);
    //number res = subtract(&res1, c);

    //number res = divide(c, d, 1000);

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

    vector<int> eNum = {2};
    number *r = new number(eNum, 0, 10);
    // number res = sqrt(e, 20);
    number x1, x2;
    x1 = *r;

    vector<int> hNum = {5};
    number *half = new number(hNum, 1, r->base);

    //number temp = divide(r, &x1, precision);
    number temp;
    int precision = 10;
    int t = 5;
    while(t--) {
        
            printf("\n\t-----Iteration Number: %d-----\n\n ",5-t);

            printf("start\n");
            printf("Num X1 basePower: %d\tBase: %d\t val: ",x1.basePower, x1.base);
            for(int i = 0; i < x1.num.size(); i++) {
                if(i == x1.num.size()-x1.basePower) printf(".");
                printf("%d",x1.num[i]);
            }
            printf("\n");
            printf("Num r basePower: %d\tBase: %d\t val: ",r->basePower, r->base);
            for(int i = 0; i < r->num.size(); i++) {
                if(i == r->num.size()-r->basePower) printf(".");
                printf("%d",r->num[i]);
            }
            printf("\n");
            

        temp = divide(r, &x1, precision);
        temp.removeDecZeroes();
        temp.truncateDecimal(precision);
            
            printf("here1\n");
            printf("Divide basePower: %d\tBase: %d\t val: ",temp.basePower, temp.base);
            for(int i = 0; i < temp.num.size(); i++) {
                if(i == temp.num.size()-temp.basePower) printf(".");
                printf("%d",temp.num[i]);
            }
            printf("\n");
            

        temp = add(&temp, &x1);
        temp.removeDecZeroes();
        temp.truncateDecimal(precision);
            
            printf("here2\n");
            printf("Add basePower: %d\tBase: %d\t val: ",temp.basePower, temp.base);
            for(int i = 0; i < temp.num.size(); i++) {
                if(i == temp.num.size()-temp.basePower) printf(".");
                printf("%d",temp.num[i]);
            }
            printf("\n");
            
        number temp2;
        set_number(&temp, half);
        temp2 = karatsuba(half, &temp);
         
            // printf("temp 2Multiply basePower: %d\tBase: %d\t val: ",temp2.basePower, temp2.base);
            // for(int i = 0; i < temp2.num.size(); i++) {
            //     if(i == temp2.num.size()-temp2.basePower) printf(".");
            //     printf("%d",temp2.num[i]);
            // }
            // printf("\n");

        temp2.basePower = temp.basePower + half->basePower;
        printf("temp2 Base: %d\n",temp2.base);
        temp = temp2;
        temp.truncateDecimal(precision);
        temp.removeDecZeroes();

            printf("here3\n");
            printf("Multiply basePower: %d\tBase: %d\t val: ",temp.basePower, temp.base);
            for(int i = 0; i < temp.num.size(); i++) {
                if(i == temp.num.size()-temp.basePower) printf(".");
                printf("%d",temp.num[i]);
            }
            printf("\n");

        x1 = temp;
    }
    number res = temp;

    int decPoint = res.num.size() - res.basePower;
    printf("res BasePower = %d\tBase = %d\n", res.basePower, res.base);
    for(int i = 0; i < res.num.size(); i++) {
        if(i == decPoint) printf(". ");
        printf("%d ",res.num[i]);
    }
    printf("\n");
}
