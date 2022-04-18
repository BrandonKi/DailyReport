#ifndef DR_TMPL_LEXER_H
#define DR_TMPL_LEXER_H

enum TokenKind {
	none,
	text,
	space,
	newline,
	meta,
	equal,
	hr,
	dash,
	brace_open,
	brace_close,
	bracket_open,
	bracket_close,
	h1,
	h2,
	h3,
	eol,
};

struct Token {
	TokenKind kind;
	
};

class TmplLexer {
public:
	TmplLexer();
	
	current_token();
	next_token();
	peek_token();
	peek_next_token();
	verify_token();
	is_token();

private:
	lex_text();

};

#endif	// DR_TMPL_LEXER_H
