#include "qtplugin.h"

#include <QPushButton>
#include <QVBoxLayout>
#include <QWidget>

QTPlugin::QTPlugin(QObject *parent) : QObject(parent), m_pluginW{new QWidget} {
  auto btn = new QPushButton(m_pluginW);
  auto vlay = new QVBoxLayout(m_pluginW);
  vlay->addStretch();
  vlay->addWidget(btn);
  vlay->addStretch();

  setWidget(m_pluginW);
  setName("QTPlugin");
}

QTPlugin::~QTPlugin() { delete m_pluginW; }

ModuleType QTPlugin::type() const { return ModuleType::eType2; }
