#include"Iterator.h"

Iterator::Iterator()
{
	_p = new char;
	*_p = '\0';
}
Iterator& Iterator::operator=(const Iterator &ite)
{
	_p = ite._p;
	return *this;
}
Iterator::~Iterator()
{
	_p = new char;
	*_p = '\0';
}
Iterator::Iterator(char* p)
{
	_p = p;
}
Iterator Iterator::operator++()
{
	Iterator temp(++_p);
	return temp;
}
Iterator Iterator::operator++(int)
{
	Iterator temp(_p++);
	return temp;
}
char& Iterator::operator*()
{
	return *_p;
}
bool Iterator::operator!=(const Iterator &ite)
{
	return *_p != *ite._p;
}