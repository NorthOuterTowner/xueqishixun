#include "warningsamecar.h"
#include "ui_warningsamecar.h"

WarningSameCar::WarningSameCar(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::WarningSameCar)
{
    ui->setupUi(this);
}

WarningSameCar::~WarningSameCar()
{
    delete ui;
}
