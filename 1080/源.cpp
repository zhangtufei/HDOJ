#include <iostream>
#include <string>
using namespace std;
int score[5][5] = { 5, -1, -2, -1, -3, -1, 5, -3, -2, -4, -2, -3, 5, -2, -2, -1, -2, -2, 5, -1, -3, -4, -2, -1,0 };
int al[110], as[110],n1,n2,dp[110];
void solve()
{

}
int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		memset(dp, 0, sizeof(dp));
		cin >> n1;
		//char c;
		//for (int i = 0; i < n1; ++i)
		//{
		//	cin >> c;
		//	switch (c)
		//	{
		//	case 'A':al[i] = 0; break;
		//	case 'C':al[i] = 1; break;
		//	case 'G':al[i] = 2; break;
		//	case 'T':al[i] = 3; break;
		//	default:break;
		//	}
		//}
		//cin >> n2;
		//for (int i = 0; i < n2; ++i)
		//{
		//	cin >> c;
		//	switch (c)
		//	{
		//	case 'A':as[i] = 0; break;
		//	case 'C':as[i] = 1; break;
		//	case 'G':as[i] = 2; break;
		//	case 'T':as[i] = 3; break;
		//	default:break;
		//	}
		//	dp[i] = -4;
		//}
	}
}