/********************************************************************************
** Form generated from reading UI file 'warningsamecar.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WARNINGSAMECAR_H
#define UI_WARNINGSAMECAR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_WarningSameCar
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label;

    void setupUi(QDialog *WarningSameCar)
    {
        if (WarningSameCar->objectName().isEmpty())
            WarningSameCar->setObjectName("WarningSameCar");
        WarningSameCar->resize(400, 300);
        buttonBox = new QDialogButtonBox(WarningSameCar);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Orientation::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::StandardButton::Cancel|QDialogButtonBox::StandardButton::Ok);
        label = new QLabel(WarningSameCar);
        label->setObjectName("label");
        label->setGeometry(QRect(90, 90, 331, 91));
        label->setStyleSheet(QString::fromUtf8("font : 22pt \"\351\232\266\344\271\246\";"));

        retranslateUi(WarningSameCar);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, WarningSameCar, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, WarningSameCar, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(WarningSameCar);
    } // setupUi

    void retranslateUi(QDialog *WarningSameCar)
    {
        WarningSameCar->setWindowTitle(QCoreApplication::translate("WarningSameCar", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("WarningSameCar", "\350\257\245\350\275\246\345\267\262\345\234\250\345\201\234\350\275\246\345\234\272\344\270\255", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WarningSameCar: public Ui_WarningSameCar {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WARNINGSAMECAR_H
