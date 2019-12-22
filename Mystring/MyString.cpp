#pragma once
#include"MyString.h"


size_t strlen(const char* str)
{
	size_t len = 0;
	for (size_t i = 0; str[i] != '\0'; i++)
		len++;

	return len;
}

Mystring::Mystring()
{
	_str = new char;
	*_str = '\0';
}

Mystring::Mystring(const Mystring& mystr)
{
	size_t len = strlen(mystr._str);

	_str = new char[len + 1];
	for (size_t i = 0; i < len; i++)
		_str[i] = mystr._str[i];

	_str[len] = '\0';

}

Mystring::Mystring(const char* str)
{
	size_t len = strlen(str);

	_str = new char[len + 1];
	for (size_t i = 0; i < len; i++)
		_str[i] = str[i];

	_str[len] = '\0';

}

Mystring::Mystring(const char* str, size_t n)
{
	_str = new char[n + 1];

	size_t i = 0;
	for (i; i < n; i++)
		if (str[i] != '\0')
			_str[i] = str[i];
		else
			break;

	if (i < n)
		for (i; i < n; i++)
			_str[i] = ' ';

	_str[n] = '\0';
}
Mystring::Mystring(const Mystring& mystr, size_t pos, size_t len)
{

}
Mystring::Mystring(size_t n, char c)
{
	_str = new char[n + 1];
	for (size_t i = 0; i < n; i++)
		_str[i] = c;

	_str[n] = '\0';
}



Mystring& Mystring::operator=(const Mystring &str)
{
	Mystring strTemp(str);
	char* pTemp = strTemp._str;
	strTemp._str = _str;
	_str = pTemp;

	delete[] strTemp._str;
	strTemp._str = NULL;

	return *this;
}


Mystring& Mystring::operator=(const char* str)
{
	Mystring strTemp(str);
	char* pTemp = strTemp._str;
	strTemp._str = _str;
	_str = pTemp;

	delete[] strTemp._str;
	strTemp._str = NULL;

	return *this;
}

Mystring& Mystring::operator=(char c)
{
	delete[] _str;
	_str = NULL;

	_str = new char[2];
	_str[0] = c;
	_str[1] = '\0';
	return *this;
}


Iterator Mystring::begin()
{
	Iterator beg(_str);
	return beg;
}
Iterator Mystring::end()
{
	Iterator endd(_str + strlen(_str));
	return endd;
}

const Iterator Mystring::begin() const
{
	Iterator beg(_str);
	return beg;
}
const Iterator Mystring::end() const
{
	Iterator endd(_str + strlen(_str));
	return endd;
}
const Iterator Mystring::cbegin() const noexcept
{
	Iterator beg(_str);
	return beg;
}
const Iterator Mystring::cend() const noexcept
{
	Iterator endd(_str + strlen(_str));
	return endd;
}


size_t Mystring::size()
{
	size_t len = 0;
	for (size_t i = 0; _str[i] != '\0'; i++)
		len++;
	return len;
}
size_t Mystring::length()
{
	size_t len = 0;
	for (size_t i = 0; _str[i] != '\0'; i++)
		len++;
	return len;
}
size_t Mystring::max_size()
{
	return LONG_MAX;
}
void Mystring::resize(size_t n)
{
	size_t len = this->size();
	if (n < len)
	{
		_str[n] = '\0';
		return;
	}


	char* str = new char[n + 1];

	size_t i = 0;
	for (i; i < len; i++)
		str[i] = _str[i];

	if (i < n)
		for (i; i < n; i++)
			str[i] = ' ';

	delete[] _str;
	_str = NULL;

	str[n] = '\0';
	_str = str;
}
void Mystring::resize(size_t n, char c)
{
	size_t len = this->size();
	if (n < len)
	{
		_str[n] = '\0';
		return;
	}

	char* str = new char[n + 1];

	size_t i = 0;
	for (i; i < len; i++)
		str[i] = _str[i];

	if (i < n)
		for (i; i < n; i++)
			str[i] = c;

	delete[] _str;
	_str = NULL;

	str[n] = '\0';
	_str = str;
}
void Mystring::clear()
{
	*_str = '\0';
}
bool Mystring::empty() const
{
	return *_str == '\0';
}
size_t Mystring::capacity() const
{
	size_t len = 0;
	for (size_t i = 0; _str[i] != '\0'; i++)
		len++;

	len = len / 16;
	return 16 * len + 15;
}
void Mystring::shrink_to_fit()
{
	size_t len = this->size();

	char *str = new char[len];
	for (size_t i = 0; i < len; i++)
		str[i] = _str[i];

	str[len] = '\0';
	_str = str;
}





char& Mystring::operator[] (size_t pos)
{
	try
	{
		if (pos > strlen(_str))
			throw exception("Out of range");
		return *(_str + pos);
	}
	catch (const exception& excep)
	{
		cerr << excep.what() << endl;
		//exit(1);
	}
}
const char& Mystring::operator[] (size_t pos) const
{
	try
	{
		if (pos > strlen(_str))
			throw exception("Out of range");
		return *(_str + pos);
	}
	catch (const exception& excep)
	{
		cerr << excep.what() << endl;
		//exit(1);
	}
}
char& Mystring::at(size_t pos)
{
	try
	{
		if (pos > strlen(_str))
			throw exception("Out of range");
		return *(_str + pos);
	}
	catch (const exception& excep)
	{
		cerr << excep.what() << endl;
		//exit(1);
	}
}
const char& Mystring::at(size_t pos) const
{
	try
	{
		if (pos > strlen(_str))
			throw exception("Out of range");
		return *(_str + pos);
	}
	catch (const exception& excep)
	{
		cerr << excep.what() << endl;
		//exit(1);
	}
}
char& Mystring::back()
{
	return *(this->_str + this->size() - 1);
}
const char& Mystring::back() const
{
	size_t len = 0;
	for (size_t i = 0; _str[i] != '\0'; i++)
		len++;

	return *(_str + len - 1);
}
char& Mystring::front()
{
	return *_str;
}
const char& Mystring::front() const
{
	return *_str;
}












Mystring& Mystring::operator+=(const Mystring& mystr)
{
	size_t len = strlen(_str);
	size_t leng = strlen(mystr._str);


	char* str = new char[len + leng + 1];
	for (size_t i = 0; i < len; i++)
		str[i] = _str[i];

	for (size_t i = 0; i < leng; i++)
		str[i + len] = mystr._str[i];

	str[len + leng] = '\0';

	delete[] _str;
	_str = NULL;

	_str = str;
	return *this;
}
Mystring& Mystring::operator+=(const char* strr)
{
	size_t len = strlen(_str);
	size_t leng = strlen(strr);


	char* str = new char[len + leng + 1];
	for (size_t i = 0; i < len; i++)
		str[i] = _str[i];

	for (size_t i = 0; i < leng; i++)
		str[i + len] = strr[i];

	str[len + leng] = '\0';

	delete[] _str;
	_str = NULL;

	_str = str;
	return *this;
}
Mystring& Mystring::operator+=(char c)
{
	size_t len = strlen(_str);
	char* str = new char[len + 2];

	for (size_t i = 0; i < len; i++)
		str[i] = _str[i];
	str[len] = c;

	str[len + 1] = '\0';

	delete[] _str;
	_str = NULL;

	_str = str;
	return *this;
}
Mystring& Mystring::append(const Mystring& mystr)
{

	size_t len = strlen(_str);
	size_t leng = strlen(mystr._str);


	char* str = new char[len + leng + 1];
	for (size_t i = 0; i < len; i++)
		str[i] = _str[i];

	for (size_t i = 0; i < leng; i++)
		str[i + len] = mystr._str[i];

	str[len + leng] = '\0';

	delete[] _str;
	_str = NULL;

	_str = str;
	return *this;
}
Mystring& Mystring::append(const Mystring& mystr, size_t pos, size_t len)
{
	return *this;
}
Mystring& Mystring::append(const char* strr)
{
	size_t len = strlen(_str);
	size_t leng = strlen(strr);


	char* str = new char[len + leng + 1];
	for (size_t i = 0; i < len; i++)
		str[i] = _str[i];

	for (size_t i = 0; i < leng; i++)
		str[i + len] = strr[i];

	str[len + leng] = '\0';

	delete[] _str;
	_str = NULL;

	_str = str;
	return *this;
}
Mystring& Mystring::append(const char* strr, size_t n)
{
	size_t len = strlen(_str);

	char* str = new char[len + n + 1];
	for (size_t i = 0; i < len; i++)
		str[i] = _str[i];

	size_t i = 0;
	for (i; i < n; i++)
		if (strr[i] != '\0')
			str[i + len] = strr[i];
		else
			break;

	if (i < n)
		for (i; i < n; i++)
			str[i + len] = ' ';

	str[len + n] = '\0';

	delete[] _str;
	_str = NULL;

	_str = str;
	return *this;
}
Mystring& Mystring::append(size_t n, char c)
{
	size_t len = strlen(_str);
	char* str = new char[len + n + 1];

	for (size_t i = 0; i < len; i++)
		str[i] = _str[i];

	for (size_t i = 0; i < n; i++)
		str[i + len] = n;

	str[len + n] = '\0';

	delete[] _str;
	_str = NULL;


	_str = str;
	return *this;
}
void Mystring::push_back(char c)
{
	size_t len = strlen(_str);
	char* str = new char[len + 2];

	for (size_t i = 0; i < len; i++)
		str[i] = _str[i];
	str[len] = c;
	str[len + 1] = '\0';

	delete[] _str;
	_str = NULL;

	_str = str;
}
Mystring& Mystring::assign(const Mystring& mystr)
{
	delete[] _str;
	_str = NULL;

	size_t len = strlen(mystr._str);

	_str = new char[len + 1];
	for (size_t i = 0; i < len; i++)
		_str[i] = mystr._str[i];

	_str[len] = '\0';

	return *this;
}
Mystring& Mystring::assign(const Mystring& mystr, size_t pos, size_t len)
{
	return *this;
}
Mystring& Mystring::assign(const char* str)
{
	delete[] _str;
	_str = NULL;

	size_t len = strlen(str);

	_str = new char[len + 1];
	for (size_t i = 0; i < len; i++)
		_str[i] = str[i];

	_str[len] = '\0';

	return *this;
}
Mystring& Mystring::assign(const char* str, size_t n)
{
	delete[] _str;
	_str = NULL;


	_str = new char[n + 1];

	size_t i = 0;
	for (i; i < n; i++)
		if (str[i] != '\0')
			_str[i] = str[i];
		else
			break;

	if (i < n)
		for (i; i < n; i++)
			_str[i] = ' ';

	_str[n] = '\0';
	return *this;
}
Mystring& Mystring::assign(size_t n, char c)
{
	delete[] _str;
	_str = NULL;

	_str = new char[n + 1];
	for (size_t i = 0; i < n; i++)
		_str[i] = c;

	_str[n] = '\0';
	return *this;
}



////////////////////////////////////////////////////////////////////////
Mystring& Mystring::insert(size_t pos, const Mystring& mystr)
{
	try
	{
		size_t len = strlen(_str);
		size_t leng = strlen(mystr._str);

		if (pos > len)
			throw exception("Out of range");

		char* str = new char[len + leng + 1];

		for (size_t i = 0; i < pos; i++)
			str[i] = _str[i];

		for (size_t i = 0; i < leng; i++)
			str[i + pos] = mystr._str[i];

		for (size_t i = pos; i < len; i++)
			str[i + leng] = _str[i];

		str[len + leng] = '\0';

		delete[] _str;
		_str = NULL;

		_str = str;
		return *this;
	}
	catch (const exception& excep)
	{
		cerr << excep.what() << endl;
		//exit(1);
	}


}
Mystring& Mystring::insert(size_t pos, const Mystring& mystr, size_t subpos, size_t sublen)
{
	try
	{
		size_t len = strlen(_str);
		size_t leng = strlen(mystr._str);

		if (pos > len)
			throw exception("Out of range");
		if (subpos > leng)
			throw exception("Out of range");

		if (sublen + subpos > leng)
			sublen = leng - subpos;

		char* str = new char[len + sublen + 1];

		for (size_t i = 0; i < pos; i++)
			str[i] = _str[i];

		for (size_t i = 0; i < sublen; i++)
			str[i + pos] = mystr._str[i + subpos];

		for (size_t i = pos; i < len; i++)
			str[i + sublen] = _str[i];

		str[len + sublen] = '\0';

		delete[] _str;
		_str = NULL;

		_str = str;
		return *this;
	}
	catch (const exception& excep)
	{
		cerr << excep.what() << endl;
		//exit(1);
	}
}
Mystring& Mystring::insert(size_t pos, const char* strr)
{
	try
	{
		size_t len = strlen(_str);
		size_t leng = strlen(strr);

		if (pos > len)
			throw exception("Out of range");

		char* str = new char[len + leng + 1];

		for (size_t i = 0; i < pos; i++)
			str[i] = _str[i];

		for (size_t i = 0; i < leng; i++)
			str[i + pos] = strr[i];

		for (size_t i = pos; i < len; i++)
			str[i + leng] = _str[i];

		str[len + leng] = '\0';

		delete[] _str;
		_str = NULL;

		_str = str;
		return *this;
	}

	catch (const exception& excep)
	{
		cerr << excep.what() << endl;
		//exit(1);
	}
}
Mystring& Mystring::insert(size_t pos, const char* strr, size_t sublen)
{
	try
	{
		size_t subpos = 0;
		size_t len = strlen(_str);
		size_t leng = strlen(strr);
		if (sublen + subpos > leng)
			sublen = leng - subpos;

		if (pos > len)
			throw exception("Out of range");


		char* str = new char[len + sublen + 1];

		for (size_t i = 0; i < pos; i++)
			str[i] = _str[i];

		for (size_t i = 0; i < sublen; i++)
			str[i + pos] = strr[i + subpos];

		for (size_t i = pos; i < len; i++)
			str[i + sublen] = _str[i];

		str[len + sublen] = '\0';

		delete[] _str;
		_str = NULL;

		_str = str;
		return *this;
	}
	catch (const exception& excep)
	{
		cerr << excep.what() << endl;
		//exit(1);
	}
}
Mystring& Mystring::insert(size_t pos, size_t n, char c)
{
	try
	{
		size_t len = strlen(_str);

		if (pos > len)
			throw exception("Out of range");

		char* str = new char[len + n + 1];

		for (size_t i = 0; i < pos; i++)
			str[i] = _str[i];

		for (size_t i = 0; i < n; i++)
			str[i + pos] = c;

		for (size_t i = pos; i < len; i++)
			str[i + n] = _str[i];

		str[len + n] = '\0';

		delete[] _str;
		_str = NULL;

		_str = str;
		return *this;
	}
	catch (const exception& excep)
	{
		cerr << excep.what() << endl;
		//exit(1);
	}
}

Mystring& Mystring::erase(size_t pos, size_t len)
{
	try
	{
		size_t leng = strlen(_str);

		if (pos > leng)
			throw exception("Out of range");

		if (len + pos > leng)
			len = leng - pos;
		char* str = new char[leng - len + 1];

		for (size_t i = 0; i < pos; i++)
			str[i] = _str[i];

		for (size_t i = 0; i < leng - len - pos; i++)
			str[i + pos] = _str[i + pos + len];

		str[leng - len] = '\0';

		delete[] _str;
		_str = NULL;

		_str = str;
		return *this;
	}
	catch (const exception& excep)
	{
		cerr << excep.what() << endl;
		//exit(1);
	}
}




void Mystring::swap(Mystring& str)
{
	char* temp = str._str;
	str._str = _str;
	_str = temp;
}

void Mystring::pop_back()
{
	this->back() = '\0';
}



Mystring& Mystring::replace(size_t pos, size_t len, const Mystring& mystr)
{
	try
	{
		size_t leng = strlen(_str);

		if (pos > leng)
			throw exception("Out of range");

		size_t lengg = strlen(mystr._str);
		if (pos + len > leng)
			len = leng - pos;

		char* str = new char[leng - len + lengg + 1];

		for (size_t i = 0; i < pos; i++)
			str[i] = _str[i];
		for (size_t i = 0; i < lengg; i++)
			str[i + pos] = mystr._str[i];
		for (size_t i = 0; i < leng - len - pos; i++)
			str[i + pos + lengg] = _str[i + pos + len];

		delete[] _str;
		_str = NULL;

		str[leng - len + lengg] = '\0';
		_str = str;
		return *this;
	}
	catch (const exception& excep)
	{
		cerr << excep.what() << endl;
		//exit(1);
	}
}
Mystring& Mystring::replace(size_t pos, size_t len, const Mystring& mystr, size_t subpos, size_t sublen)
{
	try
	{
		size_t leng = strlen(_str);
		if (pos > leng)
			throw exception("Out of range");

		size_t lengg = strlen(mystr._str);
		if (subpos > lengg)
			throw exception("Out of range");

		if (pos + len > leng)
			len = leng - pos;
		if (subpos + sublen > lengg)
			sublen = lengg - subpos;

		char* str = new char[leng - len + sublen + 1];

		for (size_t i = 0; i < pos; i++)
			str[i] = _str[i];

		for (size_t i = 0; i < sublen; i++)
			str[i + pos] = mystr._str[i + subpos];

		for (size_t i = 0; i < leng - pos - len; i++)
			str[i + pos + sublen] = _str[i + pos + len];


		delete[] _str;
		_str = NULL;


		str[leng - len + sublen] = '\0';
		_str = str;
		return *this;
	}
	catch (const exception& excep)
	{
		cerr << excep.what() << endl;
		//exit(1);
	}
}
Mystring& Mystring::replace(size_t pos, size_t len, const char* strr)
{
	try
	{
		size_t leng = strlen(_str);
		if (pos > leng)
			throw exception("Out of range");

		size_t lengg = strlen(strr);
		if (pos + len > leng)
			len = leng - pos;

		char* str = new char[leng - len + lengg + 1];

		for (size_t i = 0; i < pos; i++)
			str[i] = _str[i];
		for (size_t i = 0; i < lengg; i++)
			str[i + pos] = strr[i];
		for (size_t i = 0; i < leng - len - pos; i++)
			str[i + pos + lengg] = _str[i + pos + len];

		delete[] _str;
		_str = NULL;

		str[leng - len + lengg] = '\0';
		_str = str;
		return *this;
	}
	catch (const exception& excep)
	{
		cerr << excep.what() << endl;
		//exit(1);
	}
}
Mystring& Mystring::replace(size_t pos, size_t len, const char* strr, size_t n)
{
	try
	{
		size_t leng = strlen(_str);
		if (pos > leng)
			throw exception("Out of range");


		size_t lengg = strlen(strr);
		if (pos + len > leng)
			len = leng - pos;
		if (n > lengg)
			n = lengg;

		char* str = new char[leng - len + n + 1];

		for (size_t i = 0; i < pos; i++)
			str[i] = _str[i];

		for (size_t i = 0; i < n; i++)
			str[i + pos] = strr[i];

		for (size_t i = 0; i < leng - pos - len; i++)
			str[i + pos + n] = _str[i + pos + len];


		delete[] _str;
		_str = NULL;


		str[leng - len + n] = '\0';
		_str = str;
		return *this;
	}
	catch (const exception& excep)
	{
		cerr << excep.what() << endl;
		//exit(1);
	}
}
Mystring& Mystring::replace(size_t pos, size_t len, size_t n, char c)
{
	try
	{
		size_t leng = strlen(_str);
		if (pos > leng)
			throw exception("Out of range");

		if (pos + len > leng)
			len = leng - pos;

		char* str = new char[leng - len + n + 1];

		for (size_t i = 0; i < pos; i++)
			str[i] = _str[i];

		for (size_t i = 0; i < n; i++)
			str[i + pos] = c;

		for (size_t i = 0; i < leng - pos - len; i++)
			str[i + pos + n] = _str[i + pos + len];


		delete[] _str;
		_str = NULL;


		str[leng - len + n] = '\0';
		_str = str;
		return *this;
	}
	catch (const exception& excep)
	{
		cerr << excep.what() << endl;
		//exit(1);
	}
}




const char* Mystring::c_str() const
{
	return _str;
}
const char* Mystring::data() const
{
	return _str;
}

size_t Mystring::copy(char* s, size_t len, size_t pos) const
{
	try
	{
		int leng = strlen(_str);
		if (pos > leng)
			throw exception("Out of range");
		if (strlen(s) < len)
			throw exception("Out of range");

		//int lengg = strlen(s);
		if (len + pos > leng)
			len = leng - pos;
		for (size_t i = 0; i < len; i++)
			s[i] = _str[i + pos];
		return len;
	}
	catch (const exception& excep)
	{
		cerr << excep.what() << endl;
		//exit(1);
	}

}



size_t Mystring::find(const Mystring& mystr, size_t pos) const
{
	try
	{
		size_t len = strlen(_str);
		if (pos > len)
			throw exception("Out of range");

		size_t leng = strlen(mystr._str);

		for (size_t i = pos; i < len; i++)
			if (_str[i] == mystr._str[0])
			{
				size_t j = 0;
				for (j; j < leng; j++)
					if (_str[i + j] != mystr._str[j])
						break;
				if (j == leng)
					return i;
			}

		return this->npose;
	}
	catch (const exception& excep)
	{
		cerr << excep.what() << endl;
		//exit(1);
	}
}
size_t Mystring::find(const char* strr, size_t pos) const
{
	try
	{
		size_t len = strlen(_str);
		if (pos > len)
			throw exception("Out of range");

		size_t leng = strlen(strr);

		for (size_t i = pos; i < len; i++)
			if (_str[i] == strr[0])
			{
				size_t j = 0;
				for (j; j < leng; j++)
					if (_str[i + j] != strr[j])
						break;
				if (j == leng)
					return i;
			}

		return this->npose;
	}
	catch (const exception& excep)
	{
		cerr << excep.what() << endl;
		//exit(1);
	}
}
size_t Mystring::find(const char* strr, size_t pos, size_t n) const
{
	try
	{
		size_t len = strlen(_str);
		if (pos > len)
			throw exception("Out of range");

		size_t leng = strlen(strr);

		if (n > leng)
			n = leng;

		for (size_t i = pos; i < len; i++)
			if (_str[i] == strr[0])
			{
				size_t j = 0;
				for (j; j < n; j++)
					if (_str[i + j] != strr[j])
						break;
				if (j == n)
					return i;
			}

		return this->npose;
	}
	catch (const exception& excep)
	{
		cerr << excep.what() << endl;
		//exit(1);
	}
}
size_t Mystring::find(char c, size_t pos) const
{
	try
	{
		size_t len = strlen(_str);
		if (pos > len)
			throw exception("Out of range");

		for (size_t i = pos; i < len; i++)
			if (_str[i] == c)
				return i;

		return this->npose;
	}
	catch (const exception& excep)
	{
		cerr << excep.what() << endl;
		//exit(1);
	}
}


size_t Mystring::rfind(const Mystring& mystr) const
{
	size_t len = strlen(_str);
	size_t leng = strlen(mystr._str);

	for (size_t i = len - 1; i >= 0; i--)
		if (_str[i] == mystr._str[leng - 1])
		{
			size_t j = 0;
			for (j; j < leng; j++)
				if (_str[i - j] != mystr._str[leng - 1 - j])
					break;
			if (j == leng)
				return i - leng + 1;
		}

	return this->npose;
}
size_t Mystring::rfind(const char* strr) const
{
	size_t len = strlen(_str);
	size_t leng = strlen(strr);

	for (size_t i = len - 1; i >= 0; i--)
		if (_str[i] == strr[leng - 1])
		{
			size_t j = 0;
			for (j; j < leng; j++)
				if (_str[i - j] != strr[leng - 1 - j])
					break;
			if (j == leng)
				return i - leng + 1;
		}

	return this->npose;
}
size_t Mystring::rfind(const char* strr, size_t n) const
{
	size_t len = strlen(_str);

	for (size_t i = len - 1; i >= 0; i--)
		if (_str[i] == strr[n - 1])
		{
			size_t j = 0;
			for (j; j < n; j++)
				if (_str[i - j] != strr[n - 1 - j])
					break;
			if (j == n)
				return i - n + 1;
		}

	return this->npose;
}
size_t Mystring::rfind(char c) const
{
	size_t len = strlen(_str);

	for (size_t i = len - 1; i >= 0; i--)
		if (_str[i] == c)
			return i;

	return this->npose;
}







size_t Mystring::find_first_of(const Mystring& mystr, size_t pos) const
{
	try
	{
		size_t len = strlen(_str);
		if (pos > len)
			throw exception("Out of range");

		size_t leng = strlen(mystr._str);

		for (size_t i = pos; i < len; i++)
			for (size_t j = 0; j < leng; j++)
				if (_str[i] == mystr._str[j])
					return i;

		return this->npose;
	}
	catch (const exception& excep)
	{
		cerr << excep.what() << endl;
		//exit(1);
	}
}
size_t Mystring::find_first_of(const char* str, size_t pos) const
{
	try
	{
		size_t len = strlen(_str);
		if (pos > len)
			throw exception("Out of range");

		size_t leng = strlen(str);

		for (size_t i = pos; i < len; i++)
			for (size_t j = 0; j < leng; j++)
				if (_str[i] == str[j])
					return i;

		return this->npose;
	}
	catch (const exception& excep)
	{
		cerr << excep.what() << endl;
		//exit(1);
	}
}
size_t Mystring::find_first_of(const char* str, size_t pos, size_t n) const
{
	try
	{
		size_t len = strlen(_str);
		if (pos > len)
			throw exception("Out of range");

		size_t leng = strlen(str);
		if (n > leng)
			n = leng;

		for (size_t i = pos; i < len; i++)
			for (size_t j = 0; j < n; j++)
				if (_str[i] == str[j])
					return i;

		return this->npose;
	}
	catch (const exception& excep)
	{
		cerr << excep.what() << endl;
		//exit(1);
	}
}
size_t Mystring::find_first_of(char c, size_t pos) const
{
	try
	{
		size_t len = strlen(_str);
		if (pos > len)
			throw exception("Out of range");

		for (size_t i = pos; i < len; i++)
			if (_str[i] == c)
				return i;

		return this->npose;
	}
	catch (const exception& excep)
	{
		cerr << excep.what() << endl;
		//exit(1);
	}
}


size_t Mystring::find_last_of(const Mystring& mystr, size_t pos) const
{
	size_t len = strlen(_str);
	size_t leng = strlen(mystr._str);

	for (size_t i = len - 1; i >= 0; i--)
		for (size_t j = leng - 1; j >= 0; j--)
			if (_str[i] == mystr._str[j])
				return i;

	return this->npose;
}
size_t Mystring::find_last_of(const char* str, size_t pos) const
{
	size_t len = strlen(_str);
	size_t leng = strlen(str);

	for (size_t i = len - 1; i >= 0; i--)
		for (size_t j = leng - 1; j >= 0; j--)
			if (_str[i] == str[j])
				return i;

	return this->npose;
}
size_t Mystring::find_last_of(const char* str, size_t pos, size_t n) const
{
	size_t len = strlen(_str);
	size_t leng = strlen(str);
	if (n > leng)
		n = leng;

	for (size_t i = len - 1; i >= 0; i--)
		for (size_t j = n - 1; j >= 0; j--)
			if (_str[i] == str[j])
				return i;

	return this->npose;
}
size_t Mystring::find_last_of(char c, size_t pos) const
{
	size_t len = strlen(_str);

	for (size_t i = len - 1; i >= 0; i--)
		if (_str[i] == c)
			return i;

	return this->npose;
}

size_t Mystring::find_first_not_of(const Mystring& mystr, size_t pos) const
{
	try
	{
		size_t len = strlen(_str);
		if (pos > len)
			throw exception("Out of range");

		size_t leng = strlen(mystr._str);

		for (size_t i = pos; i < len; i++)
			for (size_t j = 0; j < leng; j++)
			{
				if (_str[i] == mystr._str[j])
					break;
				if (j == leng - 1)
					return i;
			}

		return this->npose;
	}
	catch (const exception& excep)
	{
		cerr << excep.what() << endl;
		//exit(1);
	}
}
size_t Mystring::find_first_not_of(const char* str, size_t pos) const
{
	try
	{
		size_t len = strlen(_str);
		if (pos > len)
			throw exception("Out of range");

		size_t leng = strlen(str);

		for (size_t i = pos; i < len; i++)
			for (size_t j = 0; j < leng; j++)
			{
				if (_str[i] == str[j])
					break;
				if (j == leng - 1)
					return i;
			}

		return this->npose;
	}
	catch (const exception& excep)
	{
		cerr << excep.what() << endl;
		//exit(1);
	}
}
size_t Mystring::find_first_not_of(const char* str, size_t pos, size_t n) const
{
	try
	{
		size_t len = strlen(_str);
		if (pos > len)
			throw exception("Out of range");


		size_t leng = strlen(str);
		if (n > leng)
			n = leng;

		for (size_t i = pos; i < len; i++)
			for (size_t j = 0; j < n; j++)
			{
				if (_str[i] == str[j])
					break;
				if (j == leng - 1)
					return i;
			}

		return this->npose;
	}
	catch (const exception& excep)
	{
		cerr << excep.what() << endl;
		//exit(1);
	}
}
size_t Mystring::find_first_not_of(char c, size_t pos) const
{
	try
	{
		size_t len = strlen(_str);
		if (pos > len)
			throw exception("Out of range");

		for (size_t i = pos; i < len; i++)
			if (_str[i] != c)
				return i;

		return this->npose;
	}
	catch (const exception& excep)
	{
		cerr << excep.what() << endl;
		//exit(1);
	}
}

size_t Mystring::find_last_not_of(const Mystring& mystr, size_t pos) const
{
	size_t len = strlen(_str);
	size_t leng = strlen(mystr._str);

	for (size_t i = len - 1; i >= 0; i--)
		for (size_t j = leng; j >= 0; j--)
		{
			if (_str[i] == mystr._str[j])
				break;
			if (j == 0)
				return i;
		}

	return this->npose;
}
size_t Mystring::find_last_not_of(const char* str, size_t pos) const
{
	size_t len = strlen(_str);
	size_t leng = strlen(str);

	for (size_t i = len - 1; i >= 0; i--)
		for (size_t j = leng; j >= 0; j--)
		{
			if (_str[i] == str[j])
				break;
			if (j == 0)
				return i;
		}

	return this->npose;
}
size_t Mystring::find_last_not_of(const char* str, size_t pos, size_t n) const
{
	size_t len = strlen(_str);
	size_t leng = strlen(str);
	if (n > leng)
		n = leng;

	for (size_t i = len - 1; i >= 0; i--)
		for (size_t j = n - 1; j >= 0; j--)
		{
			if (_str[i] == str[j])
				break;
			if (j == 0)
				return i;
		}

	return this->npose;
}
size_t Mystring::find_last_not_of(char c, size_t pos) const
{
	size_t len = strlen(_str);

	for (size_t i = len - 1; i >= 0; i--)
		if (_str[i] != c)
			return i;

	return this->npose;
}



int Mystring::compare(const Mystring& mystr) const
{
	size_t len = strlen(_str);
	size_t leng = strlen(mystr._str);

	if (len < leng)
		len = leng;

	for (size_t i = 0; i < len; i++)
		if (_str[i] > mystr._str[i])
			return 1;
		else if (_str[i] < mystr._str[i])
			return -1;
	return 0;
}
int Mystring::compare(size_t pos, size_t len, const Mystring& mystr) const
{
	try
	{
		size_t leng = strlen(_str);
		if (pos > leng)
			throw exception("Out of range");

		size_t lengg = strlen(mystr._str);
		if (pos + len > leng)
			len = leng - pos;

		if (len < lengg)
			len = lengg;

		for (size_t i = 0; i < len; i++)
			if (_str[i + pos] > mystr._str[i])
				return 1;
			else if (_str[i + pos] < mystr._str[i])
				return -1;
		return 0;
	}
	catch (const exception& excep)
	{
		cerr << excep.what() << endl;
		//exit(1);
	}

}
int Mystring::compare(size_t pos, size_t len, const Mystring& mystr, size_t subpos, size_t sublen) const
{
	try
	{
		size_t leng = strlen(_str);
		if (pos > leng)
			throw exception("Out of range");


		if (pos + len > leng)
			len = leng - pos;

		size_t lengg = strlen(mystr._str);
		if (subpos > lengg)
			throw exception("Out of range");

		if (subpos + sublen > lengg)
			sublen = lengg - subpos;

		if (len < sublen)
			len = sublen;

		for (size_t i = 0; i < len; i++)
			if (_str[i + pos] > mystr._str[i + subpos])
				return 1;
			else if (_str[i + pos] < mystr._str[i + subpos])
				return -1;
		return 0;

	}
	catch (const exception& excep)
	{
		cerr << excep.what() << endl;
		//exit(1);
	}
}
int Mystring::compare(const char* str) const
{
	size_t len = strlen(_str);
	size_t leng = strlen(str);

	if (len < leng)
		len = leng;

	for (size_t i = 0; i < len; i++)
		if (_str[i] > str[i])
			return 1;
		else if (_str[i] < str[i])
			return -1;
	return 0;
}
int Mystring::compare(size_t pos, size_t len, const char* str) const
{
	try
	{
		size_t leng = strlen(_str);
		if (pos > leng)
			throw exception("Out of range");

		size_t lengg = strlen(str);
		if (pos + len > leng)
			len = leng - pos;

		if (len < lengg)
			len = lengg;

		for (size_t i = 0; i < len; i++)
			if (_str[i + pos] > str[i])
				return 1;
			else if (_str[i + pos] < str[i])
				return -1;
		return 0;
	}
	catch (const exception& excep)
	{
		cerr << excep.what() << endl;
		//exit(1);
	}
}
int Mystring::compare(size_t pos, size_t len, const char* str, size_t n) const
{
	try
	{
		size_t leng = strlen(_str);
		if (pos > leng)
			throw exception("Out of range");

		if (pos + len > leng)
			len = leng - pos;

		size_t lengg = strlen(str);
		if (n > lengg)
			n = lengg;

		if (len < n)
			len = n;

		for (size_t i = 0; i < len; i++)
			if (_str[i + pos] > str[i])
				return 1;
			else if (_str[i + pos] < str[i])
				return -1;
		return 0;
	}
	catch (const exception& excep)
	{
		cerr << excep.what() << endl;
		//exit(1);
	}
}

Mystring operator+(const Mystring& lhs, const Mystring& rhs)
{
	Mystring temp(lhs);
	return temp += rhs;
}
Mystring operator+(const Mystring& lhs, const char*   rhs)
{
	Mystring temp(lhs);
	return temp += rhs;
}
Mystring operator+(const char*   lhs, const Mystring& rhs)
{
	Mystring temp(lhs);
	return temp += rhs;
}
Mystring operator+(const Mystring& lhs, char          rhs)
{
	Mystring temp(lhs);
	return temp += rhs;
}
Mystring operator+(char          lhs, const Mystring& rhs)
{
	Mystring temp(1, lhs);
	return temp += rhs;
}

bool operator== (const Mystring& lhs, const Mystring& rhs)
{
	size_t len = strlen(lhs._str);
	size_t leng = strlen(rhs._str);

	if (len != leng)
		return 0;

	for (size_t i = 0; i < len; i++)
		if (lhs._str[i] != rhs._str[i])
			return 0;

	return 1;
}
bool operator== (const char*     lhs, const Mystring& rhs)
{
	size_t len = strlen(lhs);
	size_t leng = strlen(rhs._str);

	if (len != leng)
		return 0;

	for (size_t i = 0; i < len; i++)
		if (lhs[i] != rhs._str[i])
			return 0;

	return 1;
}
bool operator== (const Mystring& lhs, const char*     rhs)
{
	size_t len = strlen(lhs._str);
	size_t leng = strlen(rhs);

	if (len != leng)
		return 0;

	for (size_t i = 0; i < len; i++)
		if (lhs._str[i] != rhs[i])
			return 0;

	return 1;
}
bool operator!= (const Mystring& lhs, const Mystring& rhs)
{
	return !(lhs == rhs);
}
bool operator!= (const char*     lhs, const Mystring& rhs)
{
	return !(lhs == rhs);
}
bool operator!= (const Mystring& lhs, const char*     rhs)
{
	return !(lhs == rhs);
}
bool operator<  (const Mystring& lhs, const Mystring& rhs)
{
	size_t len = strlen(lhs._str);
	size_t leng = strlen(rhs._str);

	if (len < leng)
		len = leng;

	for (size_t i = 0; i < len; i++)
		if (lhs._str[i] < rhs._str[i])
			return 1;
		else if (lhs._str[i] > rhs._str[i])
			return 0;
	return 0;
}
bool operator<  (const char*     lhs, const Mystring& rhs)
{
	size_t len = strlen(lhs);
	size_t leng = strlen(rhs._str);

	if (len < leng)
		len = leng;

	for (size_t i = 0; i < len; i++)
		if (lhs[i] < rhs._str[i])
			return 1;
		else if (lhs[i] > rhs._str[i])
			return 0;
	return 0;
}
bool operator<  (const Mystring& lhs, const char*     rhs)
{
	size_t len = strlen(lhs._str);
	size_t leng = strlen(rhs);

	if (len < leng)
		len = leng;

	for (size_t i = 0; i < len; i++)
		if (lhs._str[i] < rhs[i])
			return 1;
		else if (lhs._str[i] > rhs[i])
			return 0;
	return 0;
}
bool operator<= (const Mystring& lhs, const Mystring& rhs)
{
	return !(lhs > rhs);
}
bool operator<= (const char*     lhs, const Mystring& rhs)
{
	return !(lhs > rhs);
}
bool operator<= (const Mystring& lhs, const char*     rhs)
{
	return !(lhs > rhs);
}
bool operator>  (const Mystring& lhs, const Mystring& rhs)
{
	size_t len = strlen(lhs._str);
	size_t leng = strlen(rhs._str);

	if (len < leng)
		len = leng;

	for (size_t i = 0; i < len; i++)
		if (lhs._str[i] > rhs._str[i])
			return 1;
		else if (lhs._str[i] < rhs._str[i])
			return 0;
	return 0;
}
bool operator>  (const char*     lhs, const Mystring& rhs)
{
	size_t len = strlen(lhs);
	size_t leng = strlen(rhs._str);

	if (len < leng)
		len = leng;

	for (size_t i = 0; i < len; i++)
		if (lhs[i] > rhs._str[i])
			return 1;
		else if (lhs[i] < rhs._str[i])
			return 0;
	return 0;
}
bool operator>  (const Mystring& lhs, const char*     rhs)
{
	size_t len = strlen(lhs._str);
	size_t leng = strlen(rhs);

	if (len < leng)
		len = leng;

	for (size_t i = 0; i < len; i++)
		if (lhs._str[i] > rhs[i])
			return 1;
		else if (lhs._str[i] < rhs[i])
			return 0;
	return 0;
}
bool operator>= (const Mystring& lhs, const Mystring& rhs)
{
	return !(lhs < rhs);
}
bool operator>= (const char*     lhs, const Mystring& rhs)
{
	return !(lhs < rhs);
}
bool operator>= (const Mystring& lhs, const char*     rhs)
{
	return !(lhs < rhs);
}






Mystring Mystring::substr(size_t pos, size_t len) const
{
	try
	{
		size_t leng = strlen(_str);
		if (pos > leng)
			throw exception("Out of range");

		if (len + pos > leng || len == npose)
			len = leng - pos;

		char* temp = new char[len + 1];
		for (size_t i = 0; i < len; i++)
			temp[i] = _str[i + pos];

		temp[len] = '\0';
		Mystring tempp(temp);
		return tempp;
	}
	catch (const exception& excep)
	{
		cerr << excep.what() << endl;
		//exit(1);
	}

}

istream& getline(istream& is, Mystring& str, char delim)
{
	char data = is.get();
	while (data != delim)
	{
		str.push_back(data);
		data = is.get();
	}
	return is;
}
istream& getline(istream& is, Mystring& str)
{
	char data = is.get();
	while (data != '\n')
	{
		str.push_back(data);
		data = is.get();
	}
	return is;
}



istream& operator>>(istream& is, const Mystring& str)
{
	is >> str._str;
	return is;
}


ostream& operator<<(ostream& out, const Mystring& mystr)
{
	out << mystr._str;
	return out;
}

Mystring::~Mystring()
{
	delete[] _str;
	_str = NULL;
}
