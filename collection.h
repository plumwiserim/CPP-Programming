#pragma once
#include <iostream>
#include "myexception.h"

using namespace std;
using namespace MyLib::Exception;

namespace MyLib {
	namespace Collection {
		template <class T, int sz>
		class Stack {
			int top;
			T s[sz];
		public:
			Stack() {
				top = 0;
			}
			void Push(const T& value) {
				if (top == sz) throw StackException("overflow");
				s[top++] = value;
			}
			T Pop() {
				if (top == 0) throw StackException("underflow");
				T r = s[--top];
				return r;
			}
		};
	}
}