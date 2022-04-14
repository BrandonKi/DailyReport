#ifndef DR_TMPL_IR_H
#define DR_TMPL_IR_H

#include <vector>

namespace tmpl {

enum Type {
	none,
	form,
	header,
	
};

struct Element {

};

struct Form: Element {
	std::vector<Element*> children;
};

}

class TemplIR {
public:
	TmplIR();
	
};

#endif // DR_TMPL_IR_H
