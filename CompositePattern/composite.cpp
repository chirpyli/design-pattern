#include<iostream>
#include<vector>
#include<string>
using namespace std;

//接口抽象
class Component
{
public:
    Component(string name){
        m_name=name;
    }
    virtual ~Component(){}

public:
    virtual void Operation()=0;
    virtual void Add(const Component& ){}
    virtual void Remove(const Component& ){}
    virtual Component* GetChild(int ){
        return NULL;
    }

    string m_name;
};

class Composite:public Component
{
public:
    Composite(string name):Component(name){}
    ~Composite(){
        cout<<m_name<<" destructor..."<<endl;
        for (vector<Component *>::iterator it = comVec.begin();it!=comVec.end();++it){
            delete *it;
        }
    }

public:
    void Operation(){
        vector<Component*>::iterator comiter=comVec.begin();
        for (; comiter!=comVec.end();comiter++)
        {
            (*comiter)->Operation();
        }
    }
    void Add(Component* com){
        comVec.push_back(com);
    }
    void Remove(Component* com){
        for (vector<Component*>::iterator it = comVec.begin();it!=comVec.end();it++){
            if (*it == com){
                delete *it;
                *it=NULL;

                comVec.erase(it);
                break;
            }
        }
    }
    Component* GetChild(int index){
        return comVec[index];
    }

private:
    vector<Component*> comVec;
};


class Leaf:public Component
{
public:
    Leaf(string name):Component(name){
    }
    ~Leaf(){
        cout<<m_name<<" destructor..."<<endl;
    }
    void Operation(){
        cout<<"Leaf("<<m_name<<") operation......"<<endl;
    }
};

int main() {
    Composite* root = new Composite("root");

    Leaf* la=new Leaf("leaf a");
    Leaf* lb=new Leaf("leaf b");
    Leaf* laa=new Leaf("leaf aa");

    Composite* coma = new Composite("com a");
    Composite* comb = new Composite("com b");
    coma->Add(la);
    coma->Add(lb);
    comb->Add(laa);

    root->Add(coma);
    root->Add(comb);
//    coma->Operation();
    root->Operation();

//    Component* l_a=coma->GetChild(0);
//    l_a->Operation();
    delete root;

    return 0;
}