#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main()
{
	int n;
	cin >> n;
	while (n--)
	{
		char letter[10010];
		cin >> letter;
		int count = 1;
		for (int i = 0; letter[i] != '\0'; ++i)
		{
			if (letter[i] == letter[i + 1])
				++count;
			else
			{
				if (count > 1)
					cout << count;
				count = 1;
				cout << letter[i];
			}

		}
		//for (int i = 0; i < 26; ++i)
		//{
		//	char le = 'A' + i;
		//	int temp = letters[i].size();
		//	if (temp == 1)
		//		cout << le;
		//	else if (temp>1)
		//	{
		//		cout << temp;
		//		cout << le;
		//	}	
		//}
		cout << endl;
	}
	system("pause");
	return 0;
}