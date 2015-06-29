#include <iostream>
using namespace std;
int a[26];
long long num;
void dfs(int i,int p)
{
	if (i >= 26)
		return;
	if (p < 0)
		return;
	for (int temp = 1; temp <= a[i]; ++temp)
	{
		int pp = p - temp*(i + 1);
		if (pp < 0)
			break;
		++num;
		for (int j = i + 1; j < 26;++j)
			dfs(j,pp);
	}
}
int main()
{
	int n;
	cin >> n;
	while (n--)
	{
		num = 0;
		for (int i = 0; i < 26; ++i)
			cin >> a[i];
		for (int i = 0; i < 26; ++i)
		{
			if (a[i] == 0)
				continue;
			dfs(i, 50);
		}
		cout << num << endl;
	}
}