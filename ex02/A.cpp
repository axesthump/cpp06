//
// Created by casubmar on 07.12.2020.
//

#include "A.hpp"

A::A(): Base() {}
A::A(const A &src): Base() {
	*this = src;
}
A & A::operator=(const A &rhs) {
	(void)rhs;
	return *this;
}
A::~A() {}