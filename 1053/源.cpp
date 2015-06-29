//Huffman±àÂë
#include <iostream>
#include <queue>
#include <string>
#include <functional>
#include <iomanip>
using namespace std;
struct node
{
	int num;
	friend bool operator<(node a, node b){ return a.num>b.num; }
};
int main()
{
	string s;
	while (cin >> s&&s.compare("END") != 0)
	{
		node count[27];
		int sum = 0;
		memset(count, 0, sizeof(count));
		for (int i = 0; i < s.size(); ++i)
		{
			if (s[i] == '_')
			{
				++count[0].num;
			}
			else
			{
				++count[s[i] - 'A' + 1].num;
			}
		}
		priority_queue<node> p;
		for (int i = 0; i < 27; ++i)
		{
			if (count[i].num)
				p.push(count[i]);
		}
		if (p.size() == 1)
		{
			sum += p.top().num;
		}
		else
		{
			while (p.size() > 1)
			{
				int a = p.top().num;
				p.pop();
				int b = p.top().num;
				p.pop();
				sum += (a + b);
				node temp;
				temp.num = a + b;
				p.push(temp);
			}
		}
		cout << 8 * s.size() << ' ' << sum << ' ';
		double d = (s.size()*8.0) / sum;
		cout.precision(1);
		cout << fixed << d << endl;
	}
	return 0;
}