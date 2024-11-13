#include "warninginput.h"
#include "ui_warninginput.h"

warningInput::warningInput(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::warningInput)
{
    ui->setupUi(this);
}

warningInput::~warningInput()
{
    delete ui;
}
