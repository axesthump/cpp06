//
// Created by casubmar on 07.12.2020.
//

#include "C.hpp"

C::C(): Base() {}
C::C(const C& src): Base() {
	*this = src;
}
C & C::operator=(const C &rhs) {
	(void)rhs;
	return *this;
}
C::~C() {}
