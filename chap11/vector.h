#ifndef _VECTOR_H_
#define _VECTOR_H_
#include <iostream>
namespace VECTOR
{
    class Vector
    {
    
    public:
        enum Mode{RECT,POL};

    private:
        double x;
        double y;
        double mag;
        double ang;



    public:
        Vector(/* args */);
        Vector(double n1,double n2,Mode form = RECT);
        void reset(double n1,double n2,Mode form = RECT);
        ~Vector();
                void set_mag();
        void set_ang();
        void set_x();
        void set_y();
        double xval() const {return x;};
        double yval() const {return y;};
        double magval() const {return mag;};
        double angval() const {return ang;};

        void polar_mode();  //set mode to POL
        void rect_mode();

        Vector operator+(const Vector &b) const;    //第一个vector就是参数的vector ,就是调用这个＋的类对象
        Vector operator-(const Vector &b) const;
        Vector operator-()const;
        Vector operator*(double n) const;
                Mode mode;


    //friend
        friend Vector operator*(double n,const Vector &a);
        friend std::ostream & operator<<(std::ostream &os,const Vector & v);
    };

    //end Namespace
}

class Vector{

    public:
        enum { LENGTH = 14};
        static const int Lengthl = 15;
        Vector();
        Vector(int a,int b);
        Vector(int a);
        ~Vector();

    public:
        Vector operator<<(Vector &);

    public:
        int chang;
        int kuan;


    private:

};


class Car
{
private:
    /* data */
public:
    Car(/* args */);
    ~Car();
};

Car::Car(/* args */)
{
}

Car::~Car()
{
}


class Timer
{
private:
    /* data */
    int hour;
    int min;
    int sec;
public:
    Timer(/* args */);
    ~Timer();
    void setTimer(int h,int m,int s);
    int getTimerHour(){return hour;};
    int getTImerMin(){return min;};
    int getTimerSec(){return sec;};
    // Timer  operator+(Timer &);   //这里是使用引用的话，不会创建副本
    // Timer  operator()(Timer &);
    Timer  operator+(Timer );       //这里会使用复制构造函数，构造副本．
    Timer  operator()(Timer );

};

#endif