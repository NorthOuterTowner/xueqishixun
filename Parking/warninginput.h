#ifndef WARNINGINPUT_H
#define WARNINGINPUT_H

#include <QDialog>

namespace Ui {
class warningInput;
}

class warningInput : public QDialog
{
    Q_OBJECT

public:
    explicit warningInput(QWidget *parent = nullptr);
    ~warningInput();

private:
    Ui::warningInput *ui;
};

#endif // WARNINGINPUT_H
