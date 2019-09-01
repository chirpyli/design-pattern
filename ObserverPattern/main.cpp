// main.cpp
#include "observer.h"
#include "subject.h"

int main()
{
    ConcreteSubject* subject = new ConcreteSubject();
    Observer* obA = new ConcreteObserverA("observerA", -1);
    Observer* obB = new ConcreteObserverB("observerB", -1);
    subject->Attach(obA);
    subject->Attach(obB);

    subject->SetState(0);
    subject->Notify();

    subject->Detach(obA);
    subject->SetState(1);
    subject->Notify();

    delete obA;
    delete obB;
    delete subject;

    return 0;
}