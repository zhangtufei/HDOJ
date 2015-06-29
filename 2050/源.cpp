//第n条折线与前面的n-1条相交，有4（n-1）个交点，就有两条射线及4(n-1)条线段，又在折线的顶点处，两条线段只增加一块区域，所以hn=hn-1+4(n-1)-1+2》》hn=2n^2-n+1;
#include <iostream>
using namespace std;
int main()
{
	int c;
	cin >> c;
	while (c--)
	{
		int n;
		cin >> n;
		cout << 2 * n*n - n + 1 << endl;
	}
	return 0;
}