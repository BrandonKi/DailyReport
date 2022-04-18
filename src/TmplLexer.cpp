#include "TmplLexer.h"

TmplLexer::TmplLexer() {

}

TmplLexer::lex_token() {

	switch() {
		case '\n':
			// newline token
			break;
		case ' ':
			break;
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
			// lex as text
			break;
		case ':':
			// start of element token
			break;
		case ';':
			break;
		case '<':
			break;
		case '=':
			break;
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
			// lex as text token
			break;
		case '[':
			// start of button element
			break;
		case '\\':
			// escape next character
			break;
		case ']':
			// text
			break;
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
			// text
			break;
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

TmplLexer::lex_text() {

}


TmplLexer::current_token() {

}

TmplLexer::next_token() {

}

TmplLexer::peek_token() {

}

TmplLexer::peek_next_token() {

}

TmplLexer::verify_token() {

}

TmplLexer::is_token() {

}
