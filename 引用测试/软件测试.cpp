#include <iostream>
using namespace std;
//��ʼ����:�����������month��day��year��month �� day ��year��Ϊ����ֵ���������㣺1��month��12��1��day��31��1900��year��2050��
//�������:�ֱ���Ϊ�������ڵ��·ݡ��ա���ݣ�ͨ�����������������������������ϸ�һ������ڡ�
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
	cout<< year << "��" << month << "��" << day << "�ո�һ������Ϊ" << Year << "��" << Month << "��" << Day << "��" << endl;
}
/*int main()
{
	double year,month, day;
	int year1, month1, day1;
	cout<<"��������" <<endl;

	while (true)
	{
		
		cin >> year;
		year1=year;
		
		if (cin.fail())
		{
			cin.clear();
			cin.sync();
			cout << "��ʽ�����������������:" << endl;
			while (cin.get() != '\n')
			{
			 continue;
			}
			continue;
		}
		if (year1 != year)
		{
			//cin.sync();
			cout << "��ݲ���ΪС��,Ӧ������[1900,2500]�����������������룺" << endl;
			continue;
		}
		if (year < 1900)
		{
			//cin.sync();
			cout << "��ݲ���<1900,Ӧ������[1900,2500]�����������룺" << endl;
			continue;
		}
		if(year>2500)
		{
			//cin.sync();
			cout << "��ݲ���>2050,Ӧ������[1900,2500]�����������룺" << endl;
			continue;
		}
		
		break;
	}
	cout << "��������:" << endl;
	while (true)
	{

		cin >> month;
		month1 = month;
		if (cin.fail())
		{
			cin.clear();
			cin.sync();
			cout << "��ʽ���������������·�:" << endl;
			while (cin.get() != '\n')
			{
				continue;
			}
			continue;
		}
		if (month1 != month)
		{
			cout << "�·ݲ���ΪС��,�����������·ݣ�" << endl;
			continue;
		}
		if (month <= 0)
		{
			cout << "�·ݲ���<1,�����������·ݣ�" << endl;
			continue;
		}
		if(month>12)
		{
			cout << "�·ݲ���>12�������������·ݣ�" << endl;
			continue;
		}

		break;
	}


	cout << "��������:" << endl;
	while (true)
	{

		cin >> day;
		day1 = day;
		if (cin.fail())
		{
			cin.clear();
			cin.sync();
			cout << "��ʽ���������������շ�:" << endl;
			while (cin.get() != '\n')
			{
				continue;
			}
			continue;
		}
		if (day1 != day)
		{
			cout << "�շݲ���ΪС���������������շ�:" << endl;
			continue;
		}
		if(!EixstDate(year1, month1, day1) )
		{
			cout << "�շ�����������������Ҫ����շ�:" << endl;
			continue;
		}

		break;
	}
	NextDate(year1, month1, day1);
	system("pause");

}*/


