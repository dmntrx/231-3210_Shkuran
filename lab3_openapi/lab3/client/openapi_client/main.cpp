#include <QCoreApplication>
#include <QDebug>
#include "OAISupercar.h"

int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);

    auto api = std::make_shared<OpenAPI::OAISupercar>();
    api->setBasePath("http://localhost:8000");

    QObject::connect(api.get(), &OpenAPI::OAISupercar::getApiSupercarSignal,
                     [](QList<OpenAPI::OAI_Supercar> supercars){
                         qDebug() << "Получено суперкаров:" << supercars.length();
                     });

    api->getApiSupercar();

    return a.exec();
}
