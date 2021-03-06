#ifndef HELPER_H
#define HELPER_H

#include <QObject>
#include <QVector>
#include <QStringList>
#include <QXmlStreamReader>
#include <QNetworkAccessManager>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QNetworkReply>
#include <QUrl>

class Helper : public QObject
{
    Q_OBJECT
public:
    explicit Helper(QObject *parent = nullptr);
    QStringList values;

signals:

public slots:
     QString parseOneItem(QXmlStreamReader &xml);
     QStringList parseXml(QXmlStreamReader &xml);

};

#endif // HELPER_H
