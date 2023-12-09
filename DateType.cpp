#include <iostream>
#include <string>
using namespace std;

class dateType
{
private:
	int d;
	int m;
	int y;
	string month;
public:
	dateType(int = 1, int = 1, int = 2000);
	dateType(dateType&);
	void setDay(int);
	void setMonth(int);
	void setYear(int);
	void setdate(int, int, int);
	void printdate();
	void setM();
	void incday();
	void incmonth();
	void incyear();
	void incbyday(int);
	void equal(dateType&);
	bool leap();

	int getDay();
	int getMonth();
	int getYear();

};

dateType::dateType(int day, int mon, int year)
{
	d = day; m = mon; y = year;
	setM();
}
dateType::dateType(dateType& c)
{
	d = c.d;  m = c.m;  y = c.y;
	month = c.month;
}
int dateType::getDay()
{
	return d;
}
int dateType::getMonth()
{
	return m;
}
int dateType::getYear()
{
	return y;
}
bool dateType::leap()
{
	if (y % 4 == 0 && y % 100 != 0 || y % 400 == 0)
		return true;
	else
		return false;
}
void dateType::equal(dateType& c)
{
	if (d == c.d && m == c.m && y == c.y)
	{
		cout << " The dates are equal" << endl;
	}
	else
		cout << " The dates are not equal" << endl;
}
void dateType::incbyday(int day)
{
	d = d + day;

	if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12)
	{
		if (d > 31)
		{
			d = d - 31;

			if (m == 12)
			{
				m = 1;
				y++;
				setM();
			}
			else
			{
				m++;
				setM();
			}
		}
	}
	else if (m == 4 || m == 6 || m == 9 || m == 11)
	{
		if (d > 30)
		{
			d = d - 30;

			if (m == 12)
			{
				m = 1;
				y++;
				setM();
			}
			else
			{
				m++;
				setM();
			}
		}
	}
	else if (m == 2)
	{
		if (leap())
		{
			if (d > 29)
			{
				d = d - 29;

				if (m == 12)
				{
					m = 1;
					y++;
					setM();
				}
				else
				{
					m++;
					setM();
				}
			}
		}
		else
		{
			if (d > 28)
			{
				d = d - 28;

				if (m == 12)
				{
					m = 1;
					y++;
					setM();
				}
				else
				{
					m++;
					setM();
				}
			}
		}
	}
}
void dateType::incyear()
{
	y++;
}
void dateType::incmonth()
{
	if (m == 12)
	{
		m = 1;
		y++;
		setM();
	}
	else
	{
		m++;
		setM();
	}
}
void dateType::setDay(int day)
{
	d = day;
}
void dateType::setMonth(int mon)
{
	m = mon;
	setM();
}
void dateType::setYear(int year)
{
	y = year;
}
void dateType::setdate(int day, int mon, int year)
{
	d = day; m = mon; y = year;
	setM();
}
void dateType::printdate()
{
	cout << "\n ---------------------------- " << endl;
	cout << " The date is: (DD-MM-YYYY)  " << d << " - " << m << " - " << y << endl;
	cout << " The month is: " << month << endl;
}
void dateType::setM()
{
	switch (m)
	{
	case 1:
		month = "January";
		break;
	case 2:
		month = "February";
		break;
	case 3:
		month = "March";
		break;
	case 4:
		month = "April";
		break;
	case 5:
		month = "May";
		break;
	case 6:
		month = "June";
		break;
	case 7:
		month = "July";
		break;
	case 8:
		month = "August";
		break;
	case 9:
		month = "September";
		break;
	case 10:
		month = "October";
		break;
	case 11:
		month = "November";
		break;
	case 12:
		month = "December";
		break;
	default:
		break;
	}
}
void dateType::incday()
{
	if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12)
	{
		if (d == 31)
		{
			d = 1;

			if (m == 12)
			{
				m = 1;
				y++;
				setM();
			}
			else
			{
				m++;
				setM();
			}
		}
		else
			d++;
	}
	else if (m == 4 || m == 6 || m == 9 || m == 11)
	{
		if (d == 30)
		{
			d = 1;

			if (m == 12)
			{
				m = 1;
				y++;
				setM();
			}
			else
			{
				m++;
				setM();
			}
		}
		else
			d++;
	}
	else if (m == 2)
	{
		if (leap())
		{
			if (d == 29)
			{
				d = 1;

				if (m == 12)
				{
					m = 1;
					y++;
					setM();
				}
				else
				{
					m++;
					setM();
				}
			}
			else
				d++;
		}
		else
		{
			if (d == 28)
			{
				d = 1;

				if (m == 12)
				{
					m = 1;
					y++;
					setM();
				}
				else
				{
					m++;
					setM();
				}
			}
			else
				d++;
		}
	}
}

void main()
{
	dateType D;
	dateType C;

	int d, y, m;
	cout << "Enter date" << endl;
	cin >> d >> m >> y;
	cout << endl;
	D.setdate(d, m, y);
	D.printdate();
	cout << endl;
	cout << "********************" << endl;
	d = 31;
	m = 9;
	y = 1995;

	cout << "Set date:" << d << "-" << m << "-" << y << endl;
	D.setdate(d, m, y);
	cout << endl;
	D.printdate();
	cout << endl;
	cout << "********************" << endl;

	d = 28, m = 2, y = 2016;
	cout << "Set date:" << d << "-" << m << "-" << y << endl;
	D.setdate(28, 2, 2016);
	D.printdate();
	cout << endl;
	cout << "********************" << endl;

	cout << "AFTER INCREMENTING BY 1 DAY" << endl;
	D.incday();
	D.printdate();
	cout << endl;
	cout << "********************" << endl;

	cout << "If " << endl;
	D.setdate(30, 11, 2007);
	D.printdate();
	cout << endl;
	cout << "AFTER INCREMENTING BY 1 MONTH" << endl;
	D.incmonth();
	D.printdate();
	cout << endl;
	cout << "********************" << endl;

	cout << "AFTER INCREMENTING BY 1 YEAR" << endl;
	D.incyear();
	D.printdate();
	cout << endl;
	cout << "********************" << endl;

	C.setdate(12, 3, 1999);
	cout << "New object created! " << endl;
	cout << "DATE1:" << endl;
	C.printdate();
	cout << "DATE2:" << endl;
	D.printdate();
	cout << endl;
	D.equal(C);
	cout << "********************************" << endl;

	cout << "If ";
	D.printdate();
	cout << endl;
	cout << "Date after 9 days will be" << endl;
	D.incbyday(9);
	D.printdate();
}