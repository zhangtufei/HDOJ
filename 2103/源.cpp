#include <iostream>
#include <streambuf>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <math.h>
using namespace std;
long long f[31];
int main()
{
	//streambuf *bk;
	//bk = cin.rdbuf();
	//fstream fin;
	//fin.open("data.txt");
	//cin.rdbuf(fin.rdbuf());
	f[0] = 0; f[1] = 1;
	long long temp = 2;
	for (int i = 2; i <= 30; ++i)
	{
		f[i] = temp  + f[i - 1];
		temp *= 2;
	}
	int T, M, N;
	cin >> T;
	while (T--)
	{
		cin >> M >> N;
		int b[31];
		int flag = 0;
		for (int i = 1; i <= N; ++i)
		{
			cin >> b[i];
			if (!flag&&i <= M&&b[i] == 1)
				flag = i;
		}
		if (!flag)
		{
			flag = N < M ?N : M;
		}
		if (f[N - flag])
			cout << f[N - flag] << "0000 RMB" << endl;
		else
			cout <<"0 RMB"<< endl;
	}
	//cin.rdbuf(bk);
	return 0;
}