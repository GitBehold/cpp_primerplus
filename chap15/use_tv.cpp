#include <iostream>
#include "tv.h"
//编译指令弄错了,正确的编译指令是: g++ use_tv.cpp tv.cpp -o tv  //之前编译的时候漏了tv.cpp.

int main()
{
    using std::cout;
    Tv s42;
    cout << "Initial settings for 42 \" TV: \n";
    s42.settings();
    s42.onoff();
    s42.chanup();
    cout << "\n Adjusted settings for 42 \" TV: \n";
    s42.chanup();
    cout << "\n Adjusted settings for 42 \" TV: \n";
    s42.settings();

    Remote grey;

    grey.set_chan(s42,10);
    grey.volup(s42);
    grey.volup(s42);

    cout << "\n42 \" settings after using remote : \n ";
    s42.settings();

    Tv s58(Tv::On);
    s58.set_mode();
    grey.set_chan(s58,28);
    cout << "\n 58\" settings:\n ";
    s58.settings();
    return 0;
}