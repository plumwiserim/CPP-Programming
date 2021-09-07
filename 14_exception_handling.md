문제

Try to improve CharStack by providing class StackException.
```
class CharStack {
	int size ;
	int top ;
	char* s ;
  public:
		CharStack(int sz) { top = 0 ; s = new char[size=sz]; }
		// destructor, copy constructor, and assignment operator
		void push(char c) { s[top++] = c ; }
		char pop() { char r = s[--top]; s[top] = '\0' ; return r ; }
		void print() const {
			for ( int i = 0 ; i < top ; i ++ ) cout << s[i]  ;
			cout << endl ;
		}
} ;
```
```
class StackException {
	const string msg ;
	public:
		StackException(const string& msg) ;
		void print() const { cout << msg << endl ; }
} ;
```

실행 결과
```
a

abcde
overflow
```
