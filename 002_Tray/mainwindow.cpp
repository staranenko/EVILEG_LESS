#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMenu>
#include <QStyle>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Tray Program");

    /* Инициализируем иконку трея, устанавливаем иконку из набора системных
     * иконок, а также задаем всплывающую подсказку
     */
    trayIcon = new QSystemTrayIcon(this);
    trayIcon->setIcon(this->style()->standardIcon(QStyle::SP_ComputerIcon));
    trayIcon->setToolTip("Tray Program" "\n"
                         "Работа со сворачиванием программы в трей");
    /* После чего создаем контекстное меню из двух пунктов */
    QMenu *menu = new QMenu(this);
    QAction *viewWindow = new QAction(tr("Развернуть окно"), this);
    QAction *quitAction = new QAction(tr("Выход"), this);

    /* Подключаем сигналы нажатий на пункты меню к соответствующим слотам.
     * Первый пункт меню разворачивает приложение из трея,
     * а второй пункт меню завершает приложение
     */
    connect(viewWindow, SIGNAL(triggered()), this, SLOT(show()));
    connect(quitAction, SIGNAL(triggered()), this, SLOT(close()));

    menu->addAction(viewWindow);
    menu->addAction(quitAction);

    /* Устанавливаем контекстное меню на иконку
     * и показываем иконку приложения в трее
     * */
    trayIcon->setContextMenu(menu);
    trayIcon->show();

    /* Также подключаем сигнал нажатия на иконку к обработчику
     * данного нажатия
     * */
    connect(trayIcon, SIGNAL(activated(QSystemTrayIcon::ActivationReason)),
            this, SLOT(iconActivated(QSystemTrayIcon::ActivationReason)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

/* Метод который обрабатывает событие закрытия окна приложения
 * */
void MainWindow::closeEvent(QCloseEvent *event)
{
    /* Если окно видимо и чекбокс отмечен, то завершение приложения
     * игнорируется, а окно просто скрывается, что сопровождается
     * соответствующим всплывающим сообщением
     * */
    if(this->isVisible() && ui->trayCheckBox->isChecked()){
        event->ignore();
        this->hide();
        QSystemTrayIcon::MessageIcon icon = QSystemTrayIcon::MessageIcon(QSystemTrayIcon::Information);

        trayIcon->showMessage("Tray Program",
                              tr("Приложение свернуто в трей. Для того чтобы, "
                                 "развернуть окно приложения, щелкните по иконке приложения в трее"),
                              icon,
                              2000);
    }
}

/* Метод, который обрабатывает нажатие на иконку приложения в трее
 * */
void MainWindow::iconActivated(QSystemTrayIcon::ActivationReason reason)
{
    switch (reason) {
    case QSystemTrayIcon::Trigger:
        /* Событие игнорируется в том случае, если чекбокс не отмечен
         * */
        if(ui->trayCheckBox->isChecked()){
            /* иначе, если окно программы видимо, то оно скрывается,
             * и наоборот, если скрыто, то разворачивается на экран
             * */
            if(!this->isVisible()){
                this->show();
            } else {
                this->hide();
            }
        }
        break;
    default:
        break;
    }
}
