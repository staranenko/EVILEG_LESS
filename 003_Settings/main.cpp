#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    /* Для адекватной регистрации приложения в операционной системе
     * необходимо установить название организации, домен организации,
     * а также название приложения.
     * Все настройки будут храниться в операционной системе под этими
     * учетными данными приложения
     * */

    QCoreApplication::setOrganizationName(ORGANIZATION_NAME);
    QCoreApplication::setOrganizationDomain(ORGANIZATION_DOMEN);
    QCoreApplication::setApplicationName(APPLIKATION_NAME);

    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
