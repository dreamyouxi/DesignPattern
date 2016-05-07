#include "PublicHeaders.h"

#pragma once
class Visitor;
class Element;


class Visitor
{
public:
	virtual void VisitElementA(Element*ele) = 0;

};

class Element
{
public:
	void Print()
	{
		cout << " this is element" << __FUNCTION__ << endl;
	}
	/**
	* @brief the interface of visitor's visit
	*/
	virtual void Accept(Visitor *visitor) = 0;
};




class ConCreateVisitor :public Visitor
{
public:

	void VisitElementA(Element *ele)
	{
		ele->Print();
	}
};

class ConCreateElementA :public Element
{
public:
	virtual void Accept(Visitor *visitor)override
	{
		visitor->VisitElementA(this);
	}
};




void testVisitor()
{
	Element *ele = new ConCreateElementA;
	Visitor *vis = new ConCreateVisitor;

	ele->Accept(vis);

}



