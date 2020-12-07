#include <iostream>
#include "SingletonObj.h"

int main()
{
	SingletonObj* obj1 = SingletonObj::CreateAsSingleton();
	SingletonObj* obj2 = SingletonObj::CreateAsSingleton();

	if (obj1 == obj2)
	{
		std::cout << "These pointers same !" << std::endl;;
	}
	else
	{
		std::cout << "These pointers different ! Its not singleton !" << std::endl;;
	}
}

