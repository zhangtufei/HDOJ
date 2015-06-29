#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool Comp(int a,int b)
{
	return a > b;
}
int dfs(int a, int b)
{
	int tempb = a, temps = b;
	int c = tempb%temps;
	if (c == 0)
		return tempb;
	while (c)
	{
		tempb = temps;
		temps = c;
		c = tempb%temps;
	}
	if (temps == 1)
		return a*b;
	else
		return temps*dfs(a / temps, b / temps);
}
int main()
{
	int n, m;
	cin >> n;
	while (n--)
	{
		cin >> m;
		vector<int> vec;
		int temp;
		for (int i = 0; i < m; ++i)
		{
			cin >> temp;
			vec.push_back(temp);
		}
		sort(vec.begin(), vec.end(), Comp);
		vector<int>::iterator iter = vec.begin();
		int re = *iter;
		for (++iter; iter != vec.end(); ++iter)
		{
			re=dfs(re, *iter);
		}
		cout << re << endl;
		vec.clear();
	}
	system("pause");
	return 0;
}