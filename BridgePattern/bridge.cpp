#include<iostream>
using namespace std;

//实现
class AbstractionImp
{
public: 
	virtual ~AbstractionImp(){}
	virtual void Operation() = 0;
};

//不同的实现方法A
class AbstractionImpA :public AbstractionImp
{
public:
	~AbstractionImpA(){}
	AbstractionImpA(){}
	void Operation() {
		cout << "AbstractionImpA Operation()!\n";
	}
};

//不同的实现方法B
class AbstractionImpB :public AbstractionImp
{
public:
	~AbstractionImpB() {}
	AbstractionImpB() {}
	void Operation() {
		cout << "AbstractionImpB Operation()!\n";
	}
};

//抽象
class Abstraction
{
public:
	virtual ~Abstraction(){}
	virtual void Operation() = 0;
protected:
	Abstraction(){}
};

//提炼抽象，将抽象与实现桥接起来  
class RefinedAbstraction:public Abstraction
{
public:
	RefinedAbstraction(AbstractionImp* imp):_imp(imp){}
	~RefinedAbstraction(){}
	virtual void Operation()
	{
		_imp->Operation();
	}
private:
	AbstractionImp* _imp;
};

int main() {
	AbstractionImp* imp = new AbstractionImpA();     //具体的实现对象，真正的工作由这个对象来做
	Abstraction* obj = new RefinedAbstraction(imp);  //负责抽象接口，具体的工作交由imp对象
	obj->Operation();

    return 0;
}