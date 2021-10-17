#include "settings.h"
#include "ui_settings.h"

settings::settings(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::settings)
{
    ui->setupUi(this);

    connect(ui->primarylbl, SIGNAL(clicked()),
            this, SLOT(primaryColorPicker()));
}

void settings::primaryColorPicker()
{
    qDebug() << "hey";
}

settings::~settings()
{
    delete ui;
}
