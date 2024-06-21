#pragma once
#include <iostream>
#include "monom.h"
#include "list.h"
using namespace std;
class poly
{
private:
	Tlist<monom> pol;

public:
	poly() { Tlist<monom> pol; };
	poly(string& s);
	poly(const poly& p);
	void str_to_poly(string& s);
	size_t size();
	poly& operator = (const poly& p);
	poly operator + (poly& p);
	poly operator * (int k);
	poly operator * (poly& p);
	poly& conv();
	poly& der(char c);
	friend ostream& operator<<(ostream& os, poly& dt)
	{
		monom m;
		for (int i = 0; i < dt.pol.size() - 1; i++)
		{
			m = dt.pol[i];
			os << m;
			if (dt.pol[i].check_param() > 0)
				os << "+";
		}
		os << dt.pol[dt.pol.size() - 1];
		return os;
	}
	void print();
};


