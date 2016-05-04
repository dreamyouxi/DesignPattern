#include "Observer.h"





void ConCreateSubject::Attach(Observer*observer)
{
	_observers.push_back(observer);
}

void ConCreateSubject::Detach(Observer*observer)
{
	auto iter = std::find(_observers.begin(), _observers.end(), observer);
	if (iter != _observers.end())
	{
		_observers.erase(iter);
	}

}

void ConCreateSubject::Notify()
{
	// 	for each (const auto & var in _observers)
	// 	{
	// 		var.Update(this->getState());
	// 	}

	for (int i = 0; i < _observers.size(); ++i)
	{
		_observers[i]->Update(this->getState());
	}
}






void testObserver()
{
	ConCreateSubject *sub = new ConCreateSubject;

	auto a1 = new ConCreateObserverA;
	sub->Attach(a1);

	auto a2 = new ConCreateObserverA;
	sub->Attach(a2);

	auto b1 = new ConCreateObserverB;
	sub->Attach(b1);

	sub->setState("A");
 
	sub->Notify();

	sub->Detach(a1);


	sub->Notify();

}