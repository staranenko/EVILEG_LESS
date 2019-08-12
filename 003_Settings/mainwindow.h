#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QCloseEvent>
#include <QSystemTrayIcon>
#include <QAction>
#include <QSettings>
#include <QMessageBox>

/* Defining */
#define ORGANIZATION_NAME "EVELEG"
#define ORGANIZATION_DOMAIN "www.eweleg.com"
#define APPLICATION_NAME "QSettings Program"

#define SETTINGS_TRAY "settings/tray"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
    void closeEvent(QCloseEvent * event);

private slots:
    void iconActivated(QSystemTrayIcon::ActivationReason reason);

    /* Слот для кнопки, запускающей сохранение настроек приложения
     * */
    void on_saveButton_clicked();

private:
    Ui::MainWindow *ui;
    QSystemTrayIcon *trayIcon;
};
#endif // MAINWINDOW_H
