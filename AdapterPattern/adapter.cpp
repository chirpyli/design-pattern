/* adapter pattern codes */

#include<iostream>
using namespace std;


// 定义Client使用的与特定领域相关的接口
class Target
{
public:
    Target(){}
    virtual ~Target(){}
    virtual void Request();
};

void Target::Request()
{
    std::cout << "target::request" << std::endl;
}

// 定义一个已经存在的接口，这个接口需要适配（被复用的，或存在想要使用的接口）
class Adaptee
{
public:
    Adaptee(){}
    ~Adaptee(){}
    void SpecificRequest();     // 不符合要求的接口，不能直接使用
};

void Adaptee::SpecificRequest()
{
    std::cout << "Adaptee::SpecificRequest" << std::endl;
}

// 对Adaptee的接口与Target接口进行适配
class Adapter:public Target
{
public:
    Adapter(Adaptee *ade)
    {
        _ade = ade;
    }
    ~Adapter(){}
    void Request();

private:
    Adaptee* _ade;
};

void Adapter::Request()
{
    std::cout << "adapter call request:" << std::endl;
    _ade->SpecificRequest();
}


int main()
{
    Adaptee *ade = new Adaptee();
    Target *adt = new Adapter(ade);
    adt->Request();

    return 0;
}