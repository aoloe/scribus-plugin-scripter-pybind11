#ifndef SCRIPTER_PYBIND11_SCRIPTER_H
#define SCRIPTER_PYBIND11_SCRIPTER_H

#include "scribus.h" // ScribusMainWindow

#undef slots // avoid conflicts between Python.h and Qt slots
#include <pybind11/pybind11.h>
#include <pybind11/embed.h>
#define slots Q_SLOTS

class ScrAction;

namespace py = pybind11;

namespace ScribusPlugin {
namespace Scripter {

class Scripter : public QObject
{
	Q_OBJECT

	public:
		Scripter() {};
		~Scripter() {};

		void setScribusMainWindow(ScribusMainWindow* mainWindow) { this->scribusMainWindow = mainWindow; }

		void languageChange();
		void addActions();

	private slots:
		void openScriptFile();

	private:
		QMap<QString, QPointer<ScrAction> > actions{};
		ScribusMainWindow* scribusMainWindow{nullptr};

		void runScriptFile(QString path);

        py::scoped_interpreter guard{}; // start the interpreter and keep it alive
};

} // namespaces
}
#endif
