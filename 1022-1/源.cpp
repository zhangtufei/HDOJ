//虽然一次进栈的数据最多九个，但是会多次反复进栈，所以应定义大数组
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main()
{
	int n;
	while (cin >> n)
	{
		string strin, strout;
		cin >> strin >> strout;
		char inarray[10001];
		vector<string> vec;
		string s1 = "in", s2 = "out";
		int o2 = 0;
		int o1 = 0;
		int oc = 0;
		for (int i = 0; o1<n&&o2<n;++i)
		{
			if (strin[o1] != strout[o2])
			{
				vec.push_back(s1);
				inarray[i] = strin[o1];
				++o1;
				
			}
			else
			{
				vec.push_back(s1);
				vec.push_back(s2);
				++o1;
				++o2;
				++oc;
				--i;
				while (inarray[i] == strout[o2])
				{
					vec.push_back(s2);
					--i;
					++o2;
					++oc;
				}
			}
		}
		
		if (vec.size() == 2 * n&&oc==n)
		{
			vector<string>::iterator iter = vec.begin();
			cout << "Yes." << endl;
			for (; iter != vec.end(); ++iter)
				cout << *iter << endl;
			cout << "FINISH" << endl;
		}
		else
		{
			cout << "No." << endl << "FINISH" << endl;
		}
			
	}
	return 0;
}

//#include<iostream>
//using namespace std;
//struct Node
//{
//	char data;
//	Node *next;
//};
//void InitNode(Node *&m)
//{
//	m = new Node;
//	m->data = '0';
//	m->next = 0;
//}
//void push(Node *&m, char data)
//{
//	Node *p = new Node;
//	p->data = data;
//	p->next = m->next;
//	m->next = p;
//}
//int pop(Node *&m)
//{
//	if (m->next == 0)
//		return -1;
//	Node *p = m->next;
//	int temp = p->data;
//	m->next = p->next;
//	delete p;
//	return temp;
//}
//
//int main()
//{
//	Node *m;
//	int N, i, k, c1, count[10001];
//	char a[10001], b[10001];
//
//	while (cin >> N)
//	{
//		InitNode(m);
//		c1 = 0;
//		m->data = N;
//		cin >> a >> b;
//		int IC = 0, j = 0;
//		while (IC<m->data)
//		{
//
//			while (1)
//			{
//				push(m, a[IC]);
//				count[c1++] = 1;
//				if (a[IC] == b[j])break;
//				IC++;
//
//			}
//			while (1)
//			{
//				if (m->next == 0)break;
//				if (m->next->data == b[j])
//				{
//					pop(m);
//					count[c1++] = 0;
//					j++;
//				}
//				else
//					break;
//
//			}
//			IC++;
//
//		}
//
//		if (j == m->data)
//		{
//			cout << "Yes." << endl;
//			for (i = 0; i<c1; i++)
//				if (count[i] == 0)
//					cout << "out" << endl;
//				else
//					cout << "in" << endl;
//
//		}
//		else
//			cout << "No." << endl;
//		cout << "FINISH" << endl;
//
//	}
//	return 0;
//}