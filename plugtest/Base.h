#ifndef BASE_H
#define BASE_H

#include <QCoreApplication>

enum ModuleType { eType1 = 0, eType2, eType3, eType4 };

class Base {
  Q_DECLARE_TR_FUNCTIONS(Base)
 public:
  Base();
  ~Base();

 public:
  virtual ModuleType type() const = 0;

 public:
  // get
  QString name() const;
  QWidget* editor() const;

  // set
  void setName(const QString& str);
  void setWidget(QWidget* w);

 private:
  QString m_name;
  QWidget* m_widget;
};

#define PlugInterface_iid "YD.PluginInterface"

QT_BEGIN_NAMESPACE
Q_DECLARE_INTERFACE(Base, PlugInterface_iid)
QT_END_NAMESPACE

#endif  // BASE_H
