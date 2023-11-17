#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "interfacemanager.h"
static QObject *UserInstance(QQmlEngine *engine, QJSEngine *scriptEngine)
{
    Q_UNUSED(engine)
    Q_UNUSED(scriptEngine)

    //qDebug() << "Creating";

    interfacemanager *m_interfacemanager = interfacemanager::getInstance();

    return m_interfacemanager;
}

int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    interfacemanager *m_interfacemanager = new interfacemanager;
    qmlRegisterSingletonType<interfacemanager>("m_interfacemanager", 1, 0, "InterfaceManager", UserInstance);

    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
        &app, [url](QObject *obj, const QUrl &objUrl) {
            if (!obj && url == objUrl)
                QCoreApplication::exit(-1);
        }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
