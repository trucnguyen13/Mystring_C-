#pragma once
#include"Iterator.h"
#include<iostream>
using namespace std;


class Mystring
{
public:
	Mystring();
	Mystring(const Mystring&);
	Mystring(const char*);
	Mystring(const char*, size_t);
	Mystring(const Mystring& str, size_t, size_t);
	Mystring(size_t, char);


	Mystring& operator=(const Mystring&);
	Mystring& operator=(const char*);
	Mystring& operator=(char);


	Iterator begin();
	Iterator end();
	const Iterator begin() const;
	const Iterator end() const;
	const Iterator cbegin() const noexcept;
	const Iterator cend() const noexcept;


	size_t size();
	size_t length();
	size_t max_size();
	void resize(size_t);
	void resize(size_t, char c);
	void clear();
	bool empty() const;
	size_t capacity() const;
	void shrink_to_fit();


	char& operator[] (size_t);
	const char& operator[] (size_t) const;
	char& at(size_t);
	const char& at(size_t) const;
	char& back();
	const char& back() const;
	char& front();
	const char& front() const;


	Mystring& operator+=(const Mystring&);
	Mystring& operator+=(const char*);
	Mystring& operator+=(char);

	Mystring& append(const Mystring&);
	Mystring& append(const Mystring&, size_t, size_t);
	Mystring& append(const char*);
	Mystring& append(const char*, size_t);
	Mystring& append(size_t, char);

	void push_back(char);

	Mystring& assign(const Mystring&);
	Mystring& assign(const Mystring&, size_t, size_t);
	Mystring& assign(const char*);
	Mystring& assign(const char*, size_t);
	Mystring& assign(size_t, char);

	Mystring& insert(size_t pos, const Mystring& str);
	Mystring& insert(size_t pos, const Mystring& str, size_t subpos, size_t sublen);
	Mystring& insert(size_t pos, const char* s);
	Mystring& insert(size_t pos, const char* s, size_t n);
	Mystring& insert(size_t pos, size_t n, char c);

	Mystring& erase(size_t pos, size_t len = npose);

	Mystring& replace(size_t pos, size_t len, const Mystring& str);
	Mystring& replace(size_t pos, size_t len, const Mystring& str, size_t subpos, size_t sublen);
	Mystring& replace(size_t pos, size_t len, const char* s);
	Mystring& replace(size_t pos, size_t len, const char* s, size_t n);
	Mystring& replace(size_t pos, size_t len, size_t n, char c);

	void swap(Mystring& str);
	void pop_back();


	const char* c_str() const;
	const char* data() const;
	size_t copy(char* s, size_t len, size_t pos = 0) const;

	size_t find(const Mystring& str, size_t pos = 0) const;
	size_t find(const char* s, size_t pos = 0) const;
	size_t find(const char* s, size_t pos, size_t n) const;
	size_t find(char c, size_t pos = 0) const;

	size_t rfind(const Mystring& str) const;
	size_t rfind(const char* s) const;
	size_t rfind(const char* s, size_t n) const;
	size_t rfind(char c) const;

	size_t find_first_of(const Mystring& str, size_t pos = 0) const;
	size_t find_first_of(const char* s, size_t pos = 0) const;
	size_t find_first_of(const char* s, size_t pos, size_t n) const;
	size_t find_first_of(char c, size_t pos = 0) const;

	size_t find_last_of(const Mystring& str, size_t pos = npose) const;
	size_t find_last_of(const char* s, size_t pos = npose) const;
	size_t find_last_of(const char* s, size_t pos, size_t n) const;
	size_t find_last_of(char c, size_t pos = npose) const;

	size_t find_first_not_of(const Mystring& str, size_t pos = 0) const;
	size_t find_first_not_of(const char* s, size_t pos = 0) const;
	size_t find_first_not_of(const char* s, size_t pos, size_t n) const;
	size_t find_first_not_of(char c, size_t pos = 0) const;

	size_t find_last_not_of(const Mystring& str, size_t pos = npose) const;
	size_t find_last_not_of(const char* s, size_t pos = npose) const;
	size_t find_last_not_of(const char* s, size_t pos, size_t n) const;
	size_t find_last_not_of(char c, size_t pos = npose) const;

	Mystring substr(size_t pos, size_t len = npose) const;

	int compare(const Mystring& str) const;
	int compare(size_t pos, size_t len, const Mystring& str) const;
	int compare(size_t pos, size_t len, const Mystring& str, size_t subpos, size_t sublen) const;
	int compare(const char* s) const;
	int compare(size_t pos, size_t len, const char* s) const;
	int compare(size_t pos, size_t len, const char* s, size_t n) const;


	static const const size_t npose = -1;


	friend Mystring operator+(const Mystring& lhs, const Mystring& rhs);
	friend Mystring operator+(const Mystring& lhs, const char*   rhs);
	friend Mystring operator+ (const char*   lhs, const Mystring& rhs);
	friend Mystring operator+ (const Mystring& lhs, char          rhs);
	friend Mystring operator+ (char          lhs, const Mystring& rhs);

	friend bool operator== (const Mystring& lhs, const Mystring& rhs);
	friend bool operator== (const char*     lhs, const Mystring& rhs);
	friend bool operator== (const Mystring& lhs, const char*     rhs);
	friend bool operator!= (const Mystring& lhs, const Mystring& rhs);
	friend bool operator!= (const char*     lhs, const Mystring& rhs);
	friend bool operator!= (const Mystring& lhs, const char*     rhs);
	friend bool operator<  (const Mystring& lhs, const Mystring& rhs);
	friend bool operator<  (const char*     lhs, const Mystring& rhs);
	friend bool operator<  (const Mystring& lhs, const char*     rhs);
	friend bool operator<= (const Mystring& lhs, const Mystring& rhs);
	friend bool operator<= (const char*     lhs, const Mystring& rhs);
	friend bool operator<= (const Mystring& lhs, const char*     rhs);
	friend bool operator>  (const Mystring& lhs, const Mystring& rhs);
	friend bool operator>  (const char*     lhs, const Mystring& rhs);
	friend bool operator>  (const Mystring& lhs, const char*     rhs);
	friend bool operator>= (const Mystring& lhs, const Mystring& rhs);
	friend bool operator>= (const char*     lhs, const Mystring& rhs);
	friend bool operator>= (const Mystring& lhs, const char*     rhs);

	friend istream& operator>>(istream& is, const Mystring& str);
	friend	ostream& operator<<(ostream&, const Mystring&);

	friend istream& getline(istream& is, Mystring& str, char delim);
	friend istream& getline(istream& is, Mystring& str);


	~Mystring();
private:
	char* _str;
};

size_t strlen(const char* str);



