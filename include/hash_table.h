#pragma once
#include <list>
#include <vector>
#include <string>
using namespace std;

template <typename TValue>
class hash_table
{
private:
	struct elem
	{
		string key;
		TValue val;
	};

	static const int table_size = 100;
	vector<list<elem>> data;

	int hash_fun(string k)
	{
		int index = 0;
		for (int i = 0; i < k.size(); i++)
			index += (int(k[i])) % 100;
		return index % 100;
	};

public:
	hash_table() : data(table_size) {}

	void Insert(string k, TValue v)
	{
		int index = hash_fun(k);
		for (elem e : data[index])
			if (e.key == k)
			{
				cout << "Elem with this key is exist";
				return;
			}

		elem e{ k, v };
		data[index].push_back(e);
	}

	void Delete(string k)
	{
		int index = hash_fun(k);
		for (auto iter = data[index].begin(); iter != data[index].end(); iter++)
		{
			if (iter->key == k)
			{
				data[index].erase(iter);
				return;
			}
		}
		cout << "An element with such a key is missing from the table";
	}

	TValue* Find(string k)
	{
		int index = hash_fun(k);
		for (elem& e : data[index])
			if (e.key == k)
				return &e.val;
		return nullptr;
	}

	void print()
	{
		for (int i = 0; i < 100; i++)
		{
			bool is_emp = !data[i].empty();
			//if (is_emp)
			//{
			//	cout << i << " ";
			//	for (elem e : data[i])
			//		cout << "key:" << e.key << "\t||\t" << e.val;
			//	cout << "\n";
			//}
		}
		cout << "\n";
	}
};

