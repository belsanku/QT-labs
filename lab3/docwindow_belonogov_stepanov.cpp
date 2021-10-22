#include "docwindow_belonogov_stepanov.h"
#include <QFileDialog>
#include <QTextStream>
#include <QMessageBox>
#include <QColor>
#include <QColorDialog>

DocWindow_Belonogov_Stepanov::DocWindow_Belonogov_Stepanov(QWidget* pwgt) : QTextEdit(pwgt)
{

}

void DocWindow_Belonogov_Stepanov::slotLoad()
{
    QString str = QFileDialog::getOpenFileName();
    if (str.isEmpty())
    {
        return;
    }

    QFile file(str);
    if (file.open(QIODevice::ReadOnly))
    {
        QTextStream stream(&file);
        setPlainText(stream.readAll());
        file.close();
    }

    m_strFileName=str;
    emit changeWindowTitle(m_strFileName);
}

void DocWindow_Belonogov_Stepanov::slotSaveAs()
{
    QString str = QFileDialog::getSaveFileName(0, m_strFileName);
    if (!str.isEmpty())
    {
        m_strFileName=str;
        slotSave();
    }
}

void DocWindow_Belonogov_Stepanov::slotSave()
{
    if (m_strFileName.isEmpty())
    {
        slotSaveAs();
        return;
    }

    QFile file(m_strFileName);

    if (file.open(QIODevice::WriteOnly))
    {
        QTextStream(&file)<<toPlainText();

        file.close();
        emit changeWindowTitle(m_strFileName);
        QMessageBox::warning(this, "Успешное сохранение", "Файл успешно сохранен,\nпримите наши поздравления,\nмы сами не ожидали");
    }
}

void DocWindow_Belonogov_Stepanov::slotColor()
{
    QColor addColor = QColorDialog::getColor();
    setTextColor(addColor);
}
