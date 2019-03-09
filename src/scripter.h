#ifndef SCRIPTER_PYBIND11_SCRIPTER_H
#define SCRIPTER_PYBIND11_SCRIPTER_H

#include "scribus.h" // ScribusMainWindow

class ScrAction;

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
};

} // namespaces
}
#endif
