#include <monitoring/MonitoringApp.hpp>
#include <Components.hpp>
#include <thread>
#include <chrono>

MonitoringApp::MonitoringApp(QObject *parent, Components* components, QObject *rootView)
    : AppBase(parent, components)
    , mRootView(rootView)
{
    mCamerasMainPage = mRootView->findChild<QObject*>("camerasMainPage", Qt::FindChildOption::FindChildrenRecursively);
}

void MonitoringApp::run()
{
    while(true)
    {
        //the running loop that reloads the video stream every 13 minutes
        std::this_thread::sleep_for(std::chrono::minutes(13));

        if(mCamerasMainPage)
        {
            qDebug() << "refresh video player";

            QMetaObject::invokeMethod(mCamerasMainPage, "refreshVideoPlayer", Qt::QueuedConnection);
        }
        else
        {
            qDebug() << "didn't find cameras main page object";
        }
    }
}
