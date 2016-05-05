#include "Mediator.h"




ConCreateColleagueA::ConCreateColleagueA(Mediator*m)
{
	this->_mediator = m;
}
void ConCreateColleagueA::Action()
{
	this->_mediator->DoActionFromAtoB();
}


void  ConCreateColleagueA::Sync()
{
	cout << __FUNCTION__ << endl;
}

ConCreateColleagueB::ConCreateColleagueB(Mediator*m)
{
	this->_mediator = m;
}
void  ConCreateColleagueB::Action()
{
	this->_mediator->DoActionFromBtoA();
}

void ConCreateColleagueB::Sync()
{
	cout << __FUNCTION__ << endl;
}






void  ConCreateMediator::IntroColleague(Colleague*a, Colleague *b)
{
	this->colleague_A = a;
	this->colleague_B = b;
}
void ConCreateMediator::DoActionFromAtoB()
{
	colleague_B->Sync();
}
void  ConCreateMediator::DoActionFromBtoA()
{
	colleague_A->Sync();
}





void testMediator()
{
	ConCreateMediator* mediator = new ConCreateMediator;

	ConCreateColleagueA *a = new ConCreateColleagueA(mediator);
	ConCreateColleagueB *b = new ConCreateColleagueB(mediator);
	mediator->IntroColleague(a, b);

	a->Action();
	b->Action();
	a->Action();



}