#include <iostream>
#include <string>
#include <math.h>
#include <algorithm>
#include <map>
using namespace std;
//第二题
bool suc;
string ToString(long long n)
{
	string st = "";
	char temp;
	while (n)
	{
		temp = n % 10 + '0';
		st = temp + st;
		n /= 10;
	}		
	return st;
}
long long ToInt(string st)
{
	long long temp=0;
	for (int i = 0; i < st.size(); ++i)
	{
		temp = temp * 10 + (st[i] - '0');
	}
	return temp;
}
void getNext(string p, int *next)
{
	int j, k;
	next[0] = -1;
	j = 0;
	k = -1;
	while (j<p.size() - 1)
	{
		if (k == -1 || p[j] == p[k])    //匹配的情况下,p[j]==p[k]
		{
			j++;
			k++;
			next[j] = k;
		}
		else                   //p[j]!=p[k]
			k = next[k];
	}
}
bool Kmp(string s1,string s2)
{
	int next[100];
	int i, j;
	i = 0;
	j = 0;
	getNext(s2, next);
	while (i<s1.size())
	{
		if (j == -1 || s1[i] == s2[j])
		{
			i++;
			j++;
		}
		else
		{
			j = next[j];       //消除了指针i的回溯
		}
		if (j == s2.size())
			return true;
	}
	return false;
}
//bool match_s(string s1,string s2)
//{
//	!Kmp(s1, s2) 
//}
int main()
{
	long long a;
	string s;
	while (cin >> a>>s)
	{
		long long temp = 1,b;
		string st1=s, st2=s;
		if (s[0] == '0')
		{
			st1 = '1' + st1;
			temp = ToInt(st1);
		}
		else
		{
			temp = ToInt(s);
		}
		if (temp <= a)
		{
			temp = a;
		}
		b = temp / a;
		string s2 = ToString(b*a);
		string s3 = ToString((b + 1)*a);
		suc = false;
		if (Kmp(s2, s))
			suc = true;
		if (Kmp(s3, s))
		{
			++b;
			suc = true;
		}
		while (!suc)
		{
			st1 = '1' + st1;
			temp = ToInt(st1);
			b = temp / a;
			s2 = ToString(b*a);
			s3 = ToString((b + 1)*a);
			if (Kmp(s2, s))
				break;
			if (Kmp(s3, s))
			{
				++b;
				break;
			st2 += '0';
			temp = ToInt(st2);
			b = temp / a;
			s2 = ToString(b*a);
			s3 = ToString((b + 1)*a);
			if (Kmp(s2, s))
				break;
			if (Kmp(s3, s))
			{
				++b;
				break;
			}
			}
		}
		//while (!Kmp(s2, s)&&!Kmp(s3,s))
		//{
		//	temp *= 10;
		//	b = temp / a;
		//	s2 = ToString(b*a);
		//}
		cout << b << endl;
	}
	return 0;
}
//第一题
//map<long long, int> primer;
//int p[500001];
//bool Isprimer(long long x)
//{
//	if (primer[x])
//		return true;
//	long long sx = sqrt(double(x));
//	bool flag = true;
//	for (int i = 2; i <= sx; ++i)
//	{
//		if (x%i == 0)
//		{
//			flag = false;
//			break;
//		}
//	}
//	return flag;
//}
//void Init()
//{
//	primer[1] = 1;
//	for (int i = 2; i <= 500000; ++i)
//	{
//		if (!p[i]&&Isprimer(i))
//		{
//			int j = 2;
//			primer[i] = 1;
//			long long temp = i*j;
//			while (temp <= 500000)
//			{
//				p[temp] = 1;
//				++j;
//				temp = i*j;
//			}
//		}
//	}
//	//for (int i = 1; i <= 500000; ++i)
//	//{
//	//	if (!p[i])
//	//		primer[i] = 1;
//	//}
//}
//
//int main()
//{
//	long long n;
//	Init();
//	while (cin >> n)
//	{
//		long long sx = sqrt(double(n));
//		//bool flag = true;
//		//bool flag1 = false;
//		int min = 0;
//		for (int i = 1; i <= sx; ++i)
//		{
//			if (n%i == 0 )
//			{
//				if (primer[n/i]||Isprimer(n/i))
//				{
//					primer[n/i]=1;
//					min = i;
//					//flag = false;
//					break;
//				}
//				else if (primer[i]||Isprimer(i))
//				{
//					primer[i] = 1;
//					if (!min)
//						min = n / i;
//					else if (min > n / i)
//						min = n / i;
//				}
//			}
//		}
//		cout << min<< endl;
//	}
//	return 0;
//}