#include "mainwindow.h"
#include "startdialog_belonogov_stepanov.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    StartDialog_Belonogov_Stepanov StartDialog;
    StartDialog.show();

    return a.exec();
}
