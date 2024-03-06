#ifndef PATH_H
#define PATH_H

#include <QApplication>
#include <QCoreApplication>

inline QString return_path() {
//    QString path = QCoreApplication::applicationDirPath() + "/../../app/";
QString path = QCoreApplication::applicationFilePath() + "/../";
    return path;
}

#endif // PATH_H
