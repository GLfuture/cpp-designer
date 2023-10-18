#include <iostream>
class Singleton
{
public:
    Singleton(const Singleton&) =delete;
    Singleton& operator = (Singleton&) = delete;

    static Singleton* getInstance()
    {
        return singleton;
    }

    static void Reset()
    {
        if(singleton){
            delete singleton;
        }
    }

    void func()
    {
        std::cout<<"func"<<std::endl;
    }

private:
    Singleton() {
        std::cout<<"Singleton"<<std::endl;
    }
    static Singleton* singleton;
};


Singleton* Singleton::singleton = new Singleton;


int main()
{
    Singleton::getInstance()->func();    
    return 0;
}

