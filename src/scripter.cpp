#include "scripter.h"

#include "scraction.h"
#include "ui/scmwmenumanager.h" // scrMenuMgr

#include <QFileDialog>

namespace ScribusPlugin {
namespace Scripter {

void Scripter::languageChange()
{
	actions["scripter11Execute"]->setText(QObject::tr("&Execute Script..."));
}

void Scripter::addActions()
{
	actions.insert("scripter11Execute", new ScrAction(QObject::tr("&Execute Script..."), QKeySequence(), this));
	actions["scripter11Execute"]->setMenuRole(QAction::NoRole);
	connect(actions["scripter11Execute"], &ScrAction::triggered , this, &Scripter::openScriptFile);

	auto menu{scribusMainWindow->scrMenuMgr};
	menu->createMenu("Scripter11", QObject::tr("&Script11"));
	menu->addMenuItemString("scripter11Execute", "Scripter11");

	menu->addMenuStringToMenuBarBefore("Scripter11", "Windows");
	menu->addMenuItemStringstoMenuBar("Scripter11", actions);
}

void Scripter::openScriptFile()
{
	auto fileName = QFileDialog::getOpenFileName(scribusMainWindow,
	    tr("Open Python File"), "/home/ale", tr("Python Files (*.py)"));
}

} // namespaces
}
