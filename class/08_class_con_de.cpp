#include <iostream>
#include <string>
#include <string.h>

using namespace std;

class MyString {
	char* str;
	int size;
public:
	MyString() {
	}
	MyString(char* _str)
		:str(_str) {
		set(_str);
	}
	MyString(const MyString& another)
		:str(another.str), size(another.size) {
		//set(another.str);
	}
	void set(char* _str) {
		str = _str;
		size = strlen(_str);
	}
	bool isEqual(MyString another) const {
		if (this->str == another.str) return true;
		else return false;
	}
	void print() const {
		cout << str << endl;
	}
};

int main() {
	MyString strs[] = {
		MyString("C"),
		MyString(),
		MyString("Java")
	};
	strs[1].set("C++");

	const MyString target("Java");
	for (int i = 0; i < 3; i++) {
		const MyString str(strs[i]);
		if (str.isEqual(target)) {
			cout << "[" << i << "]: ";
			str.print();
			break;
		}
	}
	for (int i = 0; i < 3; i++) {
		const MyString& str = strs[i];
		str.print();
	}
}
