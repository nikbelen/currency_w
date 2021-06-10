#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "helper.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->currency_out->clear();
    QString line="01/06/2021";
    get_url(line);


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_dateEdit_dateChanged(const QDate &date)
{
    QString line = date.toString("dd/MM/yyyy");
    get_url(line);
}

void MainWindow::get_url(QString &line)
{
    QString url = "http://www.cbr.ru/scripts/XML_daily.asp?date_req=";
    url+=line;
    QNetworkAccessManager *manager = new QNetworkAccessManager();
    connect(manager, &QNetworkAccessManager::finished,this,&MainWindow::replyFinished);
    QUrl url2(url);
    QNetworkRequest g(url2);
    manager->get(g);
}

void MainWindow::replyFinished(QNetworkReply *reply)
{
    reply->deleteLater();
    ui->currency_out->clear();
    Helper helper;
    QXmlStreamReader xml(reply);
    QStringList values = helper.parseXml(xml);
    ui->currency_out->addItems(values);
}
