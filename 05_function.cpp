#include <iostream>
#include <string>
#include <vector>
#include <cassert>

using namespace std;

struct Rectangle {
	int width;
	int height;
};

enum CommandKind { ADD, SORT, PRINT, CLEAR, EXIT, INVALID };

CommandKind getCommandKind(string);
Rectangle getRectangle();
void print(const vector<Rectangle>);
void print(const Rectangle&);
inline void swap(Rectangle&, Rectangle&);
void sort(vector<Rectangle>&);

int main() {
	vector<Rectangle> rectangles;

	while (true) {
		string commandString;
		cin >> commandString;

		const CommandKind command = getCommandKind(commandString);
		switch (command) {
		case ADD: {
			const Rectangle& newRectangle = getRectangle();
			rectangles.push_back(newRectangle);
			break;
		}
		case PRINT: {
			print(rectangles);
			break;
		}
		case SORT: {
			sort(rectangles);
			print(rectangles);
			break;
		}
		case CLEAR: rectangles.clear(); break;
		case EXIT: break;
		default: assert(false); break;
		}
		if (command == EXIT) break;
	}
	return 0;
}

CommandKind getCommandKind(string commandString) {
	int commandInt;

	if (commandString == "ADD") commandInt = 0;
	else if (commandString == "SORT") commandInt = 1;
	else if (commandString == "PRINT") commandInt = 2;
	else if (commandString == "CLEAR") commandInt = 3;
	else if (commandString == "EXIT") commandInt = 4;
	else if (commandString == "INVALID") commandInt = 5;

	return CommandKind(commandInt);
}

Rectangle getRectangle() {
	int getWidth;
	int getHeight;
	cin >> getWidth >> getHeight;

	Rectangle newRect;
	newRect.width = getWidth;
	newRect.height = getHeight;

	return newRect;
}

void print(const vector<Rectangle> rects) {
	cout << "Rectangle Count: " << rects.size() << endl;

	typedef vector<Rectangle>::const_iterator it;
	for (it p = rects.begin(); p != rects.end(); ++p) {
		print(*p);
	}
}

void print(const Rectangle& rect) {
	int area = rect.width * rect.height;
	cout << '\t' << rect.width << ' ' << rect.height << ' ' << area << endl;
}

inline void swap(Rectangle& r1, Rectangle& r2) {
	Rectangle temp = r1;
	r1 = r2;
	r2 = temp;
}

void sort(vector<Rectangle>& rects) {
	int size = rects.size();
	for (int i = 0; i < size - 1; i++) {
		for (int j = i + 1; j < size; j++) {
			int area_i = rects[i].width * rects[i].height;
			int area_j = rects[j].width * rects[j].height;
			if (area_i > area_j) {
				swap(rects[i], rects[j]);
			}
		}
	}
}
