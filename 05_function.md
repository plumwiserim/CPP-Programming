# 5 함수 

1) enum,struct 
2) function call 
3) const parameter 
4) Call by reference 
5) const_iterator 

실행 예시
```
ADD 50 50 
ADD 30 30 
PRINT 
Rectangle Count: 2 
50 50 2500 
30 30 900 
SORT 
Rectangle Count: 2 
30 30 900 
50 50 2500 
ADD 10 10 
PRINT 
Rectangle Count: 3 
30 30 900 
50 50 2500 
10 10 100 
SORT 
Rectangle Count: 3 
10 10 100 
30 30 900 
50 50 2500 
CLEAR 
PRINT 
Rectangle Count: 0 
ADD 25 40 
ADD 10 20 
PRINT 
Rectangle Count: 2 
25 40 1000 
10 20 200 
SORT 
Rectangle Count: 2 
10 20 200 
25 40 1000 
EXIT 
```
​
제약 조건 

```
void main() {
    vector rectangles ;
    while ( true ) {
        string commandString;
        cin >> commandString;
        const CommandKind command = getCommandKind(commandString) ;
        switch ( command ) {
            case ADD : {
                const Rectangle& newRectangle = getRectangle() ;
                rectangles.push_back(newRectangle) ;
                break ;
                }
            case PRINT: 
                print(rectangles) ;
                // use const_iterator in print()
                // define and call print(const Rectangle&) break ;
            case SORT: { sort(rectangles) ;
                // define and call swap in sort() print(rectangles) ;
                break ;
                }
            case CLEAR: rectangles.clear() ; break ;
            case EXIT: break ;
            default: assert (false) ; break ;
        }
        if ( command == EXIT ) break ;
    }
}
​
```

제약 조건 

- Use the Rectangle and CommandKind 

```
struct Rectangle {
    int width ;
    int height ;
} ;

enum CommandKind { ADD, SORT, PRINT, CLEAR, EXIT, INVALID} ;
```
