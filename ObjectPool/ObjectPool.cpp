#include <iostream>
#include <string>
#include <list>

class CreatedObj
{
private:
	int m_Value;
public:
	CreatedObj() : m_Value(0) {}

	void Reset()
	{
		m_Value = 0;
	}

	int GetValue() const
	{
		return m_Value;
	}

	void SetValue(int value)
	{
		m_Value = value;
	}
};

class ObjectPool
{
private:
	std::list<CreatedObj*> _createdInstances;

	static ObjectPool* instance;

	ObjectPool() {}
public:
	static ObjectPool* GetInstance()
	{
		if (instance == 0)
		{
			instance = new ObjectPool;
		}

		return instance;
	}
	
	CreatedObj* GetObj()
	{
		if (_createdInstances.empty())
		{
			std::cout << "Creating new obj in the pool..." << std::endl;

			return new CreatedObj;
		}
		else
		{
			std::cout << "Return existing obj from the pool..." << std::endl;
			
			// return a reference to the first element
			CreatedObj* obj = _createdInstances.front();
			
			// remove an element from the front of a list 
			_createdInstances.pop_front();

			return obj;
		}
	}

	void DropBackIntoThePool(CreatedObj* obj)
	{
		obj->Reset();
		_createdInstances.push_back(obj);
	}
};

ObjectPool* ObjectPool::instance = 0;

int main()
{
	std::cout << "Hello World!\n";

	ObjectPool* objectPool = ObjectPool::GetInstance();

	CreatedObj* obj1 = objectPool->GetObj();
	obj1->SetValue(1);
	CreatedObj* obj2 = objectPool->GetObj();
	obj2->SetValue(2);

	objectPool->DropBackIntoThePool(obj1);

	CreatedObj* obj3 = objectPool->GetObj();

	std::cout << "obj value: " << obj3->GetValue() << std::endl;
}