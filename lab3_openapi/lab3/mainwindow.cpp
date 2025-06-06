#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "supercar.h"

#include "client/openapi_client/OAIDefaultApi.h"
#include "client/openapi_client/OAISupercar.h"

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

Supercar convertToSupercar(const OpenAPI::OAISupercar& oaiCar) {
    return Supercar(
        oaiCar.getId(),
        oaiCar.getCarBrand(),
        oaiCar.getCarModel(),
        oaiCar.getBrandCountry(),
        oaiCar.getReleaseDate().toString(Qt::ISODate),  // преобразуем QDate → QString
        oaiCar.getMaxSpeed(),
        oaiCar.getEngineName()
        );
}



void MainWindow::on_getButton_clicked()
{
    Supercar result = convertToSupercar(m_interface->GetSupercar(1));
    qDebug() << result;

}



void MainWindow::on_createButton_clicked()
{
    // Создаем и заполняем OAISupercar
    OpenAPI::OAISupercar newCar;
    newCar.setId(123);  // если id нужен
    newCar.setCarBrand("Bugatti");
    newCar.setCarModel("Chiron");
    newCar.setBrandCountry("France");
    newCar.setReleaseDate(QDate::fromString("2022-04-01", Qt::ISODate));
    newCar.setMaxSpeed(420);
    newCar.setEngineName("W16");

    // Отправляем в интерфейс
    OpenAPI::OAISupercar oaiResult = m_interface->CreateSupercar(newCar);

    // Преобразуем в локальный тип Supercar, если нужно
    Supercar result = convertToSupercar(oaiResult);

    qDebug() << result;
}



void MainWindow::on_listButton_clicked()
{
    QList<OpenAPI::OAISupercar> oaiList = m_interface->listSupercars();
    QList<Supercar> result;
    for (const auto& oaiCar : oaiList) {
        result.append(convertToSupercar(oaiCar));
    }

    for (const Supercar& car : result) {
        qDebug() << car;
    }
}



void MainWindow::on_updateButton_clicked()
{
    // Создаем OAISupercar с нужными данными для обновления (например, так)
    OpenAPI::OAISupercar updatedCar;
    updatedCar.setCarBrand("UpdatedBrand");
    // ... и т.д.

    OpenAPI::OAISupercar oaiResult = m_interface->UpdateSupercar(1002, updatedCar);
    Supercar result = convertToSupercar(oaiResult);

    qDebug() << result;
}



void MainWindow::on_deleteButton_clicked()
{
    m_interface->DeleteSupercar(7);
    qDebug() << "Deleted car with id 7";
}

