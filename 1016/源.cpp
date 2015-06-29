#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int num[25];
vector<int> prime[25];
bool isprime(int a)
{
	bool flag = true;
	for (int i = 2; i <= (int)sqrtf((float)a); ++i)
		if (a % i == 0)
		{
			flag = false;
			break;
		}
	return flag;
}
void dfs(int n,int x)
{
	if (x == n)
	{
		vector<int>::iterator iter1 = prime[num[x-1]].begin();
		
		for (; iter1 != prime[num[x-1]].end() && *iter1 <= n; ++iter1)
		{
			vector<int>::iterator iter2 = prime[1].begin();
			for (; iter2 != prime[1].end() && *iter2 <= n; ++iter2)
			{
				if (*iter1 == *iter2)
				{
					bool repeat = false;
					for (int i = 1; i < x; ++i)
						if (*iter1 == num[i])
						{
						repeat = true;
						break;
						}
					if (repeat)
						continue;
					num[x] = *iter1;
					for (int i = 1; i < n; ++i)
						cout << num[i] << ' ';
					cout <<num[n] <<endl;
					return;
				}
			}
		}
		return;
	}
	vector<int>::iterator iter = prime[num[x-1]].begin();
	for (; iter != prime[num[x-1]].end() && *iter <= n; ++iter)
	{
		bool repeat = false;
		for (int i = 1; i < x; ++i)
			if (*iter == num[i])
			{
				repeat = true;
				break;
			}
		if (repeat)
			continue;
		num[x] = *iter;
		dfs(n, x + 1);
	}
	return;
}
int main()
{
	int n;
	int flag = 0;
	
	for (int i = 1; i <= 20; ++i)
	{
		for (int j = 1; j <=20; ++j)
		{
			if (j == i)
				continue;
			if (isprime(i + j))
				prime[i].push_back(j);
		}
	}
	while (cin >> n)
	{
		num[1] = 1;
		++flag;
		cout << "Case " << flag << ':' << endl;
		if (n % 2 == 0)
			dfs(n, 2);
		else if (n == 1)
			cout << '1' << endl;
		cout << endl;
			
	}
	return 0;
}