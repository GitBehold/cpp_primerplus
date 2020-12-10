#ifndef STUDENTC_H_
#define STUDENTC_H_

#include <iostream>
#include <string>
#include <valarray>

class Student
{
private:
    typedef std::valarray<double> ArrayDb;
    std::string name;
    ArrayDb scores;

    std::ostream & arr_out(std::ostream & os) const;
public:
    Student():name("Null student"),scores(){}
    explicit Student(const std::string &s)      //使用explicit关闭隐式转换，因为只带一个参数的构造函数可以隐式转换用作参数类型到类类型的转换
        :name(s),scores(){}
    explicit Student(int n):name("Nully"),scores(n){}   //这里同样是使用explicit　防止单参数构造函数的隐式转换．－－－－＞在编译阶段出现错误优于运行阶段出现错误．
    Student(const std::string &s, int n)
        :name(s),scores(n){}
    Student(const std::string &s, const ArrayDb &a)
        :name(s),scores(a){}
    Student(const char * str,const double *pd,int n)
        :name(str),scores(pd,n){}
    ~Student(){}
    double Average() const;
    const std::string & Name() const;
    double &operator[](int i);
    double operator[](int i) const;

//friend
    friend std::istream &operator>>(std::istream &is,Student &stu); //1 word
    friend std::istream &getline(std::istream &is, Student &stu);   //1 line
    friend std::ostream &operator<<(std::ostream &os,const Student &stu);

};



#endif