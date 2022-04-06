#include "arithmetic.hpp"

number multiply(number *x, number *y)
{
    if(x->num.size() == 1 && y->num.size() == 1)
    {
        int res = x->num[0] * y->num[0];
        
        vector<int> fRes;
        fRes.push_back(res&x->base);
        if(res >= x->base)
        {
            res /= x->base;
            fRes.push_back(res);
        }

        number actualRes;
        actualRes.base = x->base;
        actualRes.
    }
}

// 4 bits: 2 and 3 -> 1, 4, 16
// 2 bits: 1, 2, 4
// 10bits: 1, 10, 100


//