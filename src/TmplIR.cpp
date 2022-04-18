#include "TmplIR.h"

TmplIR::TmplIR(): pages{} {

}

TmplIR::add_page(Page* page) {
	pages.push_back(page);
}
