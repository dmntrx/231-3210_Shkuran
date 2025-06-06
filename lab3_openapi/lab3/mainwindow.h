#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "clientinterface.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_createButton_clicked();

    void on_listButton_clicked();

    void on_getButton_clicked();

    void on_updateButton_clicked();

    void on_deleteButton_clicked();

private:
    Ui::MainWindow *ui;
    ClientInterface* m_interface = nullptr;
};
#endif // MAINWINDOW_H
