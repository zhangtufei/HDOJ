#include <iostream>
#include <string>
using namespace std;
int main()
{
	string a, b;
	while (cin>>a>>b)
	{	
		for (int i = 0; i < a.size(); ++i)
		{
			if (a[i] == '.')
			{
				for (int k = a.size() - 1; k >= i; --k)
				{
					if (a[k] == '0')
						a[k] = '\0';
					else if (a[k] == '.')
					{
						a[k] = '\0';
					}
					else
						break;
				}

				break;
			}
		}
		//for (int i = 0; i < a.size(); ++i)
		//{
		//	if (a[i]=='0'&&a[i+1])
		//}
		for (int i = 1; i < b.size(); ++i)
		{
			if (b[i] == '.')
			{
				for (int k = b.size() - 1; k >= i; --k)
				{
					if (b[k] == '0')
						b[k] = '\0';
					else if (b[k] == '.')
						b[k] = '\0';
					else
						break;
				}
				break;
			}
		}
		string c, d;
		for (int i = 0; a[i] != '\0'; ++i)
			c += a[i];
		for (int i = 0;b[i] != '\0'; ++i)
			d += b[i];
		if (c == d)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}