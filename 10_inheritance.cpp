#include <iostream>
#include <vector>

using namespace std;

enum EmployeeLevel { 사원, 대리, 과장, 차장, 부장 };

class Employee {
	string name;
	const EmployeeLevel level;
public:
	Employee(string _name, const EmployeeLevel _level)
		: name(_name), level(_level) {
	}
	friend ostream& operator << (ostream& os, const Employee& e);
};

ostream& operator << (ostream& os, const Employee& e) {
	os << e.level << '\t' << e.name << endl;
	return os;
}
class Manager : public Employee {
	vector<Employee*> group;
public:
	Manager(string name, const EmployeeLevel level)
		: Employee(name, level) {
		Employee e(name, level);
		group.push_back(&e);
	}
	void addEmployee(Employee* emp) {
		group.push_back(emp);
	}
	friend ostream& operator << (ostream& os, const Manager& m);
};

ostream& operator << (ostream& os, const Manager& m) {
	os << m.group[0] << endl;
	os << "List of employees managed by me" << endl;
	for (vector<Employee*>::const_iterator it = m.group.begin() + 1; it != m.group.end(); ++it) {
		cout << *it << endl;
	}
	return os;
}

int main() {
	Employee e1("홍", 사원), e2("김", 대리), e3("차", 사원);
	cout << e1 << e2 << e3;

	Manager m1("Tom", 차장);
	m1.addEmployee(&e1);
	m1.addEmployee(&e2);
	m1.addEmployee(&e3);
	cout << endl << "Information for Manager" << endl;
	cout << m1;
}