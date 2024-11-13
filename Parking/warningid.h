#ifndef WARNINGID_H
#define WARNINGID_H

#include <QDialog>

namespace Ui {
class WarningID;
}

class WarningID : public QDialog
{
    Q_OBJECT

public:
    explicit WarningID(QWidget *parent = nullptr);
    ~WarningID();

private:
    Ui::WarningID *ui;
};

#endif // WARNINGID_H
