#include<iostream>
#include<cassert>
using namespace std;

class Singleton
{
public:
	static Singleton* Instance();
	void update() {
        this->data++;
        cout << this->data << endl;
    }

private:
	Singleton() {}
    Singleton(int v) {
        this->data = v;
    }

	static Singleton* _instance;
    void set_data(int value) {
        this->data = value;
    }
    int data;
};

Singleton* Singleton::_instance = new Singleton(0);

Singleton* Singleton::Instance() {
	return _instance;
}

int main() {
	Singleton* sgt1 = Singleton::Instance();
    sgt1->update();
    Singleton* sgt2 = Singleton::Instance();
    sgt2->update();
    assert(sgt1 == sgt2);

    return 0;
}