/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QPushButton *ButtonLeft;
    QPushButton *ButtonMul;
    QPushButton *Button5;
    QPushButton *Button7;
    QPushButton *Button8;
    QPushButton *ButtonAdd;
    QLabel *label;
    QPushButton *ButtonEqual;
    QPushButton *ButtonRight;
    QPushButton *ButtonDot;
    QPushButton *ButtonMin;
    QPushButton *Button9;
    QPushButton *ButtonDel;
    QPushButton *Button6;
    QPushButton *Button2;
    QPushButton *ButtonC;
    QPushButton *Button3;
    QPushButton *Button1;
    QPushButton *Button4;
    QPushButton *Button0;
    QPushButton *ButtonD;
    QLabel *outputLabel;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QLabel *label_2;
    QLabel *inputLabel;
    QPushButton *pushButton_6;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        MainWindow->setStyleSheet(QString::fromUtf8("background-color: rgb(213, 235, 255);"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName("gridLayout");
        ButtonLeft = new QPushButton(centralwidget);
        ButtonLeft->setObjectName("ButtonLeft");
        ButtonLeft->setStyleSheet(QString::fromUtf8("QPushButton:hover{\n"
"	background-color: rgb(221, 221, 221);\n"
"	border:1px solid rgb(185, 185, 185);\n"
"}\n"
"QPushButton{\n"
"	background-color: rgb(255, 255, 255);\n"
"}"));

        gridLayout->addWidget(ButtonLeft, 6, 0, 1, 1);

        ButtonMul = new QPushButton(centralwidget);
        ButtonMul->setObjectName("ButtonMul");
        ButtonMul->setStyleSheet(QString::fromUtf8("QPushButton:hover{\n"
"	background-color: rgb(221, 221, 221);\n"
"	border:1px solid rgb(185, 185, 185);\n"
"}\n"
"QPushButton{\n"
"	background-color: rgb(255, 255, 255);\n"
"}"));

        gridLayout->addWidget(ButtonMul, 9, 3, 1, 1);

        Button5 = new QPushButton(centralwidget);
        Button5->setObjectName("Button5");
        Button5->setStyleSheet(QString::fromUtf8("QPushButton:hover{\n"
"	background-color: rgb(221, 221, 221);\n"
"	border:1px solid rgb(185, 185, 185);\n"
"}\n"
"QPushButton{\n"
"	background-color: rgb(255, 255, 255);\n"
"}"));

        gridLayout->addWidget(Button5, 8, 1, 1, 1);

        Button7 = new QPushButton(centralwidget);
        Button7->setObjectName("Button7");
        Button7->setStyleSheet(QString::fromUtf8("QPushButton:hover{\n"
"	background-color: rgb(221, 221, 221);\n"
"	border:1px solid rgb(185, 185, 185);\n"
"}\n"
"QPushButton{\n"
"	background-color: rgb(255, 255, 255);\n"
"}"));

        gridLayout->addWidget(Button7, 7, 0, 1, 1);

        Button8 = new QPushButton(centralwidget);
        Button8->setObjectName("Button8");
        Button8->setStyleSheet(QString::fromUtf8("QPushButton:hover{\n"
"	background-color: rgb(221, 221, 221);\n"
"	border:1px solid rgb(185, 185, 185);\n"
"}\n"
"QPushButton{\n"
"	background-color: rgb(255, 255, 255);\n"
"}"));

        gridLayout->addWidget(Button8, 7, 1, 1, 1);

        ButtonAdd = new QPushButton(centralwidget);
        ButtonAdd->setObjectName("ButtonAdd");
        ButtonAdd->setStyleSheet(QString::fromUtf8("QPushButton:hover{\n"
"	background-color: rgb(221, 221, 221);\n"
"	border:1px solid rgb(185, 185, 185);\n"
"}\n"
"QPushButton{\n"
"	background-color: rgb(255, 255, 255);\n"
"}"));

        gridLayout->addWidget(ButtonAdd, 7, 3, 1, 1);

        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setStyleSheet(QString::fromUtf8("font: 20pt \"\351\232\266\344\271\246\";\n"
"color: rgb(255, 0, 0);"));

        gridLayout->addWidget(label, 1, 0, 1, 1);

        ButtonEqual = new QPushButton(centralwidget);
        ButtonEqual->setObjectName("ButtonEqual");
        ButtonEqual->setStyleSheet(QString::fromUtf8("QPushButton:hover{\n"
"	background-color: rgb(221, 221, 221);\n"
"	border:1px solid rgb(185, 185, 185);\n"
"}\n"
"QPushButton{\n"
"	background-color: rgb(255, 255, 255);\n"
"}"));

        gridLayout->addWidget(ButtonEqual, 6, 2, 1, 1);

        ButtonRight = new QPushButton(centralwidget);
        ButtonRight->setObjectName("ButtonRight");
        ButtonRight->setStyleSheet(QString::fromUtf8("QPushButton:hover{\n"
"	background-color: rgb(221, 221, 221);\n"
"	border:1px solid rgb(185, 185, 185);\n"
"}\n"
"QPushButton{\n"
"	background-color: rgb(255, 255, 255);\n"
"}"));

        gridLayout->addWidget(ButtonRight, 6, 1, 1, 1);

        ButtonDot = new QPushButton(centralwidget);
        ButtonDot->setObjectName("ButtonDot");
        ButtonDot->setStyleSheet(QString::fromUtf8("QPushButton:hover{\n"
"	background-color: rgb(221, 221, 221);\n"
"	border:1px solid rgb(185, 185, 185);\n"
"}\n"
"QPushButton{\n"
"	background-color: rgb(255, 255, 255);\n"
"}"));

        gridLayout->addWidget(ButtonDot, 10, 2, 1, 1);

        ButtonMin = new QPushButton(centralwidget);
        ButtonMin->setObjectName("ButtonMin");
        ButtonMin->setStyleSheet(QString::fromUtf8("QPushButton:hover{\n"
"	background-color: rgb(221, 221, 221);\n"
"	border:1px solid rgb(185, 185, 185);\n"
"}\n"
"QPushButton{\n"
"	background-color: rgb(255, 255, 255);\n"
"}"));

        gridLayout->addWidget(ButtonMin, 8, 3, 1, 1);

        Button9 = new QPushButton(centralwidget);
        Button9->setObjectName("Button9");
        Button9->setStyleSheet(QString::fromUtf8("QPushButton:hover{\n"
"	background-color: rgb(221, 221, 221);\n"
"	border:1px solid rgb(185, 185, 185);\n"
"}\n"
"QPushButton{\n"
"	background-color: rgb(255, 255, 255);\n"
"}"));

        gridLayout->addWidget(Button9, 7, 2, 1, 1);

        ButtonDel = new QPushButton(centralwidget);
        ButtonDel->setObjectName("ButtonDel");
        ButtonDel->setStyleSheet(QString::fromUtf8("QPushButton:hover{\n"
"	background-color: rgb(221, 221, 221);\n"
"	border:1px solid rgb(185, 185, 185);\n"
"}\n"
"QPushButton{\n"
"	background-color: rgb(255, 255, 255);\n"
"}"));

        gridLayout->addWidget(ButtonDel, 6, 3, 1, 1);

        Button6 = new QPushButton(centralwidget);
        Button6->setObjectName("Button6");
        Button6->setStyleSheet(QString::fromUtf8("QPushButton:hover{\n"
"	background-color: rgb(221, 221, 221);\n"
"	border:1px solid rgb(185, 185, 185);\n"
"}\n"
"QPushButton{\n"
"	background-color: rgb(255, 255, 255);\n"
"}"));

        gridLayout->addWidget(Button6, 8, 2, 1, 1);

        Button2 = new QPushButton(centralwidget);
        Button2->setObjectName("Button2");
        Button2->setStyleSheet(QString::fromUtf8("QPushButton:hover{\n"
"	background-color: rgb(221, 221, 221);\n"
"	border:1px solid rgb(185, 185, 185);\n"
"}\n"
"QPushButton{\n"
"	background-color: rgb(255, 255, 255);\n"
"}"));

        gridLayout->addWidget(Button2, 9, 1, 1, 1);

        ButtonC = new QPushButton(centralwidget);
        ButtonC->setObjectName("ButtonC");
        ButtonC->setStyleSheet(QString::fromUtf8("QPushButton:hover{\n"
"	background-color: rgb(221, 221, 221);\n"
"	border:1px solid rgb(185, 185, 185);\n"
"}\n"
"QPushButton{\n"
"	background-color: rgb(255, 255, 255);\n"
"}"));

        gridLayout->addWidget(ButtonC, 10, 0, 1, 1);

        Button3 = new QPushButton(centralwidget);
        Button3->setObjectName("Button3");
        Button3->setStyleSheet(QString::fromUtf8("QPushButton:hover{\n"
"	background-color: rgb(221, 221, 221);\n"
"	border:1px solid rgb(185, 185, 185);\n"
"}\n"
"QPushButton{\n"
"	background-color: rgb(255, 255, 255);\n"
"}"));

        gridLayout->addWidget(Button3, 9, 2, 1, 1);

        Button1 = new QPushButton(centralwidget);
        Button1->setObjectName("Button1");
        Button1->setStyleSheet(QString::fromUtf8("QPushButton:hover{\n"
"	background-color: rgb(221, 221, 221);\n"
"	border:1px solid rgb(185, 185, 185);\n"
"}\n"
"QPushButton{\n"
"	background-color: rgb(255, 255, 255);\n"
"}"));

        gridLayout->addWidget(Button1, 9, 0, 1, 1);

        Button4 = new QPushButton(centralwidget);
        Button4->setObjectName("Button4");
        Button4->setStyleSheet(QString::fromUtf8("QPushButton:hover{\n"
"	background-color: rgb(221, 221, 221);\n"
"	border:1px solid rgb(185, 185, 185);\n"
"}\n"
"QPushButton{\n"
"	background-color: rgb(255, 255, 255);\n"
"}"));

        gridLayout->addWidget(Button4, 8, 0, 1, 1);

        Button0 = new QPushButton(centralwidget);
        Button0->setObjectName("Button0");
        Button0->setStyleSheet(QString::fromUtf8("QPushButton:hover{\n"
"	background-color: rgb(221, 221, 221);\n"
"	border:1px solid rgb(185, 185, 185);\n"
"}\n"
"QPushButton{\n"
"	background-color: rgb(255, 255, 255);\n"
"}"));

        gridLayout->addWidget(Button0, 10, 1, 1, 1);

        ButtonD = new QPushButton(centralwidget);
        ButtonD->setObjectName("ButtonD");
        ButtonD->setStyleSheet(QString::fromUtf8("QPushButton:hover{\n"
"	background-color: rgb(221, 221, 221);\n"
"	border:1px solid rgb(185, 185, 185);\n"
"}\n"
"QPushButton{\n"
"	background-color: rgb(255, 255, 255);\n"
"}"));

        gridLayout->addWidget(ButtonD, 10, 3, 1, 1);

        outputLabel = new QLabel(centralwidget);
        outputLabel->setObjectName("outputLabel");
        outputLabel->setStyleSheet(QString::fromUtf8("font: 20pt \"Microsoft YaHei UI\";"));

        gridLayout->addWidget(outputLabel, 1, 1, 1, 3);

        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setStyleSheet(QString::fromUtf8("QPushButton:hover{\n"
"	background-color: rgb(221, 221, 221);\n"
"	border:1px solid rgb(185, 185, 185);\n"
"}\n"
"QPushButton{\n"
"	background-color: rgb(255, 255, 255);\n"
"}"));

        gridLayout->addWidget(pushButton, 5, 0, 1, 1);

        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setStyleSheet(QString::fromUtf8("QPushButton:hover{\n"
"	background-color: rgb(221, 221, 221);\n"
"	border:1px solid rgb(185, 185, 185);\n"
"}\n"
"QPushButton{\n"
"	background-color: rgb(255, 255, 255);\n"
"}"));

        gridLayout->addWidget(pushButton_2, 5, 1, 1, 1);

        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setStyleSheet(QString::fromUtf8("QPushButton:hover{\n"
"	background-color: rgb(221, 221, 221);\n"
"	border:1px solid rgb(185, 185, 185);\n"
"}\n"
"QPushButton{\n"
"	background-color: rgb(255, 255, 255);\n"
"}"));

        gridLayout->addWidget(pushButton_3, 5, 2, 1, 1);

        pushButton_4 = new QPushButton(centralwidget);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setStyleSheet(QString::fromUtf8("QPushButton:hover{\n"
"	background-color: rgb(221, 221, 221);\n"
"	border:1px solid rgb(185, 185, 185);\n"
"}\n"
"QPushButton{\n"
"	background-color: rgb(255, 255, 255);\n"
"}"));

        gridLayout->addWidget(pushButton_4, 5, 3, 1, 1);

        pushButton_5 = new QPushButton(centralwidget);
        pushButton_5->setObjectName("pushButton_5");
        pushButton_5->setStyleSheet(QString::fromUtf8("QPushButton:hover{\n"
"	background-color: rgb(221, 221, 221);\n"
"	border:1px solid rgb(185, 185, 185);\n"
"}\n"
"QPushButton{\n"
"	font: 9pt \"\346\245\267\344\275\223\";\n"
"	background-color: rgb(255, 255, 255);\n"
"}"));

        gridLayout->addWidget(pushButton_5, 0, 0, 1, 1);

        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setStyleSheet(QString::fromUtf8("font: 20pt \"\351\232\266\344\271\246\";\n"
"color: rgb(255, 0, 0);"));

        gridLayout->addWidget(label_2, 2, 0, 1, 1);

        inputLabel = new QLabel(centralwidget);
        inputLabel->setObjectName("inputLabel");
        inputLabel->setStyleSheet(QString::fromUtf8("font: 20pt \"Microsoft YaHei UI\";"));

        gridLayout->addWidget(inputLabel, 2, 1, 1, 3);

        pushButton_6 = new QPushButton(centralwidget);
        pushButton_6->setObjectName("pushButton_6");
        pushButton_6->setStyleSheet(QString::fromUtf8("QPushButton:hover{\n"
"	background-color: rgb(221, 221, 221);\n"
"	border:1px solid rgb(185, 185, 185);\n"
"}\n"
"QPushButton{\n"
"	font: 9pt \"\346\245\267\344\275\223\";\n"
"	background-color: rgb(255, 255, 255);\n"
"}"));

        gridLayout->addWidget(pushButton_6, 0, 1, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 25));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        ButtonLeft->setText(QCoreApplication::translate("MainWindow", "(", nullptr));
        ButtonMul->setText(QCoreApplication::translate("MainWindow", "*", nullptr));
        Button5->setText(QCoreApplication::translate("MainWindow", "5", nullptr));
        Button7->setText(QCoreApplication::translate("MainWindow", "7", nullptr));
        Button8->setText(QCoreApplication::translate("MainWindow", "8", nullptr));
        ButtonAdd->setText(QCoreApplication::translate("MainWindow", "+", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\350\277\220\347\256\227\347\273\223\346\236\234\357\274\232", nullptr));
        ButtonEqual->setText(QCoreApplication::translate("MainWindow", "=", nullptr));
        ButtonRight->setText(QCoreApplication::translate("MainWindow", ")", nullptr));
        ButtonDot->setText(QCoreApplication::translate("MainWindow", ".", nullptr));
        ButtonMin->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        Button9->setText(QCoreApplication::translate("MainWindow", "9", nullptr));
        ButtonDel->setText(QCoreApplication::translate("MainWindow", "<x|", nullptr));
        Button6->setText(QCoreApplication::translate("MainWindow", "6", nullptr));
        Button2->setText(QCoreApplication::translate("MainWindow", "2", nullptr));
        ButtonC->setText(QCoreApplication::translate("MainWindow", "C", nullptr));
        Button3->setText(QCoreApplication::translate("MainWindow", "3", nullptr));
        Button1->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        Button4->setText(QCoreApplication::translate("MainWindow", "4", nullptr));
        Button0->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        ButtonD->setText(QCoreApplication::translate("MainWindow", "/", nullptr));
        outputLabel->setText(QString());
        pushButton->setText(QCoreApplication::translate("MainWindow", "!", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "^", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "\342\210\232", nullptr));
        pushButton_4->setText(QCoreApplication::translate("MainWindow", "^2", nullptr));
        pushButton_5->setText(QCoreApplication::translate("MainWindow", "\345\216\206\345\217\262\350\256\260\345\275\225", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "  \347\256\227 \345\274\217 \357\274\232", nullptr));
        inputLabel->setText(QString());
        pushButton_6->setText(QCoreApplication::translate("MainWindow", "\344\275\277\347\224\250\350\257\264\346\230\216", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
