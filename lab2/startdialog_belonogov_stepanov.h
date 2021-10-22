#ifndef STARTDIALOG_BELONOGOV_STEPANOV_H
#define STARTDIALOG_BELONOGOV_STEPANOV_H

#include <QWidget>
#include <QPushButton>
#include <QMessageBox>
#include "inputdialog_belonogov_stepanov.h"

class StartDialog_Belonogov_Stepanov : public QPushButton
{
    Q_OBJECT
public:
    StartDialog_Belonogov_Stepanov(QWidget * pwgt = 0) : QPushButton("Нажми", pwgt)
    {
        connect(this, SIGNAL(clicked()), SLOT(slotButtonClicked()));
    }
public slots:
    void slotButtonClicked()
    {
        InputDialog_Belonogov_Stepanov* pInputDialog = new InputDialog_Belonogov_Stepanov;
        if (pInputDialog->exec() == QDialog::Accepted)
        {
         QMessageBox::information(0,
                                  "Ваша информация: ",
                                  "Имя: " + pInputDialog->firstName()
                                  + "\nФамилия: " + pInputDialog->lastName());
        }
        delete pInputDialog;
    }
};

#endif // STARTDIALOG_BELONOGOV_STEPANOV_H
