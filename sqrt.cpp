#include "arithmetic.hpp"

number sqrt(number *r, int precision) 
{
    number x1, x2;
    x1 = *r;

    vector<int> hNum = {5};
    number *half = new number(hNum, 1, r->base);

    //number temp = divide(r, &x1, precision);
    number temp;

    int t = log(precision*8);
    while(t--) {

            printf("\n\t-----Iteration Number: %d-----\n\n ",int(log(precision*8))-t);

            printf("start\n");
            printf("Num X1 basePower: %d\tBase: %d\t val: ",x1.basePower, x1.base);
            for(int i = 0; i < x1.num.size(); i++) {
                if(i == x1.num.size()-x1.basePower) printf(".");
                printf("%d ",x1.num[i]);
            }
            printf("\n");
            printf("Num r basePower: %d\tBase: %d\t val: ",r->basePower, r->base);
            for(int i = 0; i < r->num.size(); i++) {
                if(i == r->num.size()-r->basePower) printf(".");
                printf("%d ",r->num[i]);
            }
            printf("\n");
            

        temp = divide(r, &x1, precision);
        //temp.removeDecZeroes();
        //temp.truncateDecimal(precision);
            
            printf("here1\n");
            printf("Divide basePower: %d\tBase: %d\t val: ",temp.basePower, temp.base);
            for(int i = 0; i < temp.num.size(); i++) {
                if(i == temp.num.size()-temp.basePower) printf(".");
                printf("%d ",temp.num[i]);
            }
            printf("\n");
            

        temp = add(&temp, &x1);
        //temp.removeDecZeroes();
        //temp.truncateDecimal(precision);
            
            printf("here2\n");
            printf("Add basePower: %d\tBase: %d\t val: ",temp.basePower, temp.base);
            for(int i = 0; i < temp.num.size(); i++) {
                if(i == temp.num.size()-temp.basePower) printf(".");
                printf("%d ",temp.num[i]);
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
        //printf("temp2 Base: %d\n",temp2.base);
        temp = temp2;
        temp.truncateDecimal(precision);
        //temp.truncateDecimal(precision);
        //temp.removeDecZeroes();

            printf("here3\n");
            printf("Multiply basePower: %d\tBase: %d\t val: ",temp.basePower, temp.base);
            for(int i = 0; i < temp.num.size(); i++) {
                if(i == temp.num.size()-temp.basePower) printf(".");
                printf("%d ",temp.num[i]);
            }
            printf("\n");
        
        x1 = temp;
    }

    //r->num[0] = {1};
    
    return temp;
}

//xn+1 = 1/2(xn + R/xn)