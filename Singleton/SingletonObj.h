#pragma once

class SingletonObj 
{
private:
	static SingletonObj* instance;

protected:
	SingletonObj();

public:
	static SingletonObj* CreateAsSingleton();
};