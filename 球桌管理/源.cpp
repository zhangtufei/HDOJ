#include <iostream>
#include <string>
#include <map>
using namespace std;
map<int, int> m;
void shenqing()
{
	cout << "请输入您想申请的球桌编号,格式如（2,3）：" << endl;
	char c;
	int a, b;
	cin >> c >> a >> c >> b >> c;
	if (a > b)
	{
		int temp = a;
		a = b;
		b = a;
	}
	for (int i = a; i <= b; ++i)
	{
		if (m[i])
		{
			cout << i << "号球台已经被占用了，请重新输入" << endl;
			return;
		}
	}
	for (int i = a; i <= b; ++i)
		++m[i];
	cout << "申请成功，祝您玩的愉快" << endl;
}
void tui()
{
	cout << "请输入您要退还的球桌编号,格式如（2,3）：" << endl;
	char c;
	int a, b;
	cin >> c >> a >> c >> b >> c;
	if (a > b)
	{
		int temp = a;
		a = b;
		b = a;
	}
	for (int i = a; i <= b; ++i)
	{
		if (!m[i])
		{
			cout << i << "号球台没有被占用，请重新输入" << endl;
			return;
		}
	}
	for (int i = a; i <= b; ++i)
		--m[i];
	cout << "退还成功，欢迎再次光临" << endl;
}
int main()
{
	for (int i = 1; i <= 100; ++i)
		m[i] = 0;
	while (1)
	{
		cout << "申请请按1，下机请按2,退出程序请按3！" << endl;
		int cmd;
		cin >> cmd;
		switch (cmd)
		{
		case 1:	shenqing(); break;
		case 2:	tui(); break;
		case 3: return 0; break;
		default:cout << "指令错误，重新输入" << endl; break;
		}
	}
}

//void fun1()
//{
//	cout << "请输入你想申请的球桌号码范围（格式如1 10）：";
//	int beg, ed;
//	cin >> beg >> ed;
//	if (beg > ed)
//	{
//		int temp = ed;
//		ed = beg;
//		beg = temp;
//	}
//	bool flag = true;
//	int t;
//	for (int i = beg; i <= ed; ++i)
//	{
//		if (a[i] == 1)
//		{
//			flag = false;
//			t = i;
//			break;
//		}
//	}
//	if (flag)
//	{
//		for (int i = beg; i <= ed; ++i)
//		{
//			a[i] = 1;
//		}
//		cout << "申请成功！" << endl;
//	}
//	else
//	{
//		cout << t << "号球桌已经被占用！" << endl;
//	}
//}
//void fun2()
//{
//	cout << "请输入你想退订的球桌号码范围（格式如1 10）：";
//	int beg, ed;
//	cin >> beg >> ed;
//	if (beg > ed)
//	{
//		int temp = ed;
//		ed = beg;
//		beg = temp;
//	}
//	bool flag = true;
//	int t;
//	for (int i = beg; i <= ed; ++i)
//	{
//		if (a[i] == 0)
//		{
//			flag = false;
//			t = i;
//			break;
//		}
//	}
//	if (flag)
//	{
//		for (int i = beg; i <= ed; ++i)
//		{
//			a[i] = 0;
//		}
//		cout << "退订成功！" << endl;
//	}
//	else
//	{
//		cout << t << "号球桌没有还没有被订哦亲！" << endl;
//	}
//}
//int main()
//{
//	memset(a, 0, sizeof(a));
//	while (1)
//	{
//		cout << "输入1：申请球桌" << endl;
//		cout << "输入2：退订球桌" << endl;
//		int t;
//		cin >> t;
//		if (t == 1)
//			fun1();
//		else if (t == 2)
//			fun2();
//		else
//			cout << "错误的输入！" << endl;
//	}
//}