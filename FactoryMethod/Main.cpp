#include <iostream>

using namespace std;

class Entity {};

class IProcessor
{
public:
    virtual void Process(Entity* e) = 0;
};

class ProcessorA : public IProcessor 
{
public:
    void Process (Entity* e) override 
    {
        cout << "Entity processed by ProcessorA !" << endl;
    }
};

class ProcessorB : public IProcessor
{
public:
    void Process(Entity* e) override
    {
        cout << "Entity processed by ProcessorB !" << endl;
    }
};

enum class ProccesorType
{
    A, B
};

class ProcessorCreator
{
public:
    IProcessor* CreateProcessor(ProccesorType processorType)
    {
        if (processorType == ProccesorType::A)
            return new ProcessorA();
        else if (processorType == ProccesorType::B)
            return new ProcessorB();
        else
            return nullptr;
    }
};

int main()
{
    ProcessorCreator processorCreator = ProcessorCreator();

    IProcessor* processor1 = processorCreator.CreateProcessor(ProccesorType::A);
    IProcessor* processor2 = processorCreator.CreateProcessor(ProccesorType::B);

    Entity e = Entity();

    processor1->Process(&e);
    processor2->Process(&e);
}