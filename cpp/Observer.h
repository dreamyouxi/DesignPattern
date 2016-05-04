#include "PublicHeaders.h"


#include <vector>
#include <string>

class Observer;

class Subject
{
public:
	virtual void Attach(Observer*) = 0;
	virtual void Detach(Observer*) = 0;
	virtual void Notify() = 0;

	void setState(const std::string&state)
	{
		this->_state = state;
	}
	const std::string& getState()const
	{
		return _state;
	}
private:
	std::string _state;
protected:

	std::vector<Observer*> _observers;

};


class ConCreateSubject :public Subject
{
public:
	virtual void Attach(Observer*) override;
	virtual void Detach(Observer*)override;
	virtual void Notify() override;


};

class  Observer
{
public:
	virtual void Update(const std::string &state) = 0;
};

class ConCreateObserverA :public Observer
{
public:
	virtual void Update(const std::string& state)override
	{
		if (state == "A")
		{
			cout << __FUNCTION__ << endl;
		}
	}
};


class ConCreateObserverB :public Observer
{
public:
	virtual void Update(const std::string& state)override
	{
		if (state == "B")
		{
			cout << __FUNCTION__ << endl;
		}
	}
};


void testObserver();