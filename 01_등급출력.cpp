#include <iostream>
#include <string>

using namespace std;

int main() {
	while (true) {
		cout << "Enter a name and score: ";
		string name;
		cin >> name;
		int score;
		cin >> score;

		if (score < 0 or score > 100) {
			cout << "Bye " << name << endl;
			break;
		}
		else {
			string grade;
			if (score >= 90) grade = "A";
			else if (score >= 80) grade = "B";
			else if (score >= 70) grade = "C";
			else if (score >= 60) grade = "D";
			else grade = "F";

			cout << "Hi " << name << "! Your grade is " << grade << endl;
		}
	}
}