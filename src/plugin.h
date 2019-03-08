 /**
 * This is the entry point for the plugin.
 * All the methods defined here are called by Scribus' plugin execution code.
 */

#ifndef SCRIPTER_PYBIND11_H
#define SCRIPTER_PYBIND11_H

#include "pluginapi.h"
#include "scplugin.h"

#include "scripter.h"

#include <QString>

class ScribusDoc;
class ScribusMainWindow;

namespace ScribusPlugin {
namespace Scripter {

class PLUGIN_API Plugin : public ScPersistentPlugin
{
	Q_OBJECT
	public:

		// Standard plugin implementation
		Plugin();
		virtual ~Plugin();
		virtual bool initPlugin();
		virtual bool cleanupPlugin();
		virtual const QString fullTrName() const override;
		virtual const AboutData* getAboutData() const override;
		virtual void deleteAboutData(const AboutData* about) const override;
		virtual void languageChange() override;
		virtual void addToMainWindowMenu(ScribusMainWindow *) override;
	private:
		Scripter scripter{};
};

} // namespaces
}

extern "C" PLUGIN_API int scripterpybind11_getPluginAPIVersion();
extern "C" PLUGIN_API ScPlugin* scripterpybind11_getPlugin();
extern "C" PLUGIN_API void scripterpybind11_freePlugin(ScPlugin* plugin);

#endif
