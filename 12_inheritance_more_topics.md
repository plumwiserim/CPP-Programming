다음의 각 개념을 설명하는 예제 소스 코드를 각각 작성하고 해당 소스 코드를 바탕으로 그 개념을 설명하시오. 

(단 교재의 코드를 사용하지 않고 새로운 소스 코드를 개발해야 함.)

 

코드1: Constructor delegation, Constructor inheritance

```
#include <iostream>

using namespace std;

enum Grade {freshman, sophomore, junior, senior};

class Student {
	string name;
	Grade grade;
	float Korean;
	float Math;
	float English;
public:
	Student(const string& _name, const Grade _grade, float _korean, float _math, float _english)
		: name(_name), grade(_grade), Korean(_korean), Math(_math), English(_english) {}
	Student(const string& _name, const Grade _grade)
		: name(_name), grade(_grade) {}
};
class Liberal_Arts : public Student {
	float Sociology;
public:
	Liberal_Arts(const string& _name, const Grade _grade, float _korean, float _math, float _english, float _sociology)
		: Student(_name, _grade, _korean, _math, _english), Sociology(_sociology) {}
	using Student::Student;
};
class Natural_Sciences : public Student {
	float Science;
public:
	Natural_Sciences(const string& _name, const Grade _grade, float _korean, float _math, float _english, float _science)
		: Student(_name, _grade, _korean, _math, _english), Science(_science) {}
	using Student::Student;
};
int main() {
	Liberal_Arts la1("Kim", sophomore, 80, 90, 75, 95);
	Liberal_Arts la2("Park", freshman, 78, 80, 95);
	Liberal_Arts la3("Lee", senior);

	Natural_Sciences ns1("Park", junior, 79, 96, 80, 92);
	Natural_Sciences ns2("Lee", junior, 80, 85, 97);
	Natural_Sciences ns3("Kim", freshman);
}
```

학생은 이름, 학년과 국어, 수학, 영어 성적을 가진다.

학생에는 문과학생 이과학생이 존재하고 

문과학생은 학생의 멤버에 사회 성적, 이과학생은 학생의 멤버에 과학 성적을 추가로 가진다.

 

코드2: Final virtual function, Final class, Virtual function override

```
#include <iostream>

using namespace std;

class Human_Health {
	int ex_freq = 0, ex_time = 0;
	int dr_freq = 0, dr_amount = 0;
public:
	virtual int exercising() { return 0; }
	virtual int drinking() { return 0; }
};
class Mature : public Human_Health {
	int ex_freq, ex_time;
	int dr_freq, dr_amount;
public:
	Mature(int _ex_freq, int _ex_time, int _dr_freq, int _dr_amount)
		: ex_freq(_ex_freq), ex_time(_ex_time), dr_freq(_dr_freq), dr_amount(_dr_amount) {}
	int exercising() {
		int ex_score = ex_freq * ex_time;
		return ex_score;
	}
	int drinking() {
		int dr_score = dr_freq * dr_amount;
		return dr_score;
	}
};
class Youth : public Human_Health {
	int ex_freq, ex_time;
	int dr_freq, dr_amount;
public:
	Youth(int _ex_freq, int _ex_time, int _dr_freq, int _dr_amount)
		: ex_freq(_ex_freq), ex_time(_ex_time), dr_freq(_dr_freq), dr_amount(_dr_amount) {}
	int exercising() {
		int ex_score = ex_freq * ex_time;
		return ex_score;
	}
	int drinking() final {
		int dr_score = dr_freq * dr_amount;
		return dr_score;
	}
};
class Teenager final : public Human_Health {
	int ex_freq, ex_time;
public:
	Teenager(int _ex_freq, int _ex_time)
		: ex_freq(_ex_freq), ex_time(_ex_time) {}
	int exercising() {
		int ex_score = ex_freq * ex_time;
		return ex_score;
	}
};
class Infant {

public:
};

int main() {
	Mature m(3, 1, 1, 2);
	Youth y(5, 1, 3, 1);
	Teenager t(2, 2);

	int m_score = m.exercising() - m.drinking();
	int y_score = y.exercising() - y.drinking();
	int t_score = t.exercising();

	cout << "Mature m's score : " << m_score << "\nYouth y's score : " << y_score << "\nTeenager t's score : " << t_score << endl;
}
```

위의 예시코드는 사람의 건강지수를 측정할 때는 사람을 노년 장년 중년 청년 청소년 아동 영유아로 나누어 각 생애주기별로 건강지수에 영향을 미치는 요인이 다르다고 생각하여

장년(Mature) 청년(Youth) 청소년(Teenager) 영유아(Infant)에 대해 건강지수에 영향을 미칠 수 있는 요인을 예상하여 작성해보았다.

Human_Health 클래스는 생애주기별로 Mature Youth Teenager Infant의 하위클래스를 가질 수 있고

건강에 좋은 영향을 미치는 운동지수, 안 좋은 영향을 미치는 음주지수를 건강의 주요요인이라고 생각하여 각각을 측정하는 함수를 Human_Health 클래스의 멤버함수로 지정하였다.

영유아는 정기적인 운동이나 음주를 할 수 없기 때문에 Teenager 클래스를 final class 로 지정하여 Infant 클래스는 Human_Health 클래스의 속성들을 상속받지 못하도록 한다.

또한 음주지수는 성인에게만 해당되므로 음주지수측정함수는 Mature Youth 클래스에는 override되지만 미성년자인 Teenager 클래스에는 override되지 않아야 한다. 그러므로 Youth 클래스의 음주지수측정함수를 final virtual function 으로 지정하여 Teenager 클래스는 Human_Health 클래스의 drinking 멤버함수를 상속받지 못하도록 한다.

​