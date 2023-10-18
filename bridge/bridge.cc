class Function
{
public:
    virtual void Get_Name() = 0;
};

class Concrete_Function: public Function
{
public:
    void Get_Name() override {
        //具体实现
    }
};

class Interface
{
public:
    virtual void Public_Interface() = 0;
    virtual ~Interface(){}
};

class Concrete_Interface :public Interface
{
public:
    Concrete_Interface(Function* func){
        this->func = func;
    }

    void Public_Interface() 
    {
        func->Get_Name();
    }

private:
    Function* func;
};

int main()
{
    Function *func = new Concrete_Function();
    Interface *interface = new Concrete_Interface(func);
    interface->Public_Interface();
    return 0;
}