#include "stack.h"

void Do()
{
	Stack* arrayOfStack;
	int size;
	cout << "Enter the capacity of Stack elements array:" << endl;
	while(true)
	{
		cin >> size;
		if(size > 0)
			break;
		else
			cout << "Size should be more than 0" << endl;
	}
	arrayOfStack = new Stack [size];
	/*
	Тут в идеале должна быть ф-ция которая удаляет 1,3,5 эл-т
	*/
}

int main()
{
	Do();

	return 0;
}