#pragma  once

#include "PublicHeaders.h"


namespace s1
{

	class Light;

	class SwitchState
	{
	public:
		virtual void PressSwitch(Light *light) = 0;
		virtual void PrintState() = 0;
	protected:
		void OnChangeState(Light*light, SwitchState* state);
	};


	class On :public SwitchState
	{
	public:
		virtual void PressSwitch(Light *light);
		virtual void PrintState();

	};
	class Off :public SwitchState
	{
	public:
		virtual void PressSwitch(Light *light);

		virtual void PrintState();



	};


	class Light
	{
	public:
		Light(SwitchState *state);

		void PressSwitch();
		void PrintCurrent();
	private:
		SwitchState* state = nullptr;
		friend class SwitchState;
	};



	void testState();
}



namespace s2
{
	class State;

	class Contex
	{
	public:
		Contex(State*state);
		void OperationInterface();
		void Print();
	private:
		void ChangeState(State*state);
		State*state = nullptr;
		friend class State;

	};

	class State
	{
	public:
		virtual void PrintState() = 0;
		virtual	void OperationInterface(Contex *contex) = 0;
	protected:
		void ChangeState(Contex*contex, State*state);

	};

	class ConCreateStateA :public State
	{
	public:
		virtual void OperationInterface(Contex *contex)override;
		virtual void PrintState() override;
	};

	class ConCreateStateB :public State
	{
	public:
		virtual void OperationInterface(Contex *contex)override;
		virtual void PrintState() override;
	};



	void testState2();
}