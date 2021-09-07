#include <iostream>
#include <exception>

using namespace std;

//Try to improve CharStack by providing class StackException.

class StackException {
	const string msg;
public:
	StackException(const string& _msg) : msg(_msg) {};
	void print() const { cout << msg << endl; }
};

class CharStack {
	int size;
	int top;
	char* s;
public:
	CharStack(int sz) {
		if (sz < 0) throw StackException("Enter positive real number or zero.");
		top = 0; s = new char[size = sz];
	}
	// destructor, copy constructor, and assignment operator
	void push(char c) {
		if (top == size) throw StackException("overflow");
		s[top++] = c;
	}
	char pop() {
		if (top == 0) throw StackException("underflow");
		char r = s[--top]; s[top] = '\0'; return r;
	}
	void print() const {
		for (int i = 0; i < top; i++) cout << s[i];
		cout << endl;
	}
};

int main() {
	try {
		//CharStack c(-1);
		CharStack c(5);
		c.push('a'); c.print();
		c.pop(); c.print();
		//c.pop();
		c.push('a'); c.push('b'); c.push('c'); c.push('d'); c.push('e'); c.print();
		c.push('f');
	}
	catch (const StackException& e) { e.print(); }
	catch (bad_alloc) { cerr << "bad_alloc after allocating" << endl; }
}