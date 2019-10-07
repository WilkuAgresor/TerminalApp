#include <QObject>
#include <QUdpSocket>
#include <QNetworkDatagram>
#include <QDebug>
#include <mutex>

#include <../common/sender.hpp>
#include <../common/receiver/receiver.hpp>
#include <../common/CommonDefinitions.hpp>

#include <Components.hpp>
#include <Receiver.hpp>

class MainApplication : public QObject
{
    Q_OBJECT
public:
    explicit MainApplication(QObject *parent = nullptr);
    ~MainApplication() = default;

    void initiate(QObject* rootObject);

private:
    QObject* mRootObject;
    Components* mComponents;
    TerminalReceiver* mReceiver;
};
