#include "warningid.h"
#include "ui_warningid.h"

WarningID::WarningID(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::WarningID)
{
    ui->setupUi(this);
}

WarningID::~WarningID()
{
    delete ui;
}
