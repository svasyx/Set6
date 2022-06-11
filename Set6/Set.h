#pragma once
class Set
{
public:
	Set(); //����������� �� �������������
	Set(const char* elements); //����������� � ����������
	Set(const Set& ob); //����������� ���������
	~Set(); //����������
	void Input(); //�������� � ���������
	bool Add(char element); //��������� ��������
	void Print(); //���� �������
	void operator =(const Set& ob); //���������� ������
	bool operator > (char symbol);//�������� �� ������������;
	Set operator*(const Set& ob);//������� ������
	bool operator <(const Set& ob); //�������� �� ���������
private:
	char* _elements;
	int _MaxSize;
	int _size;
	Set Cross(const Set& b);//������� ������
	bool subset(const Set& ob); //�������� �� ���������
	void strcopys(char* element, const char* element2, int size); //��������� �������� � ������
};