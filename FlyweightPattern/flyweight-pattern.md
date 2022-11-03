### 享元模式
意图：运用共享技术有效地支持大量细粒度的对象

动机：有些应用程序得益于其整个设计过程中采用对象技术，但简单化的实现代价极大。Flyweight模式描述了如何共享对象，使得可以细粒度地使用它们而无需高昂的代价。flyweight是一个共享对象，它可以同时在多个场景中使用，并且在每个场景中flyweight都可以作为一个独立的对象——这一点与非共享的实例没有区别。flyweight模式对那些通常因为数量太大而难以用对象来表示的概念或实体进行建模。对此我们可以将对象的状态分为“外部状态”和“内部状态”，将可以被共享（不会变化）的状态作为内部状态存储在对象中，而外部状态（对象不同的地方）我们可以在适当的时候将外部状态作为参数传递给对象。



适用性：Flyweight模式的有效性很大程度上取决于如何使用它以及在何处使用它。当以下情况都成立时使用Flyweight模式：
- 一个应用程序使用了大量的对象
- 完全由于使用大量的对象，造成很大的存储开销
- 对象的大多数状态都可变为外部状态
- 如果删除对象的外部状态，那么可以用相对较少的共享对象取代很多组对象
- 应用程序不依赖于对象标识。由于Flyweight对象可以被共享，对于概念上明显有别的对象，标识测试将返回真值。

示例代码： [flyweight.cpp](./flyweight.cpp)

```c++
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
```