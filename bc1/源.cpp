#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int n, m;
		cin >> n >> m;
		vector<int> t;
		vector<int> vec;
		vector<int> vec1;
		int temp;
		int flag = 1;
		cin >> temp;
		for (; flag < temp; ++flag)
			t.push_back(flag);
		++flag;
		for (int i = 1; i <n; ++i)
		{
			cin >> temp;
			for (; flag < temp; ++flag)
			{
				t.push_back(flag);
			}
			++flag;
		}
		int max = temp;
		vector<int>::iterator iter1 = t.begin();
		for (int i = 1; i <=m; ++i)
		{
			cin >> temp;
			bool flag = true;
			for (iter1 = t.begin(); iter1 != t.end(); ++iter1)
			{
				if (temp <= *iter1)
				{
					cout << *iter1 << endl;
					flag = false;
					break;
				}
			}
			if (flag)
			{
				if (temp > max)
					cout << temp << endl;
				else
					cout << max+1 << endl;
			}
		}
		//sort(vec.begin(), vec.end());
		//vector<int>::iterator iter = vec.begin();
		//vector<int>::iterator iter1 = t.begin();
		//for (; iter1 != t.end(); ++iter1)
		//{
		//	for (; iter != vec.end()&&*iter<=*iter1; ++iter)
		//	{
		//		cout << *iter1 << endl;
		//	}
		//	if (iter == vec.end())
		//		break;
		//}
		//while (iter!= vec.end())
		//{
		//	if (*iter > max)
		//		cout << *iter << endl;
		//	else
		//		cout << max+1 << endl;
		//	++iter;
		//}
	}
	return 0;
}