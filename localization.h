#ifndef LOCALIZATION_H
#define LOCALIZATION_H

#include <QDir>
#include <QLocale>
#include <QStringList>

class Localization
{
public:
    Localization();
    static QMap<QLocale::Language,QString> readExistsLocalizations(QStringList paths);
    static QString getFileOfLocalization(QLocale::Language, QStringList paths);
    static QString getQtBaseFileOfLocalization(QLocale::Language, QStringList paths);
    ~Localization();
};

#endif // LOCALIZATION_H
