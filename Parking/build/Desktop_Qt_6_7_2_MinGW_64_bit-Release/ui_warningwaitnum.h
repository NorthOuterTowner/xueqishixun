/********************************************************************************
** Form generated from reading UI file 'warningwaitnum.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WARNINGWAITNUM_H
#define UI_WARNINGWAITNUM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_WarningWaitNum
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label;

    void setupUi(QDialog *WarningWaitNum)
    {
        if (WarningWaitNum->objectName().isEmpty())
            WarningWaitNum->setObjectName("WarningWaitNum");
        WarningWaitNum->resize(400, 300);
        buttonBox = new QDialogButtonBox(WarningWaitNum);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Orientation::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::StandardButton::Cancel|QDialogButtonBox::StandardButton::Ok);
        label = new QLabel(WarningWaitNum);
        label->setObjectName("label");
        label->setGeometry(QRect(40, 90, 361, 71));
        label->setStyleSheet(QString::fromUtf8("font: 22pt \"\351\232\266\344\271\246\";"));

        retranslateUi(WarningWaitNum);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, WarningWaitNum, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, WarningWaitNum, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(WarningWaitNum);
    } // setupUi

    void retranslateUi(QDialog *WarningWaitNum)
    {
        WarningWaitNum->setWindowTitle(QCoreApplication::translate("WarningWaitNum", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("WarningWaitNum", "\344\276\277\351\201\223\345\267\262\346\273\241\357\274\214\346\227\240\346\263\225\346\235\245\350\275\246", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WarningWaitNum: public Ui_WarningWaitNum {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WARNINGWAITNUM_H
