#ifndef DR_TMPL_IR_H
#define DR_TMPL_IR_H

#include <vector>
#include <string>

namespace tmpl {

enum ElementType {
	none,
	page,
	text,
	form,
	header,
	button,
	checkbox,
	align,
};

struct Page;
struct Text;
struct Form;
struct Header;
struct Button;
struct Checkbox;
struct Align;

struct Page {
	std::string page_name;
	std::vector<Element*> children;
};

struct Text {
	std::string content;
};

struct Form {
	std::vector<Element*> children;
};

struct Header {
	std::string content; 
};

enum ButtonAction {
	none,
	submit_page,
	navigate
};

struct Button {
	std::string  text;
	ButtonAction action;
	union {
		struct {
			// TODO
		};
	};
};

struct Checkbox {
	std::string label;
	bool checked = false;
};

enum AlignDirection {
	none,
	left,
	right,
	center
};

struct Align {
	AlignDirection direction;
	Element*       target;
};

struct Element {	
	ElementType type;
	union {
		Text*     text;
		Form*     form;
		Header*   header;
		Button*   button;
		Checkbox* checkbox;
		Align*    align;
	};
};

enum MetaType {
	none,
	ref,
	decl,
	export
};

struct Ref {
	std::string id;
	Element* value;
};

struct Decl {
	std::string id;
	Element* value;
};

struct Export {
	std::vector<std::string> export_list;
};

struct MetaElement {
	MetaType type;
	union {
		Ref*    ref;
		Decl*   decl;
		Export* export;
	};
};

}

class TemplIR {
public:
	TmplIR();

    add_page();

private:
	std::vector<Page*> pages;
	
};

#endif // DR_TMPL_IR_H
