#include <iostream>
using namespace std;
int n;
void exc(int *a, int i,int bg)
{
	int temp = a[i];
	a[i] = a[bg];
	a[bg] = temp;
}
int main()
{
	while (cin >> n&&n)
	{
		int a[110];
		cin >> a[0];
		int min = a[0], p = 0, flag = 0;
		for (int i = 1; i < n; ++i)
		{
			cin >> a[i];
			if (a[i] < min)
			{
				min = a[i];
				p = i;
			}
		}
		exc(a, p,flag++);
		for (int i = 1; i < n; ++i)
		{
			if (a[i] == a[0])
				exc(a, i,flag++);
		}
		for (int i = 0; i < n-1; ++i)
		{
			cout << a[i] << ' ';
		}
		cout << a[n - 1] << endl;
	}
}