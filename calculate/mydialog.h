#ifndef MYDIALOG_H
#define MYDIALOG_H

#include <QDialog>
#include "ui_mydialog.h"

class MyDialog : public QDialog {
    Q_OBJECT
public:
    MyDialog(QWidget *parent = nullptr);
    ~MyDialog();
private:
    Ui::MyDialog *ui;
};

#endif // MYDIALOG_H
