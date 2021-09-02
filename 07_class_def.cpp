#include <iostream>
#include <string>
#include <vector>

using namespace std;

enum MajorType { CE, EE, ME, UD };

class Major {
private:
	MajorType majorType;
public:
	void print() {
		string stringmajorType;
		switch (majorType) {
		case CE: stringmajorType = "Computer Eng"; break;
		case EE: stringmajorType = "Electrical Eng"; break;
		case ME: stringmajorType = "Mechanical Eng"; break;
		case UD: stringmajorType = "UD"; break;
		}
		cout << " Major: " << stringmajorType << "." << endl;
	}
	friend class Student;
};

class Student {
private:
	string name;
	float gpa;
	Major major;
public:
	Student(string studentname, float studentgpa, MajorType studentmajor)
		:major() {
		name = studentname;
		gpa = studentgpa;
		major.majorType = studentmajor;
	}
	void print() {
		cout << "    Name: " << name << " GPA: " << gpa;
		major.print();
	}
	void getgpa(float& studentgpa) {
		studentgpa = gpa;
	}
	void setGPA(float studentgpa) {
		gpa = studentgpa;
	}
	void setMajor(MajorType studentmajor) {
		major.majorType = studentmajor;
	}
};

class School {
private:
	string schoolName;
	vector<Student> students;
public:
	School(string schoolname) {
		schoolName = schoolname;
	}
	Student* addStudent(string name, MajorType major) {
		Student newStudent(name, 0, major);
		students.push_back(newStudent);

		return &students[students.size() - 1];
	}
	Student* addStudent(string name, float gpa) {
		Student newStudent(name, gpa, CE);
		students.push_back(newStudent);

		return &students[students.size() - 1];
	}
	void print() {
		cout << "School Name: " << schoolName << ", Count: " << students.size() << endl;

		typedef vector<Student>::iterator it;
		for (it p = students.begin(); p != students.end(); ++p) {
			Student student = *p;
			student.print();
		}
		cout << endl;
	}
	void swap(Student& s1, Student& s2) {
		Student temp = s1;
		s1 = s2;
		s2 = temp;
	}
	void sort() {
		int size = students.size();
		for (int i = 0; i < size - 1; i++) {
			for (int j = i + 1; j < size; j++) {
				float gpa_i;
				float gpa_j;

				students[i].getgpa(gpa_i);
				students[j].getgpa(gpa_j);

				if (gpa_i < gpa_j) {
					swap(students[i], students[j]);
				}
			}
		}
	}
};

int main() {
	School pnu("PNU");

	Student* kim = pnu.addStudent("Kim", EE);
	kim->setGPA(3.5F);

	Student* hong = pnu.addStudent("Hong", CE);
	hong->setGPA(4.3F);

	Student* lee = pnu.addStudent("Lee", 4.0F);
	lee->setMajor(CE);

	Student* joo = pnu.addStudent("Joo", 1.5F);
	joo->setMajor(ME);

	pnu.print();

	pnu.sort(); // descending
	pnu.print();
}