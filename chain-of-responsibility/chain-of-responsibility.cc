#include <iostream>
class Handler
{
public:
    virtual ~Handler() {}
    virtual void Set_Handler(Handler* handler)
    {
        this->next_handler = handler;
    }

    //继续责任链的条件(打断的条件)
    virtual bool Continue() = 0;

    //继续执行责任链下一个环节
    virtual void Func()
    {
        if(next_handler){
            next_handler->Func();
        }
    }

private:
    Handler *next_handler;
};

class Concrete_Handler1:public Handler
{
public:
    bool Continue() override
    {
        return false;
    }

    void Func() override
    {
        if(Continue()){ 
            std::cout<<"continue"<<std::endl;
            //父类func，即访问下一步责任链
            Handler::Func();
        }else{
            std::cout<<"break"<<std::endl;
        }
    }
};

class Concrete_Handler2:public Handler
{
public:
    bool Continue() override
    {
        return true;
    }

    void Func() override
    {
        if(Continue()){
            std::cout<<"continue"<<std::endl;
            Handler::Func();
        }else{
            std::cout<<"break"<<std::endl;
        }
    }
};


int main()
{
    Handler* h1 = new Concrete_Handler1();
    Handler* h2 = new Concrete_Handler2();
    Handler* h3 = new Concrete_Handler2();
    h2->Set_Handler(h3);
    h3->Set_Handler(h1);
    h2->Func();
    return 0;
}