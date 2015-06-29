#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;
int main()
{
	long long step, mod;
	
	while (cin >> step >> mod)
	{
		bool flag=true;
		long long tempb, temps;
		string good = "    Good Choice";
		string bad = "    Bad Choice";
		if (step < mod)
		{
			tempb = mod;
			temps = step;
		}
		else
		{
			tempb = step;
			temps = mod;
		}
		int c = tempb%temps;
		while (c!=0)
		{
			tempb = temps;
			temps = c;
			c = tempb%temps;
		}
		string s = (temps == 1 ? good : bad);
		cout <<setw(10)<<step <<setw(10)<< mod << s << endl << endl;
	}
	return 0;
}