#include<iostream>
using namespace std;

//抽象类
class Subject {
public:
	Subject(){}
	virtual ~Subject(){}
	//抽象角色：通过接口或抽象类声明真实角色实现的业务方法。
	virtual void Request()=0;//接口
};

//委托类
class ConcreteSubject:public Subject {
public:
	ConcreteSubject(){}
	~ ConcreteSubject(){}
	//真实角色：实现抽象角色，定义真实角色所要实现的业务逻辑，供代理角色调用。
	void Request() {
		cout << "代理实现请求！" << endl;
	}
};

//代理类
class Proxy {
public:
	Proxy():_sub(NULL){}
	Proxy(Subject* sub):_sub(sub){}
	~Proxy(){
		if(_sub!=NULL){
			delete _sub;
		}
	}
	//代理角色：实现抽象角色，是真实角色的代理，
	void Request() {
		_sub->Request();	//通过真实角色的业务逻辑方法来实现抽象方法，并可以附加自己的操作。
	}

private:
	Subject* _sub;
};

int main() {
	//代理模式的最大好处就是实现了逻辑和实现的彻底解耦
	Subject* sub=new ConcreteSubject();
	Proxy* p=new Proxy(sub);
	p->Request();//p的Request请求实际上是交给了sub来实际执行
	return 0;
}