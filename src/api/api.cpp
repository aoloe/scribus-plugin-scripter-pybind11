#include "api/api.h"
#include "api/document.h"

#include <string>
#include <stdexcept>

#include <pybind11/pybind11.h>

#include "scribuscore.h"
#include "scribusdoc.h"

namespace py = pybind11;

namespace ScribusPlugin {
namespace Scripter {
namespace API {

Document getCurrentDocument()
{
	if (!ScCore->primaryMainWindow()->HaveDoc)
	{
		throw std::exception();
	}

	return Document(ScCore->primaryMainWindow()->doc);
}

void init_APIDocument(py::module &);

PYBIND11_EMBEDDED_MODULE(scribus, m) {
	m.def("get_current_document", &getCurrentDocument);
    py::class_<API>(m, "Scribus")
        .def(py::init<>())
    ;
	init_APIDocument(m);
}

} // namespaces
}
}
