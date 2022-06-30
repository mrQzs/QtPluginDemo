#ifndef QTPLUGIN_H
#define QTPLUGIN_H

#include <QObject>
#include <QtPlugin>

#include "Base.h"

class QWidget;

class QTPlugin : public QObject, public Base {
  Q_OBJECT
  Q_INTERFACES(Base)
  Q_PLUGIN_METADATA(IID PlugInterface_iid FILE "qtplugin.json")
 public:
  explicit QTPlugin(QObject* parent = nullptr);
  ~QTPlugin();

 public:
  virtual ModuleType type() const;

 signals:

 private:
  QWidget* m_pluginW;
};

#endif  // QTPLUGIN_H
