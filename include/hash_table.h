#pragma once
#include <iostream>
#include <vector>
#include <list>

#define S1MPLE 101

using namespace std;

class Hash_table
{
private:

	vector<list<vector<int>>> v;
	int max_size;
	int cur_size;
	int a, b;

	int hash_func(int i)
	{
		int res = ((a * i + b) % S1MPLE) % max_size;
		return res;
	}

public:

	Hash_table(int n)
	{
		cur_size = 0;
		max_size = n * n;

		a = rand() % (S1MPLE - 1) + 1;
		b = rand() % S1MPLE;

		v.resize(max_size);
	}

	~Hash_table() {}

	void insert(const int key, const int value)
	{
		int i = hash_func(key);
		++cur_size;
		v[i].push_back({ key, value });
	}

	void erase(const int key)
	{
		int i = hash_func(key);
		cur_size--;

		if (v[i].size() <= 1)
			v[i] = {};
		else
		{
			auto it = v[i].begin();
			do
			{
				if ((*it)[0] == key)
					break;
				it++;
			} while (it != v[i].end());
			v[i].erase(it);
		}
	}

	int get_value_by_key(const int key)
	{
		int i = hash_func(key);

		auto it = v[i].begin();
		do
		{
			if ((*it)[0] == key)
				return (*it)[1];
		} while (it != v[i].end());
	}

	int get_size()
	{
		return cur_size;
	}

	friend ostream& operator<<(ostream& out, Hash_table a);

};

ostream& operator<<(ostream& out, Hash_table a)
{
	out << "{ ";
	for (int i = 0; i < a.max_size; i++)
	{
		if (a.v[i].size())
		{
			auto it = a.v[i].begin();
			do
			{
				out << "( " << (*it)[0] << " ; " << (*it)[1] << " ) ";
			} while (it != a.v[i].end());
		}
	}
	out << "}";
	return out;
}