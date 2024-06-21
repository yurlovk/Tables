#include "monom.h"
#include <iostream>
using namespace std;
monom::monom()
{
	param = 1;
	for (int i = 0; i < 3; i++)
		degrees[i] = 0;
}

monom::monom(int p, int* d)
{
	param = p;
	for (int i = 0; i < 3; i++)
		degrees[i] = d[i];
}

monom::monom(string& s)
{
	int i = 0;
	param = 0;
	if (s[i] == '-')
	{
		i++;
		param = 0 - (int(s[i]) - 48);
		i++;
	}
	else if (s[i] == '+')
	{
		i++;
		param = int(s[i]) - 48;
		i++;
	}
	else if (s[i] == 'x')
		param = 1;

	while (s[i] != 'x')
	{
		if (param >= 0)
			param = param * 10 + (int(s[i]) - 48);
		else
			param = param * 10 - (int(s[i]) - 48);
		i++;
	}


	for (; i < s.length(); i++)
	{
		switch (s[i])
		{
		case 'x':
			i += 2;
			degrees[0] = int(s[i]) - 48;
			break;
		case 'y':
			i += 2;
			degrees[1] = int(s[i]) - 48;
			break;
		case 'z':
			i += 2;
			degrees[2] = int(s[i]) - 48;
			break;
		}
		i++;
	}
}

bool monom::is_correct_str(const string& s)
{
	string alf = "+-xyz*^123456789";
	bool flag = 0;
	for (int i = 0; i < s.length(); i++)
	{
		flag = 0;
		for (int i = 0; i < alf.length(); i++)
			if (s[i] == alf[i])
				flag = 1;

		if (flag == 0)
			throw "Uncorrect monom";
	}
	return 1;
}

int monom::check_param()
{
	return param;
}

void monom::redact_param(int i)
{
	param = i;
}

monom& monom::str_to_mon(string& s)
{
	monom tmp(s);
	*this = tmp;
	return *this;
}

monom::monom(const monom& m)
{
	param = m.param;
	for (int i = 0; i < 3; i++)
		degrees[i] = m.degrees[i];
}

monom& monom::operator = (const monom& m)
{
	param = m.param;
	for (int i = 0; i < 3; i++)
		degrees[i] = m.degrees[i];
	return *this;
}

bool monom::is_eq_deg(const monom& m)
{
	for (int i = 0; i < 3; i++)
		if (degrees[i] != m.degrees[i])
			return 0;
	return 1;
}

bool monom::operator != (const monom& m)
{
	if (param != m.param)
		return 0;
	if (!(this->is_eq_deg(m)))
		return 0;
	return 1;
}

monom monom::operator+(monom& m)
{
	monom tmp;
	for (int i = 0; i < 3; i++)
	{
		if (m.degrees[i] != degrees[i])
			throw "Error: uncorrect terms";
		tmp.degrees[i] = m.degrees[i];
	}

	tmp.param = param + m.param;
	return tmp;
}

monom monom::operator * (int m)
{
	param *= m;
	return *this;
}

monom monom::operator * (monom& m)
{
	monom tmp;
	tmp.param = param * m.param;

	for (int i = 0; i < 3; i++)
		tmp.degrees[i] = m.degrees[i] + degrees[i];

	return tmp;
}

monom& monom::der(char var)
{
	int k;
	switch (var)
	{
	case 'x':
		k = 0;
		break;
	case 'y':
		k = 1;
		break;
	case 'z':
		k = 2;
		break;
	default:
		throw ("Error: uncorrect var");
	}
	param = param * degrees[k];
	degrees[k] -= 1;
}

monom& monom::integral(char var)
{
	int k;
	switch (var)
	{
	case 'x':
		k = 0;
		break;
	case 'y':
		k = 1;
		break;
	case 'z':
		k = 2;
		break;
	default:
		throw ("Error: uncorrect var");
	}

	param = param / (degrees[k] + 1);
	degrees[k] += 1;
}

void monom::print()
{
	cout << param << "x^" << degrees[0] << "y^" << degrees[1] << "z^" << degrees[2];
}