#include <iostream>
#include <string>
using namespace std;
//将5为都看做1 table[10]={1,1,2,6,4,4,4,8,4,6};
//		F([N / 5]) * table[N的尾数] * 6
//F(N) = ----------------------------------(N > 10)
//			2 ^ ([N / 5] MOD 4)
//F[N]=F[N/5]*T[N的尾数]，下面的table表即T【N的尾数】，20为一个周期
int table[20] = { 1, 1, 2, 6, 4, 2, 2, 4, 2, 8, 4, 4, 8, 4, 6, 8, 8, 6, 8, 2 };
int main()
{
	string s;
	while (cin >> s)
	{
		int a[10000];
		for (int i = s.size() - 1,j=0; i >= 0; --i,++j)
		{
			a[j] = s[i] - 0x30;
		}
		int len = s.size(),re=1;
		while (len)
		{
			len -= !a[len - 1];
			re = re*table[a[1] % 2 * 10 + a[0]] % 10;
			for (int i = len - 1, temp = 0; i >= 0; --i)
			{
				temp = temp * 10 + a[i];
				a[i] = temp / 5;
				temp %= 5;
			}
		}
		cout << re << endl;
	}
	return 0;
}
//#include <iostream>
//using namespace std;
//int main()
//{
//	int n;
//	while (cin >> n)
//	{
//		int re[10];
//		re[1] = 1;
//		for (int i = 2; i <= n; ++i)
//		{
//			if (i % 10 == 0)
//			{
//				int temp = i;
//				while (temp % 10 == 0)
//					temp /= 10;
//				temp %= 10;
//				re[0] = (re[9] * temp) % 10;
//			}
//			else if (i % 10 == 5)//还有50.500,5000  。。。要考虑
//			{
//				int temp = re[1] * i*(i - 3);
//				while (temp % 10 == 0)
//					temp /= 10;
//				temp %= 10;
//				re[5] = (temp * 2) % 10;
//			}
//			else
//			{
//				int temp = i % 10;
//				re[temp] = (re[temp - 1] *temp) % 10;
//			}
//		}
//		cout << re[n % 10] << endl;
//	}
//	return 0;
//}

//#include<stdio.h>
//#include<string.h>
//int mod[20] = { 1, 1, 2, 6, 4, 2, 2, 4, 2, 8, 4, 4, 8, 4, 6, 8, 8, 6, 8, 2 };
//char n[1000];
//int a[1000];
//int main()
//{
//	int i, c, t, len;
//	while (scanf("%s", n) != EOF)
//	{
//		t = 1;
//		len = strlen(n);
//		for (i = 0; i<len; i++)
//			a[i] = n[len - 1 - i] - '0';
//		while (len)
//		{
//			len -= !a[len - 1];
//			//设mod表的函数为T，F[N]=F[N/5]*T[N的尾数]（一直乘到N<10），这时候在乘T【N】；
//			t = t*mod[a[1] % 2 * 10 + a[0]] % 10;//mod表以20为一个周期
//			//输入整除5
//			for (c = 0, i = len - 1; i >= 0; i--)
//				c = c * 10 + a[i], a[i] = c / 5, c %= 5;
//		}
//		printf("%d\n", t);
//	}
//	return 0;
//}