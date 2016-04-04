#include "stack.h"

#define INVALID_SIZE_EXCEPTION "Can't create Stack object! It's impossible to create negative-size stack!"
#define EMPTY_STACK_CONSTRUCTOR_EXCEPTION "Can't create Stack object! It's impossible to create stack with empty volume!" 
#define INVALID_LOADFACTOR "Can't create Stack object! Uncorrect loadFactor parameter, please, enter loadFactor between 0,1 and 1."
#define EMPTY_STACK_EXCEPTION "Stack is empty!"
#define STANDARD_SIZE 10
#define STANDARD_LOADFACTOR 0.9

Stack::Stack()
{
		stack = new int [STANDARD_SIZE];
		top = 0; // вершина стека
		massiveCapacity = STANDARD_SIZE;
		loadFactor = STANDARD_LOADFACTOR;
}

Stack::Stack(int size)
{
	if(size < 0)
		throw exception (INVALID_SIZE_EXCEPTION);
	else
		if(size == 0)
			throw exception (EMPTY_STACK_CONSTRUCTOR_EXCEPTION);
	stack = new int [size];
	top = 0;
	massiveCapacity = size;
	loadFactor = STANDARD_LOADFACTOR;
}

Stack::Stack (int size, double loadFactor)
{
	if(size < 0)
		throw exception (INVALID_SIZE_EXCEPTION);
	else
		if(size == 0)
			throw exception (EMPTY_STACK_EXCEPTION);
		else
			if(loadFactor < 0,1 || loadFactor > 1)
				throw exception (INVALID_LOADFACTOR);

	stack = new int [size];
	top = 0;
	massiveCapacity = size;
	this->loadFactor = loadFactor;
}

Stack::Stack(const Stack& obj)
{
	stack = nullptr;
	Clone(obj);
}

void Stack::Erase()
{
	delete [] stack;
	top = 0;
	massiveCapacity = 0;
}

void Stack::Clone(const Stack& obj)
{
	if(stack != nullptr)
		delete [] stack;
	massiveCapacity = obj.massiveCapacity;
	loadFactor = obj.loadFactor;
	top = obj.top;
	stack = new int [massiveCapacity];
	for(int i = 0; i < top; ++i)
	{
		stack[i] = obj.stack[i]; 
	}
}

void Stack::Expand()
{
	int* bufferedStack = new int [top];
	for(int i = 0; i < top; ++i)
	{
		bufferedStack[i] = stack[i];
	}
	delete [] stack;
	stack = new int [(int)((1.0 + loadFactor) * (float)massiveCapacity)];
	for(int i = 0; i < top; ++i)
	{
		stack[i] = bufferedStack[i];
	}
	massiveCapacity = (unsigned int)((1.0 + loadFactor) * (float)massiveCapacity);
}

void Stack::Push (int currentElement)
{
	if(top > (int)((float)massiveCapacity * loadFactor) - 1)
		// ситуация "закончилась память" - нужно выделить дополнительную
		Expand();
	stack[top++] = currentElement;
}

void Stack::Pop ()
{
	if(top == 0)
		throw exception (EMPTY_STACK_EXCEPTION);
	--top;
}

Stack::~Stack ()
{
	Erase();
}

Stack& Stack::operator = (const Stack& obj)
{
	if(this != &obj)
		Clone(obj);
	return *this;
}

int Stack::Size()
{
	return top;
}

bool Stack::Empty()
{
	return top == 0;
}

int Stack::Top()
{
	return stack[top - 1];
}

void Stack::operator-- ()
{
	return Pop();
}

Stack& Stack::operator + (int currentElement)
{
	Push(currentElement);
	return *this;
}

ostream& operator << (ostream& stream, const Stack& obj)
{
	for(int i = 0; i < obj.top; ++i) // очевидно, что вершина будет справа на консоли, если нужно слева - обратный цикл
	{
		stream << obj.stack[i] << " ";
	}
	return stream;
}