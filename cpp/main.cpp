#include <algorithm>
#include<iostream>
#include "functional"
#include "windows.h"
#include <fstream>
#include <cmath>
#include <WinBase.h>  
#include "stdio.h"
#include "stdlib.h"
#include "conio.h"
#include <thread>
#include<random>
#include <memory>
#include <map>
#include <mutex>

#include <unordered_map>
using namespace std;
#include <chrono>
#include <iostream>


using namespace std::chrono;




long long calculateMS(std::function<void()> processFunc)
{
	long long _value;
	LARGE_INTEGER freq, _start, _end;
	QueryPerformanceFrequency(&freq);
	QueryPerformanceCounter(&_start);

	processFunc();

	QueryPerformanceCounter(&_end);
	_value = (_end.QuadPart - _start.QuadPart) * 1000 / freq.QuadPart;

	return _value;
}


long long calculateUS(std::function<void()> processFunc)
{
	long long _value;
	LARGE_INTEGER freq, _start, _end;
	QueryPerformanceFrequency(&freq);
	QueryPerformanceCounter(&_start);

	processFunc();

	QueryPerformanceCounter(&_end);
	_value = (_end.QuadPart - _start.QuadPart) * 1000 * 1000 / freq.QuadPart;

	return _value;
}











inline size_t _Hash_seq(const unsigned char *_First, size_t _Count)
{	// FNV-1a hash function for bytes in [_First, _First+_Count)
#if defined(_M_X64) || defined(_LP64) || defined(__x86_64) || defined(_WIN64)
	static_assert(sizeof(size_t) == 8, "This code is for 64-bit size_t.");
	const size_t _FNV_offset_basis = 14695981039346656037ULL;
	const size_t _FNV_prime = 1099511628211ULL;

#else /* defined(_M_X64), etc. */
	static_assert(sizeof(size_t) == 4, "This code is for 32-bit size_t.");
	const size_t _FNV_offset_basis = 2166136261U;
	const size_t _FNV_prime = 16777619U;
#endif /* defined(_M_X64), etc. */

	size_t _Val = _FNV_offset_basis;
	for (size_t _Next = 0; _Next < _Count; ++_Next)
	{	// fold in another byte
		_Val ^= (size_t)_First[_Next];
		_Val *= _FNV_prime;
	}

#if defined(_M_X64) || defined(_LP64) || defined(__x86_64) || defined(_WIN64)
	static_assert(sizeof(size_t) == 8, "This code is for 64-bit size_t.");
	_Val ^= _Val >> 32;

#else /* defined(_M_X64), etc. */
	static_assert(sizeof(size_t) == 4, "This code is for 32-bit size_t.");
#endif /* defined(_M_X64), etc. */

	return (_Val);
}



static unsigned int getHashByKey(const char *key)
{
	unsigned int len = strlen(key);
	const char *end = key + len;
	unsigned int hash;

	for (hash = 0; key < end; key++)
	{
		hash *= 16777619;
		hash ^= (unsigned int)(unsigned char)toupper(*key);
	}
	return (hash);
}






class Weapon
{
public:
	virtual void use() = 0;

};




class WeaponImpl
{
public:

	void use()
	{
		weapon->use();
	}
	WeaponImpl(Weapon* wea)
	{
		this->weapon = wea;
	}
private:
	Weapon * weapon;
};




class Gun :public Weapon
{
public:
	virtual void use()override
	{
		cout << "shoot" << endl;
	}


};







class Player
{
public:


	void EquipWeapon(WeaponImpl* weapon)
	{
		this->weaponImpl = weapon;
	}
	void useWeapon()
	{
		weaponImpl->use();
	}
private:

	WeaponImpl *weaponImpl;



};





class AbstractionImpl
{
public:
	virtual void Operation() = 0;


};

class AbstractionImplA :public AbstractionImpl
{
public:
	virtual void Operation()override
	{

		cout << "do Action" << endl;
	}


};

class Abstraction
{
public:
	virtual void Operation() = 0;

};





class RefinedAbstrantion :public Abstraction
{
public:
	virtual void Operation()override
	{
		impl->Operation();

	}
	RefinedAbstrantion(AbstractionImpl *impl)
	{
		this->impl = impl;

	}
private:
	AbstractionImpl *impl;

};




class AbstractClass
{
public:
	virtual void TemplateMethod()
	{
		this->Primitive2();
		this->Primitive1();
	}
protected:
	virtual void Primitive1() = 0;
	virtual void Primitive2() = 0;
};

class ConCreateClass1 :public AbstractClass
{
public:

	virtual void Primitive2()
	{
		cout << __FUNCTION__ << endl;
	}
	virtual void Primitive1()
	{
		cout << __FUNCTION__ << endl;
	}

};




#include "Strategy.h"
#include "Factory.h"
#include "State.h"
#include "Observer.h"
#include "Memento.h"
#include "Mediator.h"
#include "Command.h"

int main(int argc, char *argv[])
{
	s3::testCommand4();
 


	system("pause");
	return 0;
}





