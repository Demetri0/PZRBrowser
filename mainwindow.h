#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtWebKit>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
private slots:
    void on_actionExit_triggered();
    void on_LineEdit_L_Url_returnPressed();
    void on_LineEdit_R_Url_returnPressed();
    void on_WebView_Left_urlChanged(const QUrl &url);
    void on_WebView_Right_urlChanged(const QUrl &url);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
