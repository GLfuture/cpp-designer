// 通过观察者通知被观测的对象根据观察者而改变自身状态
#include <iostream>
#include <vector>
class Observer;
class Object
{
public:
    virtual ~Object() {}
    virtual void update(Observer* observer) = 0;
    virtual int Get_State() = 0;
};

class Observer
{
public:
    virtual ~Observer() {} 

    void Add_obj(Object* obj){
        objects.push_back(obj);
    }

    void Del_obj(int indx)
    {
        objects.erase(objects.begin()+indx);
    }

    void notify()
    {
        for(auto& obj:objects){
            obj->update(this);
        }
    }
    virtual void Set_State(int state) = 0;
    //获取变化的接口
    virtual int Get_State() = 0;
private:
    std::vector<Object*> objects;
};

class Concrete_Object: public Object
{
public:
    void update(Observer* observer) override
    {
        this->state = observer->Get_State();
    }

    int Get_State() override
    {
        return this->state;
    }

private:
    int state;
};

class Concrete_Observer: public Observer
{
public:
    void Set_State(int state) override
    {
        this->state = state;
    }

    int Get_State() override
    {
        return this->state;
    }
private:
    int state;
};

int main()
{

    Object* obj1 = new Concrete_Object();
    Object* obj2 = new Concrete_Object();
    Observer* observer = new Concrete_Observer();
    observer->Add_obj(obj1);
    observer->Add_obj(obj2);
    observer->Set_State(123);
    observer->notify();
    std::cout<<obj1->Get_State()<<std::endl;
    std::cout<<obj2->Get_State()<<std::endl;
    return 0;
}