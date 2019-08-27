#include<iostream>
using namespace std;

// 策略抽象类
class Strategy {
public:
    virtual void AlgrithmInterface()=0;
    virtual ~Strategy(){}
protected:
    Strategy(){}
};

// 策略A
class ConcreteStrategyA :public Strategy{
public:
    ConcreteStrategyA(){}
    ~ConcreteStrategyA(){}
    void AlgrithmInterface(){
        cout<<"A strategy impl."<<endl;
    }
};

// 策略B
class ConcreteStrategyB :public Strategy {
public:
    ConcreteStrategyB(){}
    ~ConcreteStrategyB(){}
    void AlgrithmInterface(){
        cout<<"B strategy impl."<<endl;
    }
};

class Context {
public:
    Context(Strategy* s){
        m_strategy = s;
    }
    ~Context(){}
    void DoAction(){
    cout<<"Context DoAction:"<<endl;
        m_strategy->AlgrithmInterface();
    }
    void change_strategy(Strategy* v){
        m_strategy = v;
    }
private:
    Strategy* m_strategy;
};


int main(){
    Strategy* sa = new ConcreteStrategyA();
    Context* con = new Context(sa);
    con->DoAction();

    Strategy* sb = new ConcreteStrategyB();
    con->change_strategy(sb);
    con->DoAction();

    delete sa;
    delete sb;
    delete con;

    return 0;
}