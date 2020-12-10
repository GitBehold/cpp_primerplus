#ifndef WORKER0_H_
#define WORKER0_H_

#include <string>

class Worker
{
private:
    /* data */
    std::string fullname;
    long id;
public:
    Worker():fullname("no one"),id(0L){};
    Worker(const std::string &s,long n)
        :fullname(s),id(n){}
    virtual ~Worker() = 0 ;
    virtual void Set();
    virtual void Show() const;
};

class Waiter : public Worker
{
private:
    /* data */
    int panache;
public:
    Waiter():Worker(),panache(0){};
    Waiter(const std::string &s,long n,int p = 0)
        :Worker(s,n),panache(p){}
    Waiter(const Worker &wk,int p = 0)
        :Worker(wk),panache(p){}
    void Set();     //这里不需要写关键字virtual吗？
    void Show() const;
    // ~Waiter();   //不需要析构函数？？
};

class Singer : public Worker
{
protected:
    /* data */
    enum{other,alto,contralto,soprano,
            bass,baritone,tenor};
    enum{Vtypes = 7};

private:
    static char *pv[Vtypes];
    int voice;
public:
    Singer():Worker(),voice(other){};
    Singer(const std::string &s,long n,int v = other)
        :Worker(s,n),voice(v){}
    Singer(const Worker &wk,int v = other)
        :Worker(wk),voice(v){}
    void Set();
    void Show() const;

    ~Singer();
};





#endif