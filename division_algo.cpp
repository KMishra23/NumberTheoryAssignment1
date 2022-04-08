#include "arithmetic.hpp"

number divide(number *x, number *y, int precision)
{   
    number quo;
    quo.basePower = x->basePower;
    quo.base = x->base;
    number newX, newY;
    newX = *x;
    newY = *y;
    
    int finalPower = x->basePower - y->basePower;
    
    int t = precision;
    while(t--) newX.num.push_back(0);
    newX.basePower += precision;
    
    int k = newX.num.size();
    int l = newY.num.size();
    int m = k - l + 1;

    reverse(newX.num.begin(), newX.num.end());
    reverse(newY.num.begin(), newY.num.end());
    // printf("%d %d\n", newX.base, newX.basePower);
    // for(int i = 0; i < newX.num.size(); i++) {
    //     printf("%d ", newX.num[i]);
    // }
    // printf("\n");
    // printf("%d %d\n", newY.base, newY.basePower);
    // for(int i = 0; i < newY.num.size(); i++) {
    //     printf("%d ", newY.num[i]);
    // }
    // printf("\n");

    if(k < l) { //x is smaller than y
        quo.num = x->num;
        quo.basePower = x->basePower;
        return quo;
    }

    if(k == l) {
        for(int i = 0; i < k; i++) {
            if(x->num[i] < y->num[i]) {
                //printf("here\n");
                quo.num = x->num;
                quo.basePower = x->basePower;
                return quo;
            }
            else if(x->num[i] > y->num[i]) 
                break;
        }
    }    
    //printf("here\n");
    // x = {2, 4}, y = {6}
    // newX = {4, 2}, newY = {6}
    //rem = {4, 2, 0}
    number rem;
    rem.base = x->base;
    for(int i = 0; i < k; i++) {
        rem.num.push_back(newX.num[i]);
    }
    rem.num.push_back(0);
    // printf("%d %d\n", rem.base, rem.basePower);
    // for(int i = 0; i < rem.num.size(); i++) {
    //     printf("%d ", rem.num[i]);
    // }
    // printf("\n");

    for(int i = 0; i < m; i++) {
        quo.num.push_back(0);
    }
    int carry = 0, temp = 0;
    for(int i = k-l; i >= 0; i--) {
        quo.num[i] = floor((float)((rem.num[i+l] * x->base + rem.num[i+l-1]) / (newY.num[l-1])));
        if(quo.num[i] >= x->base) 
            quo.num[i] = x->base - 1;
        
        carry = 0;
        for(int j = 0; j < l; j++) {
            temp = rem.num[i+j] - quo.num[i] * newY.num[j] + carry;
            if(temp < 0) {
                if(temp % x->base == 0) {
                    carry = temp / x->base;
                    rem.num[i+j] = 0;
                }
                else {
                    carry = -(abs(temp) / x->base + 1);
                    rem.num[i+j] = (abs(temp) / x->base + 1) * x->base - abs(temp);
                }
            }
            else {
                carry = temp / x->base;
                rem.num[i+j] = temp%x->base;
            }
        }

        rem.num[i+l] += carry;
        while(rem.num[i+l] < 0) {
            carry = 0;
            for(int j = 0; j < l; j++) {
                temp = rem.num[i+j] + newY.num[j] + carry;
                if(temp < 0) {
                    carry = temp / x->base;
                    rem.num[i+j] = 0;
                    if(temp & x->base == 0) {
                        carry = temp / x->base;
                        rem.num[i+j] = 0;
                    }
                    else {
                        carry = -(abs(temp) / x->base + 1);
                        rem.num[i+j] = (abs(temp) / x->base + 1) * x->base - abs(temp);
                    }
                }
                else {
                    carry = temp / x->base;
                    rem.num[i+j] = temp%x->base;
                }
            }
            rem.num[i+l] += carry;
            quo.num[i]--;
        }
    }   
    
    reverse(quo.num.begin(), quo.num.end());
    quo.basePower = finalPower + precision;
    return quo;
}