#include <iostream>
#include <vector>
using namespace std;
vector<int> vec;
void block()
{
	for (int i = 1; i <= 1000000; ++i)
	{
		if (i == 620000)
		{
			i += 10000;
			vec.push_back(i);
			continue;
		}
		if (i == 400000)
		{
			i += 100000;
			vec.push_back(i);
			continue;
		}
			
		if (i % 100000 == 62000)
		{
			i += 1000;
			vec.push_back(i);
			continue;
		}
		if (i % 100000 == 40000)
		{
			i += 10000;
			vec.push_back(i);
			continue;
		}
		if (i % 10000 == 6200)
		{
			i += 100;
			vec.push_back(i);
			continue;
		}
		if (i % 10000 == 4000)
		{
			i += 1000;
			vec.push_back(i);
			continue;
		}
		if (i % 1000 == 620)
		{
			i += 10;
			vec.push_back(i);
			continue;
		}
		if (i % 1000 == 400)
		{
			i += 100;
			vec.push_back(i);
			continue;
		}
		if (i % 100 == 62)
		{
			i += 1;
			vec.push_back(i);
			continue;
		}
		if (i % 100 == 40)
		{
			i += 10;
			vec.push_back(i);
			continue;
		}
		if (i % 10 == 4)
			i += 1;
		vec.push_back(i);
		continue;		
	}
}
int main()
{
	int n, m;
	block();
	while (cin >> n >> m&&n&&m)
	{	
		vector<int>::iterator iter = vec.begin();
		while (*iter < n)
			++iter;
		int temp = 0;
		while (*iter <= m)
		{
			++iter;
			++temp;
		}
		cout << temp << endl;
	}
	system("pause");
	return 0;

}