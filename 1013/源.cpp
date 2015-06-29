#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main()
{
	string num;
	vector<int> re;
	while (cin >> num&&num!="0")
	{
		vector<int> vec;
		vector<int>::iterator iter;
		int len = num.length();
		char temp;
		for (int i = len - 1; i >= 0; --i)
		{
			temp =num[i];
			vec.push_back(temp - 0x30);
		}
		long long temp1 = 0;
		iter = vec.begin();
		for (; iter != vec.end(); ++iter)
			temp1 += *iter;
		while (temp1 >= 10)
		{
			vec.clear();
			int temp;
			temp = temp1 % 10;
			vec.push_back(temp);
			temp1 /= 10;
			while (temp1> 0)
			{
				temp = temp1 % 10;
				vec.push_back(temp);
				temp1 /= 10;
			}
			iter = vec.begin();
			for (; iter != vec.end(); ++iter)
				temp1 += *iter;
		}
		re.push_back(temp1);
	}
	vector<int>::iterator iter = re.begin();
	for (; iter != re.end(); ++iter)
		cout << *iter << endl;
	system("pause");
	return 0;
}