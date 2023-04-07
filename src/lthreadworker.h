#ifndef THREADWORKER_H
#define THREADWORKER_H

#include <QThread>

class LThreadWorker : public QObject
{
    Q_OBJECT

public:
    explicit LThreadWorker(QObject *parent);

    bool autoDelete() const { return m_autoDelete; }

    void setAutoDelete(const bool autoDelete) { m_autoDelete = autoDelete; }

    bool isThreadRunning() const;

    void startThread(const QString &name = QString());

    void stopThread();

    void terminateThread();

signals:
    void threadStarted();

    void threadFinished();

    void threadTerminated();

private:
    QObject *m_parent;
    QThread *m_thread;

    QAtomicInt m_autoDelete;
};

#endif // THREADWORKER_H
