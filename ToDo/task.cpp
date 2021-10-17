#include "task.h"
#include "ui_task.h"
#include <QPainter>
#include <QDebug>

task::task(QWidget *parent, QString todo, int time, QColor color) :
    QWidget(parent),
    ui(new Ui::task)
{
    ui->setupUi(this);

    ui->label->setText(todo);
    mtaskTime = time;

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(update()));
    mColor = color;
    qDebug() << mtaskTime;
}

task::~task()
{
    delete ui;
}

void task::on_checkBox_clicked(bool checked)
{
    if(checked){
        QFont f = ui->label->font();
        f.setStrikeOut(true);
        ui->label->setFont(f);
    }

    if(!checked){
        QFont f = ui->label->font();
        f.setStrikeOut(false);
        ui->label->setFont(f);
    }
}


void task::on_pushButton_clicked()
{
    QHBoxLayout* layout = qobject_cast<QHBoxLayout*>(ui->horizontalLayout->layout());

    while(layout->count() != 0){
        QLayoutItem* item = layout->takeAt(0);
        delete item->widget();
        delete item;
    }
    delete layout;
}

void task::paintEvent(QPaintEvent *event)
{
      (void) event;

      QPixmap pix(150, 150);

      QPainter painter(&pix);

      pix.fill( Qt::white );

      painter.setBrush(Qt::black);
      painter.setRenderHint(QPainter::Antialiasing);

      QRectF outerCircle(0, 0, 150.0, 150.0);
      painter.drawEllipse(outerCircle);

      painter.setBrush(mColor);
      painter.setRenderHint(QPainter::Antialiasing);

      painter.drawPie(outerCircle,0,mInterval*16);

      painter.setBrush(Qt::white);
      painter.setRenderHint(QPainter::Antialiasing);

      QRectF innerCircle(37.5, 37.5, 75.0, 75.0);
      painter.drawEllipse(innerCircle);

      ui->timer->setPixmap(pix);

      qDebug() << mColor;

}

void task::update()
{

    float minToSec = mtaskTime * 60;
    float speed = 360 / minToSec;
    mInterval += speed;

}

void task::receiveColor(const QColor color)
{
    mColor = color;
}

void task::on_startbtn_clicked()
{
    QString status = ui->startbtn->text();


    if(status == "Start"){
        ui->startbtn->setText("Stop");

        timer->start(1000);
    }
    if(status == "Stop"){
        ui->startbtn->setText("Start");

        timer->stop();
    }
}


void task::on_resetbtn_clicked()
{
    mInterval = 0;
    ui->startbtn->setText("Start");
    timer->stop();

}

