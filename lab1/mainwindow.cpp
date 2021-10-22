#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialog.h"
#include "ui_dialog.h"
#include "QFileDialog"
#include "QIODevice"
#include "QTextDocumentWriter"

void MainWindow::kek_w()
{
    Dialog *dg = new Dialog();
    dg->show();
}

void MainWindow::slotOpen()
{
    QString filename = QFileDialog::getOpenFileName(0, "Открыть Файл", QDir::currentPath(), "*.cpp *.txt");
    QFile file(filename);
    if (file.open(QIODevice::ReadOnly | QIODevice::Text));
    ui->textEdit->setPlainText(file.readAll());
}

void MainWindow::slotSave()
{
QString filename = QFileDialog::getSaveFileName(0, "Сохранить файл", QDir::currentPath(), "*.cpp *.txt");
QTextDocumentWriter writer;
writer.setFileName(filename);
writer.write(ui->textEdit->document());
}

void MainWindow::TextEditReset()
{
    ui->textEdit->clear();
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->Author, SIGNAL(triggered()), this, SLOT(kek_w()));

    QAction* pactOpen = new QAction("file open action", 0);
    pactOpen->setText("&Открыть");
    pactOpen->setShortcut(QKeySequence("CTRL+O"));
    pactOpen->setToolTip("Открытие документа");
    pactOpen->setStatusTip("Открыть файл");
    pactOpen->setWhatsThis("Открыть файл");
    pactOpen->setIcon(QPixmap("microsoft_hololens_2_6_5270D8BB6C154075AA9A2D3A12E51041.jpg"));
    connect(pactOpen, SIGNAL(triggered()), SLOT(slotOpen()));

    QAction* pactSave = new QAction("file save action", 0);
    pactSave->setText("&Сохранить");
    pactSave->setShortcut(QKeySequence("CTRL+S"));
    pactSave->setToolTip("Сохранение документа");
    pactSave->setStatusTip("Сохранить файл");
    pactSave->setWhatsThis("Сохранить файл");
    connect(pactSave, SIGNAL(triggered()), SLOT(slotSave()));

    QAction* pactClear = new QAction("clear action", 0);
    pactClear->setText("&Очистить");
    pactClear->setShortcut(QKeySequence("Delete"));
    pactClear->setToolTip("Очистка документа");
    pactClear->setStatusTip("Очистить файл");
    pactClear->setWhatsThis("Очистить файл");
    connect(pactClear, SIGNAL(triggered()), SLOT(TextEditReset()));

    QMenu* pmnuFile = new QMenu("&Файл");
    pmnuFile->addAction(pactOpen);
    pmnuFile->addAction(pactSave);
    pmnuFile->addAction(pactClear);
    menuBar()->addMenu(pmnuFile);

}

MainWindow::~MainWindow()
{
    delete ui;
}
