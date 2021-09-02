#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Student {
private:
	string name;
	float gpa;
public:
	Student(string studentname, float studentgpa) {
		name = studentname;
		gpa = studentgpa;
	}
	void print() {
		cout << "    Name: " << name << " GPA: " << gpa << endl;
	}
	void getgpa(float& studentgpa) {
		studentgpa = gpa;
	}
	void getname(string& studentname) {
		studentname = name;
	}
	void setGPA(float studentgpa) {
		gpa = studentgpa;
	}
	void setName(string studentname) {
		name = studentname;
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
	void addStudent(string name, float gpa = 0) {
		Student newStudent(name, gpa);
		students.push_back(newStudent);
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
	Student& findStudentWithName(string studentname) {
		int size = students.size();
		for (int i = 0; i < size; i++) {
			string name;

			students[i].getname(name);

			if (name == studentname) {
				return students[i];
			}
		}
	}
};

int main() {
	School pnu("PNU");

	pnu.addStudent("Kim", 2.7F);
	pnu.addStudent("Hong", 3.5F);
	pnu.addStudent("Lee");
	pnu.addStudent("Joo", 1.5F);
	pnu.print();

	pnu.sort();
	pnu.print();

	School knu("KNU");
	knu.addStudent("Seo", 2.5F);
	knu.addStudent("Lee", 3.8F);
	knu.print();

	Student& lee = pnu.findStudentWithName("Lee");
	lee.setGPA(3.3F);
	lee.setName("Yoon");
	pnu.print();

	knu.addStudent("Hong", 4.3F);
	Student& hong = knu.findStudentWithName("Hong");
	hong.setGPA(3.3F);
	hong.setName("Joon");
	knu.print();
}
