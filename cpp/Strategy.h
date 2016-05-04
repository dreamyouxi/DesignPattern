#pragma  once

#include "PublicHeaders.h"





class Strategy
{
public:
	virtual void AlgrithmInterface() = 0;
};

class ConCreateStrategy :public Strategy
{
public:
	void AlgrithmInterface()override
	{
		cout << __FUNCTION__ << endl;
	}

};
class Contex
{
public:
	Contex(Strategy *strategy)
	{
		this->strategy = strategy;
	}

	void DoAction()
	{
		this->strategy->AlgrithmInterface();
	}
private:
	Strategy*strategy;
};


/**
 * @brief  test function for strategy pattern
 */
void testStrategy()
{
	Contex* contex = new Contex(new ConCreateStrategy);

	contex->DoAction();

}





namespace s2
{
	class WeaponStrategy
	{
	public:
		virtual void doFire() = 0;
	};

	class GaTlingGun_Strategy :public WeaponStrategy
	{
	public:
		virtual void doFire()override
		{


		}

	};

	class PistolGun_Strategy :public WeaponStrategy
	{
	public:
		virtual void doFire()override
		{

		}

	};


	class PlayerContex
	{
	public:
		void Fire()
		{
			weapon->doFire();
		}


		void setWeapon(WeaponStrategy *strategy)
		{
			this->weapon = strategy;
		}

		WeaponStrategy*weapon;
	};

	void test()
	{
		PlayerContex*player = new PlayerContex;
		player->setWeapon(new GaTlingGun_Strategy);

		player->Fire();


	}

}
