#include "Header.h"
#include "set.h"

int main()
{
	char ch = NULL;
	

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	
	const char* mas2 = "abcd";
	Set a, b(mas2), c;
	a.Add('a');
	a.Add('b');
	a.Add('c');



	cout << "Введіть елемент який хочете перевірити на приналежність : ";
	cin >> ch;
	cout << endl;
	if (a > ch) {
		cout << "Елемент є в множині ";
		a.Print();
		cout << endl;
	}
	else {
		cout << "Елемент " << ch << " відсутній в множині ";
		a.Print();
		cout << endl;
	}

	if (a < b) {
		a.Print();
		cout << " є підмножиною ";
		b.Print();
		cout << endl;
	}
	else {
		a.Print();
		cout << " не є підмножиною ";
		b.Print();
		cout << endl;
	}

	c = a * b;
	cout << " Результат перетину множин: ";
	c.Print();
	_getch();
	return 1;
}

