//
// Created by casubmar on 07.12.2020.
//

#ifndef EX02_A_HPP
#define EX02_A_HPP

#include "Base.hpp"

class A: public Base {

public:
	A();
	A(A const& src);
	A& operator=(A const& rhs);
	virtual ~A();
};


#endif //EX02_A_HPP
