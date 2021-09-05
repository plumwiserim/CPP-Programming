# 10 inheritance


문제 

Implement classes to run main()
```
enum EmployeeLevel { 사원, 대리, 과장, 차장, 부장} ;
class Employee {
	string name ;
	const EmployeeLevel level ;
public:
	…
} ;
```
```
class Manager : public Employee {
  vector<Employee*> group ;
public:
  …
} ;
```
```
int main() {
	Employee e1("홍", 사원), e2("김", 대리), e3("차", 사원) ;
	cout << e1 << e2 << e3 ;

	Manager m1("Tom", 차장) ;
	m1.addEmployee(&e1) ;
	m1.addEmployee(&e2) ;
	m1.addEmployee(&e3) ;
	cout << endl << "Information for Manager" << endl ;
	cout << m1 ;
}
​
```
실행 예시 
```
0       홍
1       김
0       차
Information for Manager
3       Tom
List of employees managed by me
0       홍
1       김
0       차
```