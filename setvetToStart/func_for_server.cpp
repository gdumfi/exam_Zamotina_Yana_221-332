#include "func_for_server.h"

/*
        //расстояние между вершинами
        const QString& nexta_str = a[(i + 1) % a_count];
        QStringList nexta_coords = nexta_str.split(',');

        bool nextxok, nextyok;
        double nextX = nexta_coords[0].toDouble(&nextxok);
        double nextY = nexta_coords[1].toDouble(&nextyok);
        //формула с доски с корнем
        double distance = qSqrt(qPow(nextX - x, 2) + qPow(nextY - y, 2));
        perimeter += distance;
*/

/*

        const QString& nextv_str = v.at((i + 1) % v_count);
        QStringList nextv_coords = nextv_str.split(',');

        bool nextxok, nextyok;
        double nextX = nextv_coords.at(0).toDouble(&nextxok);
        double nextY = nextv_coords.at(1).toDouble(&nextyok);

        double crossProduct = (x * nextY) - (nextX * y);
        area += crossProduct;
    }
    area *= 0.5;
    QByteArray result = QByteArray::number(qAbs(area));
    return result;
*/
QByteArray parsing(QString str)
{
    QStringList params;
    params.clear();
    params = str.split('@');
    QString func_name;
    func_name.clear();
    func_name = params.front();

    params.pop_front();

    if(func_name=="perimetr")
        return perimetr(params);
    else if (func_name == "square")
        return square(params);
    else
        return "Error";
}



QByteArray perimetr(const QStringList& vertices) {
    double perimeter = 0.0;
    QString perimetertxt;

    if (vertices.size() < 3) {
        perimetertxt = QString::number(perimeter);
        return perimetertxt.toUtf8();
    }

    QList<QPointF> points;


    for (const QString& vertex : vertices) {
        QStringList coordinates = vertex.split(",");
        if (coordinates.size() == 2) {
            bool xOk, yOk;
            double x = coordinates[0].toDouble(&xOk);
            double y = coordinates[1].toDouble(&yOk);
            if (xOk && yOk) {
                points.append(QPointF(x, y));
            }
        }
    }

    for (int i = 0; i < points.size(); i++) {
        const QPointF& p1 = points[i];
        const QPointF& p2 = points[(i + 1) % points.size()];


        double distance = qSqrt(qPow(p2.x() - p1.x(), 2) + qPow(p2.y() - p1.y(), 2));
        perimeter += distance;
    }
    perimetertxt = QString::number(perimeter);
    return perimetertxt.toUtf8();
}


QByteArray square(const QStringList& vertices)
{


    if (vertices.size() < 3) {
        qWarning() << "Недостаточно вершин для вычисления площади";
        return QString("0.0").toUtf8();
    }

\
    QVector<QPointF> points;
    for (const QString& vertex : vertices) {
        QStringList coords = vertex.split(",");
        if (coords.size() != 2) {
            qWarning() << "Некорректный формат координат вершины" << vertex;
            return QString("0.0").toUtf8();
        }
        bool xOk, yOk;
        qreal x = coords[0].toDouble(&xOk);
        qreal y = coords[1].toDouble(&yOk);
        if (!xOk || !yOk) {
            qWarning() << "Некорректные значения координат вершины" << vertex;
            return QString("0.0").toUtf8();
        }
        points.append(QPointF(x, y));
    }


    double area = 0.0;
    int numPoints = points.size();
    for (int i = 0; i < numPoints; ++i) {
        const QPointF& p1 = points[i];
        const QPointF& p2 = points[(i + 1) % numPoints];
        area += (p1.x() * p2.y() - p2.x() * p1.y());
    }
    area *= 0.5;
    QString aretxt = QString::number(qAbs(area));
    return aretxt.toUtf8();


}

