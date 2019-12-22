#pragma once

class Iterator
{
private:
	char* _p;
public:
	Iterator();
	Iterator& operator=(const Iterator&);
	~Iterator();
	Iterator(char*);
	Iterator operator++();
	Iterator operator++(int);
	char& operator*();
	bool operator!=(const Iterator&);
};