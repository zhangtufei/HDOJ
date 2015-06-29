#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	int n;
	cin >> n;
	while (n--)
	{
		int temp;
		vector<int> vec;
		for (int i = 0; i < 6; ++i)
		{
			cin >> temp;
			vec.push_back(temp);
		}
		sort(vec.begin(), vec.end());
		int g = vec[4] + vec[5];
		int b = vec[1] + vec[2] + vec[3];
		if (g > b)
			cout << "Grandpa Shawn is the Winner!" << endl;
		else
			cout << "What a sad story!" << endl;
	}
	return 0;
}