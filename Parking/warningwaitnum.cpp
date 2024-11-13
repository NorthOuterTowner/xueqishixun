#include "warningwaitnum.h"
#include "ui_warningwaitnum.h"

WarningWaitNum::WarningWaitNum(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::WarningWaitNum)
{
    ui->setupUi(this);
}

WarningWaitNum::~WarningWaitNum()
{
    delete ui;
}
