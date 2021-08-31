# 3 type 

1) new, delete

문제 

점수를 입력 받고, 합계, 평균을 계산하는 프로그램을 작성하시오. 

- 최대 입력 가능한 점수의 개수를 입력 받는다. 

- “add” 명령으로 점수를 입력한다. 

- “sum” 명령으로 합계를 출력한다. 

- “average” 명령으로 평균을 출력한다. 단 입력된 점수가 없는 경우에는 “1개 이상의 점수가 입력되어야 한다”를 출력한다. 

- “quit” 명령으로 프로그램을 종료시킨다. 

제약 조건 

1) new와 delete를 이용해서 점수들을 저장할 메모리를 할당하시오 

2) “add”, “sum”, “average”, “quit”은 대소문자를 구분하지 않는다. 즉 “add”, “Add”, “aDd” 등은 모두 점수를 입력한다. 

3) 점수는 0부터 100사이의 정수이다. 만약 이 범위를 벗어나면 “Score should be between 0 and 100＂를 출력한다. 

4) 지정한 개수 초과의 점수가 입력되면 “Too many scores”를 출력한다. 

```
int main() {
    cout << "Enter the score count: " ;
    int maxSize ;
    cin >> maxSize ;

    int* const scores = new int[maxSize] ;
    …
    delete [] scores ;
}
​
```
실행 예시 
```
Enter the score count : 3 
Enter command : (add, sum, average, quit) add 
Enter score : 70 
70 added 
Enter command : (add, sum, average, quit) Sum 
Sum : 70 
Enter command : (add, sum, average, quit) Add 
Enter score : 15 
15 added 
Enter command : (add, sum, average, quit) SUM 
Sum : 85 
Enter command : (add, sum, average, quit) AVerage 
Average : 42 . 5 
Enter command : (add, sum, average, quit) aDd 
Enter score : 20 
20 added 
Enter command : (add, sum, average, quit) suM 
Sum : 105 
Enter command : (add, sum, average, quit) aDd 
Enter score : 120 
Score should be between 0 and 100 
Enter command : (add, sum, average, quit) avERAGE 
Average : 35 
Enter command : (add, sum, average, quit) ADd 
Too many scores 
Enter command : (add, sum, average, quit) aDD 
Too many scores 
Enter command : (add, sum, average, quit) SUm 
Sum : 105 
Enter command : (add, sum, average, quit) Quit 
Bye
```