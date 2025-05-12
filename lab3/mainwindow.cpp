#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "supercar.h"

#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QUrl>
#include <QEventLoop>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    m_interface = ClientInterface::getInstance();
    ClientInterface* interface2 = ClientInterface::getInstance();
    ClientInterface* interface3 = ClientInterface::getInstance();

    qDebug() << "m_interface = " << m_interface;
    qDebug() << "interface2 = " << interface2;
    qDebug() << "interface3 = " << interface3;

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_getButton_clicked()
{
    Supercar result = m_interface -> GetSupercar(1);
    qDebug() << result;
}



void MainWindow::on_createButton_clicked()
{
    Supercar result = m_interface -> CreateSupercar();
    qDebug() << result;
}


void MainWindow::on_listButton_clicked()
{
    QList<Supercar> result = m_interface -> GetSupercars();
    for (const Supercar& p : result)
        qDebug() << p;
}


void MainWindow::on_updateButton_clicked()
{
    Supercar result = m_interface -> UpdateSupercar(1002);
    qDebug() << result;
}


void MainWindow::on_deleteButton_clicked()
{
    bool result = m_interface -> DeleteSupercar(5);
    qDebug() << result;
}

