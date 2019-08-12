#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QCloseEvent>
#include <QSystemTrayIcon>
#include <QAction>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
    /* Виртуальная функция родительского класса в нашем классе
     * переопределяется для изменения поведения приложения,
     * чтобы оно сворачивалось в трей, когда мы этого хотим
     */
    void closeEvent(QCloseEvent *event);

private slots:
    /* Слот, который будет принимать сгнал от события
     * нажатия на иконку проложения в трее
     */
    void iconActivated(QSystemTrayIcon::ActivationReason reason);

private:
    Ui::MainWindow *ui;
    /* Объявляем объект будущей иконки приоржения для трея */
    QSystemTrayIcon *trayIcon;
};

#endif // MAINWINDOW_H
