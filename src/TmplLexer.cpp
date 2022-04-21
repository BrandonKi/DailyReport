#include "TmplLexer.h"

using enum TokenKind;

TmplLexer::TmplLexer(std::string file): file{file}, index{0}, last_token{lex_token()} {

}

Token* TmplLexer::lex_token() {

	while(index < file.size()) {
		switch(file[index]) {
			case '\n':
				++index;
				return new Token{newline};
			case ' ':
				++index;
				return new Token{space};
			case '!':
				break;
			case '"':
				break;
			case '#':
				break;
			case '$':
				break;
			case '%':
				break;
			case '&':
				break;
			case '\'':
				break;
			case '(':
				break;
			case ')':
				break;
			case '*':
				break;
			case '+':
				break;
			case ',':
				break;
			case '-':
				// can be text or <hr>
				break;
			case '.':
				break;
			case '/':
				break;
			case '0': case '1': case '2': case '3': case '4':
			case '5': case '6': case '7': case '8': case '9':
				return lex_text();
			case ':':
				// start of element token
				break;
			case ';':
				break;
			case '<':
				break;
			case '=':
				++index;
				return new Token{equal};
			case '>':
				break;
			case '?':
				break;
			case '@':
				break;
			case 'A': case 'B': case 'C': case 'D': case 'E':
			case 'F': case 'G': case 'H': case 'I': case 'J':
			case 'K': case 'L': case 'M': case 'N': case 'O':
			case 'P': case 'Q': case 'R': case 'S': case 'T':
			case 'U': case 'V': case 'W': case 'X': case 'Y':
			case 'Z':
				return lex_text();
			case '[':
				++index;
				return new Token{open_bracket};
			case '\\':
				// escape next character
				break;
			case ']':
				++index;
				return new Token{close_bracket};
			case '^':
				break;
			case '_':
				// text
				break;
			case '`':
				break;
			case 'a': case 'b': case 'c': case 'd': case 'e':
			case 'f': case 'g': case 'h': case 'i': case 'j':
			case 'k': case 'l': case 'm': case 'n': case 'o':
			case 'p': case 'q': case 'r': case 's': case 't':
			case 'u': case 'v': case 'w': case 'x': case 'y':
			case 'z':
				return lex_text();
			case '{':
				break;
			case '|':
				break;
			case '}':
				break;
			case '~':
				break;
			default:
				assert(false);
			}
		}
}

Token* TmplLexer::lex_text() {
	auto c = file[index];
	std::string str;
	
	while(is_alpha_numeric(c) || c == '.' || c == '_') {
		str += c;
		c = file[++index];
	}
	return new Token{text, str};
}

Token* TmplLexer::current_token() {
	return last_token;
}

Token* TmplLexer::next_token() {
	last_token = lex_token(); 
	return last_token;
}

Token* TmplLexer::peek_token() {
    int start_index = index;
    auto token = lex_token();
    index = start_index;
    return token;
}

void TmplLexer::verify_token(TokenKind kind) {
	assert(last_token->kind == kind);
}

bool TmplLexer::is_token(TokenKind kind) {
	return last_token->kind == kind; 
}

bool TmplLexer::has_token() {
	return index < file.size();
}
