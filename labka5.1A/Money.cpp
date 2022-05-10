#include "Money.h"
#include <iostream>
#include <iomanip>
#include <cmath>
#include <stdlib.h>
#include <sstream>

using namespace std;

void Money::setN500(int  n)
{
	if (n < 0) 
		throw invalid_argument("value < 0"); //стандарт
	n500 = n;

}
void Money::setN200(int  n)
{
	if (n < 0)
		throw invalid_argument("value < 0"); //стандарт
	n200 = n;
}
void Money::setN100(int  n)
{
	if (n < 0)
		throw invalid_argument("value < 0"); //стандарт
	n100 = n;
}
void Money::setN50(int  n)
{
	if (n < 0)
		throw invalid_argument("value < 0"); //стандарт
	n50 = n;
}
void Money::setN20(int  n)
{
	if (n < 0)
		throw invalid_argument("value < 0"); //стандарт
	n20 = n;
}
void Money::setN10(int  n)
{
	if (n < 0)
		throw invalid_argument("value < 0"); //стандарт
	n10 = n;
}
void Money::setN5(int  n)
{
	if (n < 0)
		throw invalid_argument("value < 0"); //стандарт
	n5 = n;
}
void Money::setN2(int  n)
{
	if (n < 0)
		throw invalid_argument("value < 0"); //стандарт
	n2 = n;
}
void Money::setN1(int  n)
{
	if (n < 0)
		throw invalid_argument("value < 0"); //стандарт
	n1 = n;
}
void Money::setC50(int  n)
{
	if (n < 0)
		throw MyException("value < 0"); //власний
	c50 = n;
}
void Money::setC25(int  n)
{
	if (n < 0)
		throw MyException("value < 0"); //власний
	c25 = n;
}
void Money::setC10(int  n)
{
	if (n < 0)
		throw MyException("value < 0"); //власний
	c10 = n;
}
void Money::setC5(int  n)
{
	if (n < 0)
		throw MyException("value < 0"); //власний
	c5 = n;
}
void Money::setC2(int  n)
{
	if (n < 0)
		throw new MyDeliveredException(); //нащадок
	c2 = n;
}
void Money::setC1(int  n)
{
	if (n < 0)
		throw new MyDeliveredException(); //нащадок
	c1 = n;
}
Money::Money()
	: n500(0), n200(0), n100(0), n50(0), n20(0), n10(0), n5(0), n2(0), n1(0),
	c50(0), c25(0), c10(0), c5(0), c2(0), c1(0)
{}

Money::Money(int _n500, int _n200, int _n100, int _n50, int _n20, int _n10, int _n5, int _n2, int _n1, int _c50, int _c25, int _c10, int _c5, int _c2, int _c1)
{
	setN500(_n500); setN200(_n200); setN100(_n100); setN50(_n50); setN20(_n20);
	setN10(_n10);  setN5(_n5); setN2(_n2); setN1(_n1); setC50(_c50);
	setC25(_c25); setC10(_c10); setC5(_c5); setC2(_c2); setC1(_c1);
}

Money::Money(const Money& t)
{
	*this = t;
}

Money::operator string() const
{
	double sm = Suma();
	stringstream ss;
	ss << "Гривень:  " << trunc(sm) << ", копійок: " << int((sm - trunc(sm)) * 100) << endl;

	return ss.str();
}


Money& Money::operator ++()
{
	if (c50 = 99)
		c50 = 0;
	else
		++c50;
	if (c25 = 99)
		c25 = 0;
	else
		++c25;
	if (c10 = 99)
		c10 = 0;
	else
		++c10;
	if (c5 = 99)
		c5 = 0;
	else
		++c5;
	if (c2 = 99)
		c2 = 0;
	else
		++c2;
	if (c1 = 99)
		c1 = 0;
	else
		++c1;

	return *this;
}

Money& Money::operator --()
{
	if (c50 == 0)
		c50 = 99;
	else
		--c50;
	if (c25 == 0)
		c25 = 99;
	else
		--c25;
	if (c10 == 0)
		c10 = 99;
	else
		--c10;
	if (c5 == 0)
		c5 = 99;
	else
		--c5;
	if (c2 == 0)
		c2 = 99;
	else
		--c2;
	if (c1 == 0)
		c1 = 99;
	else
		--c1;

	return *this;
}

Money Money::operator ++(int)
{
	Money tmp = *this;
	if (c50 == 99)
	{
		c50 = 0;
		++* this;
	}
	else
		++c50;
	if (c25 == 99)
	{
		c25 = 0;
		++* this;
	}
	else
		++c25;
	if (c10 == 99)
	{
		c10 = 0;
		++* this;
	}
	else
		++c10;
	if (c5 == 99)
	{
		c5 = 0;
		++* this;
	}
	else
		++c5;
	if (c2 == 99)
	{
		c2 = 0;
		++* this;
	}
	else
		++c2;
	if (c1 == 99)
	{
		c1 = 0;
		++* this;
	}
	else
		++c1;
	return tmp;
}

Money Money::operator --(int)
{
	Money tmp = *this;
	if (c50 == 0)
	{
		c50 = 99;
		--* this;
	}
	else
		--c50;
	if (c25 == 0)
	{
		c25 = 99;
		--* this;
	}
	else
		--c25;
	if (c10 == 0)
	{
		c10 = 99;
		--* this;
	}
	else
		--c10;
	if (c5 == 0)
	{
		c5 = 99;
		--* this;
	}
	else
		--c5;
	if (c2 == 0)
	{
		c2 = 99;
		--* this;
	}
	else
		--c2;
	if (c1 == 0)
	{
		c1 = 99;
		--* this;
	}
	else
		--c1;
	return tmp;
}

double Money::Suma() const
{

	return  n500 * 500 +
		n200 * 200 +
		n100 * 100 +
		n50 * 50 +
		n20 * 20 +
		n10 * 10 +
		n5 * 5 +
		n2 * 2 +
		n1 * 1 +
		c50 * 0.5 +
		c25 * 0.25 +
		c10 * 0.1 +
		c5 * 0.05 +
		c2 * 0.02 +
		c1 * 0.01;

}

Money doubleToMoney(double value)
{
	Money m;

	m.setN500((int)value / 500);
	value -= (int)value / 500 > 0 ? 500 * (int)(value / 500) : 0;

	m.setN200((int)value / 200);
	value -= (int)value / 200 > 0 ? 200 * (int)(value / 200) : 0;

	m.setN100((int)value / 100);
	value -= (int)value / 100 > 0 ? 100 * (int)(value / 100) : 0;

	m.setN50((int)value / 50);
	value -= (int)value / 50 > 0 ? 50 * (int)(value / 50) : 0;

	m.setN20((int)value / 20);
	value -= (int)value / 20 > 0 ? 20 * (int)(value / 20) : 0;

	m.setN10((int)value / 10);
	value -= (int)value / 10 > 0 ? 10 * (int)(value / 10) : 0;

	m.setN5((int)value / 5);
	value -= (int)value / 5 > 0 ? 5 * (int)(value / 5) : 0;

	m.setN2((int)value / 2);
	value -= (int)value / 2 > 0 ? 2 * (int)(value / 2) : 0;

	m.setN1((int)value / 1);
	value -= (int)value / 1 > 0 ? 1 * (int)(value / 1) : 0;

	value *= 100;

	m.setC50((int)value / 50);
	value -= (int)value / 50 > 0 ? 50 * (int)(value / 50) : 0;

	m.setC25((int)value / 25);
	value -= (int)value / 25 > 0 ? 25 * (int)(value / 25) : 0;

	m.setC10((int)value / 10);
	value -= (int)value / 10 > 0 ? 10 * (int)(value / 10) : 0;

	m.setC5((int)value / 5);
	value -= (int)value / 5 > 0 ? 5 * (int)(value / 5) : 0;

	m.setC2((int)value / 2);
	value -= (int)value / 2 > 0 ? 2 * (int)(value / 2) : 0;

	m.setC1((int)value / 1);
	value -= (int)value / 1 > 0 ? 1 * (int)(value / 1) : 0;

	return m;
}

double div(Money m1, Money m2)
{
	return m1.Suma() / m2.Suma();
}

double div1(Money m1, double value)
{
	return  m1.Suma() / value;
}




ostream& operator <<(ostream& out, const Money& f)
{
	out << string(f);
	return out;
}
istream& operator >>(istream& in, Money& a)
{
	cout << endl;
	cout << "Кількість бакнот по 500грн: "; in >> a.n500;
	cout << "Кількість бакнот по 200грн: "; in >> a.n200;
	cout << "Кількість бакнот по 100грн: "; in >> a.n100;
	cout << "Кількість бакнот по 50грн:  "; in >> a.n50;
	cout << "Кількість бакнот по 20грн:  "; in >> a.n20;
	cout << "Кількість бакнот по 10грн:  "; in >> a.n10;
	cout << "Кількість бакнот по 5грн:   "; in >> a.n5;
	cout << "Кількість бакнот по 2грн:   "; in >> a.n2;
	cout << "Кількість бакнот по 1грн:   "; in >> a.n1;
	cout << "Кількість копійок по 50к:   "; in >> a.c50;
	cout << "Кількість копійок по 25к:   "; in >> a.c25;
	cout << "Кількість копійок по 10к:   "; in >> a.c10;
	cout << "Кількість копійок по 5к:    "; in >> a.c5;
	cout << "Кількість копійок по 2к:    "; in >> a.c2;
	cout << "Кількість копійок по 1к:    "; in >> a.c1;

	return in;
}


bool operator < (Money& m1, Money& m2)
{
	return m1.Suma() < m2.Suma();
}

bool operator > (Money& m1, Money& m2)
{
	return m1.Suma() > m2.Suma();
}

bool operator == (Money& m1, Money& m2)
{
	return m1.Suma() == m2.Suma();
}

bool operator != (Money& m1, Money& m2)
{
	return !operator ==(m1, m2);
}

bool operator <= (Money& m1, Money& m2)
{
	return m1.Suma() <= m2.Suma();
}

bool operator >= (Money& m1, Money& m2)
{
	return m1.Suma() >= m2.Suma();
}