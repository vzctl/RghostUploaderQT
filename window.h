#ifndef WINDOW_H
#define WINDOW_H

#include <QSystemTrayIcon>
#include <QDialog>
#include "tabwidget.h"

QT_BEGIN_NAMESPACE
class QAction;
class QMenu;
QT_END_NAMESPACE

class Window : public QDialog
{
    Q_OBJECT

public:
    static Window & instance();
    static Window * shared_instance;
    void setVisible(bool visible);

signals:
    void UploadingsReceived();

protected:
    void closeEvent(QCloseEvent *event);
    void dragEnterEvent(QDragEnterEvent *event);
    void dropEvent(QDropEvent *event);
    Window();

private slots:
    void iconActivated(QSystemTrayIcon::ActivationReason reason);

public:
    void createActions();
    void createTrayIcon();

    QAction *minimizeAction;
    QAction *restoreAction;
    QAction *quitAction;

    QSystemTrayIcon *trayIcon;
    QMenu *trayIconMenu;
    TabWidget * tabWidget;
};

#endif
