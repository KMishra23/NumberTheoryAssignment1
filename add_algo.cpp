#include "arithmetic.hpp"

number add(number *x, number *y)
{
    //assumming both are of the same base
    //assuming all basePower values are always negative but are stored as +ve vals to make it easier

    // int higherPower = (x->basePower >= y->basePower) ? (x->basePower) : (y->basePower);
    // int lowerPower = (x->basePower <= y->basePower) ? (x->basePower) : (y->basePower);

    //if x ka basepower is more(in -ve) than y ka basepower, then multiply both by x ka basepower in +ve or simply shift y by the difference
    //in their basepowers to the left and vice-versa

    //simply assuming that x ka basepower is more than y always, so comparing their basepowers and assigning new variables to each

    
    number a, b;
    if(x->basePower >= y->basePower) 
    {
        a = *x;
        b = *y;
    }
    else 
    {
        a = *y;
        b = *x;
    }

    // int longestNonDecimalNum = (a.num.size() - a.basePower >= b.num.size() - b.basePower) ? (a.num.size() - a.basePower) : (b.num.size() - b.basePower);
    // printf("longest non decimal num: %d\n", longestNonDecimalNum);
    //a = 137.1347
    //b = 128.12
    int basePowerDiff = a.basePower - b.basePower;
    //basePowerDiff = 2
    vector<int> newB;
    for(int i = 0; i < basePowerDiff; i++)
    {
        newB.push_back(0);
    }
    for(int i = 0; i < b.num.size(); i++)
    {
        newB.push_back(b.num[i]);
    }
    //newB = [1,2,8,1,2,0,0]; this is a reverse vector. So I am taking index 0 to be at right most pos
    printf("Number B is: ");
    for(int i = newB.size() - 1; i >= 0; i--)
    {
        printf("%d ", newB[i]);
    }
    printf("\n");
    printf("\n");

    printf("Number A is: ");
    for(int i = a.num.size() - 1; i >= 0; i--)
    {
        printf("%d ", a.num[i]);
    }
    printf("\n");
    printf("\n");

    b.num = newB;
    b.basePower = a.basePower;

    number res;
    int base = a.base;
    res.basePower = a.basePower;
    res.base = a.base;
    int carry = 0;

    //a = 137.1347
    //b = 128.12
    for(int i = 0; i < newB.size(); i++)
    {
        int temp;
        temp = a.num[i] + b.num[i] + carry;

        carry = 0;
        //in case of a carryover
        if(temp >= base)
        {
            carry = 1;
            temp = temp-base;
        }
        res.num.push_back(temp);
    }

    for(int i = res.num.size() - 1; i >= 0; i--)
    {
        printf("%d ", res.num[i]);
    }
    printf("\n");

    return res;
}
