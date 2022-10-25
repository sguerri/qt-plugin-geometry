#ifndef PGEOMETRY_H
#define PGEOMETRY_H

#include <QMainWindow>

namespace PGeometry
{
    extern void load(QMainWindow* window, const QString& name = "");
    extern void save(QMainWindow* window, const QString& name = "");
};


#endif // PGEOMETRY_H
