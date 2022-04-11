#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Student
{
  private:
	int StudentNumber;

  public:
	Student(int n)
	{
		this->StudentNumber = n;
	}
	int getStudentNumber()
	{
		return this->StudentNumber;
	}
};

class comparator
{
  public:
	bool operator()(Student &lhs, Student &rhs)
	{
		return lhs.getStudentNumber() > rhs.getStudentNumber();
	}
};

int main()
{
	vector<Student> v;
	for (int i = 10; i >= 0; --i)
	{
		v.push_back(Student(i));
	}

	cout << "Before Sorting: \n";
	for (unsigned int i = 0; i < v.size(); ++i)
	{
		cout << v[i].getStudentNumber() << " ";
	}
	cout << endl;
	cout << "After Sorting: \n";

	sort(v.begin(), v.end(), comparator());

	for (unsigned int i = 0; i < v.size(); ++i)
	{
		cout << v[i].getStudentNumber() << " ";
	}
}
