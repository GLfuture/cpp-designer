//用一个虚基类的接口包装另一个类的方法以适配接口
class Interface
{
public:
    Interface(){}
    virtual void Public_Interface() = 0;
    virtual ~Interface() {}
};

class Other
{
public:
    Other(){}
    void GetName(){
        //具体实现
    }
};

//第一种实现
//同时继承两个类

class Adapter1 : public Other,public Interface
{
public:
    //用一个类的接口包装另一个类的方法
    void Public_Interface() override
    {
        GetName();
    }
};


//第二种实现
//在适配器类中包含另一个类，将接口提供出来

class Adapter2 : public Interface
{
public:
    void Public_Interface() override
    {
        other->GetName();
    }
private:
    Other *other;
};

int main()
{
    Interface *adapter1 = new Adapter1();
    Interface *adapter2 = new Adapter2();

    adapter1->Public_Interface();
    adapter2->Public_Interface();
    return 0;
}