#include "arithmetic.hpp"
#include <iostream>

int B = 10;

void copy(vector<int> &a, vector<int> &b, int i, int j)
{
    //cout<<"i: "<<i<<"  j:"<<j<<endl;
    for(int k = i; k < j; k++)
    {
        //cout<<"copying..."<<b[k]<<" to a"<<endl;
        a.push_back(b[k]);
    }
}

void prind(number &x)
{
    int decPoint = x.num.size() - x.basePower;
    for (int i = 0; i < x.num.size(); i++)
    {
        if(i == decPoint) cout << ". ";
        cout<<x.num[i]<<" ";
    }
    cout<<endl;
}

void prind2(number *x)
{
    int decPoint = x->num.size() - x->basePower;
    for (int i = 0; i < x->num.size(); i++)
    {
        if(i == decPoint) cout << ". ";
        cout<<x->num[i]<<" ";
    }
    cout<<endl;
}

void print2(number *x)
{
    for (int i = 0; i < x->num.size(); i++)
    {
        cout<<x->num[i]<<"";
    }
    cout<<endl;
}

void multiply(number *x, number *y, number *ret)
{
    if(x->num[0] * y->num[0] >= B)
    {
        ret->num.push_back((x->num[0] * y->num[0])/B);
        ret->num.push_back(x->num[0] * y->num[0]%B);
    }
    else
    {
        ret->num.push_back(x->num[0] * y->num[0]);
    }
}

void set_number(number *x, number *y)
{
    if(x->num.size()!=y->num.size())
    {
        if(x->num.size()>y->num.size())
        {
            if(x->num.size()%2!=0)
            {
                int y_size = y->num.size();
                x->num.insert(x->num.begin(), 0);
                y->num.insert(y->num.begin(), x->num.size() - y_size, 0);
            }
            else
            {
                int y_size = y->num.size();
                y->num.insert(y->num.begin(), x->num.size() - y_size, 0);
            }
        }
        else
        {
            if(y->num.size()%2!=0)
            {
                int x_size = x->num.size();
                y->num.insert(y->num.begin(), 0);
                x->num.insert(x->num.begin(), y->num.size() - x_size, 0);
            }
            else
            {
                int x_size = x->num.size();
                x->num.insert(x->num.begin(), y->num.size() - x_size, 0);                
            }
        }
    }
    else
    {
        if(x->num.size()!=1 && y->num.size()!=1)
        {
            if(x->num.size()%2!=0 && x->num.size()%2!=0)
            {
                x->num.insert(x->num.begin(), 0);
                y->num.insert(y->num.begin(), 0);
            }
        }
    }
}

void remove_zeroes(number *x)
{
    int flag = 0;
    for(int i=0; i<x->num.size(); i++)
    {
        if(x->num[i]!=0)
        {
            flag = 1;
        }
    }
    if(flag != 0)
    {
        while(x->num[0]==0)
        {
            vector<int>::iterator it;
            it = x->num.begin();
            x->num.erase(it);
        }
    }    
}

number karatsuba(number *x, number *y)
{
//    q++;
    //cout<<"entering karatsuba..."<<endl;
    if(x->num.size() == 1 && y->num.size() == 1)
    {
        //cout<<x->num[0] * y->num[0]<<endl;
        //cout<<"base case"<<endl;
        number ret;
        multiply(x, y, &ret);
        ret.base = x->base;
        //print(ret.num);
        return ret;
    }

    int m = min(x->num.size(), y->num.size());
    int k = floor(m/2);
    //cout<<"m : "<<m<<endl;

    number Xr, Yr, Xl, Yl;


    copy(Xr.num, x->num, 0, k);
//    print2(&Xr); cout<<"size Xr:"<<Xr.num.size()<<endl;
    copy(Yr.num, y->num, 0, k);
//    print2(&Yr); cout<<"size Yr:"<<Yr.num.size()<<endl;
    copy(Xl.num, x->num, k, x->num.size());
//    print2(&Xl); cout<<"size Xl:"<<Xl.num.size()<<endl;
    copy(Yl.num, y->num, k, y->num.size());
//    print2(&Yl); cout<<"size Yl:"<<Yl.num.size()<<endl;

    //print2(&Xr); cout<<" ---Xr:"<<endl;
    //print2(&Xl); cout<<" ---Xl:"<<endl;
   // print2(&Yr); cout<<" ---Yr:"<<endl;
    //print2(&Yl); cout<<" ---Yl:"<<endl;

    //cout<<endl;

    number Zr, Zl, Zrl;

    remove_zeroes(&Xl);
    remove_zeroes(&Yl);
    remove_zeroes(&Xr);
    remove_zeroes(&Yr);

    set_number(&Xl, &Yl);
    set_number(&Xr, &Yr);

    //print2(&Xr); cout<<" ---Xr:"<<endl;
    //print2(&Xl); cout<<" ---Xl:"<<endl;
    //print2(&Yr); cout<<" ---Yr:"<<endl;
    //print2(&Yl); cout<<" ---Yl:"<<endl;

    Zl = karatsuba(&Xl, &Yl);
    //cout<<"Zl : "; print2(&Zl); cout<<endl;
    Zr = karatsuba(&Xr, &Yr);
    //cout<<"Zr : "; print2(&Zr); cout<<endl;

    Xr.base = 10;
    Yr.base = 10;
    Xr.basePower = 0;
    Yr.basePower = 0;
    Xl.base = 10;
    Yl.base = 10;
    Xl.basePower = 0;
    Yl.basePower = 0;

    number Xrl = add(&Xr, &Xl);
    number Yrl = add(&Yr, &Yl);
    remove_zeroes(&Xrl);
    remove_zeroes(&Yrl);


//    for (auto i = 0; i <k; ++i)
//    {
//        Xrl.num.push_back(Xl.num[i] + Xr.num[i]);
//        Yrl.num.push_back(Yl.num[i] + Yr.num[i]);
//    }
    
    set_number(&Xrl, &Yrl);
//    print2(&Xrl);
//    print2(&Yrl);

    //cout<<"Xrl : "; print2(&Xrl); cout<<endl;
    //cout<<"Yrl : "; print2(&Yrl); cout<<endl;


    Zrl = karatsuba(&Xrl, &Yrl);
    //cout<<"Zrl : "; print2(&Zrl); cout<<endl;

//    remove_zeroes(&Zr);
//    remove_zeroes(&Zl);
//    remove_zeroes(&Zrl);
//
    Zr.base = 10;
    Zl.base = 10;
    Zr.basePower = 0;
    Zl.basePower = 0;

    number Zr_plus_Zl = add(&Zr, &Zl);

    Zrl.base = 10;
    Zr_plus_Zl.base = 10;
    Zrl.basePower = 0;
    Zr_plus_Zl.basePower = 0;    
    number Zrl_minus = subtract(&Zrl, &Zr_plus_Zl);///////////////////////////////////////////////////////Zrl - Zr_plus_Zl

    //cout<<"Zrl_minus"<<endl;
    //print2(&Zrl_minus);

    for(auto i = 0; i < m; ++i)
    {
        Zr.num.push_back(0);
    }

    for(auto i = 0; i < m/2; ++i)
    {
        Zrl_minus.num.push_back(0);
    }

    number result1 = add(&Zr, &Zrl_minus);
    number result = add(&result1, &Zl);

    //print2(&result);
    remove_zeroes(&result);
    //cout<<"result : ";
    return result;
}

// int main()
// {
//     vector<int> a = {8,0,0,0,0,0,6,1,8,6,5,2,1,4,2,2,1};
//     vector<int> b = {6,4,9,5,9,9,8,0,0,0,0,0,4,0,1,5,2,6,7,0,2,2,1}; 

//     number x, y;

//     copy(x.num, a, 0, a.size());
//     copy(y.num, b, 0, b.size());
//     cout<<"copied"<<endl;

// //    x.num.push_back(1);
// //    x.num.push_back(3);
// //    y.num.push_back(4);
// //    y.num.push_back(0);

//     x.base = 10;
//     y.base = 10;
//     x.basePower = 0;
//     y.basePower = 0;

//     prind2(&x);
//     prind2(&y);

//     number pee = add(&x, &y);
//     prind(pee);

//     set_number(&x, &y);

//     print2(&x);
//     print2(&y);

// //    number test = subtract(&x, &y);
// //    print2(&test);
// //    remove_zeroes(&test);
// //    print2(&test);


//     number z = karatsuba(&x, &y);


//     remove_zeroes(&x);
//     remove_zeroes(&y);

// //    print(x.num);
// //    print(y.num);

//     print2(&z);
// }