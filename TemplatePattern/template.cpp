#include<iostream>
using namespace std;

//抽象类 实现总的通用算法框架，算法细节交给子类实现
class Abstact {
public:
    virtual ~Abstact(){}
    // 将不变的部分（通用的算法框架）在抽象类中实现，而将变化的部分（算法细节）抽象出来交给子类实现。
    void TemplateMethod(){
        cout<<"TemplateMethod:"<<endl;
        this->PrimitiveOperation1();    
        this->PrimitiveOperation2();
    }
protected:
    virtual void PrimitiveOperation1()=0;
    virtual void PrimitiveOperation2()=0;
    Abstact(){}        
};

//子类A，实现自己的算法细节
class ConcreteA: public Abstact {
public:
    ConcreteA(){}
    ~ConcreteA(){}
protected:
    void PrimitiveOperation1() {
        cout<<"A ---> PrimitiveOperation1:"<<endl;
    }

    void PrimitiveOperation2(){
        cout<<"A ---> PrimitiveOperation2:"<<endl;
    }
};

//子类B，实现自己的算法细节
class ConcreteB: public Abstact{
public:
    ConcreteB(){}
    ~ConcreteB(){}
protected:
    void PrimitiveOperation1(){
        cout<<"B ---> PrimitiveOperation1:"<<endl;
    }

    void PrimitiveOperation2(){
        cout<<"B ---> PrimitiveOperation2:"<<endl;
    }
};

int main(){
    cout<< "template pattern."<<endl;
    Abstact* a = new ConcreteA();
    a->TemplateMethod();
    Abstact* b = new ConcreteB();
    b->TemplateMethod();

    delete a;
    delete b;

    return 0;
}