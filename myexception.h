#pragma once
#include <iostream>

using namespace std;

namespace MyLib {
	namespace Exception {
		class StackException {
			const string msg;
		public:
			StackException(const string& _msg) : msg(_msg) {};
			void print() const { cout << msg << endl; }
		};
	}
}
