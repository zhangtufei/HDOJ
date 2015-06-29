#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;
int main()
{
	int a, b;
	while (cin >> a >> b&&b)
	{
		vector<int> vec;
		a *= 100;
		int temp = a%b;
		if (temp == 0)
			vec.push_back(0);
		temp = b - temp;
		while (temp <= 99)
		{
			vec.push_back(temp);
			temp += b;
		}
		vector<int>::iterator iter = vec.begin();
		for (; iter != vec.end(); ++iter)
		{
			if (iter == vec.end() - 1)
			{
				if (*iter < 10)
					cout << '0' << *iter << endl;
				else
					cout << *iter << endl;
				break;
			}
			if (*iter < 10)
				cout << '0' << *iter << ' ';
			else
				cout << *iter << ' ';
		}
	}
	return 0;
}