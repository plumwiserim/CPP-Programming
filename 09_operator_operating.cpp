#include <iostream>

using namespace std;

class Matrix {
	int** values;
	int row, column;
public:
	Matrix(int row = 0, int column = 0) {
		this->row = row;
		this->column = column;

		values = new int* [row];
		for (int i = 0; i < row; i++) {
			values[i] = new int[column];
		}
	}
	Matrix(const Matrix& m) {
		this->values = m.values;
		row = m.row;
		column = m.column;
	}
	Matrix& operator = (const Matrix& m) {
		delete[] values;

		row = m.row;
		column = m.column;

		for (int i = 0; i < row; i++) {
			for (int j = 0; j < column; j++) {
				values[i][j] = m.values[i][j];
			}
		}
		return *this;
	}
	friend Matrix operator + (const Matrix& m1, const Matrix& m2);
	friend Matrix operator * (const Matrix& m, int c);
	friend istream& operator >> (istream& is, Matrix& m);
	friend ostream& operator << (ostream& os, const Matrix& m);
};

Matrix operator + (const Matrix& m1, const Matrix& m2) {
	Matrix m;
	m.row = m1.row;
	m.column = m1.column;
	m.values = new int* [m1.row];
	for (int i = 0; i < m1.row; i++) {
		m.values[i] = new int[m1.column];
	}

	for (int i = 0; i < m1.row; i++) {
		for (int j = 0; j < m1.column; j++) {
			m.values[i][j] = m1.values[i][j] + m2.values[i][j];
		}
	}
	return m;
}

Matrix operator * (const Matrix& m, int c) {
	Matrix matrix(m.row, m.column);
	for (int i = 0; i < m.row; i++) {
		for (int j = 0; j < m.column; j++) {
			matrix.values[i][j] = m.values[i][j] * c;
		}
	}
	return matrix;
}

istream& operator >> (istream& is, Matrix& m) {
	for (int i = 0; i < m.row; i++) {
		for (int j = 0; j < m.column; j++) {
			is >> m.values[i][j];
		}
	}
	return is;
}

ostream& operator << (ostream& os, const Matrix& m) {
	for (int i = 0; i < m.row; i++) {
		for (int j = 0; j < m.column; j++) {
			os << m.values[i][j] << '\t';
		}
		cout << endl;
	}
	return os;
}

int main() {
	Matrix m1(2, 3), m2(2, 3);
	cin >> m1;
	cin >> m2;

	Matrix m3(m1 + m2);
	Matrix m4(2, 2);

	m4 = m3 * 10;

	cout << m3 << endl << m4 << endl;
}