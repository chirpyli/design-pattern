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