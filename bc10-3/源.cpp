#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <math.h>
using namespace std;

int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int N;
		cin >> N;
		long long x[1010], y[1010];
		for (int i = 0; i < N; ++i)
		{
			cin >> x[i] >> y[i];
		}
		int re = 2;
		for (int i = 0; i < N; ++i)
		{
			for (int j = i + 1; j < N; ++j)
			{
				int sum = 2;
				if (x[i] == x[j])
				{
					for (int k = 0; k < N; ++k)
					{
						if (k == i || k == j)
							continue;
						if (x[k]==x[i])
							++sum;
					}
				}
				else
				{
					double xie = (y[i] - y[j]) / (x[i] - x[j]);
					double b = y[i] - xie*x[i];
					for (int k = 0; k < N; ++k)
					{
						if (k == i || k == j)
							continue;
						if (y[k] == xie*x[k] + b)
							++sum;
					}
				}
				if (sum > re)
					re = sum;
			}
		}
		cout << re / 3 << endl;
	}
	return 0;
}