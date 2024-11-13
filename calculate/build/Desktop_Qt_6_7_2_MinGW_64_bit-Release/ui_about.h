/********************************************************************************
** Form generated from reading UI file 'about.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ABOUT_H
#define UI_ABOUT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_About
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label;
    QLabel *label_2;

    void setupUi(QDialog *About)
    {
        if (About->objectName().isEmpty())
            About->setObjectName("About");
        About->resize(400, 300);
        buttonBox = new QDialogButtonBox(About);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Orientation::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::StandardButton::Cancel|QDialogButtonBox::StandardButton::Ok);
        label = new QLabel(About);
        label->setObjectName("label");
        label->setGeometry(QRect(160, 0, 71, 31));
        label->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);\n"
"font: 18pt \"\351\232\266\344\271\246\";"));
        label_2 = new QLabel(About);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(10, 30, 381, 211));
        label_2->setStyleSheet(QString::fromUtf8("font: 15pt \"\345\215\216\346\226\207\350\241\214\346\245\267\";"));

        retranslateUi(About);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, About, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, About, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(About);
    } // setupUi

    void retranslateUi(QDialog *About)
    {
        About->setWindowTitle(QCoreApplication::translate("About", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("About", "\350\257\264\346\230\216", nullptr));
        label_2->setText(QCoreApplication::translate("About", "@\344\275\234\350\200\205: \346\235\216\347\221\236\346\263\275@23301069\n"
"\n"
"\344\275\277\347\224\250\346\263\250\346\204\217:\n"
"1.\350\257\267\346\263\250\346\204\217\345\274\200\346\240\271\351\234\200\350\246\201\345\205\210\350\276\223\345\205\245\346\240\271\345\217\267\344\270\213\n"
"\347\232\204\346\225\260\345\255\227\357\274\214\347\204\266\345\220\216\347\202\271\345\207\273\346\240\271\345\217\267\357\274\214\345\233\240\344\270\272\345\274\200\346\240\271\n"
"\346\230\257\347\224\250\345\271\202\350\277\220\347\256\227\345\256\232\344\271\211\347\232\204\343\200\202\n"
"2.\350\276\223\345\205\245\350\264\237\346\225\260\346\230\257\351\200\232\350\277\207\344\273\245\351\233\266\345\207\217\345\256\236\347\216\260\347\232\204\343\200\202\n"
"3.\351\230\266\344\271\230\346\230\257\351\200\232\350\277\207\350\277\236\344\271\230\345\256\236\347\216\260\347\232\204\343\200\202", nullptr));
    } // retranslateUi

};

namespace Ui {
    class About: public Ui_About {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ABOUT_H
