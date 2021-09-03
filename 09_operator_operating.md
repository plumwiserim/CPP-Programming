# 9 operator overloading

문제 

Implement class Matrix for main() to run like this.
```
class Matrix {
	int** values ;
	int row, column ;
public:
	…
} ;
```
```
int main() {
	Matrix m1(2, 2), m2(2, 2) ;
	cin >> m1 ;
	cin >> m2 ;

	Matrix m3(m1 + m2);
	Matrix m4(2, 2);

    m4 = m3 * 10 ;

	cout << m3 << endl << m4 << endl ;
}

```
실행 예시 
```
1 2 3 4
5 6 7 8
6        8
10      12
60      80
100     120
```
