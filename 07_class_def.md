# 7 class 정의 

Member initialization list Constructor overloading 

실습 문제 

```
int main() { 
School pnu("PNU") ; 
Student* kim = pnu.addStudent("Kim", EE) ; 
kim->setGPA(3.5F) ; 
Student* hong = pnu.addStudent("Hong", CE) ; 
hong->setGPA(4.3F) ; 
Student* lee = pnu.addStudent("Lee", 4.0F) ; 
lee->setMajor(CE) ; 
Student* joo = pnu.addStudent("Joo", 1.5F) ; 
joo->setMajor(ME) ; 
pnu.print() ; 
pnu.sort() ; 
// descending pnu.print() ; 
} 
​
```

실행 예시 
```
School Name: PNU, Count: 4 
Name: Kim GPA: 3.5 Major: Electrical Eng. 
Name: Hong GPA: 4.3 Major: Computer Eng. 
Name: Lee GPA: 4 Major: Computer Eng. 
Name: Joo GPA: 1.5 Major: Mechanical Eng. 
```
​
```
School Name: PNU, Count: 4 
Name: Hong GPA: 4.3 Major: Computer Eng. 
Name: Lee GPA: 4 Major: Computer Eng. 
Name: Kim GPA: 3.5 Major: Electrical Eng. 
Name: Joo GPA: 1.5 Major: Mechanical Eng. 

```

제약 조건 

```
class Student { 
private: 
string name ; 
float gpa ; 
Major major ; 
public: 
… 
} ; 
```
```
class School { 
private: 
string schoolName ; 
vector students ; 

public: 
… 
} ; 
```
```
enum MajorType { CE, EE, ME, UD}; 
class Major { 
private: 
MajorType majorType ; 

public:
```