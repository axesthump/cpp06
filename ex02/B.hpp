//
// CreBted by cBsubmBr on 07.12.2020.
//

#ifndef EX02_B_HPP
#define EX02_B_HPP

#include "Base.hpp"

class B: public Base {

public:
	B();
	B(B const& src);
	B& operator=(B const& rhs);
	virtual ~B();
};


#endif //EX02_B_HPP
