#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QColorDialog>

void Write(QColor color){
    QFile mFile("://save/savefile.txt.txt");

    if(!mFile.open(QFile::WriteOnly | QFile::Text)){

        qDebug() << "could not open file";
        return;
    }

    QTextStream out(&mFile);
    //out << color;

    mFile.flush();
    mFile.close();
}


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

//    connect(this, SIGNAL(sendColor(QColor)), pa, SLOT(receiveColor(QColor)));

//    QString mFilename = "C:/test/test.txt";

//    modeltodo = new QStringListModel(this);
//    QStringList listtodo;
//    QFile fIn(mFilename);
//    if(fIn.open(QFile::ReadOnly | QFile::Text)){
//        QTextStream sIn(&fIn);
//        while(!sIn.atEnd()){
//            listtodo += sIn.readLine();
//        }
//    } else{
//        qDebug() << "could not open file";
//    }
//    modeltodo->setStringList(listtodo);


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::receivetodo(const QString &todo, const int time)
{
    task* t = new task(ui->groupBox,todo, time, mColor);
    QVBoxLayout* layout = qobject_cast<QVBoxLayout*>(ui->groupBox->layout());
    layout->setEnabled(true);
    layout->insertWidget(0,t);
}



void MainWindow::on_pushButton_2_clicked()
{
    at = new AddTask(this);
    at->show();
}

void MainWindow::on_actionPrimary_Color_Picker_triggered()
{
    QColor color = QColorDialog::getColor(Qt::white, this, "Choose Color");
    if(color.isValid()){
        mColor = color;
    }
}

