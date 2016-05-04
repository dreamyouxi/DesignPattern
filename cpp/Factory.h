#pragma  once

#include "PublicHeaders.h"
 
namespace s1
{
	class Object
	{
	public:
		static  Object*create()
		{
			return new Object;
		}
	private:
		Object(){}
	};

	void testFactory1()
	{
		Object::create();
	}
}


namespace s2
{
	class Product
	{
	public:
		virtual void Opreation() = 0;
	};

	class ConCreateProduct1:public Product
	{
	public:
		void Opreation()override
		{
			cout << __FUNCTION__ << endl;
		}
	};

	class Factory
	{
	public: 
		Product* CreateProduct()
		{
			return new ConCreateProduct1;
		}
	};

	void testFactory2()
	{
		Factory *fa = new Factory;

		fa->CreateProduct()->Opreation();




	}
}


namespace s3
{



}