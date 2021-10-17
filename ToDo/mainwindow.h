#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtCore>
#include <QtGui>
#include <QMainWindow>
#include <QPainter>
#include "task.h"
#include "addtask.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

signals:
    void sendColor(const QColor color);
public slots:
    void receivetodo(const QString &task, const int time);

private slots:
    void on_pushButton_2_clicked();
    void on_actionPrimary_Color_Picker_triggered();

private:
    Ui::MainWindow *ui;
    void Write();
    QColor mColor = Qt::green;
    task* t;
    AddTask* at;

protected:
//    void closeEvent(QCloseEvent *event) override;


};
#endif // MAINWINDOW_H
