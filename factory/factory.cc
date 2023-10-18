//抽象产品类A的基类
class ProductA {
public:
    virtual void function() = 0;
    virtual ~ProductA() {};
};
//抽象产品类B的基类
class ProductB {
public:
    virtual void function() = 0;
    virtual ~ProductB() {}
};
//抽象工厂类的基类
class Factory_Base
{
public:
    //可以将生产产品的方法定义为static方法
    virtual ProductA* create_productA() = 0;
    virtual ProductB* create_productB() = 0;
    virtual ~Factory_Base(){};
};

//具体产品
class ProductA_1: public ProductA
{
public: 
    void function() override{}
    ~ProductA_1(){}
};

class ProductB_1 : public ProductB
{
public:
    void function() override{};
    ~ProductB_1() {}
};

//工厂类

class Factory_1: public Factory_Base
{
public:
    ProductA* create_productA() override
    {
        return new ProductA_1();
    }

    ProductB* create_productB() override
    {
        return new ProductB_1();
    }
};

//产品
class ProductA_2: public ProductA
{
public:
    void function() override{}
    ~ProductA_2() {}
};

class ProductB_2 : public ProductB
{
public:
    void function() override {};
    ~ProductB_2() {}
};

//工厂
class Factory_2: public Factory_Base
{
public:
    ProductA* create_productA() override
    {
        return new ProductA_2();
    }

    ProductB* create_productB() override
    {
        return new ProductB_2();
    }
};


int main()
{
    Factory_Base* factory1 = new Factory_1();
    Factory_Base* factory2 = new Factory_2();
    ProductA* pa1 = factory1->create_productA();
    ProductB* pb1 = factory1->create_productB();
    ProductA* pa2 = factory2->create_productA();
    ProductB* pb2 = factory2->create_productB();
    return 0;
}