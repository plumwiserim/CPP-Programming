문제

Implement template class List using templates

int main() {
  List<Complex, 100> cList ;
  List<MyString, 200> sList ;

  cList.add(Complex(0, 0)) ;
  cList.add(Complex(1, 1)) ;

  sList.add(“abc”) ;
  sList.add(“def”) ;

  cList.find(Complex(1, 0)) ;
  sList.find(“def”) ;
  cList.remove(Complex(0, 0)) ;
  sList.remove(“abc”) ;

  List<MyString, 200> s2List(sList) ;
  List<MyString, 200> s3List ;
  s3List.add(“123”) ;
  s3List = s2List ;
  s3List.remove(“def”) ;
}
class Complex {
private:
	float real, imaginary;

public:
	…
};
class MyString {
private:
	char* str;

public:
	…
};
실행 예시

﻿
0,0 is added
1,1 is added
abc is added
def is added
1,0 is not found
def is found
0,0 is removed
abc is removed
123 is added
def is removed