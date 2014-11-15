#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
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

