/********************************************************************************
** Form generated from reading UI file 'warningid.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WARNINGID_H
#define UI_WARNINGID_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_WarningID
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label;

    void setupUi(QDialog *WarningID)
    {
        if (WarningID->objectName().isEmpty())
            WarningID->setObjectName("WarningID");
        WarningID->resize(400, 300);
        buttonBox = new QDialogButtonBox(WarningID);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Orientation::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::StandardButton::Cancel|QDialogButtonBox::StandardButton::Ok);
        label = new QLabel(WarningID);
        label->setObjectName("label");
        label->setGeometry(QRect(140, 80, 321, 101));
        label->setStyleSheet(QString::fromUtf8("font: 22pt \"\351\232\266\344\271\246\";"));

        retranslateUi(WarningID);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, WarningID, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, WarningID, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(WarningID);
    } // setupUi

    void retranslateUi(QDialog *WarningID)
    {
        WarningID->setWindowTitle(QCoreApplication::translate("WarningID", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("WarningID", "\350\257\267\350\276\223\345\205\245\350\275\246\350\276\206", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WarningID: public Ui_WarningID {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WARNINGID_H
