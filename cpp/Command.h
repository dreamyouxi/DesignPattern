#pragma once
#include "PublicHeaders.h"




class Receiver
{
public:
	virtual void Action()
	{
		cout << __FUNCTION__ << endl;
	}
};




class Command
{
public:
	virtual void Execute() = 0;

protected:
	Receiver*recver;

};



class ConCreateCommand :public Command
{
public:
	virtual void Execute()override
	{
		recver->Action();
	}

	ConCreateCommand(Receiver*recevier)
	{
		this->recver = recevier;
	}

};


class Invoker
{
public:
	void Invoke()
	{
		command->Execute();
	}
	Invoker(Command *com)
	{
		this->command = com;
	}
private:
	Command*command;

};


void testCommand()
{
	Receiver *recv = new Receiver;
	ConCreateCommand *com = new ConCreateCommand(recv);

	Invoker *invoke = new Invoker(com);

	invoke->Invoke();
}





namespace s2
{
	class ReceverTV
	{
	public:
		void ActionVolumeUp()
		{
			cout << __FUNCTION__ << endl;
		}
		void ActionPowerOn()
		{
			cout << __FUNCTION__ << endl;
		}

	};


	class Command
	{
	public:
		virtual void Execute() = 0;

	protected:
		ReceverTV *recv;
	};

	class CommandOn :public Command
	{
	public:
		virtual void Execute()override
		{
			cout << "power on" << endl;
			recv->ActionPowerOn();

		}
		CommandOn(ReceverTV *tv)
		{
			recv = tv;
		}
	};

	class CommandVolumeUp :public Command
	{
	public:
		virtual void Execute()
		{
			cout << "volume up" << endl;
			recv->ActionVolumeUp();
		}
		CommandVolumeUp(ReceverTV *tv)
		{
			recv = tv;
		}
	};
	class Invoker
	{

	public:
		void Invoke()
		{
			com->Execute();
		}
		Invoker(Command *com)
		{
			this->com = com;
		}
	private:
		Command*com;
	};



	void testCommand2()
	{
		ReceverTV*tv = new ReceverTV();

		auto *on = new CommandVolumeUp(tv);

		Invoker *invoke = new Invoker(on);
		invoke->Invoke();

	}


	void testCommand3()
	{
		ReceverTV*tv = new ReceverTV();
		auto *on = new CommandVolumeUp(tv);

		on->Execute();
	}


};


namespace s3
{


#include <functional>


	class Receiver
	{
	public:
		virtual void Action()
		{
			cout << __FUNCTION__ << endl;
		}
	};


	class Command
	{
	public:
		virtual void Execute() = 0;
	};


	class CallbackCommand :public Command
	{
	public:
		virtual void Execute()override
		{
			if (recever)
				recever();
		}
		CallbackCommand(const std::function<void(void)>& recever)
		{
			this->recever = recever;
		}
	private:
		std::function<void(void)> recever = nullptr;

	};


	void testCommand4()
	{
		Receiver *rev = new Receiver;
		Command *com = new CallbackCommand([=]()
		{
			rev->Action();
		});
		com->Execute();

		//RTTI
	//	cout << typeid(com).hash_code();

		cout << (unsigned int)(com) << endl;;





		{
			Receiver *rev = new Receiver;
			Command *com = new CallbackCommand([=]()
			{
				rev->Action();
			});
			com->Execute();

			//RTTI
			//cout << typeid(com).hash_code();
			cout << (unsigned int)(com) << endl;


		}
	//	cout <<  (unsigned int)(com);



	}

};