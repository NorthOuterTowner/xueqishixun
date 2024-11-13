#ifndef WARNINGNOCAR_H
#define WARNINGNOCAR_H

#include <QDialog>

namespace Ui {
class WarningNoCar;
}

class WarningNoCar : public QDialog
{
    Q_OBJECT

public:
    explicit WarningNoCar(QWidget *parent = nullptr);
    ~WarningNoCar();

private:
    Ui::WarningNoCar *ui;
};

#endif // WARNINGNOCAR_H
