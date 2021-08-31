# 2 type 

1) Built-in types 
2) string 
3) numeric_limits

문제 

다음과 같이 동작하는 프로그램을 작성하시오. 

- char, int, long, float, double의 타입이름을 문자열로서 입력받 아서 각 타입이 표현할 수 있는 최소값과 최대값을 출력한다. 

- 타입이름이 입력되는 동안 반복적으로 수행되며 “quit” 문자 열이 입력되면 반복문은 종료된다. 

- 반복문이 종료되면 각 타입 별로 실제로 입력된 횟수를 출력 한다. 

제약 조건 

1) C++ 언어에서 입/출력 지원을 위한 cin과 cout를 사용하시오 

2) 문자열은 C++의 string을 이용하시오 

3) numeric_limits를 이용하시오 

실행 예시 
```
int 
-2147483648 2147483647 
long 
-2147483648 2147483647 
long 
-2147483648 2147483647 
float 
1.17549 e -038 3 .40282e+038 
double 
2.22507 e -308 1 .79769e+308 
int 
-2147483648 2147483647 
long 
-2147483648 2147483647 
double 
2.22507 e -308 1 .79769e+308 
quit 
=== A List of # of types === 
int : 2 
long : 3 
float : 1 
double : 2 
char : 0
int m
```