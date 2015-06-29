#include <iostream>
#include <vector>
using namespace std;
int main()
{
	char c;
	
	vector<char> ch;
	vector<int> num;
	while (cin >> c&&c != '@')
	{
		int n;
		cin >> n;
		ch.push_back(c);
		num.push_back(n);
	}
	vector<char>::iterator iterc = ch.begin();
	vector<int>::iterator itern = num.begin();
	for (; iterc != ch.end() && itern != num.end(); ++iterc, ++itern)
	{
		for (int i = 0; i < *itern - 1; ++i)
		{
			for (int j = 1; j <= *itern + i; ++j)
			{
				if (j != *itern - i&&j != *itern + i)
					cout << ' ';
				else
					cout << *iterc;
			}
			cout << endl;
		}
		for (int i = 0; i < 2 * (*itern) - 1; ++i)
			cout << *iterc;
		cout << endl;
		if (iterc != ch.end() - 1)
			cout << endl;
	}
	system("pause");
	return 0;
}