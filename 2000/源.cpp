#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int main()
{	
	char temp;
	string s;
	while (cin>>s)
	{
		vector<char> vec;

		for (int i = 0; i < 3; ++i)
		{
			vec.push_back(s[i]);
		}
		sort(vec.begin(), vec.end());
		cout << vec[0] << ' ' << vec[1] << ' ' << vec[2] << endl;
	}
	return 0;
}