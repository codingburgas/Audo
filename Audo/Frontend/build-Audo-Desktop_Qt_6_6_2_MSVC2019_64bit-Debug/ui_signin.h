/********************************************************************************
** Form generated from reading UI file 'signin.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIGNIN_H
#define UI_SIGNIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SignIn
{
public:
    QLabel *Background;
    QLabel *Frame;
    QLabel *SignInLabel;
    QTextEdit *Email;
    QLabel *EmailFrame;
    QLabel *PasswordFrame;
    QTextEdit *Password;
    QPushButton *Continue;
    QLabel *SignUpLabel;
    QPushButton *SignUpButton;
    QLabel *Warning;

    void setupUi(QWidget *SignIn)
    {
        if (SignIn->objectName().isEmpty())
            SignIn->setObjectName("SignIn");
        SignIn->resize(1280, 832);
        SignIn->setCursor(QCursor(Qt::ArrowCursor));
        SignIn->setAutoFillBackground(false);
        SignIn->setStyleSheet(QString::fromUtf8("background-color: rgb(75, 76, 173);"));
        Background = new QLabel(SignIn);
        Background->setObjectName("Background");
        Background->setGeometry(QRect(0, 0, 1280, 832));
        Background->setPixmap(QPixmap(QString::fromUtf8(":/backgrounds/assets/backgrounds/login-background.png")));
        Background->setAlignment(Qt::AlignCenter);
        Frame = new QLabel(SignIn);
        Frame->setObjectName("Frame");
        Frame->setGeometry(QRect(310, 140, 668, 525));
        Frame->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"border-radius: 16px;"));
        SignInLabel = new QLabel(SignIn);
        SignInLabel->setObjectName("SignInLabel");
        SignInLabel->setGeometry(QRect(350, 180, 111, 41));
        QFont font;
        font.setFamilies({QString::fromUtf8("Roboto Serif Medium")});
        font.setPointSize(20);
        font.setWeight(QFont::DemiBold);
        font.setItalic(false);
        SignInLabel->setFont(font);
        SignInLabel->setAutoFillBackground(false);
        SignInLabel->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);\n"
"color: rgb(68, 81, 120);\n"
"font: 600 20pt \"Roboto Serif Medium\";"));
        SignInLabel->setScaledContents(false);
        SignInLabel->setAlignment(Qt::AlignCenter);
        Email = new QTextEdit(SignIn);
        Email->setObjectName("Email");
        Email->setGeometry(QRect(370, 290, 551, 41));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Roboto Serif Medium")});
        font1.setPointSize(16);
        font1.setWeight(QFont::Medium);
        font1.setItalic(false);
        Email->setFont(font1);
        Email->setAutoFillBackground(false);
        Email->setStyleSheet(QString::fromUtf8("background: none;\n"
"font: 500 16pt \"Roboto Serif Medium\";\n"
"background-color: rgba(255, 255, 255, 0);\n"
"border: none;\n"
"color: rgba(107, 125, 179, 255);"));
        EmailFrame = new QLabel(SignIn);
        EmailFrame->setObjectName("EmailFrame");
        EmailFrame->setGeometry(QRect(360, 270, 561, 71));
        EmailFrame->setStyleSheet(QString::fromUtf8("background-color: #F3F3FF;\n"
"border-radius: 16px;"));
        PasswordFrame = new QLabel(SignIn);
        PasswordFrame->setObjectName("PasswordFrame");
        PasswordFrame->setGeometry(QRect(360, 370, 561, 71));
        PasswordFrame->setStyleSheet(QString::fromUtf8("background-color: #F3F3FF;\n"
"border-radius: 16px;"));
        Password = new QTextEdit(SignIn);
        Password->setObjectName("Password");
        Password->setGeometry(QRect(370, 390, 551, 41));
        Password->setFont(font1);
        Password->setAutoFillBackground(false);
        Password->setStyleSheet(QString::fromUtf8("background: none;\n"
"background-color: rgba(255, 255, 255, 0);\n"
"border: none;\n"
"color: rgba(107, 125, 179, 255);\n"
"font: 500 16pt \"Roboto Serif Medium\";"));
        Continue = new QPushButton(SignIn);
        Continue->setObjectName("Continue");
        Continue->setGeometry(QRect(560, 480, 161, 51));
        Continue->setCursor(QCursor(Qt::PointingHandCursor));
        Continue->setAutoFillBackground(false);
        Continue->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"font: 600 16pt \"Roboto Serif SemiBold\";\n"
"background-color: #0085FF;\n"
"border-radius: 10px;\n"
"color:#ffffff;\n"
"}\n"
"QPushButton:hover {\n"
"font: 600 16pt \"Roboto Serif SemiBold\";\n"
"background-color: #006FD6;\n"
"border-radius: 10px;\n"
"color:#ffffff;\n"
" }\n"
"\n"
""));
        Continue->setFlat(true);
        SignUpLabel = new QLabel(SignIn);
        SignUpLabel->setObjectName("SignUpLabel");
        SignUpLabel->setGeometry(QRect(510, 628, 231, 16));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Inter SemiBold")});
        font2.setPointSize(12);
        font2.setBold(true);
        SignUpLabel->setFont(font2);
        SignUpLabel->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);\n"
"color: #C4CAE1;"));
        SignUpLabel->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        SignUpButton = new QPushButton(SignIn);
        SignUpButton->setObjectName("SignUpButton");
        SignUpButton->setGeometry(QRect(700, 620, 81, 31));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Inter")});
        font3.setPointSize(12);
        font3.setBold(true);
        SignUpButton->setFont(font3);
        SignUpButton->setCursor(QCursor(Qt::PointingHandCursor));
        SignUpButton->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);\n"
"color: #A6B2D4;"));
        Warning = new QLabel(SignIn);
        Warning->setObjectName("Warning");
        Warning->setGeometry(QRect(360, 240, 341, 31));
        Warning->setFont(font3);
        Warning->setAutoFillBackground(false);
        Warning->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);\n"
"color: rgb(170, 0, 0);"));
        Background->raise();
        Frame->raise();
        EmailFrame->raise();
        SignInLabel->raise();
        Email->raise();
        PasswordFrame->raise();
        Password->raise();
        Continue->raise();
        SignUpLabel->raise();
        SignUpButton->raise();
        Warning->raise();

        retranslateUi(SignIn);

        QMetaObject::connectSlotsByName(SignIn);
    } // setupUi

    void retranslateUi(QWidget *SignIn)
    {
        SignIn->setWindowTitle(QCoreApplication::translate("SignIn", "Sign In", nullptr));
        Background->setText(QString());
        Frame->setText(QString());
        SignInLabel->setText(QCoreApplication::translate("SignIn", "Sign in", nullptr));
        Email->setPlaceholderText(QCoreApplication::translate("SignIn", "Email", nullptr));
        EmailFrame->setText(QString());
        PasswordFrame->setText(QString());
        Password->setPlaceholderText(QCoreApplication::translate("SignIn", "Password", nullptr));
        Continue->setText(QCoreApplication::translate("SignIn", "Continue", nullptr));
        SignUpLabel->setText(QCoreApplication::translate("SignIn", "Don\342\200\231t have an account?", nullptr));
        SignUpButton->setText(QCoreApplication::translate("SignIn", "Sign Up", nullptr));
        Warning->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class SignIn: public Ui_SignIn {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIGNIN_H
