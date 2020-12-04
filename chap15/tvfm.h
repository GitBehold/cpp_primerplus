#ifndef TVFM_H_
#define TVFM_H_


class Tv;       //如果用到某个友元类,则友元类需要前向声明.

class Remote
{

public:
    enum State{Off,On};
    enum {MinVal,MaxVal=20};
    enum {Antenna,Cable};

    enum {TV,DVD};

private:
    int mode;   //Control Tv or DVD

public:

    Remote(int m = TV):mode(m){}
    bool volup(Tv & t);//{return t.volup();}    //注意这里只是做了方法的声明,而不能在这里实现.需要在Tv类声明其所有方法后才能实现.
    bool voldown(Tv & t);//{return t.voldown();}
    void onoff(Tv & t);//{t.off();}
    void chanup(Tv & t);//{t.chanup();}
    void chandown(Tv & t);//{t.chandown();}

    void set_chan(Tv &t,int c);//{t.channel = c;}
    void set_mode(Tv &t);//{t.set_mode();}
    void set_input(Tv &t);//{t.set_input();}
    ~Remote();
};

class Tv
{
    public:
        // friend class Remote;    //Remote can access Tv private parts;
        friend void Remote::set_chan(Tv &t, int c);
        enum State{Off,On};
        enum {MinVal,MaxVal=20};
        enum {Antenna,Cable};

        enum {TV,DVD};

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


inline bool Remote::volup(Tv & t){return t.volup();}
inline bool Remote::voldown(Tv & t){return t.voldown();}
inline void Remote::onoff(Tv & t){t.off();}
inline void Remote::chanup(Tv & t){t.chanup();}
inline void Remote::chandown(Tv & t){t.chandown();}

inline void Remote::set_chan(Tv &t,int c){t.channel = c;}
inline void Remote::set_mode(Tv &t){t.set_mode();}
inline void Remote::set_input(Tv &t){t.set_input();}
#endif

/*
正确的排列方式
class Tv;
class Remote{...};      //由于在Remote中使用了Tv类的方法,因此编译器必须先看到Tv类的声明,这样才能知道Tv有那些方法. 因此必须有class Tv的前向声明;
class Tv{...};

错误的排列方式:
class Remote;           //不能这么做的原因
class Tv{...};          //因为Tv类中包含了友元类Remote,因此必须先看到Remote类的声明?? 存疑
class Remote{...};



 */