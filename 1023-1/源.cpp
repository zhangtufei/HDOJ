#include <iostream>
#include <iomanip>
using namespace std;
//卡特兰数
//其前几项为: 1, 2, 5, 14, 42, 132, 429, 1430, 4862, 16796, 58786, 208012, 742900,
//	2674440, 9694845, 35357670, 129644790, 477638700, 1767263190, 6564120420,
//	24466267020, 91482563640, 343059613650, 1289904147324, 4861946401452, ...
//令h(0) = 1, h(1) = 1，catalan数满足递推式[1] ：
//h(n) = h(0)*h(n - 1) + h(1)*h(n - 2) + ... + h(n - 1)h(0) (n >= 2)
//例如：h(2) = h(0)*h(1) + h(1)*h(0) = 1 * 1 + 1 * 1 = 2
//h(3) = h(0)*h(2) + h(1)*h(1) + h(2)*h(0) = 1 * 2 + 1 * 1 + 2 * 1 = 5
//另类递推式[2] ：
//h(n) = h(n - 1)*(4 * n - 2) / (n + 1);

//#include <stdio.h>
//#define MAX 54
//void Multiple(int n, int* des)
//{
//	int i, k, temp1, temp2;
//	temp1 = 0;
//	for (k = MAX - 1; !des[k]; k--);
//	for (i = 0; i <= k; i++){
//		temp2 = des[i] * n + temp1;
//		des[i] = temp2 % 10000, temp1 = temp2 / 10000;
//	}
//	des[i] = temp1;
//	return;
//}
//void Devision(int n, int* des)
//{
//	int i, temp1, temp2;
//	temp1 = 0;
//	for (i = MAX - 1; !des[i]; i--);
//	for (; i >= 0; i--){
//		temp2 = des[i] + temp1 * 10000;
//		des[i] = temp2 / n;
//		temp1 = temp2 % n;
//	}
//	return;
//}
//void CatalanNumber(int n, int *des)
//{
//	int i;
//	for (i = n + 2; i <= 2 * n; i++) Multiple(i, des);
//	for (i = 1; i <= n; i++) Devision(i, des);
//	return;
//}
//int main()
//{
//	int i, n;
//	int des[MAX];
//	while (scanf("%d", &n) != EOF){
//		for (i = 0; i<MAX; i++) des[i] = 0; des[0] = 1;
//		CatalanNumber(n, des);
//		for (i = MAX - 1; i >= 0; i--) if (des[i] != 0) { printf("%d", des[i]); break; }
//		for (i--; i >= 0; i--){
//			printf("%04d", des[i]);
//		}
//		printf("\n");
//	}
//	return 0;
//}
int main()
{
	int n;
	while (cin >> n)
	{
		int num[60];
		num[0] = 1;
		for (int i = 1; i < 60; ++i)
			num[i] = 0;
		int mul;
		int add = 0;
		int add1 = 0;
		int flag = 1;
		for (int i = 2; i <= n; ++i)
		{
			mul = 4 * i - 2;
			for (int j = 0; j < flag; ++j)
			{
				num[j] *= mul;
				num[j] += add;
				add = 0;
				if (num[j] >= 10000)
				{
					add = num[j] / 10000;
					num[j] %= 10000;
					if (j == flag - 1)
						++flag;
					
				}
			}
		}
		for (int i = 2; i <= n; ++i)
		{
			for (int j = flag - 1; j >= 0; --j)
			{
				int temp = (num[j] + add1 * 10000);
				num[j] = temp / (i+1);
				add1 = temp%(i+1);
			}
		}
		int i = flag-1;
		while (num[i]  <=0)
			--i;
		cout << num[i];
		for (int j = i - 1; j >= 0; --j)
		{
			if (num[j] >= 1000)
				cout << num[j];
			else if (num[j] >= 100)
				cout << "0" << num[j];
			else if (num[j] >= 10)
				cout << "00" << num[j];
			else
				cout << "000" << num[j];
		}
		cout << endl;
	}
	return 0;
}