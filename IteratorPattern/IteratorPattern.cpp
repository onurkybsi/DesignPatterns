#include <iostream>
#include <vector>

class Iterator
{
public:
	virtual bool next() = 0;
	// void* like pointer of any type 
	virtual void* getItem() = 0;
};


class VectorIterator : public Iterator
{
private:
	std::vector<int> _storage;
	int index = 0;
public:
	void* getItem() override
	{

	}
	bool next() override
	{

	}
};

class ArrayIterator : public Iterator
{
private:
	int* _storage;
	int index = 0;
public:
	void* getItem() override
	{

	}
	bool next() override
	{

	}
};

class Iterable
{
public:
	virtual Iterator* GetIterator() = 0;
};

class IterableA : public Iterable
{
private:
	std::vector<int> _storage;
public:
	IterableA() {};

	std::vector<int> GetItems() 
	{
		return _storage;
	}

	Iterator* GetIterator() override
	{
		return new VectorIterator();
	}
};

class IterableB : public Iterable
{
private:
	int* _storage = new int[5];
public:
	IterableB() {};

	int* GetItems()
	{
		return _storage;
	}

	Iterator* GetIterator() override
	{
		return new ArrayIterator();
	}
};

int main()
{
}