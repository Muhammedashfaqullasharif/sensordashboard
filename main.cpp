#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <SensorModel.h>
#include <SensorController.h>
#include <QQmlContext>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    SensorModel sensorModel;
    SensorController controller(&sensorModel);

    QQmlApplicationEngine engine;
    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    engine.loadFromModule("sensormonitor", "Main");

    engine.rootContext()->setContextProperty("sensorModel", &sensorModel);

    return app.exec();
}
