#include <iostream>
#include <string>

using namespace std;

int main() {
	cout << "Enter the score count: ";
	int maxSize;
	cin >> maxSize;

	int* const scores = new int[maxSize];

	int j = 0;
	double sum = 0;
	while (true) {
		cout << "Enter command: (add, sum, average, quit) ";
		string command;
		cin >> command;

		for (int i = 0; i < command.size(); i++) {
			command[i] = tolower(command[i]);
		}
		
		if (command == "add") {
			if (j == maxSize) {
				cout << "Too many scores" << endl;
			}
			else {
				int score;
				cout << "Enter score: ";
				cin >> score;
				if (score < 0 or score > 100) {
					cout << "Score should be between 0 and 100" << endl;
				}
				else {
					scores[j] = score;
					cout << score << " added" << endl;
					j++;
				}
			}
		}
		else if (command == "sum") {
			sum = 0;
			for (int k = 0; k < j; k++) {
				sum += scores[k];
			}

			cout << "Sum: " << sum << endl;
		}
		else if (command == "average") {
			sum = 0;
			for (int k = 0; k < j; k++) {
				sum += scores[k];
			}

			double average;
			average = sum / j;

			cout << "Average: " << average << endl;
		}
		else if (command == "quit") {
			cout << "Bye";
			break;
		}
	}
	delete[] scores;
}