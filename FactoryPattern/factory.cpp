#include <iostream>
#include <vector>
#include<memory>
using namespace std;

typedef enum ProductTypeTag {
	TypeA,
	TypeB,
	TypeC
} PRODUCTTYPE;

// Here is the product class
class Product {
public:
	virtual void Show() = 0;
};

class ProductA : public Product {
public:
	void Show() {
		cout<<"I'm ProductA"<<endl;
	}
};

class ProductB : public Product {
public:
	void Show() {
		cout<<"I'm ProductB"<<endl;
	}
};

class ProductC : public Product {
public:
	void Show() {
		cout<<"I'm ProductC"<<endl;
	}
};

// Here is the Factory class
class Factory {
public:
	Product* CreateProduct(PRODUCTTYPE type) {
		switch (type)
		{
		case TypeA:
			return new ProductA();

		case TypeB:
			return new ProductB();

		case TypeC:
			return new ProductC();

		default:
			return NULL;
		}
	}
};

int main() {
	// First, create a factory object
	std::unique_ptr<Factory> ProductFactory(new Factory);

	std::unique_ptr<Product> productObjA(ProductFactory->CreateProduct(TypeA));
	productObjA->Show();

	std::unique_ptr<Product> productObjB(ProductFactory->CreateProduct(TypeB));
	productObjB->Show();

	std::unique_ptr<Product> productObjC(ProductFactory->CreateProduct(TypeC));
	productObjC->Show();

	return 0;
}