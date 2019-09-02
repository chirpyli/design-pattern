#include<iostream>
using namespace std;

//抽象构件（Component）角色：给出一个抽象接口，以规范准备接收附加责任的对象。
class Component{
public:
    virtual ~Component();
    virtual void Operation()=0;

protected:
    Component(){}
};

Component::~Component(){
}

//具体构件（Concrete Component）角色：定义一个将要接收附加责任的类。
class ConcreteComponent:public Component
{
public:
    ConcreteComponent(){}
    ~ConcreteComponent(){}

    void Operation(){
        cout << "ConcreteComponent Operation()" << endl;
    }
};

//装饰（Decorator）角色：持有一个构件（Component）对象的实例，并定义一个与抽象构件接口一致的接口。
class Decorator:public Component
{
public:
    Decorator(Component* com){
        this->_com=com;
    }

    virtual ~Decorator(){
        delete _com;
    }

    void Operation(){
    }

protected:
    Component* _com;
};

//具体装饰（Concrete Decorator）角色：负责给构件对象”贴上”附加的责任。
class ConcreteDecorator:public Decorator
{
public:
    ConcreteDecorator(Component* com):Decorator(com)
    {
    }

    ~ConcreteDecorator(){}

    void Operation(){
        _com->Operation();
        this->AddBehavior();
    }

    void AddBehavior(){
        cout << "ConcreteDecorator AddBehavior()" << endl;
    }
};

int main(){
    Component* com1 = new ConcreteComponent();
    Decorator* dec = new ConcreteDecorator(com1);
    dec->Operation();
    delete dec;

    return 0;
}