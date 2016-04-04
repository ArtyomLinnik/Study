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
	void Erase(); // ������� ����� (��������� �����)
	void Clone(const Stack& ); // ����������� ����� (��������� �����) - ��� 2 ������ ����� ��� �������� ������ �� ������. ���� ���� ��������� ������� ��������/������
	void Expand(); // ������������ ���������� �����
public:
	Stack(); // ����������� �� ��������� - ������� ���� ������ � 10 �����
	Stack(int); // ������� ���� �������� �����(�������)
	Stack (int, double); // ������� ���� �������� ����� � �������� ������������ ����������
 	Stack(const Stack& ); // ����������� �����������
	void Push (int); // ����� ������� �� ������� �����
	void Pop (); // ������� ������� � ������� �����
	~Stack(); // ���������� �����
	Stack& operator = (const Stack& );
	int Size();
	bool Empty();
	int Top();
	void operator -- (); // ������ �������� Pop - ������������� ��������
	Stack& operator + (int); // ������ �������� Push, ������ ��� ���� ��� � ������������ ���� ������ - ������������� ��������
	friend ostream& operator << (ostream&, const Stack&); // ������������� �������� ������ ����� � �����. � ��������� ����� ������ ��������� ���, �� ������� ����� ������� ��� ��-��

};



#endif