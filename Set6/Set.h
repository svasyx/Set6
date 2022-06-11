#pragma once
class Set
{
public:
	Set(); //конструктор за замовчуванням
	Set(const char* elements); //конструктор з параметром
	Set(const Set& ob); //конструктор копіювання
	~Set(); //деструктор
	void Input(); //елементи з клавіатури
	bool Add(char element); //додавання елементів
	void Print(); //друк множини
	void operator =(const Set& ob); //присвоення множин
	bool operator > (char symbol);//перевірка на приналежність;
	Set operator*(const Set& ob);//перетин множин
	bool operator <(const Set& ob); //перевірка на підмножину
private:
	char* _elements;
	int _MaxSize;
	int _size;
	Set Cross(const Set& b);//перетин множин
	bool subset(const Set& ob); //перевірка на підмножину
	void strcopys(char* element, const char* element2, int size); //копіювання елементів в массив
};