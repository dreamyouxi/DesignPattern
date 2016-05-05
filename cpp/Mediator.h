#pragma  once
#include "PublicHeaders.h"

class Mediator;


class Colleague
{
public:
	virtual void Action() = 0;

protected:
	Mediator *_mediator;
	friend class ConCreateMediator;
	virtual void Sync() = 0;

};

class ConCreateColleagueA :public Colleague
{
public:
	ConCreateColleagueA(Mediator*m);
	virtual void Action()override;
private:

	virtual void Sync()override;
};

class ConCreateColleagueB :public Colleague
{
public:
	ConCreateColleagueB(Mediator*m);
	virtual void Action()override;
private:

	virtual void Sync()override;
};



class Mediator
{
public:
	virtual void IntroColleague(Colleague*a, Colleague *b) = 0;
	virtual void DoActionFromAtoB() = 0;
	virtual void DoActionFromBtoA() = 0;


protected:
	Colleague *colleague_A;
	Colleague *colleague_B;


};


class ConCreateMediator :public Mediator
{
public:
	virtual void IntroColleague(Colleague*a, Colleague *b)override;
	virtual void DoActionFromAtoB()override;
	virtual void DoActionFromBtoA()override;

};



void testMediator();