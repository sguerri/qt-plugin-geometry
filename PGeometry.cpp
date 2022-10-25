#include "PGeometry.h"

#include <QSettings>
#include <QDebug>

using namespace PGeometry;

void PGeometry::load(QMainWindow* window, const QString& name)
{
    const QString& sGeometry = "application/geometry" + (name == "" ? "" : "/" + name);
    const QString& sState = "application/state" + (name == "" ? "" : "/" + name);

    /*
    QObject::connect(window, &QMainWindow::destroyed, window, [=](QObject* w){
        if (w == nullptr) return;
        QSettings settings;
        settings.setValue(sState, window->saveState());
        settings.setValue(sGeometry, window->saveGeometry());
    });
    */

    QSettings settings;
    if (settings.contains(sGeometry)) {
        window->restoreGeometry(settings.value(sGeometry).toByteArray());
    }
    if (settings.contains(sState)) {
        window->restoreState(settings.value(sState).toByteArray());
    }
}

void PGeometry::save(QMainWindow* window, const QString& name)
{
    const QString& sGeometry = "application/geometry" + (name == "" ? "" : "/" + name);
    const QString& sState = "application/state" + (name == "" ? "" : "/" + name);

    QSettings settings;
    settings.setValue(sState, window->saveState());
    settings.setValue(sGeometry, window->saveGeometry());
}
