#include <iostream>
using namespace std;
//初始条件:三个输入变量month、day、year（month 、 day 和year均为整数值，并且满足：1≤month≤12，1≤day≤31和1900≤year≤2050）
//操作结果:分别作为输入日期的月份、日、年份，通过程序可以输出该输入日期在日历上隔一天的日期。
bool EixstDate(int year, int month, int day)
{
	
		switch (month)
		{
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			if (day <=0||day>31) 
			return false;
			break;
		case 4:
		case 6:
		case 9:
		case 11:
			if (day <= 0 || day > 30)
			return false;
			break;

		case 2:
			if (day <= 0 || day>29||(day== 29 && !(year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)))
			return false;
			break;
		}
}
void NextDate(int year,int month,int day)
{
	int Year=year, Month=month, Day=day;
	if ((year % 4 == 0 && year % 100 != 0)||(year%400==0))
	{
		switch (month)
		{
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
			if (0<day < 30) Day = day + 2;
			else if(30<=day<=31)
			{
				Day = 2 - (31 - day);
				Month = month + 1;
			}
			/*else
			{

			}*/
			break;
		case 4:
		case 6:
		case 9:
		case 11:
			if (day < 29) Day = day + 2;
			else
			{
				Day = 2 - (30 - day);
				Month = month + 1;
			}
			break;
		case 12:
			if (day < 30) Day = day + 2;
			else
			{
				Day = 2 - (31 - day);
				Month = 1;
				Year = Year + 1;
			}
			break;

		case 2:
			if (day < 27) Day = day + 2;
			else
			{
				Day = 2 - (29 - day);
				Month = month + 1;
			}
		}
	}
	else
	{
		switch (month)
		{
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
			if (day < 30) Day = day + 2;
			else
			{
				Day = 2 - (31 - day);
				Month = month + 1;
			}
			break;
		case 4:
		case 6:
		case 9:
		case 11:
			if (day < 29) Day = day + 2;
			else
			{
				Day = 2 - (30 - day);
				Month = month + 1;
			}
			break;
		case 12:
			if (day < 30) Day = day + 2;
			else
			{
				Day = 2 - (31 - day);
				Month = 1;
				Year = Year + 1;
			}
			break;

		case 2:
			if (day < 26) Day = day + 2;
			else
			{
				Day = 2 - (28 - day);
				Month = month + 1;
			}
		}
	}
	cout<< year << "年" << month << "月" << day << "日隔一天日期为" << Year << "年" << Month << "月" << Day << "日" << endl;
}
/*int main()
{
	double year,month, day;
	int year1, month1, day1;
	cout<<"请输入年" <<endl;

	while (true)
	{
		
		cin >> year;
		year1=year;
		
		if (cin.fail())
		{
			cin.clear();
			cin.sync();
			cout << "格式错误请输入整数年份:" << endl;
			while (cin.get() != '\n')
			{
			 continue;
			}
			continue;
		}
		if (year1 != year)
		{
			//cin.sync();
			cout << "年份不能为小数,应该属于[1900,2500]的整数，请重新输入：" << endl;
			continue;
		}
		if (year < 1900)
		{
			//cin.sync();
			cout << "年份不能<1900,应该属于[1900,2500]，请重新输入：" << endl;
			continue;
		}
		if(year>2500)
		{
			//cin.sync();
			cout << "年份不能>2050,应该属于[1900,2500]，请重新输入：" << endl;
			continue;
		}
		
		break;
	}
	cout << "请输入月:" << endl;
	while (true)
	{

		cin >> month;
		month1 = month;
		if (cin.fail())
		{
			cin.clear();
			cin.sync();
			cout << "格式错误，请输入整数月份:" << endl;
			while (cin.get() != '\n')
			{
				continue;
			}
			continue;
		}
		if (month1 != month)
		{
			cout << "月份不能为小数,请重新输入月份：" << endl;
			continue;
		}
		if (month <= 0)
		{
			cout << "月份不能<1,请重新输入月份：" << endl;
			continue;
		}
		if(month>12)
		{
			cout << "月份不能>12，请重新输入月份：" << endl;
			continue;
		}

		break;
	}


	cout << "请输入日:" << endl;
	while (true)
	{

		cin >> day;
		day1 = day;
		if (cin.fail())
		{
			cin.clear();
			cin.sync();
			cout << "格式错误，请输入整数日份:" << endl;
			while (cin.get() != '\n')
			{
				continue;
			}
			continue;
		}
		if (day1 != day)
		{
			cout << "日份不能为小数，请输入整数日份:" << endl;
			continue;
		}
		if(!EixstDate(year1, month1, day1) )
		{
			cout << "日份输入错误，请输入符合要求的日份:" << endl;
			continue;
		}

		break;
	}
	NextDate(year1, month1, day1);
	system("pause");

}*/


