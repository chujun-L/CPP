#include <iostream>
#include <string>

using namespace std;

class Person
{
private:
	static const int LIMIT = 25;
	string lname;					// last name
	char fname[LIMIT];				// first name

public:
	Person() { lname = ""; fname[0] = '\0'; }				// 类内初始化数据成员
	Person(const string &ln, const char *fn = "Heyyou");

	void Show() const;
	void FormalShow() const;
};

Person::Person(const string &ln, const char *fn)
{
	lname = ln;
	strncpy_s(fname, fn, LIMIT - 1);
	fname[LIMIT - 1] = '\0';
}

void Person::Show() const
{
	cout << fname << " " << lname << endl;
}

void Person::FormalShow() const
{
	cout << lname << ", " << fname << endl;
}

int main2()
{
	Person one;
	one.Show();
	one.FormalShow();

	Person two("smythecraft");
	two.Show();
	two.FormalShow();

	Person three("dimwiddy", "sam");
	three.Show();
	three.FormalShow();

	system("pause");
	return 0;
}