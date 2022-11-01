### 外观模式
意图：为子系统中的一组接口提供一个一致的界面，外观模式定义了一个高层接口，这个接口使的这一子系统更加容易使用。

动机：将一个系统划分成为若干个子系统有利于降低系统的复杂性。一个常见的设计目标是使子系统间的通信和互相依赖关系达到最小。达到该目标的途径之一就是引入一个外观对象，它为子系统中较一般的设施提供了一个单一而简单的界面。

适用性：在遇到以下情况时可以考虑外观模式
- 当你要为一个复杂子系统提供一个简单接口时。子系统往往因为不断演化而变得越来越复杂。大多数模式使用时都会产生更多更小的类。这使得子系统更具有可重用性，也更容易对子系统进行定制，但这也给那些不需要定制子系统的用户带了一些使用上的困难。Facade可以提供一个简单的缺省视图，这一视图对大多数用户来说已经足够，而那些需要更多的可定制性的用户可以越过facade层。
- 客户程序与抽象类的实现部分之间存在着很大的依赖性。引入facade将这个子系统与客户以及其他子系统分离，可以提高子系统的独立性和可移植性。
- 当你需要构建一个层次结构的子系统时，使用facade模式定义子系统中每层的入口点。如果子系统之间是相互依赖的，你可以让它们仅通过facade进行通讯，从而简化了它们之间的依赖关系


优点：
1. 对客户屏蔽了子系统组件，因而减少了客户处理的对象数目并使子系统使用起来更加方便
2. 它实现了子系统与客户之间的松耦合关系，而子系统内部的功能组件往往是紧耦合的。松耦合关系使得子系统的组件变化不会影响到它的客户。Facade模式有助于建立层次结构系统，也有助于对对象之间的依赖关系分层。
3. 如果应用需要，它并不限制客户使用子系统类，可在系统易用性和通用性之间加以选择。


示例代码： [facade.cpp](./facade.cpp)

```c++
/* facade pattern codes. */

#include<iostream>
using namespace std;

// 子系统1，实现子系统的功能
class Subsystem1
{
public:
    Subsystem1(){}
    ~Subsystem1(){}
    void Operation()
    {
        std::cout << "subsystem1 operation." << std::endl;
    }
};

// 子系统2，实现子系统的功能
class Subsystem2
{
public:
    Subsystem2(){}
    ~Subsystem2(){}
    void Operation()
    {
        std::cout << "subsystem2 operation." << std::endl;
    }
};

// 对外接口，知道那些子系统类负责处理请求，将客户的请求代理给适当的子系统对象，对客户屏蔽了子系统
class Facade
{
public:
    Facade(Subsystem1 *sub1, Subsystem2 *sub2):_sub1(sub1),_sub2(sub2){}
    ~Facade(){}
    void OperationWrapper()
    {
        std::cout << "facade visit:" << std::endl;
        this->_sub1->Operation();
        this->_sub2->Operation();
    }

private:
    Subsystem1 *_sub1;
    Subsystem2 *_sub2;
};

int main()
{
    Subsystem1 *sub1 = new Subsystem1();
    Subsystem2 *sub2 = new Subsystem2();

    Facade *f = new Facade(sub1, sub2);
    f->OperationWrapper();

    delete sub1;
    delete sub2;
    delete f;

    return 0;
}
```