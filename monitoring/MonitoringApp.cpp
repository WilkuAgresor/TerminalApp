#include <monitoring/MonitoringApp.hpp>
#include <Components.hpp>
#include <thread>
#include <chrono>
#include <QUrl>
#include <QQmlComponent>

MonitoringApp::MonitoringApp(QObject *parent, Components* components, QObject *rootView)
    : AppBase(parent, components)
    , mRootView(rootView)
{
    qDebug() << "monitoring init";
    mCamerasMainPage = mRootView->findChild<QObject*>("camerasMainPage", Qt::FindChildOption::FindChildrenRecursively);

    QMetaObject::invokeMethod(mCamerasMainPage, "play", Qt::DirectConnection);

    // QMetaObject::invokeMethod(mCamerasMainPage, "addCameraView", Qt::DirectConnection,
    //                           Q_ARG(QVariant, QVariant("camera1")),
    //                           Q_ARG(QVariant, QVariant("rtsp://admin:@192.168.100.206/stream=1")));
    // QMetaObject::invokeMethod(mCamerasMainPage, "addCameraView", Qt::DirectConnection,
    //                           Q_ARG(QVariant, QVariant("camera2")),
    //                           Q_ARG(QVariant, QVariant("rtsp://admin:@192.168.100.203/stream=1")));
    // QMetaObject::invokeMethod(mCamerasMainPage, "addCameraView", Qt::DirectConnection,
    //                           Q_ARG(QVariant, QVariant("camera3")),
    //                           Q_ARG(QVariant, QVariant("rtsp://admin:@192.168.100.201/stream=1")));
    // QMetaObject::invokeMethod(mCamerasMainPage, "addCameraView", Qt::DirectConnection,
    //                           Q_ARG(QVariant, QVariant("camera4")),
    //                           Q_ARG(QVariant, QVariant("rtsp://admin:@192.168.100.202/stream=1")));
    // QMetaObject::invokeMethod(mCamerasMainPage, "addCameraView", Qt::DirectConnection,
    //                           Q_ARG(QVariant, QVariant("camera5")),
    //                           Q_ARG(QVariant, QVariant("rtsp://admin:@192.168.100.204/stream=1")));
    // QMetaObject::invokeMethod(mCamerasMainPage, "addCameraView", Qt::DirectConnection,
    //                           Q_ARG(QVariant, QVariant("camera6")),
    //                           Q_ARG(QVariant, QVariant("rtsp://admin:@192.168.100.205/stream=1")));
    qDebug() << "monitoring finish";
}

void MonitoringApp::run()
{

    while(true)
    {
        //the running loop that reloads the video stream every 13 minutes
        std::this_thread::sleep_for(std::chrono::seconds(30));

        // if(mCamerasMainPage)
        // {

        //     if(play)
        //     {
        //         qDebug() << "start playing";

        //         QMetaObject::invokeMethod(mCamerasMainPage, "stop", Qt::QueuedConnection);
        //     }
        //     else
        //     {
        //         qDebug() << "stop playing";

        //         QMetaObject::invokeMethod(mCamerasMainPage, "play", Qt::QueuedConnection);
        //     }
        //     play = !play;
        // }
        // else
        // {
        //     qDebug() << "didn't find cameras main page object";
        // }

        // qDebug() << "OK";

    }
}
