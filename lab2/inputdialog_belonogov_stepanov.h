#ifndef INPUTDIALOG_BELONOGOV_STEPANOV_H
#define INPUTDIALOG_BELONOGOV_STEPANOV_H

#include <QDialog>
#include <QLineEdit>

class QLineEdit;

class InputDialog_Belonogov_Stepanov: public QDialog
{
    Q_OBJECT;
private:
    QLineEdit * m_ptxtFirstName;
    QLineEdit * m_ptxtLastName;
public:
    InputDialog_Belonogov_Stepanov(QWidget* pwgt = 0);

    QString firstName() const;
    QString lastName() const;
};

#endif // INPUTDIALOG_BELONOGOV_STEPANOV_H
