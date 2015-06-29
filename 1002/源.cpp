#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main()
{

	string s1,s2,num1,num2;
	string::iterator iter1, iter2,iters;
	vector<string> vec;
	int lines;
	cin >> lines;
	//while (cin >> lines)
	//{
		while (lines >= 1 && lines <= 20)
		{
			cin >> s1 >> s2;
			if (s1.length() >= s2.length())
			{
				num1 = s1;
				num2 = s2;
			}
			else
			{
				num1 = s2;
				num2 = s1;
			}
			iter1 = num1.end() - 1;
			iter2 = num2.end() - 1;
			int flag = 0;
			for (; (*iter1 >= '0'&&*iter1 <= '9') && (*iter2 >= '0'&&*iter2 <= '9'); --iter1, --iter2)
			{

				*iter1 = *iter1 + *iter2 - 0x30+flag;
				flag = 0;
				if (*iter1 > '9')
				{
					*iter1 -= 10;
					flag = 1;
				}
				if (iter2 == num2.begin())
				{
					if (flag == 1)
					{
						if (iter1 == num1.begin())
							num1 = '1' + num1;
						else
						{
							while (flag == 1)
							{
								*(--iter1) += 1;
								if (*iter1 > '9')
								{
									*iter1 -= 10;
									if (iter1 == num1.begin())
									{
										num1 = '1' + num1;
										flag = 0;
									}
								}
								else
									flag = 0;
							}
						}
					}
					break;
				}
			}
			iter1 = num1.begin();
			while (*iter1 == '0')
				++iter1;
			string temp;
			for (; iter1 != num1.end(); ++iter1)
				temp += *iter1;
			num2 = s1 + " + " + s2 + " = " + temp;
			vec.push_back(num2);
			--lines;
		}
		vector<string>::iterator iter = vec.begin();
		for (int i = 1; iter != vec.end(); ++iter, ++i)
		{
			cout << "Case " << i <<':'<< endl;
			cout << *iter << endl;
			if (iter != vec.end() - 1)
				cout << endl;
		}
	//	vec.clear();
	//}
	system("pause");
	return 0;
}
//int lines;
//vector<long long> vec;
//vector<long long>::iterator iter;
//vector<long long> vec1;
//vector<long long> vec2;
//string s;
//long long num1, num2, sum;
//cin >> lines;
//if (lines >= 1 && lines <= 20)
//{
//	while (lines > 0)
//	{
//		cin >> num1 >> num2;
//		sum = num1 + num2;
//		vec.push_back(sum);
//		vec1.push_back(num1);
//		vec2.push_back(num2);
//		--lines;
//	}
//	iter = vec.begin();
//	for (int i = 0; iter != vec.end(); ++iter, ++i)
//	{
//		cout << "Case " << i + 1 << ':' << endl;
//		cout << vec1[i] << '+' << vec2[i] << '=' << *iter << endl << endl;
//	}
//	vec.clear();
//	vec1.clear();
//	vec2.clear();
//}