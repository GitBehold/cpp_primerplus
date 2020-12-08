#include "studentc.h"
using std::ostream;
using std::endl;
using std::istream;
using std::string;

//public method

double Student::Average()const
{
    if(scores.size() > 0)
        return scores.sum()/scores.size();
    else
        return 0;
}

const string & Student::Name()const
{
    return name;
}

double & Student::operator[](int i)
{
    return scores[i];
}

double Student::operator[](int i) const
{
    return scores[i];
}
//private method
ostream & Student::arr_out(ostream &os) const
{
    int i;
    int lim = scores.size();
    if(lim > 0)
    {
        for(i = 0 ; i < lim; i++)
        {
            os << scores[i] << " ";
            if(i % 5 == 4)
                os << endl;
            if(i % 5 != 0)
                os << endl;
        }
    }
    else
        os << "empty array";
    return os;
}


//friends
//>>的字符串版本
istream &operator>>(istream &is,Student &stu)
{
        is >> stu.name;
        return is;
}
//getline版本
istream & getline(istream &is, Student & stu)
{
    getline(is,stu.name);
    return is;
}
// <<的字符串版本
ostream & operator<<(ostream &os,const Student & stu)
{
    os << "Scores for" << stu.name << ":\n";
    stu.arr_out(os);
    return os;
}