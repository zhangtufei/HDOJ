#include <iostream>
#include <streambuf>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <math.h>
using namespace std;
int h[100100];
int sol(int a, int  b)
{
	int temp = a%b;
	while (temp)
	{
		a = b;
		b = temp;
		temp = a%b;
	}
	return b;
}
int main()
{
		//streambuf *bk;
		//bk = cin.rdbuf();
		//fstream fin;
		//fin.open("data1.txt");
		//cin.rdbuf(fin.rdbuf());
		int T;
		cin >> T;
		int flag = 1;
		while (T--)
		{
			int n;
			cin >> n;
			memset(h, 0, sizeof(h));
			int max = 1;
			for (int i = 0; i < n; ++i)
			{
				int temp;
				cin >> temp;
				h[temp]++;
				if (h[temp] >= 2 && temp > max)
					max = temp;
			}
			
			for (int i = max; i <= 100000; ++i)
			{
				if (i < max)
					i = max + 1;
				int temp;
				int tt = 0;
				for (int j = 1; (temp = i*j) <= 100000; ++j)
				{
					if (h[temp])
					{
						if (tt==0)
							tt = 1;
						else if (tt == 1)
						{
							max = i;
							break;
						}
					}
				}
			}
			cout << "Case #" << flag++ << ": " << max << endl;
		}
		//cin.rdbuf(bk);
		return 0;
}



//1001
//struct point
//{
//	int x;
//	int y;
//	int z;
//};
//point vec(point B, point A)
//{
//	point ba;
//	ba.x = A.x - B.x;
//	ba.y = A.y - B.y;
//	ba.z = A.z - B.z;
//	return ba;
//}
//int main()
//{
//	//streambuf *bk;
//	//bk = cin.rdbuf();
//	//fstream fin;
//	//fin.open("data.txt");
//	//cin.rdbuf(fin.rdbuf());
//	int n;
//	cin >> n;
//	int flag = 1;
//	while (n--)
//	{
//		point A, B, C, D;
//		cin >> A.x >> A.y >> A.z >> B.x >> B.y >> B.z >> C.x >> C.y >> C.z >> D.x >> D.y >> D.z;
//		int t1 = (C.x - A.x)*(C.x - A.x) + (C.y - A.y)*(C.y - A.y) + (C.z - A.z)*(C.z - A.z);
//		int t2 = (B.x - A.x)*(B.x - A.x) + (B.y - A.y)*(B.y - A.y) + (B.z - A.z)*(B.z - A.z);
//		int t3 = (D.x - A.x)*(D.x - A.x) + (D.y - A.y)*(D.y - A.y) + (D.z - A.z)*(D.z - A.z);
//		if (t1 == t2)
//		{
//			point ba;
//			ba = vec(B, A);
//			point ad;
//			ad = vec(A, D);
//			point ac = vec(A, C);
//			if (ad.x + ba.x == ac.x&&ad.y + ba.y == ac.y&&ad.z + ba.z == ac.z)
//			{
//				cout << "Case #" << flag++ << ": Yes" << endl;
//				continue;
//			}
//		}
//		else if (t1 == t3)
//		{
//			point ab = vec(A, B);
//			point ca = vec(C, A);
//			point ad = vec(A, D);
//			if (ab.x + ca.x == ad.x&&ab.y + ca.y == ad.y&&ab.z + ca.z == ad.z)
//			{
//				cout << "Case #" << flag++ << ": Yes" << endl;
//				continue;
//			}
//		}
//		else if (t2 == t3)
//		{
//			point ba;
//			ba = vec(B, A);
//			point ac = vec(A, C);
//			point ad = vec(A, D);
//			if (ba.x + ac.x == ad.x&&ba.y + ac.y == ad.y&&ba.z + ac.z == ad.z)
//			{
//				cout << "Case #" << flag++ << ": Yes" << endl;
//				continue;
//			}
//		}
//		cout << "Case #" << flag++ << ": No" << endl;
//	}
//
//	//cin.rdbuf(bk);
//	return 0;
//}