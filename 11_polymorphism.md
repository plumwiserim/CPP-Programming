문제

Implement classes to run main()
```
int main() {
	Point p1(0, 0), p2(0, 10), p3(20, 20), p4(20, 30) ;

	Shape* const r = new Rectangle(p1, p2, p3, p4) ;
	Shape* const t = new Triangle(p1, p2, p3) ;

	ShapeList list{} ;
	list.addShape(r) ;
	list.addShape(t) ;
	delete r;
	delete t;

	list.print() ;
	cout << list.getTotalArea() << endl ;
}
​
```
실행 예시
```
Rectangle: (0, 0)(0, 10)(20, 20)(20, 30)
Triangle: (0, 0)(0, 10)(20, 20)
XXXX
```

제약 조건
```
enum Color {RED, BLUE, YELLOW} ;

class Shape {
	Color lineColor ;
public:
	Color getLineColor() const { return lineColor ; }
	virtual Shape* clone() const = 0 ;
	virtual void print() const = 0 ;
	virtual float getLength() const = 0 ;
} ;
```
