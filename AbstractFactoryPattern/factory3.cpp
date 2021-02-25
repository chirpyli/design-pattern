#pragma once
#include <iostream>
#include<memory>
using namespace std;

// Product A
class ProductA
{
public:
	virtual void Show() = 0;
};

class ProductA1 : public ProductA
{
public:
	void Show()
	{
		cout << "I'm ProductA1" << endl;
	}
};

class ProductA2 : public ProductA
{
public:
	void Show()
	{
		cout << "I'm ProductA2" << endl;
	}
};

// Product B
class ProductB
{
public:
	virtual void Show() = 0;
};

class ProductB1 : public ProductB
{
public:
	void Show()
	{
		cout << "I'm ProductB1" << endl;
	}
};

class ProductB2 : public ProductB
{
public:
	void Show()
	{
		cout << "I'm ProductB2" << endl;
	}
};

// Factory
class Factory
{
public:
	virtual ProductA *CreateProductA() = 0;
	virtual ProductB *CreateProductB() = 0;
};

class Factory1 : public Factory
{
public:
	ProductA *CreateProductA()
	{
		return new ProductA1();
	}

	ProductB *CreateProductB()
	{
		return new ProductB1();
	}
};

class Factory2 : public Factory
{
	ProductA *CreateProductA()
	{
		return new ProductA2();
	}

	ProductB *CreateProductB()
	{
		return new ProductB2();
	}
};


int main()
{
	std::unique_ptr<Factory> facObj1(new Factory1);
	std::unique_ptr<ProductA> proObjA1(facObj1->CreateProductA());
	std::unique_ptr<ProductB> proObjB1(facObj1->CreateProductB());
	proObjA1->Show();
	proObjB1->Show();

	std::unique_ptr<Factory> facObj2(new Factory2);
	std::unique_ptr<ProductA> proObjA2(facObj2->CreateProductA());
	std::unique_ptr<ProductB> proObjB2(facObj2->CreateProductB());
	proObjA2->Show();
	proObjB2->Show();

    return 0;
}