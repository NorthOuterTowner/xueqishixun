/********************************************************************************
** Form generated from reading UI file 'warninginput.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WARNINGINPUT_H
#define UI_WARNINGINPUT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_warningInput
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label;
    QLabel *label_2;

    void setupUi(QDialog *warningInput)
    {
        if (warningInput->objectName().isEmpty())
            warningInput->setObjectName("warningInput");
        warningInput->resize(400, 300);
        buttonBox = new QDialogButtonBox(warningInput);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Orientation::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::StandardButton::Cancel|QDialogButtonBox::StandardButton::Ok);
        label = new QLabel(warningInput);
        label->setObjectName("label");
        label->setGeometry(QRect(70, 40, 401, 111));
        label->setStyleSheet(QString::fromUtf8("font:22pt \"\351\232\266\344\271\246\";"));
        label_2 = new QLabel(warningInput);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(40, 120, 441, 111));
        label_2->setStyleSheet(QString::fromUtf8("font:22pt \"\351\232\266\344\271\246\";"));

        retranslateUi(warningInput);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, warningInput, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, warningInput, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(warningInput);
    } // setupUi

    void retranslateUi(QDialog *warningInput)
    {
        warningInput->setWindowTitle(QCoreApplication::translate("warningInput", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("warningInput", "\350\257\267\345\205\210\350\276\223\345\205\245\350\275\246\344\275\215\346\200\273\346\225\260\345\222\214", nullptr));
        label_2->setText(QCoreApplication::translate("warningInput", "\344\276\277\351\201\223\350\275\246\350\276\206\345\256\271\347\272\263\346\225\260\345\274\200\345\220\257\347\263\273\347\273\237", nullptr));
    } // retranslateUi

};

namespace Ui {
    class warningInput: public Ui_warningInput {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WARNINGINPUT_H
