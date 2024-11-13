#ifndef WARNINGSAMECAR_H
#define WARNINGSAMECAR_H

#include <QDialog>

namespace Ui {
class WarningSameCar;
}

class WarningSameCar : public QDialog
{
    Q_OBJECT

public:
    explicit WarningSameCar(QWidget *parent = nullptr);
    ~WarningSameCar();

private:
    Ui::WarningSameCar *ui;
};

#endif // WARNINGSAMECAR_H
