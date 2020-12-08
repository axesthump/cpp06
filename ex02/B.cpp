//
// Created by casubmar on 07.12.2020.
//

#include "B.hpp"

B::B(): Base() {}
B::B(const B& src): Base() {
	*this = src;
}
B & B::operator=(const B &rhs) {
	(void)rhs;
	return *this;
}
B::~B() {}