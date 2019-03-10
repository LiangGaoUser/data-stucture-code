//#include<iostream>
//using namespace std;
//int &min(int &, int &);
//int main()
//{
//	int a = 3, b = 7, c = 12, d = 9;
//	cout << "a=" << a << "b=" << b << "min=" << min(a, b) << endl;
//	min(a, b)++;
//	cout << "a=" << a << "b=" << b << "min=" << min(a, b) << endl;
//	system("pause");
//}
//int &min(int &a, int &b)
//{
//	if (a < b)
//	{
//		return a;
//	}
//	else
//		return b;
//}

/*int main()
{
	double year, month, day;
	int year1, month1, day1;
	cout << "请输入年" << endl;
	cin >> year;
	year1 = year;
	while (cin.fail() || year<1900 || year>2050 || year1 != year)
	{
		if (cin.fail())
		{
			cin.clear();
			cin.sync();
			cout << "格式错误请输入整数年份:" << endl;
		}
		else
		{
			if (year1 != year)
			{
				cout << "年份不能为小数,应该属于[1900,2500]的整数，请重新输入：" << endl;
			}
			else
			{
				if (year < 1900)
				{
					cout << "年份不能<1900,应该属于[1900,2500]，请重新输入：" << endl;
				}
				else
				{
					cout << "年份不能>2050,应该属于[1900,2500]，请重新输入：" << endl;
				}
			}


		}
		while (cin.get() != '\n') {
			continue;
		}
		cin >> year;
		year1 = year;
	}
	cout << "请输入月" << endl;
	cin >> month;
	month1 = month;
	while (cin.fail() || month <= 0 || month>12 || month1 != month)
	{
		if (cin.fail())
		{
			cin.clear();
			cin.sync();
			cout << "格式错误，请输入整数月份:" << endl;

		}
		else
		{
			if (month1 != month)
			{
				cout << "月份不能为小数,请重新输入月份：" << endl;
			}
			else
			{
				if (month <= 0)
				{
					cout << "月份不能<1,请重新输入月份：" << endl;
				}
				else
				{
					cout << "月份不能>12，请重新输入月份：" << endl;
				}
			}

		}
		while (cin.get() != '\n') {
			continue;
		}
		cin >> month;
		month1 = month;
	}
	cout << "请输入日" << endl;
	cin >> day;
	day1 = day;
	while (cin.fail() || !EixstDate(year1, month1, day1) || day1 != day)
	{
		if (cin.fail())
		{
			cin.clear();
			cin.sync();
			cout << "格式错误请输入整数日份:" << endl;
		}
		else
		{
			cout << "日份输入错误，请输入符合要求的日份:" << endl;
		}
		while (cin.get() != '\n') {
			continue;
		}
		cin >> day;
		day1 = day;
	}
	NextDate(year1, month1, day1);
	system("pause");

}*/
