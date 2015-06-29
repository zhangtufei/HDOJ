#include <iostream>
#include <stdio.h>
#include <map>
using namespace std;
int main()
{
	int n;
	while (cin >> n&&n)
	{
		map<int, int> m;
		int temp;
		for (int i = 0; i < n; ++i)
		{
			scanf("%d", &temp);
			++m[temp];
		}
		map<int, int>::iterator iter = m.begin();
		for (; iter != m.end(); ++iter)
			if (iter->second == 1)
				cout << iter->first << endl;
	}
	return 0;
}
//叼炸天，按位异或
//#include <stdio.h>
//
//int main()
//{
//	int n, s, a;
//	while (scanf("%d", &n), n) {
//		s = 0;
//		while (n--) {
//			scanf("%d", &a);
//			s ^= a;
//		}
//		printf("%d\n", s);
//	}
//	return 0;
//}