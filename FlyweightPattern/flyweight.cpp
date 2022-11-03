/* flyweight pattern codes. */

#include<iostream>
#include<cstring>
#include<vector>
using namespace std;

// 抽象出对象中可以共享的部分
class Flyweight
{
public:
    virtual ~Flyweight(){}
    virtual void Operation(const string& extState){}
    string GetIntinState()
    {
        return this->_inState;
    }

protected:
    Flyweight(string inState):_inState(inState){}

private:
    string _inState;    // 可以被共享的， 内状态
};

// 具体的对象
class ConcreteFlyweight:public Flyweight
{
public:
    ConcreteFlyweight(string inState):Flyweight(inState)
    {
        std::cout<<"Concrete Flyweight Build ......" << inState << std::endl;
    }

    ~ConcreteFlyweight(){}
    // 传入不被共享的外部状态，extState
    void Operation(const string& extState)
    {
        std::cout<< "Flyweight: inner state[" << this->GetIntinState() << "] " << "outer state[" << extState << "]" << std::endl;
    }
};

// 对象工厂，生产对象
class FlyweightFactory
{
public:
    FlyweightFactory(){}
    ~FlyweightFactory()
    {
        vector<Flyweight*>::iterator it = _fly.begin();
        for (; it != _fly.end(); it++)
        {
            delete *it;
        }
    }

    // 获取一个对象，如果已存在，则直接返回，如果不存在，则创建
    Flyweight* getFlyweight(const string& key)
    {
        vector<Flyweight*>::iterator it = _fly.begin();
        for(;it != _fly.end(); it++)
        {
            if (key.compare((*it)->GetIntinState()) == 0)
            {
                std::cout << "already created by users......" << std::endl;
                return *it;
            }
        }

        Flyweight *fn = new ConcreteFlyweight(key);
        _fly.push_back(fn);

        return fn;
    }

private:
    vector<Flyweight*> _fly;  // 对象池
};

int main()
{
    FlyweightFactory *fc = new FlyweightFactory();
    Flyweight *fobj1 = fc->getFlyweight("changan");
    fobj1->Operation("sl03");

    Flyweight *fobj2 = fc->getFlyweight("hauwei");
    fobj2->Operation("m5");

    Flyweight *fobj3 = fc->getFlyweight("huawei");
    fobj3->Operation("m7");

    delete fc;

    return 0;
}

/*
-- 输出结果：
[postgres@slpc FlyweightPattern]$ g++ flyweight.cpp -std=c++11;
[postgres@slpc FlyweightPattern]$ ./a.out 
Concrete Flyweight Build ......changan
Flyweight: inner state[changan] outer state[sl03]
Concrete Flyweight Build ......hauwei
Flyweight: inner state[hauwei] outer state[m5]
Concrete Flyweight Build ......huawei
Flyweight: inner state[huawei] outer state[m7]
*/