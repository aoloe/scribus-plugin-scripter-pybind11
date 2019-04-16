#include <memory>

#include "scripter.h"
#include "API/API.h"

#include "scraction.h"
#include "ui/scmwmenumanager.h" // scrMenuMgr

#include <QFileDialog>

using namespace pybind11::literals; // for the ""_a

namespace ScribusPlugin {
namespace Scripter {

void Scripter::languageChange()
{
	actions["scripter11Execute"]->setText(tr("&Execute Script..."));
}

void Scripter::addActions()
{
	actions.insert("scripter11Execute", new ScrAction(tr("&Execute Script..."), QKeySequence(), this));
	actions["scripter11Execute"]->setMenuRole(QAction::NoRole);
	connect(actions["scripter11Execute"], &ScrAction::triggered , this, &Scripter::openScriptFile);

	auto menu{scribusMainWindow->scrMenuMgr};
	menu->createMenu("Scripter11", tr("&Script11"));
	menu->addMenuItemString("scripter11Execute", "Scripter11");

	menu->addMenuStringToMenuBarBefore("Scripter11", "Windows");
	menu->addMenuItemStringsToMenuBar("Scripter11", actions);
}

void Scripter::openScriptFile()
{
	// TODO: find a good value for the path
	auto path = QFileDialog::getOpenFileName(scribusMainWindow,
	    tr("Open Python File"), QDir::homePath(), tr("Python Files (*.py)"));
	qDebug() << path;

	runScriptFile(path);
}

void Scripter::runScriptFile(QString path)
{
    API::API scripterAPI;
    // scripterAPI.setDocument(document);

    auto module = py::module::import("scripterpybind11api");

	// TODO: probably, pass it by value
    auto locals = py::dict("Scribus"_a = py::cast(scripterAPI, py::return_value_policy::reference));
    py::eval_file(path.toUtf8().constData(), py::globals(), locals);
}

} // namespaces
}
