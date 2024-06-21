#pragma once
#include <iostream>
using namespace std;
class monom
{
private:
	int param;
	int degrees[3] = { 0 };
public:
	monom();
	monom(int p, int* d);
	monom(string& s);
	monom(const monom& m);
	monom& operator = (const monom& m);
	bool operator != (const monom& m);
	bool is_eq_deg(const monom& m);
	bool is_correct_str(const string& s);
	int check_param();
	void redact_param(int i);
	monom& str_to_mon(string& s);
	monom operator+(monom& m);
	monom operator * (int m);
	monom operator * (monom& m);
	monom& der(char var);
	monom& integral(char var);
	friend ostream& operator<<(ostream& os, const monom& dt)
	{
		os << dt.param << "x^" << dt.degrees[0] << "y^" << dt.degrees[1] << "z^" << dt.degrees[2];
		return os;
	}
	void print();
};


