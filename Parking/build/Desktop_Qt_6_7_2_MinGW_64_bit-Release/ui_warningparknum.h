/********************************************************************************
** Form generated from reading UI file 'warningparknum.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WARNINGPARKNUM_H
#define UI_WARNINGPARKNUM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>

QT_BEGIN_NAMESPACE

class Ui_WarningParkNum
{
public:
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *WarningParkNum)
    {
        if (WarningParkNum->objectName().isEmpty())
            WarningParkNum->setObjectName("WarningParkNum");
        WarningParkNum->resize(400, 300);
        buttonBox = new QDialogButtonBox(WarningParkNum);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Orientation::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::StandardButton::Cancel|QDialogButtonBox::StandardButton::Ok);

        retranslateUi(WarningParkNum);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, WarningParkNum, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, WarningParkNum, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(WarningParkNum);
    } // setupUi

    void retranslateUi(QDialog *WarningParkNum)
    {
        WarningParkNum->setWindowTitle(QCoreApplication::translate("WarningParkNum", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WarningParkNum: public Ui_WarningParkNum {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WARNINGPARKNUM_H
