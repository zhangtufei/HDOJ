#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	int m;
	cin >> m;
	while (m--)
	{
		int n;
		cin >> n;
		vector<int> vec;
		int temp;
		for (int i = 0; i < n; ++i)
		{
			cin >> temp;
			vec.push_back(temp);
		}
		sort(vec.begin(), vec.end());
		int mid = vec[vec.size() / 2];
		int sum=0;
		vector<int>::iterator iter = vec.begin();
		for (; iter != vec.end(); ++iter)
		{
			sum += (*iter - mid>0) ? (*iter - mid) : (mid - *iter);
		}
		cout << sum << endl;
	}
	return 0;
}