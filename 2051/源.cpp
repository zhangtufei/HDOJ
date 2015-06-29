#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;
int main()
{
	int n;
	while (cin >> n)
	{
		vector<int> vec;
		vec.push_back(n % 2);
		n /= 2;
		while (n)
		{
			vec.push_back(n % 2);
			n /= 2;
		}
		vector<int>::iterator iter = vec.end();
		while (1)
		{
			cout << *(--iter);
			if (iter == vec.begin())
				break;
		}
		cout << endl;
	}
	return 0;
}
