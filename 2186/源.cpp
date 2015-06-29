#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>
#include <streambuf>
using namespace std;
int main()
{
	//streambuf *bk;
	//fstream fin;
	//bk = cin.rdbuf();
	//fin.open("data.txt");
	//cin.rdbuf(fin.rdbuf());
	int c;
	cin >> c;
	while (c--)
	{
		int n, re = 0;
		cin>>n;
		int a = n*0.5;
		re += (a / 10);
		if (a % 10)
			++re;
		n -= a;
		a = n * 2 / 3.0;
		re += (a / 10);
		if (a % 10)
			++re;
		n -= a;
		a = n;
		re += (a / 10);
		if (a % 10)
			++re;
		cout << re << endl;
	}
	//cin.rdbuf(bk);
	return 0;
}