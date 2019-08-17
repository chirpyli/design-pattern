#include<iostream>
#include<cassert>
#include<mutex>
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
	static Singleton* _instance;
    static mutex _mutex;
    void set_data(int value) {
        this->data = value;
    }
    int data;
};

Singleton* Singleton::_instance = nullptr;
mutex Singleton::_mutex;

Singleton* Singleton::Instance() {
	if (nullptr == _instance) {
		_mutex.lock();
        if (nullptr == _instance) {
            _instance = new Singleton();
            _instance->set_data(0);
        }
        _mutex.unlock();
	}

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