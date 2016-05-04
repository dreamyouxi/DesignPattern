#include "State.h"

namespace s1
{

	void SwitchState::OnChangeState(Light*light, SwitchState* state)
	{
		if (light->state)
		{
			delete light->state;
		}
		light->state = state;
	}


	void On::PressSwitch(Light *light)
	{
		this->OnChangeState(light, new Off);

	}

	void  On::PrintState()
	{
		cout << "current is on" << endl;
	}



	void  Off::PressSwitch(Light *light)
	{
		this->OnChangeState(light, new On);

	}

	void Off::PrintState()
	{
		cout << "current is off" << endl;
	}



	Light::Light(SwitchState *state)
	{
		this->state = state;
	}

	void 	Light::PressSwitch()
	{
		state->PressSwitch(this);
	}
	void 	Light::PrintCurrent()
	{
		state->PrintState();
	}


	void testState()
	{
		Light *light = new Light(new Off);


		light->PrintCurrent();
		light->PressSwitch();


		light->PrintCurrent();
		light->PressSwitch();

		light->PrintCurrent();
		light->PressSwitch();

		light->PrintCurrent();


	}
};













namespace s2
{

	void  Contex::Print()
	{
		state->PrintState();
	}
	void Contex::OperationInterface()
	{
		state->OperationInterface(this);
	}


	void  Contex::ChangeState(State*state)
	{
		this->state = state;
	}

	Contex::Contex(State*state)
	{
		this->state = state;
	}


	void State::ChangeState(Contex*contex, State*state)
	{
		contex->ChangeState(state);
	}

	void  ConCreateStateA::PrintState()
	{
		cout << "current is A" << endl;
	}
	void ConCreateStateA::OperationInterface(Contex *contex)
	{
		this->ChangeState(contex, new ConCreateStateB);
	}



	void  ConCreateStateB::OperationInterface(Contex *contex)
	{
		this->ChangeState(contex, new ConCreateStateA);
	}


	void  ConCreateStateB::PrintState()
	{
		cout << "current is B" << endl;
	}



	void testState2()
	{

		Contex *contes = new Contex(new ConCreateStateA);
		contes->Print();
		contes->OperationInterface();

		contes->Print();
		contes->OperationInterface();

		contes->Print();
		contes->OperationInterface();
	}
};