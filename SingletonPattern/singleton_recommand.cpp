// 推荐
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
    void set_data(int value) {
        this->data = value;
    }
    int data;
};


Singleton* Singleton::Instance() {
	static Singleton s(0);

	return &s;
}

int main() {
	Singleton* sgt1 = Singleton::Instance();
    sgt1->update();
    Singleton* sgt2 = Singleton::Instance();
    sgt2->update();
    assert(sgt1 == sgt2);

    return 0;
}