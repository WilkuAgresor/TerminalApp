#include <QApplication>
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

#include <iostream>
#include <QDateTime>


static const QtMessageHandler QT_DEFAULT_MESSAGE_HANDLER = qInstallMessageHandler(0);

void myMessageOutput(QtMsgType type, const QMessageLogContext &context, const QString &msg)
{
    QString finalLogMessage = QDateTime::currentDateTime().toString(Qt::ISODateWithMs)+ " | " + msg;

    (*QT_DEFAULT_MESSAGE_HANDLER)(type, context, finalLogMessage);
}

int main(int argc, char *argv[])
{
    qputenv("QT_IM_MODULE", QByteArray("qtvirtualkeyboard"));  
    qRegisterMetaType<QNetworkDatagram>("QNetworkDatagram");

    QGuiApplication::setAttribute(Qt::AA_ShareOpenGLContexts, true);
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QApplication app(argc, argv);
    qInstallMessageHandler(myMessageOutput);

    QApplication::setOverrideCursor(QCursor(Qt::BlankCursor));
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
