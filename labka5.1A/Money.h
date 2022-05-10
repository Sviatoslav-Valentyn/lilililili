#pragma once
#include <sstream>
#include <iostream>
#include <string>
#include <exception>
#include "MyException.h"
#include "MyDeliveredException.h"

using namespace std;

class Money
{
private:
	int n500 = 0;
	int n200 = 0;
	int n100 = 0;
	int n50 = 0;
	int n20 = 0;
	int n10 = 0;
	int n5 = 0;
	int n2 = 0;
	int n1 = 0;
	int c50 = 0;
	int c25 = 0;
	int c10 = 0;
	int c5 = 0;
	int c2 = 0;
	int c1 = 0;
public:
	void setN500(const int n);
	void setN200(const int n);
	void setN100(const int n);
	void setN50(const int n);
	void setN20(const int n);
	void setN10(const int n);
	void setN5(const int n);
	void setN2(const int n);
	void setN1(const int n);
	void setC50(const int n);
	void setC25(const int n);
	void setC10(const int n);
	void setC5(const int n);
	void setC2(const int n);
	void setC1(const int n);

	int getN500() const { return n500; }
	int getN200() const { return n200; }
	int getN100() const { return n100; }
	int getN50() const { return n50; }
	int getN20() const { return n20; }
	int getN10() const { return n10; }
	int getN5() const { return n5; }
	int getN2() const { return n2; }
	int getN1() const { return n1; }
	int getC50() const { return c50; }
	int getC25() const { return c25; }
	int getC10() const { return c10; }
	int getC5() const { return c5; }
	int getC2() const { return c2; }
	int getC1() const { return c1; }

	Money();
	Money(int, int, int, int, int, int, int, int, int, int, int, int, int, int, int);
	Money(const Money&);

	operator string() const;

	Money& operator ++();
	Money& operator --();
	Money operator ++(int);
	Money operator --(int);

	friend ostream& operator <<(ostream&, const Money&);
	friend istream& operator >>(istream&, Money&);

	double Suma()const;

	friend double div(Money m1, Money m2);
	friend double div1(Money m, double value);
	friend Money doubleToMoney(double value);


	friend bool operator < (Money&, Money&);
	friend bool operator == (Money&, Money&);
	friend bool operator > (Money&, Money&);
	friend bool operator <= (Money&, Money&);
	friend bool operator != (Money&, Money&);
	friend bool operator >= (Money&, Money&);
};