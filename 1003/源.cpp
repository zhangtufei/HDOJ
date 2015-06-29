#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
using namespace std;
struct Result
{
	int result;
	int re_end;
	int re_begin;
};
int main()
{
	int lines, nums[100001];
	int cur_sum=0, end, max_sum = -1000, begin,m_end;
	int result=-1000, re_end, re_begin;
	vector<Result> vec;
	cin >> lines;
	while (lines--)
	{
		cin >> nums[0];
		if (nums[0] >= 1 && nums[0] <= 100000)
		{
			for (int i = 1; i <= nums[0]; ++i)
				cin >> nums[i];
			end = nums[0];
			for (int i = end; i >= 1; --i)
			{
				cur_sum += nums[i];
				if (cur_sum >= max_sum)
				{
					max_sum = cur_sum;
					begin = i;
					m_end = end;
				}
				/*if(cur_sum=max_sum)*/
				if (cur_sum <= 0 || i == 1)
				{
					if (max_sum >= result)
					{
						result = max_sum;
						re_begin = begin;
						re_end = m_end;
					}
					end =i-1;
					cur_sum = 0;
				}
				
			}
		}
		Result re;
		re.result = result;
		re.re_begin = re_begin;
		re.re_end = re_end;
		vec.push_back(re);
		max_sum = -1000;
		result = -1000;
	}
	vector<Result>::iterator iter;
	int i = 1;
	for (iter = vec.begin(); iter != vec.end(); ++iter,++i)
	{
		cout << "Case " << i << ':' << endl;
		cout << iter->result << ' ' << iter->re_begin << ' ' << iter->re_end << endl;
		if (iter != vec.end() - 1)
			cout << endl;
	}
	system("pause");
	return 0;
}