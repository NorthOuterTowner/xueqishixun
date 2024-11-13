#ifndef WARNINGWAITNUM_H
#define WARNINGWAITNUM_H

#include <QDialog>

namespace Ui {
class WarningWaitNum;
}

class WarningWaitNum : public QDialog
{
    Q_OBJECT

public:
    explicit WarningWaitNum(QWidget *parent = nullptr);
    ~WarningWaitNum();

private:
    Ui::WarningWaitNum *ui;
};

#endif // WARNINGWAITNUM_H
