#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    app.setOrganizationName("PZR");
    app.setOrganizationDomain("https://pomzr.com/");
    app.setApplicationName("PZRBrowser");
    app.setApplicationVersion("0.0.1 Pre-Alpha");
    app.setApplicationDisplayName( QObject::tr("PZR Browser") );

    MainWindow w;
    w.show();

    return app.exec();
}
