#include<iostream>
using namespace std;

class Prototype
{
public:
	virtual ~Prototype(){}
	virtual Prototype* Clone() const = 0;   //原型模式，最核心的抽象，凡是原型模式必须实现该抽象
protected:
	Prototype(){}
};

class ConcretePrototype:public Prototype
{
public:
	ConcretePrototype(){}
	ConcretePrototype(const ConcretePrototype& obj){
		cout << "拷贝构造，注意深拷贝，浅拷贝的问题\n";
	}
	~ConcretePrototype(){}
	Prototype* Clone()const {
		return new ConcretePrototype(*this);
	}
private:
};

int main() {
	Prototype* p = new ConcretePrototype();
	Prototype* p1 = p->Clone();

    return 0;
}