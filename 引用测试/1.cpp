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
	cout << "��������" << endl;
	cin >> year;
	year1 = year;
	while (cin.fail() || year<1900 || year>2050 || year1 != year)
	{
		if (cin.fail())
		{
			cin.clear();
			cin.sync();
			cout << "��ʽ�����������������:" << endl;
		}
		else
		{
			if (year1 != year)
			{
				cout << "��ݲ���ΪС��,Ӧ������[1900,2500]�����������������룺" << endl;
			}
			else
			{
				if (year < 1900)
				{
					cout << "��ݲ���<1900,Ӧ������[1900,2500]�����������룺" << endl;
				}
				else
				{
					cout << "��ݲ���>2050,Ӧ������[1900,2500]�����������룺" << endl;
				}
			}


		}
		while (cin.get() != '\n') {
			continue;
		}
		cin >> year;
		year1 = year;
	}
	cout << "��������" << endl;
	cin >> month;
	month1 = month;
	while (cin.fail() || month <= 0 || month>12 || month1 != month)
	{
		if (cin.fail())
		{
			cin.clear();
			cin.sync();
			cout << "��ʽ���������������·�:" << endl;

		}
		else
		{
			if (month1 != month)
			{
				cout << "�·ݲ���ΪС��,�����������·ݣ�" << endl;
			}
			else
			{
				if (month <= 0)
				{
					cout << "�·ݲ���<1,�����������·ݣ�" << endl;
				}
				else
				{
					cout << "�·ݲ���>12�������������·ݣ�" << endl;
				}
			}

		}
		while (cin.get() != '\n') {
			continue;
		}
		cin >> month;
		month1 = month;
	}
	cout << "��������" << endl;
	cin >> day;
	day1 = day;
	while (cin.fail() || !EixstDate(year1, month1, day1) || day1 != day)
	{
		if (cin.fail())
		{
			cin.clear();
			cin.sync();
			cout << "��ʽ���������������շ�:" << endl;
		}
		else
		{
			cout << "�շ�����������������Ҫ����շ�:" << endl;
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
