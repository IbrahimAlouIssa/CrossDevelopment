#include "addtask.h"
#include "ui_addtask.h"
#include "mainwindow.h"

AddTask::AddTask(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddTask)
{
    ui->setupUi(this);

    connect(this, SIGNAL(sendtodo(QString, int)), parent, SLOT(receivetodo(QString, int)));

    this->setAttribute(Qt::WA_DeleteOnClose);

}

AddTask::~AddTask()
{
    delete ui;
}

void AddTask::on_pushButton_clicked()
{
    QString input = ui->lineEdit->text();
    int time = ui->label->text().toInt();
    emit sendtodo(input, time);

    this->close();

}


void AddTask::on_dial_valueChanged(int value)
{
    ui->label->setText(QVariant(value).toString());
}

