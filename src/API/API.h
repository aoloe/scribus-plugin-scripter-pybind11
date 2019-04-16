#ifndef SCRIPTER_PYBIND11_SCRIPTER_API_H
#define SCRIPTER_PYBIND11_SCRIPTER_API_H

#include <string>

#undef slots // avoid conflicts between Python.h and Qt slots
// #include <pybind11/pybind11.h>
#include <pybind11/embed.h>
#define slots Q_SLOTS

namespace ScribusPlugin {
namespace Scripter {
namespace API {

class API
{
	public:
		API() {}
		std::string getCurrentDocumentName();
};

} // namespaces
}
}

#endif

