#include <iostream>
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <time.h>
#include <typeinfo>

Base * generate(void) {
	if (rand() % 3 == 1) {
		return new A();
	} else if (rand() % 3 == 2) {
		return new B();
	} else {
		return new C();
	}
}

void identify_from_pointer(Base * p) {
	A* a = dynamic_cast<A *>(p);
	if (a) {
		std::cout << "A\n";
	} else {
		B* b = dynamic_cast<B *>(p);
		if (b) {
			std::cout << "B\n";
		} else {
			C* c = dynamic_cast<C *>(p);
			if (c) {
				std::cout << "C\n";
			} else {
				std::cout << "Base\n";
			}
		}
	}
}

void identify_from_reference( Base & p) {
	try {
		A& a = dynamic_cast<A&>(p);
		std::cout << "A\n";
		return ;
	} catch (std::bad_cast &e) {
		try {
			B& b = dynamic_cast<B&>(p);
			std::cout << "B\n";
			(void)e;
			return ;
		} catch (std::bad_cast& e) {
			try {
				C& c = dynamic_cast<C&>(p);
				(void)e;
				std::cout << "C\n";
				return ;
			} catch (std::bad_cast& e) {
				(void)e;
				std::cout << "Base";
			}
		}
	}
}


int main() {
	std::srand(time(NULL));
	Base* base = generate();
	identify_from_pointer(base);
	identify_from_reference(*base);
	delete base;
	return 0;
}
