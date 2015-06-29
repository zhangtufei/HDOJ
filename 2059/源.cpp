#include <iostream>
#include <string>
using namespace std;
double p[110];
int main()
{
	int L;
	while (cin >> L)
	{
		int N;
		double	C, T;
		cin >> N >> C >> T;
		double vr, vt1, vt2;
		cin >> vr >> vt1 >> vt2;
		double path[110];
		path[0] = 0.0;
		path[N + 1] = L;
		for (int i = 1; i <= N; ++i)
		{
			cin >> path[i];
		}
		memset(p,0, sizeof(double) * 110);
		for (int i = N; i >= 0; --i)
		{
			double temp = path[i + 1] - path[i];
			p[i] = T;
			if (temp >= C)
			{
				p[i] += C / (double)vt1;
				p[i] += (temp - C) / (double)vt2;

			}
			else
				p[i] += temp / (double)vt1;
		}
		p[0] -= T;
		//bool powe = true;//表示在上一个充电站是否充电
		double p0;
		double p1 = path[1] - path[0];
		if (p1 > C)
			p0 = 0;
		else
			p0 = C - p1;
		for (int i = 1; i <= N; ++i)
		{
			//p1 = path[i] - path[i - 1];
			if (L - path[i] <= C)
			{
				for (int j = i; j <= N; ++j)
				{
					p[j] = (path[j + 1] - path[j]) / (double)vt1;
				}
				p[i] += T;
				break;
			}
			double p2 = path[i + 1] - path[i];
			double t;
			if (p0 == 0)
			{
				t = p2 / (double)vt2;
			}
			else
			{
				if (p0>p2)
					t = p2 / (double)vt1;
				else
				{
					t = p0 / (double)vt1;
					t += (p2 - p0) / (double)vt2;
				}
			}
			if (t <= p[i])
			{
				p[i] = t;
				//powe = false;
				if (p0 > p2)
					p0 -= p2;
				else
					p0 = 0;
			}
			else
			{
				//powe = true;
				if (C > p2)
					p0 = C - p2;
				else
					p0 = 0;
			}
		}
		double sum = 0;
		for (int i = 0; i <= N; ++i)
			sum += p[i];
		double time = L / (double)vr;
		if (sum > time)
			cout << "Good job,rabbit!" << endl;
		else
			cout << "What a pity rabbit!" << endl;
	}
	return 0;
}