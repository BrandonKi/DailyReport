#include "TmplParser.h"

using namespace tmpl;

TmplParser::TmplParser(Args args): args{args}, ir{}, files{} {
	for(auto& name: args.files)
		files.emplace_back(name, read_file(name));
}

TmplIR TmplParser::parse() {
	// TODO thread pool
	for(auto& file: files) {
		TmplLexer lexer(file.data);
		ir.add_page(new Page {
			.page_name = file.name,
			.children = parse_page(lexer)
		});
	}

	assert(false);
	return {};
}

std::vector<Element*> TmplParser::parse_page(TmplLexer& lexer) {
	auto current = lexer.current_token();
	while(lexer.has_token()) 
		current = lexer.next_token();
	assert(false);
	return {};
}

