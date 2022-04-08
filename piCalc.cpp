#include "arithmetic.hpp"

number piEst(int precision, int base) 
{
    number a0, a1, b1, p0, p1;
    
    vector<int> num2 = {2};
    number *n2 = new number(num2, 1, base);
    a0 = sqrt1(n2, precision);
    
    vector<int> b0num = {0};
    number *zeroNum = new number(b0num, 1, base);
    number b0 = *zeroNum;

    p0 = add(&a0, n2);
    
    number temp1, temp2, rootAn;
    int t = ceil(precision * log2(10))/base;
    
    vector<int> oneNum = {1};
    number *one = new number(oneNum, 1, base);
    int flag = 1;
    // printf("%d\n", t);
    while(t--) {

        // cout << "here" << endl;
        rootAn = sqrt1(&a0, precision);
        // cout << "here" << endl;
        temp1 = divide(one, &rootAn, precision);
        // cout << "here" << endl;
        temp1 = add(&a0, &temp1);
        // cout << "here" << endl;
        a1 = divide(&temp1, n2, precision);
        // cout << "here" << endl;
        // a1.print();

        if(flag == 1) {
            flag = 0;
            temp1 = *one;
        }
        else temp1 = add(one, &b0);
        // cout << "here2" << endl;
        set_number(&rootAn, &temp1);
        // cout << "here2" << endl;
        temp2 = karatsuba(&rootAn, &temp1);
        // cout << "here2" << endl;
        temp2.truncateDecimal(precision);
        // cout << "here2" << endl;
        temp1 = add(&a0, &b0);
        // cout << "here2" << endl;
        b1 = divide(&temp2, &temp1, precision);
        // cout << "here2" << endl;
        // b1.print();

        temp1 = add(one, &a1);
        // cout << "here3" << endl;
        set_number(&temp1, &p0);
        // cout << "here3" << endl;
        temp2 = karatsuba(&temp1, &p0);
        // cout << "here3" << endl;
        temp2.truncateDecimal(precision);
        // cout << "here3" << endl;
        set_number(&temp2, &b1);
        // cout << "here3" << endl;
        temp1 = karatsuba(&temp2, &b1);
        // cout << "here3" << endl;
        temp1.truncateDecimal(precision);
        // cout << "here3" << endl;
        temp2 = add(one, &b1);
        // cout << "here3" << endl;
        
        temp2.removeZeroes();
        temp1.removeDecZeroes();
        temp1.removeZeroes();
        temp2.removeDecZeroes();
        // temp1.print();
        // temp2.print();
        p1 = divide(&temp1, &temp2, precision);
        //cout << "here3      " << t << endl;

        a0 = a1;
        b0 = b1;
        p0 = p1;
        //cout << "PI" << endl;
        // p1.print();
    }

    return p1;
}