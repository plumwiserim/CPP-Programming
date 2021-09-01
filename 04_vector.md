# 4 type, control structure, function 

1) struct
2) vector, iterator ​

문제 

실행 예 1) 

```
2 
Kim 50 60 70 
Park 100 70 80 

1 Kim 50 60 70 180 60 
2 Park 100 70 80 250 83.3333 
Total 150 130 150 430 
```
​
실행 예 2) 

```
3 
Kim 100 100 90 
Park 100 90 90 
Lee 100 100 100 

1 Kim 100 100 90 290 96.6667 
2 Park 100 90 90 280 93.3333 
3 Lee 100 100 100 300 100 
Total 300 290 280 870 
```

제약사항 

- Use StudentInfo 
```
const int SUBJECT_NO = 3 ;

struct StudentInfo {
    string name ;
    int scores[SUBJECT_NO] ;
    int sum ;
    float average ;
} ;
```
- Use vector 
- Define a function that print a StudentInfo 
- Define a function that print vector 
- Use iterator 
