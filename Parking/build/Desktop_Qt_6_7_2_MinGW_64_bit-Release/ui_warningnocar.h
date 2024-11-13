/********************************************************************************
** Form generated from reading UI file 'warningnocar.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WARNINGNOCAR_H
#define UI_WARNINGNOCAR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_WarningNoCar
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label_2;

    void setupUi(QDialog *WarningNoCar)
    {
        if (WarningNoCar->objectName().isEmpty())
            WarningNoCar->setObjectName("WarningNoCar");
        WarningNoCar->resize(400, 300);
        buttonBox = new QDialogButtonBox(WarningNoCar);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Orientation::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::StandardButton::Cancel|QDialogButtonBox::StandardButton::Ok);
        label_2 = new QLabel(WarningNoCar);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(120, 100, 351, 51));
        label_2->setStyleSheet(QString::fromUtf8("font: 22pt \"\351\232\266\344\271\246\";"));

        retranslateUi(WarningNoCar);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, WarningNoCar, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, WarningNoCar, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(WarningNoCar);
    } // setupUi

    void retranslateUi(QDialog *WarningNoCar)
    {
        WarningNoCar->setWindowTitle(QCoreApplication::translate("WarningNoCar", "Dialog", nullptr));
        label_2->setText(QCoreApplication::translate("WarningNoCar", "\344\270\215\345\255\230\345\234\250\350\257\245\350\275\246\350\276\206", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WarningNoCar: public Ui_WarningNoCar {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WARNINGNOCAR_H
