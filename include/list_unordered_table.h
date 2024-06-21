#pragma once
#include <list>

template <typename TKey, typename TValue>
class list_unordered_table
{
private:
	struct elem
	{
		TKey key;
		TValue val;
	};

	list<elem> data;

public:

	void Insert(TKey k, TValue v)
	{
		if (Find(k) == nullptr)
		{
			elem e{ k, v };
			data.push_back(e);
		}
		else
			cout << "Elem with this key is exist";
	};

	void Delete(TKey k)
	{
		for (auto iter = data.begin(); iter != data.end(); iter++)
		{
			elem e = *iter;
			if (e.key == k)
			{
				data.erase(iter);
				cout << "\nDelete\n";
				return;
			}
		}
		cout << "No elem with this key \n";
	};

	TValue* Find(TKey k)
	{
		for (elem& e : data)
			if (k == e.key)
			{
				return &(e.val);
			}

		return nullptr;
	};

	void print()
	{
		cout << "\nKey\t||\tElem\n";
		for (elem e : data)
			cout << e.key << "\t||\t" << e.val << "\n";
	};
};

