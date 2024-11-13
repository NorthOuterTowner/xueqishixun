#include "warningnocar.h"
#include "ui_warningnocar.h"

WarningNoCar::WarningNoCar(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::WarningNoCar)
{
    ui->setupUi(this);
}

WarningNoCar::~WarningNoCar()
{
    delete ui;
}
