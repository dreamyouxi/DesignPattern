#include "PublicHeaders.h"
#pragma  once

#include <string>



class Memento
{
public:
	Memento(const std::string & state)
	{
		this->state = state;
	}
	void setState(const std::string& state)
	{
		this->state = state;
	}

	const std::string getState()const
	{
		return state;
	}
private:

	std::string state;
};




class Originator
{
public:
	Memento* CreateMemento()
	{
		if (backup)
		{
			delete backup;
		}
		backup = new Memento(state);
		return backup;
	}

	void RestoreMemento()
	{
		this->state = backup->getState();
	}


	void RestoreMemento(Memento*mem)
	{
		this->state = mem->getState();
	}


	const std::string &getState()const
	{
		return state;
	}
	void setState(const std::string& state)
	{
		this->state = state;
	}

	void PrintState()
	{
		std::cout << state << std::endl;

	}

private:
	Memento *backup = nullptr;

	std::string state = "";
};


void testMemento()
{
	Originator * ori = new Originator;
	ori->setState("old");
	ori->PrintState();
	ori->CreateMemento();


	ori->setState("new");
	ori->PrintState();
	ori->RestoreMemento();
	ori->PrintState();
 
}

