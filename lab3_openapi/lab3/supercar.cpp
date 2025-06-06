#include "supercar.h"

Supercar::Supercar() {

}

Supercar::Supercar(int id, QString car_brand, QString car_model, QString brand_country, QString release_date, int max_speed, QString engine_name) {
    this ->id = id;
    this ->car_brand = car_brand;
    this ->car_model = car_model;
    this ->brand_country = brand_country;
    this ->release_date = release_date;
    this ->max_speed = max_speed;
    this ->engine_name = engine_name;
}

Supercar Supercar::fromJson(const QByteArray &jsonData) {
    qDebug() << "JSON data size:" << jsonData.size();
    qDebug() << "JSON data:" << jsonData;

//    QJsonDocument doc = QJsonDocument::fromJson(jsonData);
//    if (!doc.isObject()) {
//        throw std::runtime_error("Invalid JSON format");
//    }

    QJsonParseError parseError;
    QJsonDocument doc = QJsonDocument::fromJson(jsonData, &parseError);
    if (parseError.error != QJsonParseError::NoError) {
        qWarning() << "JSON parse error:" << parseError.errorString();
        throw std::runtime_error(parseError.errorString().toStdString());
    }
    if (!doc.isObject()) {
        throw std::runtime_error("Invalid JSON format: not an object");
    }

    QJsonObject obj = doc.object();
    int id = obj.value("id").toInt();
    QString car_brand = obj.value("car_brand").toString();
    QString car_model = obj.value("car_model").toString();
    QString brand_country = obj.value("brand_country").toString();
    QString release_date = obj.value("release_date").toString();
    int max_speed = obj.value("max_speed").toInt();
    QString engine_name = obj.value("engine_name").toString();

    return Supercar(id, car_brand, car_model, brand_country, release_date, max_speed, engine_name);
}

QDebug operator<<(QDebug dbg, const Supercar &p) {
    dbg.nospace() << "Supercar("
                  << "id: " << p.id
                  << ", car_brand: " << p.car_brand
                  << ", car_model: " << p.car_model
                  << ", brand_country: " << p.brand_country
                  << ", release_date: " << p.release_date
                  << ", max_speed: " << p.max_speed
                  << ", engine_name: " << p.engine_name
                  << ")";
    return dbg.space();
}
