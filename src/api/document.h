#ifndef SCRIPTER_PYBIND11_SCRIPTER_DOCUMENT_H
#define SCRIPTER_PYBIND11_SCRIPTER_DOCUMENT_H

#include <string>

#undef slots // avoid conflicts between Python.h and Qt slots
// #include <pybind11/pybind11.h>
#include <pybind11/embed.h>
#define slots Q_SLOTS

class ScribusDoc;

namespace ScribusPlugin {
namespace Scripter {
namespace API {

class Document
{
	public:
		Document(ScribusDoc* scribusDoc) :
			m_scribusDoc{scribusDoc} {}
		std::string getName();
	private:
		ScribusDoc* m_scribusDoc;
};

} // namespaces
}
}

#endif
