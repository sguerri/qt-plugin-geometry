#include "PGeometry.h"

#include <QSettings>

using namespace PGeometry;

void PGeometry::init(QMainWindow* window, const QString& name)
{
    const QString& sGeometry = "application/geometry" + (name == "" ? "" : "/" + name);
    const QString& sState = "application/state" + (name == "" ? "" : "/" + name);

    QObject::connect(window, &QMainWindow::destroyed, [=](){
        QSettings settings;
        settings.setValue(sGeometry, window->saveGeometry());
        settings.setValue(sState, window->saveState());
    });

    QSettings settings;
    if (settings.contains(sGeometry)) {
        window->restoreGeometry(settings.value(sGeometry).toByteArray());
    }
    if (settings.contains(sState)) {
        window->restoreState(settings.value(sState).toByteArray());
    }
}
