#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDate>
#include <QObject>
#include <QVector>
#include <QStringList>
#include <QXmlStreamReader>
#include <QNetworkAccessManager>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QNetworkReply>
#include <QUrl>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_dateEdit_dateChanged(const QDate &date);
    void replyFinished(QNetworkReply *reply);

private:
    Ui::MainWindow *ui;
    void get_url(QString &line);
    void finished(QNetworkReply &reply);

};
#endif // MAINWINDOW_H
