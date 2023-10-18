#include <iostream>
//各个命令对应的执行
class Excutor
{
public:
    virtual void action() = 0;
    virtual ~Excutor() {}
};

class Command
{
public:
    Command(Excutor* excutor)
    {
        this->excutor = excutor;
    }
    virtual void excute() = 0;
    virtual ~Command(){
        if(excutor){
            delete excutor;
        }
    }
protected:
    Excutor* excutor;
};

class Set_Excutor: public Excutor
{
public:
    void action() override
    {
        std::cout<<"Set"<<std::endl;
    }
};

class Get_Excutor: public Excutor
{
public:
    void action() override
    {
        std::cout<<"Get"<<std::endl;
    }
};

class Set_Command:public Command
{
public:
    Set_Command(Excutor* excutor):Command(excutor)
    {

    }
    void excute() override
    {
        excutor->action();
    }
};

class Get_Command:public Command
{
public:
    Get_Command(Excutor* excutor):Command(excutor)
    {

    }
    void excute() override
    {
        excutor->action();
    }
};


class Invoke
{
public:
    void Set_Command(Command* command)
    {
        this->command = command;
    }

    void clear()
    {
        command = nullptr;
    }

    void execute_cmd()
    {
        if(command){
            command->excute();
        }
    }

private:
    Command* command;
};


int main()
{
    Excutor* set_excutor = new Set_Excutor;
    Excutor* get_excutor = new Get_Excutor;
    Command* set = new Set_Command(set_excutor);
    Command* get = new Get_Command(get_excutor);
    Invoke invoke;
    invoke.Set_Command(set);
    invoke.execute_cmd();
    invoke.clear();
    invoke.Set_Command(get);
    invoke.execute_cmd();
    invoke.clear();
    return 0;
}