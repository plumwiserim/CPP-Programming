#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int SUBJECT_NO = 3;

struct StudentInfo {
    string name;
    int scores[SUBJECT_NO];
    int sum;
    float average;
};

vector<int> printStruct(const StudentInfo& si);
void printVector(const vector<StudentInfo>& vSI);

int main() {
    int intSize;
    cin >> intSize;

    vector<StudentInfo> vSI;

    for (unsigned int i = 0; i < intSize; i++) {
        StudentInfo si;

        int sum = 0;
        cin >> si.name;

        int score;
        for (unsigned int j = 0; j < SUBJECT_NO; j++) {
            cin >> score;
            si.scores[j] = score;
            sum += score;
        }

        si.sum = sum;
        si.average = static_cast<float> (sum) / SUBJECT_NO;

        vSI.push_back(si);
    }
    cout << endl;
    printVector(vSI);

    return 0;
}

vector<int> printStruct(const StudentInfo& si) {
    vector<int> buffer(4);

    cout << si.name << '\t';

    for (unsigned int i = 0; i < SUBJECT_NO; ++i) {
        cout << si.scores[i] << '\t';
        buffer.at(i) = si.scores[i];
    }
    buffer.at(3) = si.sum;
    cout << si.sum << '\t' << si.average << '\t' << endl;

    return buffer;
}

void printVector(const vector<StudentInfo>& vSI) {
    vector<int> total(4);
    vector<int> temp(4);

    int index = 1;
    for (vector<StudentInfo>::const_iterator it = vSI.begin(); it != vSI.end(); ++it) {
        cout << index << '\t';
        temp = printStruct(*it);
        for (unsigned int i = 0; i < 4; ++i) total.at(i) += temp.at(i);
        index++;
    }

    cout << "Total\t";
    for (vector<int>::iterator it = total.begin(); it != total.end(); ++it) {
        cout << '\t' << *it;
    }
}
