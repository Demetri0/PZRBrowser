#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "localization.h"

#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    QLocale::Language language = QLocale::Russian;
    QString appDirPath = qApp->applicationDirPath() + QDir::separator();
    qtTr.load( Localization::getQtBaseFileOfLocalization( language, QStringList() << appDirPath ) );
    appTr.load( Localization::getFileOfLocalization( language, QStringList() << appDirPath ) );

    qApp->installTranslator(&qtTr);
    qApp->installTranslator(&appTr);
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionExit_triggered()
{
    qApp->exit(0);
}

void MainWindow::on_LineEdit_L_Url_returnPressed()
{
    QString url = ui->LineEdit_L_Url->text();
    if( url.toUpper().startsWith("http") == false )
        url = "http://" + url;
    ui->WebView_Left->setUrl( QUrl( url ) );
}

void MainWindow::on_LineEdit_R_Url_returnPressed()
{
    QString url = ui->LineEdit_R_Url->text();
    if( url.toUpper().startsWith("http") == false )
        url = "http://" + url;
    ui->WebView_Right->setUrl( QUrl( url ) );
}

void MainWindow::on_WebView_Left_urlChanged(const QUrl &url)
{
    ui->LineEdit_L_Url->setText( url.toString() );
}

void MainWindow::on_WebView_Right_urlChanged(const QUrl &url)
{
    ui->LineEdit_R_Url->setText( url.toString() );
}

