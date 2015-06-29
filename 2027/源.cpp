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
		getline(cin, s);
		int num[5];
		char le[5] = { 'a','e','i','o','u' };
		memset(num, 0, sizeof(num));
		for (int i = 0; i < s.size(); ++i)
		{
			switch (s[i])
			{
			case 'a':++num[0]; break;
			case 'e':++num[1]; break;
			case 'i':++num[2]; break;
			case 'o':++num[3]; break;
			case 'u':++num[4]; break;
			default:break;
			}
		}
		for (int i = 0; i < 5; ++i)
		{
			cout << le[i] << ':' << num[i] << endl;
		}
		if (n)
			cout << endl;
	}
	system("pause");
	return 0;
}