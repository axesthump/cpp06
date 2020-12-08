//
// Created by casubmar on 07.12.2020.
//

#ifndef EX02_BASE_HPP
#define EX02_BASE_HPP


class Base {

public:
	Base();
	Base(Base const& src);
	Base& operator=(Base const& rhs);
	virtual ~Base();
};


#endif //EX02_BASE_HPP
