#ifndef TASK_H
#define TASK_H

#include <QWidget>
#include <QPushButton>
#include <QCheckBox>
#include <QHBoxLayout>
#include <QLabel>
#include <QPainter>
#include <QTimer>
#include <QTime>
#include <QtCore>
#include <QtGui>

namespace Ui {
class task;
}

class task : public QWidget
{
    Q_OBJECT

public:
    explicit task(QWidget *parent = nullptr, QString todo="", int mTime = 0, QColor color = Qt::green);
    virtual void paintEvent(QPaintEvent *event);
    ~task();

public slots:
    void update();
    void receiveColor(const QColor color);
private:
    QHash<QPushButton*, QHBoxLayout*> mButtontoHboxmap;
    QHash<QCheckBox*, QLabel*> mChecktoLabelmap;
    Ui::task *ui;
    QTimer* timer;
    float mInterval = 0;
    int mtaskTime;
    QColor mColor;
private slots:
    void on_checkBox_clicked(bool checked);
    void on_pushButton_clicked();
    void on_startbtn_clicked();
    void on_resetbtn_clicked();
};

#endif // TASK_H
