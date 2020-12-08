//
// Created by casubmar on 07.12.2020.
//

#ifndef EX02_C_HPP
#define EX02_C_HPP
#include "Base.hpp"

class C: public Base {
public:
	C();
	C(C const& src);
	C& operator=(C const& rhs);
	virtual ~C();
};


#endif //EX02_C_HPP
