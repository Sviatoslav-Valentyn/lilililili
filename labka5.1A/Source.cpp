#include "Money.h"
#include <iostream>
#include <Windows.h>

void _unexpected_to_bad()
{
	cerr << "bad_exception" << endl;
	throw;
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	set_unexpected(_unexpected_to_bad);
	set_terminate(_unexpected_to_bad);

	Money f1, f4;
	try
	{
		cout << "Enter first number" << endl;
		cin >> f1;
		cout << endl;
		cout << "1 випадок:" << endl << f1 << endl;
	}
	catch (invalid_argument a)
	{
		cerr << "Exception first: " << a.what() << endl;
	}


	try
	{
		cout << "Enter second number" << endl;
		cin >> f4;
		cout << endl;
		cout << "2 випадок:" << endl << f4 << endl;
		try {
			f4--;
			--f4;
		}
		catch (MyDeliveredException* e)
		{
			cerr << e->what() << endl;
		}
		catch (MyDeliveredException& e)
		{
			cerr << e.What() << endl;
		}
	}
	catch (invalid_argument e)
	{
		cerr << e.what() << endl;
	}

	int f;
	f = f1 < f4;
	cout << "f1 < f4 - " << f << endl;
	f = f1 == f4;
	cout << "f1 == f4 - " << f << endl;
	f = f1 > f4;
	cout << "f1 > f4 - " << f << endl;
	f = f1 <= f4;
	cout << "f1 <= f4 - " << f << endl;
	f = f1 != f4;
	cout << "f1 != f4 - " << f << endl;
	f = f1 >= f4;
	cout << "f1 >= f4 - " << f << endl;
	cout << endl;

	cout << ++f1 << endl;
	cout << --f1 << endl;
	cout << f1++ << endl;
	cout << f1-- << endl;

	cout << "Ділення суми на число: " << div1(f1, 44) << endl;
	cout << endl;
	cout << endl;

	cout << "Ділення сум: " << div(f1, f4) << endl;
	cout << endl;
	cout << endl;

	return 0;
}