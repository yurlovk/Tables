#include "poly.h"
#include <iostream>
using namespace std;
poly::poly(string& s)
{
	string tmp_s;
	monom tmp_m;
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == '+' || s[i] == '-')
		{
			tmp_m.str_to_mon(tmp_s);
			pol.PushFront(tmp_m);
			tmp_s = s[i];
		}
		else
			tmp_s += s[i];
	}

	tmp_m.str_to_mon(tmp_s);
	pol.PushFront(tmp_m);
}

void poly::str_to_poly(string& s)
{
	string tmp_s;
	monom tmp_m;
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == '+' || s[i] == '-')
		{
			tmp_m.str_to_mon(tmp_s);
			pol.PushFront(tmp_m);
			tmp_s = s[i];
		}
		else
			tmp_s += s[i];
	}

	tmp_m.str_to_mon(tmp_s);
	pol.PushFront(tmp_m);
}

poly::poly(const poly& p)
{
	pol = p.pol;
}

poly& poly::operator = (const poly& p)
{
	pol = p.pol;
	return *this;
}

size_t poly::size()
{
	return(pol.size());
}

poly& poly::conv()
{
	poly tmp_p(*this);
	int tmp_k = 0;
	monom tmp_m;
	poly res;

	for (int i = 0; !(tmp_p.pol.IsEmpty());)
	{
		tmp_m = tmp_p.pol[i];
		tmp_p.pol.Pop(i);
		tmp_k = tmp_m.check_param();

		for (int j = 0; j < tmp_p.pol.size(); j++)
		{
			if (tmp_m.is_eq_deg(tmp_p.pol[j]))
			{
				tmp_m.redact_param(tmp_m.check_param() + tmp_p.pol[j].check_param());
				tmp_p.pol.Pop(j);
				j--;
			}
		}
		res.pol.PushFront(tmp_m);
	}

	*this = res;
	return *this;
}

poly poly::operator + (poly& p)
{
	poly res;
	poly tmp(p);
	bool flag = 0;
	for (int i = 0; i < pol.size(); i++)
	{
		flag = 0;
		for (int j = 0; j < tmp.size(); j++)
		{
			if (pol[i].is_eq_deg(tmp.pol[j]))
			{
				res.pol.PushFront(pol[i] + tmp.pol[j]);
				tmp.pol.Pop(j);
				j--;
				flag++;
				break;
			}
		}
		if (flag == 0)
			res.pol.PushFront(pol[i]);
	}

	for (int i = 0; i < tmp.size(); i++)
		res.pol.PushFront(tmp.pol[i]);

	res.conv();
	return res;
}

poly poly::operator * (int k)
{
	for (int i = 0; i < this->size(); i++)
		this->pol[i] = (this->pol[i]) * k;
	return *this;
}

poly poly::operator * (poly& p)
{
	poly tmp_p;
	for (int i = 0; i < pol.size(); i++)
		for (int j = 0; j < p.size(); j++)
			tmp_p.pol.PushFront(pol[i] * p.pol[j]);

	tmp_p.conv();
	return tmp_p;
}

void poly::print()
{
	for (int i = 0; i < pol.size() - 1; i++)
	{
		pol[i].print();
		if (pol[i + 1].check_param() > 0)
			cout << "+";
	}
	pol[pol.size() - 1].print();
}



poly& poly::der(char c)
{
	for (int i = 0; i < this->pol.size(); i++)
		pol[i].der(c);

	return *this;
}