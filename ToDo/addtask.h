#ifndef ADDTASK_H
#define ADDTASK_H

#include <QDialog>
#include "task.h"

namespace Ui {
class AddTask;
}

class AddTask : public QDialog
{
    Q_OBJECT

public:
    explicit AddTask(QWidget *parent = nullptr);
    task* t;
    ~AddTask();
signals:
    void sendtodo(const QString &task, const int &time);

private slots:
    void on_pushButton_clicked();

    void on_dial_valueChanged(int value);

private:
    Ui::AddTask *ui;
};

#endif // ADDTASK_H
