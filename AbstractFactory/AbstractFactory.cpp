#include <iostream>
#include <string>

class AbstractProductA
{
public:
    virtual std::string GetProductAInfo() const = 0;
};

class AbstractProductB
{
public:
    virtual std::string GetProductBInfo() const = 0;
};

class AbstractFactory
{
public:
    virtual AbstractProductA* CreateProductA() const = 0;
    virtual AbstractProductB* CreateProductB() const = 0;
};

class ConcreteProductA : public AbstractProductA
{
public:
    std::string GetProductAInfo() const
    {
        return "ProductAInfo by ConcreteProductA";
    }
};

class ConcreteProductB : public AbstractProductB
{
public:
    std::string GetProductBInfo() const
    {
        return "ProductBInfo by ConcreteProductB";
    }
};

class ConcreteFactoryA : public AbstractFactory
{
    AbstractProductA* CreateProductA() const
    {
        return new ConcreteProductA();
    }

    AbstractProductB* CreateProductB() const 
    {
        return new ConcreteProductB();
    }
};

int main()
{
    std::cout << "Hello World!\n";

    // It may be different factory imp.
    AbstractFactory* abstractFactory = new ConcreteFactoryA();

    AbstractProductA* abstractProductA = abstractFactory->CreateProductA();
    std::cout << abstractProductA->GetProductAInfo() << std::endl;

    AbstractProductB* abstractProductB = abstractFactory->CreateProductB();
    std::cout << abstractProductB->GetProductBInfo() << std::endl;
}