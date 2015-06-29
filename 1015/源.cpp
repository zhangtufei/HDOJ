#include <iostream>
#include <string>
using namespace std;
int main()
{
	long long num;
	string letters;
	int n[12];
	while (cin >> num >> letters&&!(num == 0 && letters == "END"))
	{
		int len = letters.length();
		memset(n, 0, sizeof(n));
		for (int i = 0; i < len; ++i)
		{
			n[i] = letters[i] - 'A' + 1;
		}
		for (int i = 0; i < len; ++i)
		{
			for (int j = i + 1; j < len; ++j)
			{
				if (n[i] < n[j])
				{
					int temp = n[i];
					n[i] = n[j];
					n[j] = temp;
				}
			}
		}
		bool flag = false;
		for (int i = 0; i < len; ++i)
		{
			for (int j = 0; j < len; ++j)
			{
				if (j == i)
					continue;
				for (int k = 0; k < len; ++k)
				{
					if (k == i || k == j)
						continue;
					for (int x = 0; x < len; ++x)
					{
						if (x == i || x == j || x == k)
							continue;
						for (int y = 0; y < len; ++y)
						{
							if (y == i || y == j || y == k || y == x)
								continue;
							int re = n[i] - n[j] * n[j] + n[k] * n[k] * n[k] - n[x] * n[x] * n[x] * n[x] + n[y] * n[y] * n[y] * n[y] * n[y];
							if (re == num)
							{
								char s1[6];
								s1[0] = n[i] + 'A'-1;
								s1[1] = n[j] + 'A'-1;
								s1[2] = n[k] + 'A'-1;
								s1[3] = n[x] + 'A'-1;
								s1[4] = n[y] + 'A'-1;
								s1[5] = '\0';
								cout << s1 << endl;
								flag = true;
								break;
							}
						}
						if (flag)
							break;
					}
					if (flag)
						break;
				}
				if (flag)
					break;
			}
			if (flag)
				break;
		}
		if (flag == false)
			cout << "no solution" << endl;
	}
	system("pause");
	return 0;
}