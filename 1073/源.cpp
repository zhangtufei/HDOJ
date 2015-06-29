#include <iostream>
#include <string>
using namespace std;
int main()
{
	int T;
	cin >> T;
	string s1 = "START", s2 = "END";
	getchar();
	while (T--)
	{
		string sc;
		string stemp;
		while (getline(cin, stemp))
		{
			if (stemp == s1)
				continue;
			if (stemp == s2)
				break;
			sc =sc+ stemp + '\n';
		}
		string so;
		while (getline(cin, stemp))
		{
			if (stemp == s1)
				continue;
			if (stemp == s2)
				break;
			so =so+ stemp + '\n';
		}
		int flag = 0;//1ÎªWA£¬2ÎªPE£»
		int i = 0, j = 0;
		for (; i < sc.size(),j<so.size();)
		{
			if (sc[i] == so[j])
			{
				++j;
				++i;
				continue;
			}
			else
			{
				if (sc[i] == ' ' || sc[i] == '\t' || sc[i] == '\n')
				{
					if (so[j] == ' ' || so[j] == '\t' || so[j] == '\n')
					{
						flag = 2;
						++i;
						++j;
						continue;
					}
					else
					{
						flag = 2;
						++i;
						continue;
					}
				}
				else if (so[j] == ' ' || so[j] == '\t' || so[j] == '\n')
				{
					flag = 2;
					++j;
					continue;
				}
				else
				{
					flag = 1;
					break;
				}
			}
		}
		if (flag != 1)
		{
			if (i != sc.size())
			{
				for (; i < sc.size(); ++i)
				{
					if (sc[i] == ' ' || sc[i] == '\t' || sc[i] == '\n')
					{
						flag = 2;
						continue;
					}
					else
					{
						flag = 1;
						break;
					}
				}
			}
			else if (j != so.size())
			{
				for (; j < so.size(); ++j)
				{
					if (so[j] == ' ' || so[j] == '\t' || so[j] == '\n')
					{
						flag = 2;
						continue;
					}
					else
					{
						flag = 1;
						break;
					}
				}
			}
		}
		if (!flag)
			cout << "Accepted" << endl;
		else if (flag == 2)
			cout << "Presentation Error" << endl;
		else if (flag == 1)
			cout << "Wrong Answer" << endl;
	}
	return 0;
}