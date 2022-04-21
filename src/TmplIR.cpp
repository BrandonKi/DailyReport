#include "TmplIR.h"

using namespace tmpl;

TmplIR::TmplIR(): pages{} {

}

void TmplIR::add_page(Page* page) {
	pages.push_back(page);
}
