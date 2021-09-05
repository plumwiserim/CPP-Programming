#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

enum Color { RED, BLUE, YELLOW };

class Shape {
	Color lineColor;
public:
	Color getLineColor() const { return lineColor; }
	virtual Shape* clone() const = 0;
	virtual void print() const = 0;
	virtual float getLength() const = 0;
};

class Point {
	int x, y;
public:
	Point(int _x, int _y) {
		x = _x; y = _y;
	}
	friend class Rectangle;
	friend class Triangle;
};

class Rectangle : public Shape {
	int x1, y1, x2, y2, x3, y3, x4, y4;
public:
	Rectangle(Point p1, Point p2, Point p3, Point p4) {
		x1 = p1.x; y1 = p1.y;
		x2 = p2.x; y2 = p2.y;
		x3 = p3.x; y3 = p3.y;
		x4 = p4.x; y4 = p4.y;
	}
	virtual Shape* clone() const {
		return new Rectangle(*this);
	}
	virtual void print() const {
		cout << "Rectangle: " << "(" << x1 << ", " << y1 << ")(" << x2 << ", " << y2 << ")(" << x3 << ", " << y3 << ")(" << x4 << ", " << y4 << ")" << endl;
	}
	virtual float getLength() const {
		float a1 = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
		float b1 = sqrt(pow(x2 - x3, 2) + pow(y2 - y3, 2));
		float c1 = sqrt(pow(x3 - x1, 2) + pow(y3 - y1, 2));

		float a2 = sqrt(pow(x2 - x3, 2) + pow(y2 - y3, 2));
		float b2 = sqrt(pow(x3 - x4, 2) + pow(y3 - y4, 2));
		float c2 = sqrt(pow(x4 - x2, 2) + pow(y4 - y2, 2));

		float s1 = (a1 + b1 + c1) / 2;
		float S1 = sqrt(s1 * (s1 - a1) * (s1 - b1) * (s1 - c1));

		float s2 = (a2 + b2 + c2) / 2;
		float S2 = sqrt(s2 * (s2 - a2) * (s2 - b2) * (s2 - c2));

		float S = S1 + S2;

		return S;
	}
	friend class ShapeList;
};

class Triangle : public Shape {
	int x1, y1, x2, y2, x3, y3;
public:
	Triangle(Point p1, Point p2, Point p3) {
		x1 = p1.x; y1 = p1.y;
		x2 = p2.x; y2 = p2.y;
		x3 = p3.x; y3 = p3.y;
	}
	virtual Shape* clone() const {
		return new Triangle(*this);
	}
	virtual void print() const {
		cout << "Triangle: " << "(" << x1 << ", " << y1 << ")(" << x2 << ", " << y2 << ")(" << x3 << ", " << y3 << ")" << endl;
	}
	virtual float getLength() const {
		float a1 = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
		float b1 = sqrt(pow(x2 - x3, 2) + pow(y2 - y3, 2));
		float c1 = sqrt(pow(x3 - x1, 2) + pow(y3 - y1, 2));

		float s = (a1 + b1 + c1) / 2;

		float S = sqrt(s * (s - a1) * (s - b1) * (s - c1));

		return S;
	}
	friend class ShapeList;
};

class ShapeList {
	vector<Shape*> shapelist;
public:
	ShapeList() {
	}
	void addShape(Shape* const pShape) {
		shapelist.push_back(pShape->clone());
	}
	void print() {
		for (int i = 0; i < shapelist.size(); i++) {
			shapelist.at(i)->print();
		}
	}
	float getTotalArea() {
		float area = 0;

		for (int i = 0; i < shapelist.size(); i++) {
			area += shapelist.at(i)->getLength();
		}
		return area;
	}
};

int main() {
	Point p1(0, 0), p2(0, 10), p3(20, 20), p4(20, 30);

	Shape* const r = new Rectangle(p1, p2, p3, p4);
	Shape* const t = new Triangle(p1, p2, p3);

	ShapeList list{};
	list.addShape(r);
	list.addShape(t);
	delete r;
	delete t;

	list.print();
	cout << list.getTotalArea() << endl;
}