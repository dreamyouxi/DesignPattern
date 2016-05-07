#include "PublicHeaders.h"
#pragma once


class Request
{
public:

	virtual int GetType()
	{
		return this->_type;
	}


	Request(int t)
	{
		this->_type = t;
	}
private:
	int _type;

};

class Handler
{
public:
	virtual void HandleRequest(Request*request) = 0;
	void setSuccessor(Handler *s)
	{
		this->successor = s;
	}

protected:
	Handler *successor = nullptr;
 
};



class HandlerA :public Handler
{
public:

	virtual void HandleRequest(Request*request)override
	{
		if (request->GetType() == 0)
		{
			cout << "do request success in " << __FUNCTION__ << endl;
			return;
		}
		if (successor)
		{
			successor->HandleRequest(request);
		}

	}
};

class HandlerB :public Handler
{
public:
public:

	virtual void HandleRequest(Request*request)override
	{
		if (request->GetType() == 1)
		{
			cout << "do request success in " << __FUNCTION__ << endl;
			return;
		}
		if (successor)
		{
			successor->HandleRequest(request);
		}

	}
};




void testChain()
{

	Handler *ha = new HandlerA;
	Handler*hb = new HandlerB;
	ha->setSuccessor(hb);

	Request *re = new Request(99);

	ha->HandleRequest(re);

}








