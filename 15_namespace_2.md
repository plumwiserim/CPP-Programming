문제

Implement Stack and StackException so that the main function works correctly.
```
using namespace MyLib::Collection;
using namespace MyLib::Exception;

int main() {
	Stack<int, 3> is;
	while (true) {
		char cmd; int value;
		cin >> cmd;
		try {
			switch (cmd) {
				case 'i': {
					cin >> value;
					is.Push(value);
					cout << value << " is pushed!" << endl;
					break;
				}
				case 'x': {
					value = is.Pop();
					cout << value << " is popped!" << endl;
					break;
				}
				default: {
					cout << "Invalid command!" << endl;
					return 0;
				}
			}
		}
		catch (const StackException& e) { e.print(); }
	}
}
```
