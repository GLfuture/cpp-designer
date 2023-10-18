//向上层掩饰底层细节
class Base
{
public:
    virtual ~Base(){}
    virtual void func() = 0;
};

class Concrete_Base:public Base
{
public:
    void func() override
    {
        //具体实现
    }
};

class Proxy
{
public:
    //就是用proxy封装Concrete_Base
    Proxy()
    { 
        base = new Concrete_Base;
    }

    void Public_Fuc()
    {
        base->func();
    }
private:
    Concrete_Base* base;
};

int main()
{
    Proxy *p = new Proxy;
    p->Public_Fuc();
    return 0;
}