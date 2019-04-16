#include <pybind11/pybind11.h>

#include "scripterAPI/scripterAPI.h"

namespace ScribusPlugin {
namespace Scripter {
namespace API {

std::string API::getCurrentDocumentName()
{
	return "the document";
}

} // namespaces
}
}

namespace py = pybind11;

namespace ScribusPlugin {
namespace Scripter {
namespace API {

void init_ScripterAPI(py::module &m) {
    py::class_<API>(m, "Scribus")
        .def(py::init<>())
        .def("get_name", &API::getCurrentDocumentName)
    ;
}

} // namespaces
}
}

PYBIND11_MODULE(scripterapi, m) {
	m.doc() = "Python interface for Scribus";
	ScribusPlugin::Scripter::API::init_ScripterAPI(m);
}
