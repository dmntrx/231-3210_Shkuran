//#ifndef CLIENTINTERFACE_H
//#define CLIENTINTERFACE_H
//#include "supercar.h"
//#include <QNetworkAccessManager>
//#include <QNetworkReply>
//#include <QNetworkRequest>
//#include <QEventLoop>
//#include <QUrl>

//class ClientInterface
//{
//public:
//    // Singleton
//    static ClientInterface* existing_object;
//    static ClientInterface* getInstance() {
//        QString root_url = "http://localhost/api/";
//        if(existing_object == nullptr) {
//            existing_object = new ClientInterface(root_url);
//        }
//        return existing_object;
//    }

//    static void removeInstance() {
//        if(existing_object)
//            delete existing_object;
//        existing_object = nullptr;
//    }

//    // методы класса для вызова restAPI
//    Supercar GetSupercar(const unsigned int id);
//    Supercar UpdateSupercar(const unsigned int id);
//    bool DeleteSupercar(const unsigned int id);
//    Supercar CreateSupercar();
//    QList<Supercar> GetSupercars();
//private:
//    ClientInterface(QString& root_url);
//    QNetworkAccessManager* m_client = nullptr;
//    QString m_root_url;
//};

//#include "client/openapi_client/OAIDefaultApi.h"
//#include "client/openapi_client/OAISupercar.h"

//class ClientInterface : public QObject {
//    Q_OBJECT
//public:
//    explicit ClientInterface(const QString& rootUrl, QObject* parent = nullptr);

//    OpenAPI::OAISupercar getSupercar(unsigned int id);
//    QList<OpenAPI::OAISupercar> listSupercars();
//    OpenAPI::OAISupercar createSupercar(const OpenAPI::OAISupercar& car);
//    OpenAPI::OAISupercar updateSupercar(unsigned int id, const OpenAPI::OAISupercar& car);
//    void deleteSupercar(unsigned int id);

//private:
//    QString m_root_url;
//};


//#endif // CLIENTINTERFACE_H

#ifndef CLIENTINTERFACE_H
#define CLIENTINTERFACE_H

#include "client/openapi_client/OAIDefaultApi.h"
#include "client/openapi_client/OAISupercar.h"
#include <QObject>
#include <QString>

class ClientInterface : public QObject {
    Q_OBJECT
public:
    // Получить единственный экземпляр синглтона
    static ClientInterface* getInstance(const QString& rootUrl = QString());

    OpenAPI::OAISupercar GetSupercar(unsigned int id);
    QList<OpenAPI::OAISupercar> listSupercars();
    OpenAPI::OAISupercar CreateSupercar(const OpenAPI::OAISupercar& car);
    OpenAPI::OAISupercar UpdateSupercar(unsigned int id, const OpenAPI::OAISupercar& car);
    void DeleteSupercar(unsigned int id);

private:
    explicit ClientInterface(const QString& rootUrl, QObject* parent = nullptr);

    static ClientInterface* m_instance;

    QString m_root_url;
};

#endif // CLIENTINTERFACE_H
