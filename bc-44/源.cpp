#include <iostream>
#include <streambuf>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <math.h>
using namespace std;
//int main()
//{
//	streambuf *bk;
//	bk = cin.rdbuf();
//	fstream fin;
//	fin.open("data.txt");
//	cin.rdbuf(fin.rdbuf());
//
//
//	cin.rdbuf(bk);
//	return 0;
//}
int main()
{
	//streambuf *bk;
	//bk = cin.rdbuf();
	//fstream fin;
	//fin.open("data2.txt");
	//cin.rdbuf(fin.rdbuf());
	int T;
	cin >> T;
	int flag = 1;
	while (T--)
	{
		cout << "Case #" << flag++ << ": ";
		int n;
		vector<int> vec;
		cin >> n;
		int temp;
		for (int i = 0; i < n; ++i)
		{
			cin >> temp;
			vec.push_back(temp);
		}
		long long sum = 0;
		int lowbit;
		for (int i = 0; i < vec.size(); ++i)
		{
			for (int j = i + 1; j < vec.size(); ++j)
			{

				lowbit = vec[i] ^ vec[j];
				long long k = 0x00010000;
				if (lowbit == 0)
				{
					continue;
				}
				temp = 8;
				int x1 = lowbit%k, x2 = lowbit % (k >> 1);
				while (!(x1 != 0 && x2 == 0))
				{
					if (x1==0)
					{
						k=k << temp;
						if(temp!=1)
							temp /= 2;
					}
					else
					{
						k=k >> temp;
						if(temp!=1)
							temp /= 2;
					}
					x1 = lowbit%k;
					x2 = lowbit % (k >> 1);
				}
		/*		while (lowbit%k==0)
				{
					k *=2;
				}*/
				sum = (sum + k/2) % 998244353;
			}
		}
		cout << sum*2 << endl;
	}

	//cin.rdbuf(bk);
	return 0;
}
//int score[4] = { 4, 6, 8, 10 };
//int lows[4] = { 400, 600, 800, 1000 };
//int main()
//{
//	//streambuf *bk;
//	//bk = cin.rdbuf();
//	//fstream fin;
//	//fin.open("data.txt");
//	//cin.rdbuf(fin.rdbuf());
//	int T;
//	cin >> T;
//	int flag = 1;
//	while (T--)
//	{
//		cout << "Case #" << flag++ << ": ";
//		int sum = 0;
//		int a, b;
//		for (int i = 0; i < 4; ++i)
//		{
//			int temp = 0;
//			cin >> a >> b;
//			temp = (250 - a)*score[i] - b * 50;
//			if (temp < lows[i])
//				temp = lows[i];
//			sum += temp;
//		}
//		cout << sum << endl;
//	}
//	//cin.rdbuf(bk);
//	return 0;
//}