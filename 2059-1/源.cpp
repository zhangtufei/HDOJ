//动态规划
#include <iostream>
#include <string>
using namespace std;
int main()
{
	int L;
	while (cin >> L)
	{
		int N,C, T;
		cin >> N >> C >> T;
		int vr, vt1, vt2;
		cin >> vr >> vt1 >> vt2;
		double path[110];
		path[0] = 0.0;
		path[N + 1] = L;
		for (int i = 1; i <= N; ++i)
		{
			cin >> path[i];
		}
		double dp[110];
		for (int i = 1; i < 110; ++i)
			dp[i] = 0xfffffff;
		dp[0] = 0;
		double time = L / (double)vr;
		//用i循环遍历所有加油站，再用j循环遍历所有i之前的加油站，找到从j站加油，到i站，最短时间,保存在DP中
		for (int i = 1; i <= N + 1; ++i)
		{
			for (int j = 0; j < i; ++j)
			{
				double temp;
				if (path[i] - path[j] <= C)
					temp = (path[i] - path[j]) / (double)vt1 + T;
				else
					temp = C / (double)vt1 + (path[i] - path[j] - C) / (double)vt2 + T;
				if (!j)
					temp -= T;
				dp[i] = (dp[i] < dp[j] + temp) ? dp[i] : (dp[j] + temp);
			}
		}
		if (dp[N + 1]>time)
			cout << "Good job,rabbit!" << endl;
		else
			cout << "What a pity rabbit!" << endl;
	}
	return 0;
}