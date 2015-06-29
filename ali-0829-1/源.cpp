#include <iostream>
#include <string>
using namespace std;

int main()
{
	string que, text;
	cin >> que >> text;
	int re = 0;
	for (int i = 0; i < text.size(); ++i)
	{
		for (int j = 0; j < que.size(); ++j)
		{
			int last = (text.size() - i) < (que.size() - j) ? (text.size() - i) : (que.size() - j);
			if (last < re)
				break;
			if (text[i] == que[j])
			{

				int temp = 1;
				int t = i+1, q = j+1;
				if (t != text.size() && q != que.size())
				{
					while (text[t++] == que[q++])
					{
						++temp;
						if (t == text.size() || q == que.size())
							break;
					}
				}
				if (temp > re)
					re = temp;
			}
		}
	}
	cout << re << endl;
	system("pause");
}