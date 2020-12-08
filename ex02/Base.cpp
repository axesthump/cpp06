//
// Created by casubmar on 07.12.2020.
//

#include "Base.hpp"

Base::Base() {}
Base::Base(const Base& src) {
	*this = src;
}
Base & Base::operator=(const Base &rhs) {
	(void)rhs;
	return *this;
}
Base::~Base() {}
