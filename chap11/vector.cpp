
#include "vector.h"
#include <cmath>
using std::sqrt;
using std::sin;
using std::cos;
using std::atan;
using std::atan2;
using std::cout;





namespace VECTOR{

        const double Rad_to_deg = 45.0/atan(1.0);

        void Vector::set_mag()
        {
            mag = sqrt(x*x + y*y);
        }

        void Vector::set_ang()
        {
            if(x == 0.0 && y == 0.0)
                ang = 0.0;
            else
            {
                ang = atan2(y,x);
            }
            
        }
        void Vector::set_x()
        {
            x = mag * cos(ang);
        }

        void Vector::set_y()
        {
            y = mag *sin(ang);
        }

        Vector::Vector()
        {
            x= y = mag = ang = 0.0;
            mode = RECT;
        }

        Vector::Vector(double n1 ,double n2,Mode form)
        {
            mode = form;
            if(form == RECT)
            {
                x = n1;
                y = n2;
                set_mag();
                set_ang();
            }else if(form == POL)
            {
                mag = n1 ;
                ang = n2/Rad_to_deg;
                set_x();
                set_y();
            }else
            {
                cout << "Incorrect 3rd argument to Vector() --";
                cout << "vector set to 0\n";
                x= y = mag = ang = 0.0;
                mode = RECT;
            }
            
        }

        void Vector::reset(double n1,double n2,Mode form)
        {
            mode = form ;
            if(form == RECT)
            {
                x = n1 ; 
                y = n2;
                set_mag();
                set_ang();
                
            }else if(form == POL)
            {
                mag = n1 ;
                ang = n2/Rad_to_deg;
                set_x();
                set_y();
            }else
            {
                cout << "Incorrect 3rd argument to Vector() --";
                cout << "vector set to 0\n";
                x= y = mag = ang = 0.0;
                mode = RECT;
            }
        }

        Vector::~Vector()
        {

        }

        void Vector::polar_mode()
        {
            mode = POL;
        }

        void Vector::rect_mode()
        {
            mode  = RECT;
        }

        Vector Vector::operator+(const Vector &b) const //第一个const限定了不修改Vector b的值,
        {
            return Vector(x+b.x,y+b.y);     //这里调用了完整的构造函数来完成工作会更简单,更可靠
        }

        Vector Vector::operator-(const Vector &b) const
        {
            return Vector(x-b.x,y-b.y);
        }

        Vector Vector::operator-()const
        {
            return Vector(-x,-y);
        }

        Vector Vector::operator*(double n) const
        {
            return Vector(n*x,n*y);
        }

        Vector operator*(double n ,const Vector &a)
        {
            return a*n;
        }
        //  int getA() const  { 
        //       return m_a; //同return this->m_a;。    注意this指针的用法.
        //   } 

        std::ostream & operator<<(std::ostream &os,const Vector & v)
        {
            if(v.mode == Vector::RECT)
            {
                os <<"(x,y) =(" << v.x << ","<<v.y <<")";
            }else if(v.mode == Vector::POL)
            {
                os <<"(m,a) = (" << v.mag << "," <<v.ang * Rad_to_deg <<")";
            }else
            {
                os << "Vector object mode is invaild";
            }
            return os;
        }

}       //end namespace VECTOR.


Timer::Timer(/* args */)
{
}

Timer::~Timer()
{
}

void Timer::setTimer(int h,int m,int s){
    hour = h;
    min  = m;
    sec  = s;
}


Timer Timer::operator+(Timer t)
{
    Timer sum ;
    sum.min = this->min +t.min;
    sum.hour = hour + t.hour;
    sum.sec = this->sec +t.sec;
    return sum;

}

Timer Timer::operator()(Timer t)
{
    Timer sum ;
    sum.min = this->min +t.min;
    sum.hour = hour + t.hour;
    sum.sec = this->sec +t.sec;
    return sum;

}


int main()
{
    Timer t1,t2,t3;
    t1.setTimer(20,16,55);
    t2.setTimer(2,2,4);
    // t3 = t1+t2;
    t3=t1(t2);
    fprintf(stderr,"t: %d:%d:%d\r\n",t3.getTimerHour(),t3.getTImerMin(),t3.getTimerSec());

}