#pragma once
#include <list>

template <typename TKey, typename TValue>
class list_ordered_table
{
private:
	struct elem
	{
		TKey key;
		TValue val;
		bool is_del = 0;
	};

	list<elem> data;

public:

	void Insert(TKey k, TValue v)
	{
		elem e{ k, v };
		for (auto iter = data.begin(); iter != data.end(); iter++)
		{
			if ((iter->key == k) && (iter->is_del == 1))
			{
				iter->val = v;
				iter->is_del = 0;
				return;
			}
			else if ((iter->key == k) && (iter->is_del == 0))
			{
				cout << "Elem with this key is exist";
				return;
			}
			else if ((iter->key > k) && (Find(k) == nullptr))
			{
				data.insert(iter, e);
				return;
			}
		}
		data.push_back(e);
	};

	void Delete(TKey k)
	{
		for (auto iter = data.begin(); iter != data.end(); iter++)
		{
			if ((iter->key == k) && !(iter->is_del))
			{
				iter->is_del = 1;
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
		{
			if (e.is_del == 0)
				cout << e.key << "\t||\t" << e.val << "\n";
		}
	};

};

