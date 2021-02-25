#include<numeric>
#include<algorithm>
#include<iostream>

typedef int Object;

class Iterator;
class ConcreteIterator;
//聚合抽象类
class Aggregate {
public: 
	virtual ~Aggregate(){}
	virtual Object GetItem(int idx) = 0;
	virtual int GetSize() = 0;
protected:
	Aggregate(){}
};

//聚合具体类，在具体应用中可以是数组、链表、集合、队列等等。
class ConcreteAggregate: public Aggregate { 
public: 
	enum {SIZE = 3};
	ConcreteAggregate() {
		std::iota(std::begin(_objs), std::end(_objs), 1);
	}
	~ConcreteAggregate(){}
	
    Object GetItem(int idx) {
		if(idx < this->GetSize()) {
			return _objs[idx];
		} else {
			return -1;
		}
	}

	int GetSize(){
		return SIZE;
	}

private: 
	Object _objs[SIZE];
};

//迭代器抽象类
class Iterator { 
public: 
	virtual ~Iterator(){}
	virtual void First() = 0;
	virtual void Next() = 0;
	virtual bool IsDone() = 0;
	virtual Object CurrentItem() = 0;
protected: 
	Iterator(){}
};

//迭代器具体类，关联到具体聚合类的迭代器，不同的聚合类有不同的迭代器类实现
class ConcreteIterator: public Iterator { 
public: 
	ConcreteIterator(Aggregate* ag , int idx = 0):_ag(ag),_idx(idx){}
	~ConcreteIterator(){}
	void First() {
		_idx = 0;
	}
	void Next(){
		++_idx;
	}
	bool IsDone(){
		return _idx == _ag->GetSize();
	}
	Object CurrentItem(){
		return _ag->GetItem(_idx);
	}

private: 
	Aggregate* _ag;
	int _idx;
};

int main() {
	using namespace std;
	Aggregate* ag = new ConcreteAggregate();    //聚合类
	Iterator* it = new ConcreteIterator(ag);	//建立聚合类对应得迭代器
	for(; !it->IsDone(); it->Next()) {
		cout << it->CurrentItem() << endl;
	}

	return 0;
}