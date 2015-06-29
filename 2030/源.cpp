#include <iostream>
#include <string>
using namespace std;
int main()
{
	int n;
	cin >> n;
	getchar();
	while (n--)
	{
		string s;
		getline(cin,s);
		int sum = 0;
		for (int i = 0; i<s.size(); ++i)
		{
			
			if (s[i] < 0)
			{
				++sum;
			}
		}
		cout << sum/2 << endl;
	}
	return 0;
}