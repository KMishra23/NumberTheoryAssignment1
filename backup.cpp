#define lli long long int

#include "arithmetic.hpp"

number divide(number *x, number *y, int precision)
{   
    int base = x->base;
    number *newX = x;
    number *newY = y;
    number::makeLengthEqual(newX, newY);
    
    int finalPower = x->basePower - y->basePower;
    
    int t = precision;
    while(t--) newX->num.push_back(0);
    newX->basePower += precision;
    
    int k = newX->num.size();
    int l = newY->num.size();
    int m = k - l + 1;

    reverse(newX->num.begin(), newX->num.end());
    reverse(newY->num.begin(), newY->num.end());

    // printf("%d %d\n", newX->base, newX->basePower);
    // for(int i = 0; i < newX->num.size(); i++) {
    //     printf("%d ", newX->num[i]);
    // }
    // printf("\n");
    // printf("%d %d\n", newY->base, newY->basePower);
    // for(int i = 0; i < newY->num.size(); i++) {
    //     printf("%d ", newY->num[i]);
    // }
    // printf("\n");
    // if(k < l) { //x is smaller than y
    //     quo.num = x->num;
    //     quo.basePower = x->basePower;
    //     return quo;
    // }
    // if(k == l) {
    //     for(int i = 0; i < k; i++) {
    //         if(x->num[i] < y->num[i]) {
    //             //printf("here\n");
    //             quo.num = x->num;
    //             quo.basePower = x->basePower;
    //             return quo;
    //         }
    //         else if(x->num[i] > y->num[i]) 
    //             break;
    //     }
    // }    
    //printf("here\n");
    // x = {2, 4}, y = {6}
    // newX = {4, 2}, newY = {6}
    //rem = {4, 2, 0}
   
    vector<int> rNum(newX->num.begin(), newX->num.end());
    number *rem = new number(rNum, 0, base);
    rem->num.push_back(0);
    
    // printf("%d %d\n", rem->base, rem->basePower);
    // for(int i = 0; i < rem->num.size(); i++) {
    //     printf("%d ", rem->num[i]);
    // }
    // printf("\n");

    vector<int> qNum(m);
    number *quo = new number(qNum, finalPower, base);

    for(lli i = k-l; i >= 0; i--) {
        quo->num[i] = floor((float)((rem->num[i+l] * base + rem->num[i+l-1]) / (newY->num[l-1])));
        if(quo->num[i] >= base) 
            quo->num[i] = base - 1;     
        int carry = 0;
        for(lli j = 0; j <= l-1; j++) {
            lli temp = rem->num[i+j] - quo->num[i] * newY->num[j] + carry;
            if(temp < 0) {
                if(temp % base == 0) {
                    carry = temp / base;
                    rem->num[i+j] = 0;
                }
                else {
                    carry = -(abs(temp) / base + 1);
                    rem->num[i+j] = (abs(temp) / base + 1) * (base)-abs(temp);
                }
            }
            else {
                carry = temp / base;
                rem->num[i+j] = temp%base;
            }   
        rem->num[i+l] += carry;
        while(rem->num[i+l] < 0) {
            carry = 0;
            for(lli j = 0; j <= l-1; j++) {
                lli temp = rem->num[i+j] + newY->num[j] + carry;
                if(temp < 0) {
                    // carry = temp / x->base;
                    // rem->num[i+j] = 0;
                    if(temp % base == 0) {
                        carry = temp / base;
                        rem->num[i+j] = 0;
                    }
                    else {
                        carry = -(abs(temp) / base + 1);
                        rem->num[i+j] = (abs(temp) / base + 1) * base - abs(temp);
                    }
                }
                else {
                    carry = temp / base;
                    rem->num[i+j] = temp%base;
                }
            }
            rem->num[i+l] += carry;
            quo->num[i]--;
        }
        }
    }
     

    // for(int i = k-l; i >= 0; i--) {
    //     if(i > quo->num.size()) 
    //         quo->num.resize(i+1);
    //     quo->num[i] = floor((float)((rem->num[i+l]*base + rem->num[i+l-1])/newY.num[l-1]));
    //     if(quo->num[i] >= base) 
    //         quo->num[i] = base - 1;
    //     carry = 0;
    //     for(int j = 0; j < l; j++) {
    //         int temp = rem->num[i+j] - quo->num[i] * newY.num[i] + carry;
    //         int a,b;
    //         if(temp >= 0) {
    //             a = temp/base;
    //             b = temp%base;
    //         }
    //         else {
    //             if(temp%base == 0) {
    //                 a = temp/base;
    //                 b = 0;
    //             }
    //             else {
    //                 a = temp/base - 1;
    //                 b = base + temp%base;
    //             }
    //         }
    //         carry = a;
    //         rem->num[i+j] = b;
    //     }
    //     rem->num[i+l] += carry;
    //     while(rem->num[i+l] < 0) {
    //         carry = 0;
    //         for(int j = 0; j <= l-1; j++) {
    //             int temp = rem->num[i+j] + newY.num[j] + carry;
    //             int a,b;
    //             if(temp >= 0) {
    //                 a = temp/base;
    //                 b = temp%base;
    //             }
    //             else {
    //                 if(temp%base == 0) {
    //                     a = temp/base;
    //                     b = 0;
    //                 }
    //                 else {
    //                     a = temp/base - 1;
    //                     b = base + temp%base;
    //                 }
    //             }
    //             carry = a;
    //             rem->num[i+j] = b;
    //         }
    //         rem->num[i+1] += carry;
    //         quo->num[i] -= 1;
    //     }
    // }

    // if(quo->num.size() == 0) quo->num.push_back(0);


    // free(&newX);
    // free(&newY);
    // free(&rem);

    reverse(quo->num.begin(), quo->num.end());
    quo->basePower = finalPower + precision;
    return *quo;
}