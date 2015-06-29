#include <iostream>
#include <math.h>
using namespace std;
int main()
{
	int N, M;
	while (cin >> N >> M)
	{
		int n_i, n_x, n_y, m_i, m_x, m_y;
		n_i = sqrt((double)(N - 1)) + 1;
		n_x = (N - (n_i - 1)*(n_i - 1) - 1) / 2 + 1;
		n_y = (n_i*n_i - N) / 2 + 1;
		m_i = sqrt((double)(M - 1)) + 1;
		m_x = (M - (m_i - 1)*(m_i - 1) - 1) / 2 + 1;
		m_y = (m_i*m_i - M) / 2 + 1;
		n_i = n_i - m_i > 0 ? n_i - m_i : m_i - n_i;
		n_x = n_x - m_x > 0 ? n_x - m_x : m_x - n_x;
		n_y = n_y - m_y > 0 ? n_y - m_y : m_y - n_y;
		cout << n_i + n_x + n_y << endl;
	}
	return 0;
}