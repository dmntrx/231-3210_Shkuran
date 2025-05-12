#ifndef CLIENTINTERFACE_H
#define CLIENTINTERFACE_H
#include "supercar.h"
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QEventLoop>
#include <QUrl>

class ClientInterface
{
public:
    // Singleton
    static ClientInterface* existing_object;
    static ClientInterface* getInstance() {
        QString root_url = "http://localhost/api/";
        if(existing_object == nullptr) {
            existing_object = new ClientInterface(root_url);
        }
        return existing_object;
    }

    static void removeInstance() {
        if(existing_object)
            delete existing_object;
        existing_object = nullptr;
    }

    // методы класса для вызова restAPI
    Supercar GetSupercar(const unsigned int id);
    Supercar UpdateSupercar(const unsigned int id);
    bool DeleteSupercar(const unsigned int id);
    Supercar CreateSupercar();
    QList<Supercar> GetSupercars();
private:
    ClientInterface(QString& root_url);
    QNetworkAccessManager* m_client = nullptr;
    QString m_root_url;
};

#endif // CLIENTINTERFACE_H
