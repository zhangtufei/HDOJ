#include <iostream>
#include <string>
using namespace std;
string str_add(string a, string b)
{
	int j = a.size() - 1;
	int temp = 0;
	for (int i = b.size() - 1; i >= 0; --i, --j)
	{
		int x = a[j] - 0x30 + b[i] - 0x30 + temp;
		a[j] = x % 10+0x30;
		temp =x/ 10;
	}
	while (temp&&j >= 0)
	{
		int x = a[j] - 0x30 + temp;
		a[j] = x % 10 + 0x30;
		temp =x/ 10;
		--j;
	}
	if (temp)
	{
		char c = temp + 0x30;
		a = c + a;
	}
	return a;
}
int main()
{
	string h[1010];
	h[1] = h[2] = "1";
	for (int i = 3; i <= 1000; ++i)
	{
		h[i] = str_add(h[i - 1], h[i - 2]);
	}
	int T;
	cin >> T;
	while (T--)
	{
		int pi;
		cin >> pi;
		cout << h[pi] << endl;
	}
	return 0;
}