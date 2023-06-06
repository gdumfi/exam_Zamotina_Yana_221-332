#ifndef FUNC_FOR_SERVER_H
#define FUNC_FOR_SERVER_H
#include <QTcpSocket>
#include <QByteArray>
#include <QString>
#include <QList>
#include <QStringList>
#include <QDebug>
#include <QPointF>
#include <QtCore/QPointF>
#include <QtCore/QStringList>
#include <QtCore/QVector>
QByteArray parsing(QString str);

QByteArray perimetr(const QStringList& vertices);
QByteArray square(const QStringList& vertices);


#endif // FUNC_FOR_SERVER_H
