#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class TypeW;
class Base;

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

private slots:
  void on_pushButton_clicked();

private:
  bool loadPlugin();

 private:
  Ui::MainWindow *ui;
  TypeW *m_typew;
  Base *m_plugW;
};
#endif  // MAINWINDOW_H
