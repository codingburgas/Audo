/********************************************************************************
** Form generated from reading UI file 'SignUp.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIGNUP_H
#define UI_SIGNUP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SignUp
{
public:
    QLabel *SignInLabel;
    QPushButton *SignInButton;
    QLabel *Background;
    QLabel *SignInTitle;
    QPushButton *Teacher;
    QLabel *label;
    QLabel *Frame;
    QPushButton *pushButton;

    void setupUi(QWidget *SignUp)
    {
        if (SignUp->objectName().isEmpty())
            SignUp->setObjectName("SignUp");
        SignUp->resize(1280, 832);
        SignUp->setMinimumSize(QSize(1280, 832));
        SignUp->setMaximumSize(QSize(1280, 832));
        SignUp->setBaseSize(QSize(1280, 832));
        SignUp->setAutoFillBackground(false);
        SignUp->setStyleSheet(QString::fromUtf8("background-color: #4B4CAD;"));
        SignInLabel = new QLabel(SignUp);
        SignInLabel->setObjectName("SignInLabel");
        SignInLabel->setGeometry(QRect(500, 520, 271, 31));
        QFont font;
        font.setFamilies({QString::fromUtf8("Inter SemiBold")});
        font.setPointSize(12);
        font.setBold(true);
        SignInLabel->setFont(font);
        SignInLabel->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);\n"
"color: #C4CAE1;"));
        SignInLabel->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        SignInButton = new QPushButton(SignUp);
        SignInButton->setObjectName("SignInButton");
        SignInButton->setGeometry(QRect(700, 520, 81, 31));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Inter")});
        font1.setPointSize(12);
        font1.setBold(true);
        SignInButton->setFont(font1);
        SignInButton->setCursor(QCursor(Qt::PointingHandCursor));
        SignInButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"background-color: rgba(255, 255, 255, 0);\n"
"color: #A6B2D4;\n"
"}\n"
"QPushButton:hover {\n"
"\n"
"background-color: rgba(255, 255, 255, 0);\n"
"color: #737B95;\n"
" }\n"
"QPushButton:pressed {\n"
"background-color: rgba(255, 255, 255, 0);\n"
"color:#444A5F;\n"
" }\n"
""));
        SignInButton->setCheckable(false);
        SignInButton->setFlat(true);
        Background = new QLabel(SignUp);
        Background->setObjectName("Background");
        Background->setGeometry(QRect(0, 0, 1280, 832));
        Background->setPixmap(QPixmap(QString::fromUtf8(":/backgrounds/assets/backgrounds/main-background.png")));
        Background->setAlignment(Qt::AlignCenter);
        SignInTitle = new QLabel(SignUp);
        SignInTitle->setObjectName("SignInTitle");
        SignInTitle->setGeometry(QRect(340, 260, 151, 61));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Roboto Serif Medium")});
        font2.setPointSize(20);
        font2.setWeight(QFont::DemiBold);
        font2.setItalic(false);
        font2.setKerning(false);
        SignInTitle->setFont(font2);
        SignInTitle->setAutoFillBackground(false);
        SignInTitle->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);\n"
"color: #26013C;\n"
"font: 600 20pt \"Roboto Serif Medium\";"));
        SignInTitle->setScaledContents(false);
        SignInTitle->setAlignment(Qt::AlignCenter);
        Teacher = new QPushButton(SignUp);
        Teacher->setObjectName("Teacher");
        Teacher->setGeometry(QRect(670, 410, 180, 60));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Roboto Serif SemiBold")});
        font3.setPointSize(16);
        font3.setWeight(QFont::DemiBold);
        font3.setItalic(false);
        font3.setKerning(true);
        Teacher->setFont(font3);
        Teacher->setCursor(QCursor(Qt::PointingHandCursor));
        Teacher->setMouseTracking(true);
        Teacher->setAutoFillBackground(false);
        Teacher->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"font: 600 16pt \"Roboto Serif SemiBold\";\n"
"background-color: #8C31F4;\n"
"border-radius: 10px;\n"
"color:#ffffff;\n"
"}\n"
"QPushButton:hover {\n"
"font: 600 16pt \"Roboto Serif SemiBold\";\n"
"background-color: #6319B7;\n"
"border-radius: 10px;\n"
"color:#ffffff;\n"
" }\n"
"\n"
""));
        Teacher->setFlat(true);
        label = new QLabel(SignUp);
        label->setObjectName("label");
        label->setGeometry(QRect(625, 420, 31, 31));
        QFont font4;
        font4.setFamilies({QString::fromUtf8("Roboto Serif Medium")});
        font4.setPointSize(16);
        font4.setWeight(QFont::DemiBold);
        font4.setItalic(false);
        label->setFont(font4);
        label->setAutoFillBackground(false);
        label->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);\n"
"color: #26013C;\n"
"font: 600 16pt \"Roboto Serif Medium\";"));
        Frame = new QLabel(SignUp);
        Frame->setObjectName("Frame");
        Frame->setGeometry(QRect(304, 230, 670, 330));
        Frame->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"border-radius: 16px;"));
        pushButton = new QPushButton(SignUp);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(420, 410, 180, 60));
        pushButton->setFont(font3);
        pushButton->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton->setMouseTracking(true);
        pushButton->setAutoFillBackground(false);
        pushButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"font: 600 16pt \"Roboto Serif SemiBold\";\n"
"background-color: #8C31F4;\n"
"border-radius: 10px;\n"
"color:#ffffff;\n"
"}\n"
"QPushButton:hover {\n"
"font: 600 16pt \"Roboto Serif SemiBold\";\n"
"background-color: #6319B7;\n"
"border-radius: 10px;\n"
"color:#ffffff;\n"
" }\n"
"\n"
""));
        pushButton->setFlat(true);
        Background->raise();
        Frame->raise();
        SignInLabel->raise();
        SignInTitle->raise();
        Teacher->raise();
        label->raise();
        pushButton->raise();
        SignInButton->raise();

        retranslateUi(SignUp);

        Teacher->setDefault(false);
        pushButton->setDefault(false);


        QMetaObject::connectSlotsByName(SignUp);
    } // setupUi

    void retranslateUi(QWidget *SignUp)
    {
        SignUp->setWindowTitle(QCoreApplication::translate("SignUp", "Form", nullptr));
        SignInLabel->setText(QCoreApplication::translate("SignUp", "Already have an account?", nullptr));
        SignInButton->setText(QCoreApplication::translate("SignUp", "Sign In", nullptr));
        Background->setText(QString());
        SignInTitle->setText(QCoreApplication::translate("SignUp", "Sign up", nullptr));
        Teacher->setText(QCoreApplication::translate("SignUp", "Teacher", nullptr));
        label->setText(QCoreApplication::translate("SignUp", "or", nullptr));
        Frame->setText(QString());
        pushButton->setText(QCoreApplication::translate("SignUp", "Student", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SignUp: public Ui_SignUp {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIGNUP_H
