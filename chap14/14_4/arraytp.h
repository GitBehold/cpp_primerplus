#ifndef ARRAYTP_H_
#define ARRAYTP_H_

#include <iostream>
#include <cstdlib>

template <class T,int n>    //指定类型为int ,这种指定特殊的类型而不是用作泛型名的称为非类型参数或者叫 表达式参数.
class ARRAYTP
{
private:
    T ar[n];
public:
    ARRAYTP(){};
    explicit ARRAYTP(const T &v);
    virtual T & operator[](int i);
    virtual T operator[](int i) const;

};


template <class T,int n>
ARRAYTP<T,n>::ARRAYTP(const T &v)
{
    for(int i = 0 ; i < n ;i++)
        ar[i] = v;
}


template <class T,int n>
T & ARRAYTP<T,n>::operator[](int i)
{
    if(i < 0 || i >= n)
    {
        std::cerr << "Error in array limits: " << i
                  << " is out of range\n";
        std::exit(EXIT_FAILURE);
    }
    return ar[i];
}

template <class T,int n>
T ARRAYTP<T,n>::operator[](int i) const
{
    if(i < 0 || i >= n)
    {
        std::cerr << "Error in array limits: " << i
                << " is out of range\n";
        std::exit(EXIT_FAILURE);
    }
    return ar[i];
}
#endif