#ifndef TV_H_
#define TV_H_


class Remote;       //如果用到某个友元类,则友元类需要前向声明.

class Tv
{
    public:
        friend class Remote;    //Remote can access Tv private parts; 
        enum{Off,On};
        enum{MinVal,MaxVal=20};
        enum{Antenna,Cable};

        enum{TV,DVD};

        Tv(int s = Off,int mc = 125):state(s),volume(5),maxchannel(mc),channel(2),mode(Cable),input(TV){}
        void off(){state = (state == On)?Off:On;}
        bool ison()const {return state == On;}

        bool volup();
        bool voldown();
        void chanup();
        void chandown();
        void set_mode(){mode = (mode == Antenna)? Cable : Antenna;}
        void set_input(){input = (input == TV)?DVD:TV;}
        void settings() const;
        ~Tv();

    private:
        int state;
        int volume;
        int maxchannel;
        int channel;
        int mode;
        int input;

};


class Remote
{
private:
    int mode;   //Control Tv or DVD
public:

    Remote(int m = Tv::TV):mode(m){}
    bool volup(Tv & t){return t.volup();}
    bool voldown(Tv & t){return t.voldown();}
    void onoff(Tv & t){t.off();}
    void chanup(Tv & t){t.chanup();}
    void chandown(Tv & t){t.chandown();}

    void set_chan(Tv &t,int c){t.channel = c;}
    void set_mode(Tv &t){t.set_mode();}
    void set_input(Tv &t){t.set_input();}
    ~Remote();
};



#endif

/*
正确的排列方式
class Tv;
class Remote{...};      //由于在Remote中使用了Tv类的方法,因此编译器必须先看到Tv类的声明,这样才能知道Tv有那些方法. 因此必须有class Tv的前向声明;
class Tv{...};

错误的排列方式:
class Remote;           //
class Tv{...};          /实际证明这是可行的.
class Remote{...};



 */

