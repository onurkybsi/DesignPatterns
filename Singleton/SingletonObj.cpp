#include "SingletonObj.h"
#include <iostream>

SingletonObj* SingletonObj::instance = nullptr;

SingletonObj::SingletonObj()
{
	std::cout << "SingletonObj created !" << std::endl;;
}

SingletonObj* SingletonObj::CreateAsSingleton()
{
	if (instance == nullptr)
	{
		instance = new SingletonObj();
	}

	return instance;
}