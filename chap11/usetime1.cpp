#include <iostream>
#include "mytime1.h"

//RUN : g++ usetime0.cpp mytime0.cpp -o usetime0
int main()
{
    using std::cout;
    using std::endl;
    Time planning;
    Time coding(2,40);
    Time fixing(5,55);
    Time total;

    cout << "planning time = ";
    planning.Show();
    cout << endl;

    cout << "coding time = ";
    coding.Show();
    cout << endl;

    cout << "fixing time = ";
    fixing.Show();
    cout << endl;

    // total = coding.Sum(fixing);
    total = coding + fixing;
    cout << "coding + fixing = ";
    total.Show();
    cout << endl;

    Time morefixing(3,28);
    cout << "more fixing time = ";
    morefixing.Show();
    cout << endl;

    total = morefixing.operator+(total);        //注意这种用法也是可行的

    cout << "morefixing.operator+(total) = ";
    total.Show();
    cout << endl;

    return 0;
}