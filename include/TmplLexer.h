#ifndef DR_TMPL_LEXER_H
#define DR_TMPL_LEXER_H

#include "TmplIR.h"

enum TokenKind {
	none,
	text,
	space,
	newline,
	meta,
	equal,
	hr,
	dash,
	open_brace,
	close_brace,
	open_paren,
	close_paren,
	open_bracket,
	close_bracket,
	h1,
	h2,
	h3,
	eol,
};

struct Token {
	TokenKind kind;
	std::string data;
};

class TmplLexer {
public:
	TmplLexer(std::string);
	
	Token* current_token();
	Token* next_token();
	Token* peek_token();
	Token* peek_next_token();
	void verify_token(TokenKind);
	bool is_token(TokenKind);

	bool has_token();

private:
	std::string file;
	int index;
	Token* last_token;

	Token* lex_token();
	Token* lex_text();
	
};

#endif	// DR_TMPL_LEXER_H
