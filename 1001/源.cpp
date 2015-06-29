#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main()
{
	int temp,i,sum;
	vector<int> vec;
	vector<int>::iterator iter;
	while (cin >> temp)
	{
		sum = 0;
		for (i = 1; i <= temp; ++i)
		{
			sum += i;
		}
		vec.push_back(sum);
	}
	for (iter = vec.begin(); iter != vec.end(); ++iter)
	{
		cout << *iter << endl << endl;
	}
	system("pause");
	return 0;
}