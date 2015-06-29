#include <iostream>
#include <algorithm>
#include <stack>
#include <string>
using namespace std;
struct node
{
	int beg;
	int end;
};
int used[100001];
int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int n;
		cin >> n;
		string words[100001], temp;
		node a[100001];
		for (int i = 0; i < n; ++i)
		{
			cin >> temp;
			words[i] = temp;
			a[i].beg = temp[0] - 'a';
			a[i].end = temp[temp.size() - 1] - 'a';
		}
	}
}