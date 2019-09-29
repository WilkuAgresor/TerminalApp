#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QCursor>
#include <QTextCodec>
#include <QtDebug>
#include <QObject>
#include <QPushButton>

#include <backend.hpp>
#include <HeatingView.hpp>

int main(int argc, char *argv[])
{
    qputenv("QT_IM_MODULE", QByteArray("qtvirtualkeyboard"));

    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);
    QGuiApplication::setOverrideCursor(QCursor(Qt::BlankCursor));
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));

    qmlRegisterType<BackEnd>("terminal.backend", 1, 0, "BackEnd");

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    qDebug() << "rootObjects size:" <<engine.rootObjects().size();

//    QObject::connect(heating, SIGNAL(buttonClicked(QString)), &salonSet, SLOT(clicked(QString)));

    Heating heating(engine.rootObjects().first());

    heating.setRoomCurTemp("salon", 28);

    heating.setRoomSetterTemperature("salon", 2800);


    return app.exec();
}
