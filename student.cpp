#include <iostream>
using namespace std;

class student
{
private:
	char* name;
	int rollNo;
	double* marks;
	double percentage;
public:
	student(char* n, int rn, double* marks);
	void calPercentage(int , double* );
	void Grade(int, double*);
};
student::student(char* n, int rn, double* m)
{
	name = n;
	rollNo = rn;
	marks = m;
	percentage = 0.0;
}
void student::calPercentage(int size, double* Tm)
{
	double OM = 0, TM = 0;
	for (int i = 0; i < size; i++)
	{
		OM = OM + marks[i];
		TM = TM + Tm[i];
	}
	percentage = (OM / TM) * 100;
}
void student::Grade(int size, double* Tm)
{
	calPercentage(size, Tm);
	
	cout << "\n\n Name: " << name << endl;
	cout << " Roll No: " << rollNo << endl;
	cout << " Percentage: " << percentage << endl;

	if (percentage >= 0 && percentage <= 49)
		cout << " Grade: F" << endl;
	else if (percentage >= 50 && percentage <= 55)
		cout << " Grade: D" << endl;
	else if (percentage > 55 && percentage <= 60)
		cout << " Grade: D+" << endl;
	else if (percentage > 60 && percentage <= 65)
		cout << " Grade: C" << endl;
	else if (percentage >65 && percentage <= 70)
		cout << " Grade: C+" << endl;
	else if (percentage > 70 && percentage <= 75)
		cout << " Grade: B-" << endl;
	else if (percentage > 75 && percentage <= 80)
		cout << " Grade: B" << endl;
	else if (percentage > 80 && percentage <= 85)
		cout << " Grade: B+" << endl;
	else if (percentage > 85 && percentage <= 90)
		cout << " Grade: A" << endl;
	else if (percentage > 90 && percentage <= 100)
		cout << " Grade: A+" << endl;
}
int main()
{
	char n[25];
	double* marks, *tmarks;
	int size, rollNo;

	cout << " Enter name: ";
	cin.get(n, 25);
	cout << " Enter roll no: ";
	cin >> rollNo;

	cout << " Enter the number of marks you want to enter: ";
	cin >> size;
	marks = new double[size];
	tmarks = new double[size];

	for (int i = 0; i < size; i++)
	{
		cout << "\n Test " << i + 1 << " : " << endl;
		cout << " Enter obtained marks: ";
		cin >> marks[i];
		cout << " Enter total marks: ";
		cin >> tmarks[i];
	}

	student s(n, rollNo, marks);

	s.Grade(size, tmarks);

	delete[] marks;
	delete[] tmarks;

	return 0;
}