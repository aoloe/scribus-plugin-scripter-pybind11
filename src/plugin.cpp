#include "plugin.h"

#include "scribuscore.h"
#include "scribusdoc.h"

#include <QString>

int scripterpybind11_getPluginAPIVersion()
{
	return PLUGIN_API_VERSION;
}

ScPlugin* scripterpybind11_getPlugin()
{
	auto plug = new ScribusPlugin::Scripter::Plugin();
	Q_CHECK_PTR(plug);
	return plug;
}

void scripterpybind11_freePlugin(ScPlugin* plugin)
{
	auto plug = dynamic_cast<ScribusPlugin::Scripter::Plugin*>(plugin);
	Q_ASSERT(plug);
	delete plug;
}

namespace ScribusPlugin {
namespace Scripter {

Plugin::Plugin()
{
	// languageChange();
}

Plugin::~Plugin()
{
	// unregisterAll();
};

void Plugin::languageChange()
{
	scripter.languageChange();
}

const QString Plugin::fullTrName() const
{
	return tr("Scripter pybind11");
}

const ScActionPlugin::AboutData* Plugin::getAboutData() const
{
	AboutData* about = new AboutData;
	about->authors = "Ale Rimoldi <a.l.e@ideale.ch>";
	about->shortDescription = tr("Python3 scripter based pybind11.");
	about->description = tr("Python3 scripter based pybind11.");
	about->license = "MIT";
	Q_CHECK_PTR(about);
	return about;
}

void Plugin::deleteAboutData(const AboutData* about) const
{
	Q_ASSERT(about);
	delete about;
}

bool Plugin::initPlugin()
{
	return true;
}

/**
 * Things created in initPlugin(), will be deleted in cleanupPlugin()...
 */
bool Plugin::cleanupPlugin()
{
	return true;
}

void Plugin::addToMainWindowMenu(ScribusMainWindow* mainWindow)
{
	// TODO: it would be nice if mainWindow would be passed in the constructor...
	scripter.setScribusMainWindow(mainWindow);
	scripter.addActions();
	languageChange(); // TODO: this should go in the constructor or in initPlugin(), but at that point we don't have the menus and the translatable items are not ready yet.
}

} // namespaces
}

