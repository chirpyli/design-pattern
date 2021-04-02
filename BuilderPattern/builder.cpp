/*
Builder pattern.  这里的实现有点复杂了，代码要根据实际情况，很多时候可以直接写一个XXBuilder类直接构造对象就可以了.

*/

#include<string>
#include <iostream>
using namespace std;

//待建造——被构造的复杂对象
class Product {
private:
    int a;
    string b;
public:
    Product(){}

    void setA(const int a) {
        this->a = a;
    }

    void setB(const string b) {
        this->b = b;
    }

    void output() {
        cout << this->a << " " << this->b << endl;
    }
};

//建造者抽象类——为创建一个Product对象的各个部件指定抽象接口
class Builder {
public:
    virtual void buildA(const int pars) = 0;
    virtual void buildB(const string pars) = 0;
    virtual Product* build() = 0;
};

//建造者——实现Builder的接口以构造和装配该产品的各个部件
class ConcreteBuilder: public Builder {
private:
    Product* product;
public:
    ConcreteBuilder() {
        product = new Product();
    }

    void buildA(const int pars) {
        product->setA(pars);
    }

    void buildB(const string pars) {
        product->setB(pars);
    }

    Product* build(){
        return product;
    }
};

//导演——构造一个使用Builder接口的对象
class Directer {
private:
    Builder* builder;

public:
    Directer(Builder* builder) {
        this->builder = builder;
    }

    Product* construct(const int pars_a, const string pars_b) {
        builder->buildA(pars_a);
        builder->buildB(pars_b);
        return builder->build();
    }
};

int main(){
    Builder* builder = new ConcreteBuilder();
    Directer* directer = new Directer(builder);
    Product* product = directer->construct(10,"ten");
    product->output();

    delete product;
    delete directer;
    delete builder;

    return 0;
}