#include "mainwindow.h"

#include <TypeW.h>

#include <QDebug>
#include <QDir>
#include <QMessageBox>
#include <QPluginLoader>

#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow), m_typew{new TypeW} {
  ui->setupUi(this);
  m_typew->setName("haha");

  if (!loadPlugin()) {
    QMessageBox::warning(this, MainWindow::tr("错误"),
                         MainWindow::tr("无法加载插件!"));
  }
}

MainWindow::~MainWindow() { delete ui; }

bool MainWindow::loadPlugin() {
  QDir dir(QCoreApplication::applicationDirPath() + "/plugins");

  foreach (QString fileName, dir.entryList(QDir::Files)) {
    qDebug() << fileName;
    QPluginLoader pluginLoader(dir.absoluteFilePath(fileName));
    QObject *plugin = pluginLoader.instance();
    if (plugin) {
      m_plugW = qobject_cast<Base *>(plugin);
      if (m_plugW) {
        return true;
      }
    }
  }
  return false;
}

void MainWindow::on_pushButton_clicked() {
  if (m_plugW) {
    auto name = m_plugW->name();
    auto w = m_plugW->editor();
    ui->tabWidget->addTab(w, name);
  }
}
