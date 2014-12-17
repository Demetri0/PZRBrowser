#include "localization.h"

#include <QDebug>

Localization::Localization()
{
}

QMap<QLocale::Language,QString> Localization::readExistsLocalizations(QStringList paths)
{
//    QSet<QString> localizationList;
    QMap<QLocale::Language,QString> localizationList;
    if( paths.isEmpty() ){
        qCritical() << "Empty paths to localization";
        return localizationList;
    }

    foreach (QString path, paths) {
        QString l10n = QDir(path).path() + QDir::separator() + "l10n" + QDir::separator();
        foreach(QString fileName, QDir(l10n).entryList( QStringList("PZRBrowser*")) ){
            fileName = fileName.replace("PZRBrowser_", "");
            fileName = fileName.replace(".qm", "");
            QLocale::Language language = QLocale(fileName).language();
            localizationList.insert(language, QLocale::languageToString( language ) );
        }
    }

    return localizationList;
}

QString Localization::getFileOfLocalization(QLocale::Language lang, QStringList paths)
{
    if( paths.isEmpty() ){
        qCritical() << "Empty paths to localization";
        return QString::null;
    }

    foreach (QString path, paths) {
        QString l10n = QDir(path).path() + QDir::separator() + "l10n" + QDir::separator();
        foreach(QString fileName, QDir(l10n).entryList( QStringList("PZRBrowser*")) ){
            QString fullFileName = fileName;
            fileName.replace("PZRBrowser_", "").replace(".qm", "");
            QLocale::Language language = QLocale(fileName).language();
            if( language == lang ){
                return l10n + fullFileName;
            }
        }
    }

    qCritical() << "Localization " + QLocale::languageToString(lang) + " not found";
    return QString::null;
}

QString Localization::getQtBaseFileOfLocalization(QLocale::Language lang, QStringList paths)
{
    if( paths.isEmpty() ){
        qCritical() << "Empty paths to localization";
        return QString::null;
    }
    if( lang == QLocale::English )
        return QString::null;

    foreach (QString path, paths) {
        QString l10n = QDir(path).path() + QDir::separator() + "l10n" + QDir::separator();
        foreach(QString fileName, QDir(l10n).entryList( QStringList("qtbase_*")) ){
            QString fullFileName = fileName;
            fileName.replace("qtbase_", "").replace(".qm", "");
            QLocale::Language language = QLocale(fileName).language();
            if( language == lang ){
                return l10n + fullFileName;
            }
        }
    }

    qCritical() << "QtBase Localization " + QLocale::languageToString(lang) + " not found";
    return QString::null;
}
