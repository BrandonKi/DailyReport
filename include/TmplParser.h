#ifndef DR_TMPL_PARSER_H
#define DR_TMPL_PARSER_H

#include "TmplLexer.h"

struct File {
	std::string name;
	std::string data;
};

class TmplParser {
public:
	TmplParser(Args);
	TmplIR parse();

private:
	Args args;
	TmplIR ir;
	std::vector<File> files;

	std::vector<tmpl::Element*> parse_page(TmplLexer&);
	
};

#endif // DR_TMPL_PARSER_H
