#include<memory>
#include <iostream>
#include <vector>
using namespace std;

// Here is the product class
class Product {
public:
	virtual void Show() = 0;
};

class ProductA : public Product
{
public:
	void Show()
	{
		cout<<"I'm ProductA"<<endl;
	}
};

class ProductB : public Product
{
public:
	void Show()
	{
		cout<<"I'm ProductB"<<endl;
	}
};

class ProductC : public Product
{
public:
	void Show()
	{
		cout<<"I'm ProductC"<<endl;
	}
};

// Here is the Factory class
class Factory
{
public:
	virtual Product* CreateProduct()=0;

};

class FactoryA:public Factory
{
public:
	Product* CreateProduct()
	{
		return new ProductA;
	}
};

class FactoryB:public Factory
{
public:
	Product* CreateProduct()
	{
		return new ProductB;
	}
};

class FactoryC:public Factory
{
public:
	Product* CreateProduct()
	{
		return new ProductC;
	}
};



int main() {
	// First, create a factory object
	Factory* ProductFactory=new FactoryA;

	std::unique_ptr<Product> productObjA(ProductFactory->CreateProduct());
	productObjA->Show();

	ProductFactory = new FactoryB;
	std::unique_ptr<Product> productObjB(ProductFactory->CreateProduct());
	productObjB->Show();

	ProductFactory = new FactoryC;
	std::unique_ptr<Product> productObjC(ProductFactory->CreateProduct());
	productObjC->Show();

	delete ProductFactory;

	return 0;
}