#ifndef DR_TMPL_PARSER_H
#define DR_TMPL_PARSER_H

class TmplParser {
public:
	TmplParser();
	TmplIR parse();

private:
	TmplIR ir;
}



#endif // DR_TMPL_PARSER_H
