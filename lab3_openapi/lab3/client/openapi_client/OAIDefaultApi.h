/**
 * Supercar API
 * API для управления данными о суперкарах
 *
 * The version of the OpenAPI document: 1.0.0
 *
 * NOTE: This class is auto generated by OpenAPI Generator (https://openapi-generator.tech).
 * https://openapi-generator.tech
 * Do not edit the class manually.
 */

#ifndef OAI_OAIDefaultApi_H
#define OAI_OAIDefaultApi_H

#include "OAIHelpers.h"
#include "OAIHttpRequest.h"
#include "OAIServerConfiguration.h"
#include "OAIOauth.h"

#include "OAISupercar.h"
#include <QString>

#include <QObject>
#include <QByteArray>
#include <QStringList>
#include <QList>
#include <QNetworkAccessManager>

namespace OpenAPI {

class OAIDefaultApi : public QObject {
    Q_OBJECT

public:
    OAIDefaultApi(const int timeOut = 0);
    ~OAIDefaultApi();

    void initializeServerConfigs();
    int setDefaultServerValue(int serverIndex,const QString &operation, const QString &variable,const QString &val);
    void setServerIndex(const QString &operation, int serverIndex);
    void setApiKey(const QString &apiKeyName, const QString &apiKey);
    void setBearerToken(const QString &token);
    void setUsername(const QString &username);
    void setPassword(const QString &password);
    void setTimeOut(const int timeOut);
    void setWorkingDirectory(const QString &path);
    void setNetworkAccessManager(QNetworkAccessManager* manager);
    int addServerConfiguration(const QString &operation, const QUrl &url, const QString &description = "", const QMap<QString, OAIServerVariable> &variables = QMap<QString, OAIServerVariable>());
    void setNewServerForAllOperations(const QUrl &url, const QString &description = "", const QMap<QString, OAIServerVariable> &variables =  QMap<QString, OAIServerVariable>());
    void setNewServer(const QString &operation, const QUrl &url, const QString &description = "", const QMap<QString, OAIServerVariable> &variables =  QMap<QString, OAIServerVariable>());
    void addHeaders(const QString &key, const QString &value);
    void enableRequestCompression();
    void enableResponseCompression();
    void abortRequests();
    QString getParamStylePrefix(const QString &style);
    QString getParamStyleSuffix(const QString &style);
    QString getParamStyleDelimiter(const QString &style, const QString &name, bool isExplode);


    virtual void apiSupercarGet();

    /**
    * @param[in]  pk qint32 [required]
    */
    virtual void apiSupercarPkDelete(const qint32 &pk);

    /**
    * @param[in]  pk qint32 [required]
    */
    virtual void apiSupercarPkGet(const qint32 &pk);

    /**
    * @param[in]  pk qint32 [required]
    * @param[in]  oai_supercar OAISupercar [required]
    */
    virtual void apiSupercarPkPatch(const qint32 &pk, const OAISupercar &oai_supercar);

    /**
    * @param[in]  oai_supercar OAISupercar [required]
    */
    virtual void apiSupercarPost(const OAISupercar &oai_supercar);


private:
    QMap<QString,int> _serverIndices;
    QMap<QString,QList<OAIServerConfiguration>> _serverConfigs;
    QMap<QString, QString> _apiKeys;
    QString _bearerToken;
    QString _username;
    QString _password;
    int _timeOut;
    QString _workingDirectory;
    QNetworkAccessManager* _manager;
    QMap<QString, QString> _defaultHeaders;
    bool _isResponseCompressionEnabled;
    bool _isRequestCompressionEnabled;
    OAIHttpRequestInput _latestInput;
    OAIHttpRequestWorker *_latestWorker;
    QStringList _latestScope;
    OauthCode _authFlow;
    OauthImplicit _implicitFlow;
    OauthCredentials _credentialFlow;
    OauthPassword _passwordFlow;
    int _OauthMethod = 0;

    void apiSupercarGetCallback(OAIHttpRequestWorker *worker);
    void apiSupercarPkDeleteCallback(OAIHttpRequestWorker *worker);
    void apiSupercarPkGetCallback(OAIHttpRequestWorker *worker);
    void apiSupercarPkPatchCallback(OAIHttpRequestWorker *worker);
    void apiSupercarPostCallback(OAIHttpRequestWorker *worker);

Q_SIGNALS:

    void apiSupercarGetSignal(QList<OAISupercar> summary);
    void apiSupercarPkDeleteSignal();
    void apiSupercarPkGetSignal(OAISupercar summary);
    void apiSupercarPkPatchSignal();
    void apiSupercarPostSignal();


    void apiSupercarGetSignalFull(OAIHttpRequestWorker *worker, QList<OAISupercar> summary);
    void apiSupercarPkDeleteSignalFull(OAIHttpRequestWorker *worker);
    void apiSupercarPkGetSignalFull(OAIHttpRequestWorker *worker, OAISupercar summary);
    void apiSupercarPkPatchSignalFull(OAIHttpRequestWorker *worker);
    void apiSupercarPostSignalFull(OAIHttpRequestWorker *worker);

    Q_DECL_DEPRECATED_X("Use apiSupercarGetSignalError() instead")
    void apiSupercarGetSignalE(QList<OAISupercar> summary, QNetworkReply::NetworkError error_type, QString error_str);
    void apiSupercarGetSignalError(QList<OAISupercar> summary, QNetworkReply::NetworkError error_type, const QString &error_str);
    Q_DECL_DEPRECATED_X("Use apiSupercarPkDeleteSignalError() instead")
    void apiSupercarPkDeleteSignalE(QNetworkReply::NetworkError error_type, QString error_str);
    void apiSupercarPkDeleteSignalError(QNetworkReply::NetworkError error_type, const QString &error_str);
    Q_DECL_DEPRECATED_X("Use apiSupercarPkGetSignalError() instead")
    void apiSupercarPkGetSignalE(OAISupercar summary, QNetworkReply::NetworkError error_type, QString error_str);
    void apiSupercarPkGetSignalError(OAISupercar summary, QNetworkReply::NetworkError error_type, const QString &error_str);
    Q_DECL_DEPRECATED_X("Use apiSupercarPkPatchSignalError() instead")
    void apiSupercarPkPatchSignalE(QNetworkReply::NetworkError error_type, QString error_str);
    void apiSupercarPkPatchSignalError(QNetworkReply::NetworkError error_type, const QString &error_str);
    Q_DECL_DEPRECATED_X("Use apiSupercarPostSignalError() instead")
    void apiSupercarPostSignalE(QNetworkReply::NetworkError error_type, QString error_str);
    void apiSupercarPostSignalError(QNetworkReply::NetworkError error_type, const QString &error_str);

    Q_DECL_DEPRECATED_X("Use apiSupercarGetSignalErrorFull() instead")
    void apiSupercarGetSignalEFull(OAIHttpRequestWorker *worker, QNetworkReply::NetworkError error_type, QString error_str);
    void apiSupercarGetSignalErrorFull(OAIHttpRequestWorker *worker, QNetworkReply::NetworkError error_type, const QString &error_str);
    Q_DECL_DEPRECATED_X("Use apiSupercarPkDeleteSignalErrorFull() instead")
    void apiSupercarPkDeleteSignalEFull(OAIHttpRequestWorker *worker, QNetworkReply::NetworkError error_type, QString error_str);
    void apiSupercarPkDeleteSignalErrorFull(OAIHttpRequestWorker *worker, QNetworkReply::NetworkError error_type, const QString &error_str);
    Q_DECL_DEPRECATED_X("Use apiSupercarPkGetSignalErrorFull() instead")
    void apiSupercarPkGetSignalEFull(OAIHttpRequestWorker *worker, QNetworkReply::NetworkError error_type, QString error_str);
    void apiSupercarPkGetSignalErrorFull(OAIHttpRequestWorker *worker, QNetworkReply::NetworkError error_type, const QString &error_str);
    Q_DECL_DEPRECATED_X("Use apiSupercarPkPatchSignalErrorFull() instead")
    void apiSupercarPkPatchSignalEFull(OAIHttpRequestWorker *worker, QNetworkReply::NetworkError error_type, QString error_str);
    void apiSupercarPkPatchSignalErrorFull(OAIHttpRequestWorker *worker, QNetworkReply::NetworkError error_type, const QString &error_str);
    Q_DECL_DEPRECATED_X("Use apiSupercarPostSignalErrorFull() instead")
    void apiSupercarPostSignalEFull(OAIHttpRequestWorker *worker, QNetworkReply::NetworkError error_type, QString error_str);
    void apiSupercarPostSignalErrorFull(OAIHttpRequestWorker *worker, QNetworkReply::NetworkError error_type, const QString &error_str);

    void abortRequestsSignal();
    void allPendingRequestsCompleted();

public Q_SLOTS:
    void tokenAvailable();
};

} // namespace OpenAPI
#endif
