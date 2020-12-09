//Prototype is a creational design pattern that allows cloning objects, even complex ones, without coupling to their specific classes.

#include <iostream>

class IPrototype {
public:
	virtual IPrototype* Clone() = 0;
	virtual int GetData() const = 0;
};

class PrototypeA : public IPrototype {
private:
	int m_Data;

public:
	PrototypeA(int data) : m_Data(data) {}
	PrototypeA(const PrototypeA& other) : m_Data(other.m_Data) {}

	int GetData() const
	{
		return m_Data;
	}

	PrototypeA* Clone() override
	{
		return new PrototypeA(*this);
	}
};


int main()
{
	IPrototype* p1 = new PrototypeA(1234);
	IPrototype* p2 = p1->Clone();

	std::cout << p1->GetData() << std::endl;
	std::cout << p2->GetData() << std::endl;
}