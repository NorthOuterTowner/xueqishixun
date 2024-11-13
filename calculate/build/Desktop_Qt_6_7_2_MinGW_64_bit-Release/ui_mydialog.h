/********************************************************************************
** Form generated from reading UI file 'mydialog.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYDIALOG_H
#define UI_MYDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_MyDialog
{
public:
    QGridLayout *gridLayout;
    QLabel *history;
    QLabel *h1;
    QLabel *h2;
    QLabel *h3;
    QLabel *h4;
    QLabel *h5;
    QLabel *h6;
    QLabel *h7;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *MyDialog)
    {
        if (MyDialog->objectName().isEmpty())
            MyDialog->setObjectName("MyDialog");
        MyDialog->resize(400, 300);
        gridLayout = new QGridLayout(MyDialog);
        gridLayout->setObjectName("gridLayout");
        history = new QLabel(MyDialog);
        history->setObjectName("history");
        history->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);\n"
"font: 18pt \"\351\232\266\344\271\246\";"));

        gridLayout->addWidget(history, 0, 0, 1, 1);

        h1 = new QLabel(MyDialog);
        h1->setObjectName("h1");

        gridLayout->addWidget(h1, 1, 0, 1, 1);

        h2 = new QLabel(MyDialog);
        h2->setObjectName("h2");

        gridLayout->addWidget(h2, 2, 0, 1, 1);

        h3 = new QLabel(MyDialog);
        h3->setObjectName("h3");

        gridLayout->addWidget(h3, 3, 0, 1, 1);

        h4 = new QLabel(MyDialog);
        h4->setObjectName("h4");

        gridLayout->addWidget(h4, 4, 0, 1, 1);

        h5 = new QLabel(MyDialog);
        h5->setObjectName("h5");

        gridLayout->addWidget(h5, 5, 0, 1, 1);

        h6 = new QLabel(MyDialog);
        h6->setObjectName("h6");

        gridLayout->addWidget(h6, 6, 0, 1, 1);

        h7 = new QLabel(MyDialog);
        h7->setObjectName("h7");

        gridLayout->addWidget(h7, 7, 0, 1, 1);

        buttonBox = new QDialogButtonBox(MyDialog);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setOrientation(Qt::Orientation::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::StandardButton::Cancel|QDialogButtonBox::StandardButton::Ok);

        gridLayout->addWidget(buttonBox, 8, 0, 1, 1);


        retranslateUi(MyDialog);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, MyDialog, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, MyDialog, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(MyDialog);
    } // setupUi

    void retranslateUi(QDialog *MyDialog)
    {
        MyDialog->setWindowTitle(QCoreApplication::translate("MyDialog", "Dialog", nullptr));
        history->setText(QCoreApplication::translate("MyDialog", "          \345\216\206\345\217\262\350\256\260\345\275\225", nullptr));
        h1->setText(QString());
        h2->setText(QString());
        h3->setText(QString());
        h4->setText(QString());
        h5->setText(QString());
        h6->setText(QString());
        h7->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MyDialog: public Ui_MyDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYDIALOG_H
