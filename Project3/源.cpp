#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	string in;
	vector<string> sv;
	while (cin >> in)
	{
		sv.push_back(in);
	}
	vector<string>::iterator iter = sv.begin();
	for (; iter != sv.end();++iter)
	{
		string stemp;
		vector<string> vec;
		bool first = true;
		for (int i = 0; (*iter)[i] != '\0'; ++i)
		{
			if ((*iter)[i] == ',' || (i == (*iter).size() - 1))
			{
				if ((i == (*iter).size() - 1))
					stemp += (*iter)[i];
				if (stemp == "")
					continue;
				if (first)
				{
					vec.push_back(stemp);
					first = false;
				}
				else
				{
					vector<string>::iterator iter = vec.begin();
					bool flag = true;
					for (; iter != vec.end(); ++iter)
					{
						if (stemp == *iter)
						{
							flag = false;
							break;
						}
					}
					if (flag)
						vec.push_back(stemp);
				}
				stemp = "";
				continue;
			}
			stemp += (*iter)[i];
		}
		vector<string>::iterator iter1 = vec.begin();
		for (; iter1 != vec.end(); ++iter1)
		{
			if (iter1 == vec.end() - 1)
				cout << *iter1 << endl;
			else
				cout << *iter1 << ',';
		}
	}

}