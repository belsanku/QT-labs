#ifndef SDIPROGRAM_BELONOGOV_STEPANOV_H
#define SDIPROGRAM_BELONOGOV_STEPANOV_H

#include <QMainWindow>
#include <QtWidgets>
#include "docwindow_belonogov_stepanov.h"
#include "sdiprogram_belonogov_stepanov.h"

class SDIProgram_Belonogov_Stepanov : public QMainWindow
{
    Q_OBJECT

public:
    explicit SDIProgram_Belonogov_Stepanov(QWidget *pwgt = 0) : QMainWindow(pwgt)
    {
        QMenu* pmnuFile = new QMenu("&File");
        QMenu* pmnuHelp = new QMenu("&Help");
        DocWindow_Belonogov_Stepanov* pdoc = new DocWindow_Belonogov_Stepanov;
        pmnuFile->addAction("&Open...",
                            pdoc,
                            SLOT(slotLoad()),
                            QKeySequence("CTRL+O"));
        pmnuFile->addAction("&Save",
                            pdoc,
                            SLOT(slotSave()),
                            QKeySequence("CTRL+S"));
        pmnuFile->addAction("&Save As...",
                            pdoc,
                            SLOT(slotSaveAs()),
                            QKeySequence("CTRL+V"));
        pmnuFile->addAction("&Color",
                            pdoc,
                            SLOT(slotColor()),
                            QKeySequence("F2"));
        pmnuFile->addAction("&Quit",
                            qApp,
                            SLOT(quit()));
        pmnuHelp->addAction("&About",
                            this,
                            SLOT(slotAbout()),
                            QKeySequence("F1"));

        menuBar()->addMenu(pmnuFile);
        menuBar()->addMenu(pmnuHelp);

        setCentralWidget(pdoc);

        connect(pdoc,
                SIGNAL(changeWindowTitle(const QString&)),
                SLOT(slotChangeWindowTitle(const QString&)));

        statusBar()->showMessage("Ready", 2000);
    }
public slots:
    void slotAbout()
    {
        QMessageBox::warning(this, "About", "Студенты группы ИП-912:\nБелоногов и Степанов");
    }

    void slotChangeWindowTitle(const QString& str)
    {
        setWindowTitle(str);
    }

};

#endif // SDIPROGRAM_BELONOGOV_STEPANOV_H
