#include <iostream>
#include <vector>

#include "table.h"

using namespace std;

int main()
{
	{
		Unordered_table a({ {1,1}, {5,5}, {2, 7} });
		cout << "Unordered table:" << endl;
		cout << "before:" << endl << a.get_size() << endl << a << endl;
		a.insert(3, 8);
		cout << "became after insertion:" << endl << a.get_size() << endl << a << endl;
		a.erase(2);
		cout << "became after deletion:" << endl << a.get_size() << endl;
		cout << a << endl;
	}
	
	{
		cout << endl << "Ordered table:" << endl;
		Ordered_table a({ {1,1}, {5,5}, {2, 7} });
		cout << "before:" << endl << a.get_size() << endl << a << endl;
		a.insert(3, 8);
		cout << "became after insertion:" << endl << a.get_size() << endl << a << endl;
		a.erase(2);
		cout << "became after deletion:" << endl << a.get_size() << endl;
		cout << a << endl;
	}

	return 0;
}