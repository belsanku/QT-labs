#ifndef DOCWINDOW_BELONOGOV_STEPANOV_H
#define DOCWINDOW_BELONOGOV_STEPANOV_H

#include <QTextEdit>

class DocWindow_Belonogov_Stepanov : public QTextEdit
{
        Q_OBJECT
private:
    QString m_strFileName;
public:
    DocWindow_Belonogov_Stepanov(QWidget* pwgt = 0);
signals:
    void changeWindowTitle(const QString&);
public slots:
    void slotLoad();
    void slotSave();
    void slotSaveAs();
    void slotColor();
};

#endif // DOCWINDOW_BELONOGOV_STEPANOV_H
