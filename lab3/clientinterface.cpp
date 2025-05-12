#include "clientinterface.h"
#include <QJsonArray>


ClientInterface* ClientInterface::existing_object = nullptr;

ClientInterface::ClientInterface(QString& root_url) {
    m_root_url = root_url;
    m_client = new QNetworkAccessManager();
}

Supercar ClientInterface::CreateSupercar() {
    QJsonObject body;
    body["car_brand"] = "Posrche";
    body["car_model"] = "GT3 RS 991";
    body["brand_country"] = "Germany";
    body["release_date"] = "2023-01-01";
    body["max_speed"] = 310;
    body["engine_name"] = "4.0 PDK GT3 RS";

    QNetworkRequest request(QUrl(m_root_url + "supercar"));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    QNetworkReply* reply = m_client->post(request, QJsonDocument(body).toJson());

    QEventLoop loop;
    QObject::connect(reply, &QNetworkReply::finished, &loop, &QEventLoop::quit);
    loop.exec();

    QByteArray response = reply->readAll();
    Supercar created = Supercar::fromJson(response);
    /*qDebug() << "Created:" << created*/;
    return created;
}

bool ClientInterface::DeleteSupercar(const unsigned int id) {
    QNetworkRequest request(QUrl(m_root_url + "supercar/" + QString::number(id)));
    QNetworkReply* reply = m_client->deleteResource(request);

    QEventLoop loop;
    QObject::connect(reply, &QNetworkReply::finished, &loop, &QEventLoop::quit);
    loop.exec();

    // qDebug() << "Delete response code:" << reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();
    return reply->error() == QNetworkReply::NoError;
}

Supercar ClientInterface::GetSupercar(const unsigned int id) {
    QNetworkRequest request(QUrl(m_root_url + "supercar/" + QString::number(id)));
    request.setHeader(
        QNetworkRequest::ContentTypeHeader,
        "application/json");

    QNetworkReply * reply = m_client -> get(request);

    QEventLoop evtLoop;
    QObject::connect(reply, &QNetworkReply::readyRead, &evtLoop, &QEventLoop::quit);
    QObject::connect(reply, &QNetworkReply::errorOccurred, &evtLoop, &QEventLoop::quit);
    QObject::connect(reply, &QNetworkReply::sslErrors, &evtLoop, &QEventLoop::quit);
    evtLoop.exec();

    Supercar result = Supercar::fromJson(reply -> readAll());
    return result;
}

QList<Supercar> ClientInterface::GetSupercars() {
    QNetworkRequest request(QUrl(m_root_url + "supercar"));
    QNetworkReply* reply = m_client->get(request);

    QEventLoop loop;
    QObject::connect(reply, &QNetworkReply::finished, &loop, &QEventLoop::quit);
    loop.exec();

    QByteArray response = reply->readAll();
    QJsonDocument doc = QJsonDocument::fromJson(response);
    QJsonArray array = doc.array();

    QList<Supercar> result;
    for (const QJsonValue& value : array) {
        QJsonObject obj = value.toObject();
        result.append(Supercar::fromJson(QJsonDocument(obj).toJson()));
    }

    return result;

}

Supercar ClientInterface::UpdateSupercar(const unsigned int id) {
    QJsonObject body;
    body["car_brand"] = "Posrche";
    body["car_model"] = "GT3 RS 991";
    body["brand_country"] = "Germany";
    body["release_date"] = "2023-01-01";
    body["max_speed"] = 310;
    body["engine_name"] = "4.0 PDK GT3 RS";

    QNetworkRequest request(QUrl(m_root_url + "supercar/" + QString::number(id)));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    QNetworkReply* reply = m_client->sendCustomRequest(request, "PATCH", QJsonDocument(body).toJson());

    QEventLoop loop;
    QObject::connect(reply, &QNetworkReply::finished, &loop, &QEventLoop::quit);
    loop.exec();

    QByteArray response = reply->readAll();
    Supercar updated = Supercar::fromJson(response);
    // qDebug() << "Updated:" << updated;
    return updated;
}
