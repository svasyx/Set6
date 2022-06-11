#include "Header.h"
#include "set.h"
#define SizeMax 100;

Set::Set()
{
	_size = 0;
	_elements = nullptr;
	_MaxSize = SizeMax;
}

Set::Set(const char* elements)
{
	_MaxSize = SizeMax;
	int i = 0;
	_size = strlen(elements);
	if (_size > _MaxSize)
	{
		exit(1);
	}
	_elements = new char[_size];
	if (_elements == nullptr)
	{
		exit(1);
	}
	strcopys(_elements, elements, _size);
}

Set::Set(const Set& ob)
{
	_MaxSize = ob._MaxSize;
	_size = ob._size;
	if (_size > _MaxSize)
	{
		exit(1);
	}
	_elements = new char[_size];
	if (_elements == nullptr)
	{
		exit(1);
	}
	strcopys(_elements, ob._elements, ob._size);

}

Set::~Set()
{
	if (_elements != nullptr)
	{
		delete[]_elements;
	}
}

void Set::operator=(const Set& ob)
{
	_MaxSize = ob._MaxSize;
	_size = ob._size;
	if (_size > _MaxSize)
	{
		exit(1);
	}
	_elements = new char[_size + 1];
	if (_elements == nullptr)
	{
		exit(1);
	}
	strcopys(_elements, ob._elements, ob._size);
}

bool Set::operator > (char symbol)
{
	if (this->_size == 0)
		return 0;
	if (strchr(_elements, symbol) != NULL)
		return 1;
	else
		return 0;

}

Set Set::operator*(const Set& ob)
{
	return Cross(ob);
}

Set Set::Cross(const Set& ob)
{
	int count = 0;
	if (_size > ob._size)
	{
		count = ob._size;
	}
	else
	{
		count = _size;
	}
	char* buf;
	buf = new char[count + 1];
	int k = 0;
	for (int i = 0; i < _size; i++)
	{
		for (int j = 0; j < ob._size; j++)
		{
			if (_elements[i] == ob._elements[j])
			{
				buf[k] = ob._elements[j];
				k++;
			}
		}
	}
	buf[k] = '\0';
	Set res(buf);
	delete[]buf;
	return res;
}


bool Set::operator<(const Set& ob)
{
	return subset(ob);
}

bool Set::subset(const Set& ob)
{
	for (int i = 0; i < _size; i++)
	{
		bool check = false;
		for (int j = 0; j < ob._size; j++)
		{
			if (ob._elements[j] == _elements[i])
			{
				check = true;
			}
		}
		if (check == false) {
			return false;
		}
	}
	return true;
}

bool Set::Add(const char element)
{
	for (int i = 0; i < _size; i++)
	{
		if (element == _elements[i])
		{
			return false;
		}
	}
	char* buf;
	buf = new char[_size];
	if (buf == nullptr)
	{
		exit(1);
	}
	strcopys(buf, _elements, _size);
	_size++;
	if (_size > _MaxSize) {
		exit(1);
	}
	//for(int i = 0; i < _size; i++)

	delete[]_elements;
	_elements = new char[_size];
	if (_elements == nullptr)
	{
		exit(1);
	}
	strcopys(_elements, buf, _size);
	delete[]buf;
	_elements[_size - 1] = element;
	//_elements[_size] = '\0';//прибрати
	return true;
}


void Set::Print()
{
	for (int i = 0; i < _size; i++) {
		cout << _elements[i];
	}
}


void Set::strcopys(char* element, const char* element2, int size) {
	for (int i = 0; i < size; i++) {
		element[i] = element2[i];
	}
}

void Set::Input()
{
	char data[256];
	cin >> data;
	for (int i = 0; i < strlen(data); i++)
	{
		Add(data[i]);
	}
}