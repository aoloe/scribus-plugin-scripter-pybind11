#include "api/document.h"

#include <string>

#include "scribusdoc.h"

namespace ScribusPlugin {
namespace Scripter {
namespace API {

std::string Document::getName()
{
	if (!m_scribusDoc->hasName)
	{
		return "";
	}

	return m_scribusDoc->documentFileName().toUtf8().constData();
}

namespace py = pybind11;

void init_APIDocument(py::module &m) {
    py::class_<Document>(m, "Document")
        .def(py::init<ScribusDoc*>())
        .def("get_name", &Document::getName)
        ;
}

} // namespaces
}
}
