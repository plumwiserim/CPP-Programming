# 6 class 정의 

실습 문제 
```
int main() {
    School pnu("PNU") ;

    pnu.addStudent("Kim", 2.7F) ;
    pnu.addStudent("Hong", 3.5F) ;
    pnu.addStudent("Lee") ;
    pnu.addStudent("Joo", 1.5F) ;

    pnu.print() ;

    pnu.sort() ; // descending
    pnu.print() ;

    School knu("KNU") ;
    knu.addStudent("Seo", 2.5F) ;
    knu.addStudent("Lee", 3.8F) ;
    knu.print() ;

    Student& lee = pnu.findStudentWithName("Lee") ;
    lee.setGPA(3.3F) ;
    lee.setName("Yoon") ;

    pnu.print() ;

    knu.addStudent("Hong", 4.3F) ;
    Student& hong = knu.findStudentWithName("Hong") ;
    hong.setGPA(3.3F) ;
    hong.setName("Joon") ;
    knu.print() ;
}
​
```

실행 예시 
```
School Name: PNU, Count: 4 
Name: Kim GPA: 2.7 
Name: Hong GPA: 3.5 
Name: Lee GPA: 0 
Name: Joo GPA: 1.5 
​
School Name: PNU, Count: 4 
Name: Hong GPA: 3.5 
Name: Kim GPA: 2.7 
Name: Joo GPA: 1.5 
Name: Lee GPA: 0 
​
School Name: KNU, Count: 2 
Name: Seo GPA: 2.5 
Name: Lee GPA: 3.8 
​
School Name: PNU, Count: 4 
Name: Hong GPA: 3.5 
Name: Kim GPA: 2.7 
Name: Joo GPA: 1.5 
Name: Yoon GPA: 3.3 
​
School Name: KNU, Count: 3 
Name: Seo GPA: 2.5 
Name: Lee GPA: 3.8 
Name: Joon GPA: 3.3 
```
​
제약 조건 

- Define class Student and School ! 

- No non-member(i.e., global functions) 
```
class Student {
private:
    string name ;
    float gpa ;

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