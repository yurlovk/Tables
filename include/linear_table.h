#pragma once
#include "iostream"
#include "vector"
using namespace std;

template<typename TKey, typename TValue>
class linear_table
{
private:
	struct elem
	{
		TKey key;
		TValue value;
	};

	vector <elem> data{};

public:

	size_t size()
	{
		return data.size();
	};

	TValue& operator [] (size_t pos)
	{
		if (pos > size())
			throw ("Index out of range");
		return data[pos].value;
	};

	void Delete(TKey k)
	{
		for (int i = 0; i < size(); i++)
			if (data[i].key == k)
			{
				data.erase(data.begin() + i);
				cout << "\nDelete\n";
				return;
			}
		cout << "No elem with this key \n";
	};

	TValue* Find(TKey k)
	{
		for (int i = 0; i < size(); i++)
			if (data[i].key == k)
				return (&(data[i].value));
		return nullptr;
	};

	void Insert(TKey k, TValue v)
	{
		if (this->Find(k) == nullptr)
		{
			elem e{ k, v };
			data.push_back(e);
		}
		else
			cout << "Elem with key " << k << " is exist\n";
	};

	void print()
	{
		cout << "\nKey\t||\tElem\n";
		for (int i = 0; i < size(); i++)
			cout << data[i].key << "\t||\t" << data[i].value << "\n";
	};
};