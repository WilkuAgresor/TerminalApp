#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QCursor>
#include <QTextCodec>
#include <QtDebug>
#include <QObject>
#include <QPushButton>
#include <QNetworkDatagram>
#include <MainApp.hpp>

#include <heating/HeatingCurrentView.hpp>

int main(int argc, char *argv[])
{
    qputenv("QT_IM_MODULE", QByteArray("qtvirtualkeyboard"));  
    qRegisterMetaType<QNetworkDatagram>("QNetworkDatagram");

    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);
    QGuiApplication::setOverrideCursor(QCursor(Qt::BlankCursor));
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));

    QScopedPointer<MainApplication> mainApp(new MainApplication(&app));

    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("mainApp", mainApp.data());
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;


    qDebug() << "rootObjects size:" <<engine.rootObjects().size();

    mainApp->initiate(engine.rootObjects().first());

    return app.exec();
}
