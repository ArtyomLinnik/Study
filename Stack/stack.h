#ifndef STACK_H_DEFINED
#define STACK_H_DEFINED

#include <iostream>
#include <exception>
#include <fstream>

using namespace std;

class Stack
{
protected:
	int* stack;
	int top;
	unsigned int massiveCapacity;
	double loadFactor;
	void Erase(); // очистка стека (приватный метод)
	void Clone(const Stack& ); // копирование стека (приватный метод) - эти 2 метода нужны для простоты работы со стеком. Ведь есть несколько методов удаления/записи
	void Expand(); // динамическое расширение стека
public:
	Stack(); // конструктор по умолчанию - создает стек длиной в 10 чисел
	Stack(int); // создает стек заданной длины(размера)
	Stack (int, double); // создает стек заданной длины с заданным кэффициентом заполнения
 	Stack(const Stack& ); // конструктор копирования
	void Push (int); // пушит элемент на вершину стека
	void Pop (); // удаляет элемент с вершины стека
	~Stack(); // деструктор стека
	Stack& operator = (const Stack& );
	int Size();
	bool Empty();
	int Top();
	void operator -- (); // аналог операции Pop - перегруженный оператор
	Stack& operator + (int); // аналог операции Push, только при этом еще и возвращается этот объект - перегруженный оператор
	friend ostream& operator << (ostream&, const Stack&); // перегруженный оператор вывода стека в поток. В настоящем стеке такого оператора нет, мб полезно будет вывести все эл-ты

};



#endif