#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;
int main()
{
	vector<string> output;
	int lines;
	while (cin >> lines)
	{
		if (lines == 0)
			break;
		map<string, int> input;
		string col;
		while (lines--)
		{
			cin >> col;
			++input[col];
		}
		map<string, int>::iterator iter = input.begin();
		int max = 0;
		for (; iter != input.end(); ++iter)
		{
			if (iter->second > max)
			{
				max = iter->second;
				col = iter->first;
			}
		}
		output.push_back(col);
	}
	vector<string>::iterator iter = output.begin();
	for (; iter != output.end(); ++iter)
	{
		cout << *iter << endl;
	}
	system("pause");
	return 0;
}