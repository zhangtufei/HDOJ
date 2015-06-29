#include <iostream>
#include <streambuf>
#include <fstream>
using namespace std;
int main()
{
	//streambuf * backup;
	//fstream fin;
	//fin.open("data.txt");
	//backup = cin.rdbuf();
	//cin.rdbuf(fin.rdbuf());
	int n, m;
	while (cin >> n >> m)
	{
		int temp, a, b;
		if (n == m)
		{
			cout << n << endl;
			continue;
		}
		if (n < m)
		{
			a = m;
			b = n;
		}
		else
		{
			a = n;
			b = m;
		}
		temp = a%b;
		while (temp)
		{
			a = b;
			b= temp;
			temp = a%b;
		}
		cout << n*m / b << endl;
	}
	//cin.rdbuf(backup);
	return 0;
}