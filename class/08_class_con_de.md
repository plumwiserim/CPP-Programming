# 8 class constructor & destructor

문제

Implement class MyString so that the following program runs
```
int main() {
	MyString strs[] = {
		MyString("C"),
		MyString(),
		MyString("Java")
	} ;
	strs[1].set("C++") ;

	const MyString target("Java") ;
	for ( int i = 0 ; i < 3 ; i ++ ) {
		const MyString str(strs[i]) ;
		if ( str.isEqual(target) ) {
			cout << "[" << i << "]: " ;
			str.print() ;
			break ;
		}
	}
	for ( int i = 0 ; i < 3 ; i ++ ) {
		const MyString& str = strs[i] ;
		str.print() ;
	}
}
​
```
실행 예시 
```
[2]: Java
C
C++
Java
```
​

제약 조건

- Implement class MyString !

- Implement all the member functions necessary for MyString

- Do not make any changes to the given code. Just add member functions, not modifying the data members.
```
class MyString {
	char* str ;
	int size ;
public:
	…
} ;
```
