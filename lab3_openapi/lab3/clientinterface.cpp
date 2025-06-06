//#include "clientinterface.h"
//#include <QJsonArray>


//ClientInterface* ClientInterface::existing_object = nullptr;

//ClientInterface::ClientInterface(QString& root_url) {
//    m_root_url = root_url;
//    m_client = new QNetworkAccessManager();
//}

//Supercar ClientInterface::CreateSupercar() {
//    QJsonObject body;
//    body["car_brand"] = "Posrche";
//    body["car_model"] = "GT3 RS 991";
//    body["brand_country"] = "Germany";
//    body["release_date"] = "2023-01-01";
//    body["max_speed"] = 310;
//    body["engine_name"] = "4.0 PDK GT3 RS";

//    QNetworkRequest request(QUrl(m_root_url + "supercar"));
//    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

//    QNetworkReply* reply = m_client->post(request, QJsonDocument(body).toJson());

//    QEventLoop loop;
//    QObject::connect(reply, &QNetworkReply::finished, &loop, &QEventLoop::quit);
//    loop.exec();

//    QByteArray response = reply->readAll();
//    Supercar created = Supercar::fromJson(response);
//    /*qDebug() << "Created:" << created*/;
//    return created;
//}

//bool ClientInterface::DeleteSupercar(const unsigned int id) {
//    QNetworkRequest request(QUrl(m_root_url + "supercar/" + QString::number(id)));
//    QNetworkReply* reply = m_client->deleteResource(request);

//    QEventLoop loop;
//    QObject::connect(reply, &QNetworkReply::finished, &loop, &QEventLoop::quit);
//    loop.exec();

//    // qDebug() << "Delete response code:" << reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();
//    return reply->error() == QNetworkReply::NoError;
//}

//Supercar ClientInterface::GetSupercar(const unsigned int id) {
//    QNetworkRequest request(QUrl(m_root_url + "supercar/" + QString::number(id)));
//    request.setHeader(
//        QNetworkRequest::ContentTypeHeader,
//        "application/json");

//    QNetworkReply * reply = m_client -> get(request);

//    QEventLoop evtLoop;
//    QObject::connect(reply, &QNetworkReply::readyRead, &evtLoop, &QEventLoop::quit);
//    QObject::connect(reply, &QNetworkReply::errorOccurred, &evtLoop, &QEventLoop::quit);
//    QObject::connect(reply, &QNetworkReply::sslErrors, &evtLoop, &QEventLoop::quit);
//    evtLoop.exec();

//    Supercar result = Supercar::fromJson(reply -> readAll());
//    return result;
//}

//QList<Supercar> ClientInterface::GetSupercars() {
//    QNetworkRequest request(QUrl(m_root_url + "supercar"));
//    QNetworkReply* reply = m_client->get(request);

//    QEventLoop loop;
//    QObject::connect(reply, &QNetworkReply::finished, &loop, &QEventLoop::quit);
//    loop.exec();

//    QByteArray response = reply->readAll();
//    QJsonDocument doc = QJsonDocument::fromJson(response);
//    QJsonArray array = doc.array();

//    QList<Supercar> result;
//    for (const QJsonValue& value : array) {
//        QJsonObject obj = value.toObject();
//        result.append(Supercar::fromJson(QJsonDocument(obj).toJson()));
//    }

//    return result;

//}

//Supercar ClientInterface::UpdateSupercar(const unsigned int id) {
//    QJsonObject body;
//    body["car_brand"] = "Posrche";
//    body["car_model"] = "GT3 RS 991";
//    body["brand_country"] = "Germany";
//    body["release_date"] = "2023-01-01";
//    body["max_speed"] = 310;
//    body["engine_name"] = "4.0 PDK GT3 RS";

//    QNetworkRequest request(QUrl(m_root_url + "supercar/" + QString::number(id)));
//    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

//    QNetworkReply* reply = m_client->sendCustomRequest(request, "PATCH", QJsonDocument(body).toJson());

//    QEventLoop loop;
//    QObject::connect(reply, &QNetworkReply::finished, &loop, &QEventLoop::quit);
//    loop.exec();

//    QByteArray response = reply->readAll();
//    Supercar updated = Supercar::fromJson(response);
//    // qDebug() << "Updated:" << updated;
//    return updated;
//}

#include "ClientInterface.h"
#include <QEventLoop>
#include <QDebug>

using namespace OpenAPI;

// Инициализация статического указателя на единственный экземпляр
ClientInterface* ClientInterface::m_instance = nullptr;

ClientInterface* ClientInterface::getInstance(const QString& rootUrl) {
    if (!m_instance) {
        QString url = rootUrl.isEmpty() ? "http://localhost:8000" : rootUrl;
        m_instance = new ClientInterface(url);
    }
    return m_instance;
}

ClientInterface::ClientInterface(const QString& rootUrl, QObject* parent)
    : QObject(parent), m_root_url(rootUrl) {}

OAISupercar ClientInterface::GetSupercar(unsigned int id) {
    OAIDefaultApi api;
    api.setNewServerForAllOperations(QUrl(m_root_url), "default", QMap<QString, OAIServerVariable>{});

    QEventLoop loop;
    OAISupercar result;

    QObject::connect(&api, &OAIDefaultApi::apiSupercarPkGetSignal,
                     [&](OAISupercar car) {
                         result = car;
                         loop.quit();
                     });

    QObject::connect(&api, &OAIDefaultApi::apiSupercarPkGetSignalE,
                     [&](OAISupercar /*summary*/, QNetworkReply::NetworkError error, QString errorStr) {
                         qWarning() << "Ошибка при getSupercar:" << error << errorStr;
                             loop.quit();
                     });


    api.apiSupercarPkGet(id);
    loop.exec();

    return result;
}


QList<OAISupercar> ClientInterface::listSupercars() {
    OAIDefaultApi api;
    api.setNewServerForAllOperations(QUrl(m_root_url), "default", QMap<QString, OAIServerVariable>{});

    QEventLoop loop;
    QList<OAISupercar> result;

    QObject::connect(&api, &OAIDefaultApi::apiSupercarGetSignal,
                     [&](QList<OAISupercar> list) {
                         result = list;
                         loop.quit();
                     });

    QObject::connect(&api, &OAIDefaultApi::apiSupercarGetSignalE,
                     [&](QList<OAISupercar> /*summary*/, QNetworkReply::NetworkError error, QString errorStr) {
                         qWarning() << "Ошибка при listSupercars:" << error << errorStr;
                             loop.quit();
                     });

    api.apiSupercarGet();
    loop.exec();

    return result;
}


OAISupercar ClientInterface::CreateSupercar(const OAISupercar& car) {
    OAIDefaultApi api;
    api.setNewServerForAllOperations(QUrl(m_root_url), "default", QMap<QString, OAIServerVariable>{});

    QEventLoop loop;
    OAISupercar result;
    bool success = false;

    QObject::connect(&api, &OAIDefaultApi::apiSupercarPostSignalFull,
                     [&](OAIHttpRequestWorker *worker) {
                         QByteArray responseData = worker->response;  // берем ответ напрямую
                         try {
                             result = OAISupercar::fromJson(responseData);  // статический метод парсинга JSON
                             success = true;
                         } catch (const std::exception &e) {
                             qWarning() << "Ошибка парсинга JSON:" << e.what();
                         }
                         loop.quit();
                     });

    QObject::connect(&api, &OAIDefaultApi::apiSupercarPostSignalErrorFull,
                     [&](OAIHttpRequestWorker *worker, QNetworkReply::NetworkError error, const QString &errorStr) {
                         Q_UNUSED(worker);
                         qWarning() << "Ошибка при createSupercar:" << error << errorStr;
                             loop.quit();
                     });

    api.apiSupercarPost(car);
    loop.exec();

    if (!success) {
        qWarning() << "Не удалось создать суперкар";
        // Можно выбросить исключение или вернуть объект по умолчанию
    }

    return result;
}


OAISupercar ClientInterface::UpdateSupercar(unsigned int id, const OAISupercar& car) {
    OAIDefaultApi api;
    api.setNewServerForAllOperations(QUrl(m_root_url), "default", QMap<QString, OAIServerVariable>{});

    QEventLoop loop;
    OAISupercar result;
    bool success = false;

    QObject::connect(&api, &OAIDefaultApi::apiSupercarPkPatchSignalFull,
                     [&](OAIHttpRequestWorker *worker) {
                         QByteArray responseData = worker->response;
                         try {
                             result = OAISupercar::fromJson(responseData);
                             success = true;
                         } catch (const std::exception &e) {
                             qWarning() << "Ошибка парсинга JSON при updateSupercar:" << e.what();
                         }
                         loop.quit();
                     });

    QObject::connect(&api, &OAIDefaultApi::apiSupercarPkPatchSignalErrorFull,
                     [&](OAIHttpRequestWorker *worker, QNetworkReply::NetworkError error, const QString &errorStr) {
                         Q_UNUSED(worker);
                         qWarning() << "Ошибка при updateSupercar:" << error << errorStr;
                             loop.quit();
                     });

    api.apiSupercarPkPatch(id, car);
    loop.exec();

    if (!success) {
        qWarning() << "Не удалось обновить суперкар";
    }

    return result;
}


void ClientInterface::DeleteSupercar(unsigned int id) {
    OAIDefaultApi api;
    api.setNewServerForAllOperations(QUrl(m_root_url), "default", QMap<QString, OAIServerVariable>{});

    QEventLoop loop;

    QObject::connect(&api, &OAIDefaultApi::apiSupercarPkDeleteSignal,
                     [&]() {
                         loop.quit();
                     });

    QObject::connect(&api, &OAIDefaultApi::apiSupercarPkDeleteSignalE,
                     [&](QNetworkReply::NetworkError error, const QString &errorStr) {
                         qWarning() << "Ошибка при deleteSupercar:" << error << errorStr;
                             loop.quit();
                     });

    api.apiSupercarPkDelete(id);
    loop.exec();
}
