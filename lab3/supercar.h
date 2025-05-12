#ifndef Supercar_H
#define Supercar_H

#include <QString>
#include <QJsonDocument>
#include <QJsonObject>


class Supercar
{
public:
    Supercar();
    Supercar(int id, QString car_brand, QString car_model, QString brand_country, QString release_date, int max_speed, QString engine_name);
    static Supercar fromJson(const QByteArray &jsonData);

    friend QDebug operator<<(QDebug dbg, const Supercar &p);
private:
    unsigned int id;
    QString car_brand;
    QString car_model;
    QString brand_country;
    QString release_date;
    unsigned int max_speed;
    QString engine_name;
};

#endif // Supercar_H
