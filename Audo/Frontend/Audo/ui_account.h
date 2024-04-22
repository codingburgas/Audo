/********************************************************************************
** Form generated from reading UI file 'account.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ACCOUNT_H
#define UI_ACCOUNT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form
{
public:
    QLabel *Frame;
    QLabel *Background;
    QLabel *SignInLabel;
    QLabel *generalInfo;
    QLabel *EmailFrame;
    QLabel *UserFirstName;
    QLabel *generalInfo_2;
    QLabel *EmailFrame_2;
    QLabel *UserLastName;
    QLabel *generalInfo_3;
    QLabel *SignInLabel_4;
    QLabel *UserEmail;
    QLabel *SignInLabel_5;
    QLabel *generalInfo_4;
    QLabel *UserPassword;
    QLabel *EmailFrame_4;
    QLabel *generalInfo_5;
    QPushButton *SignOut;
    QPushButton *DeleteAccount;
    QPushButton *SignInButton;

    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName("Form");
        Form->resize(1280, 832);
        Frame = new QLabel(Form);
        Frame->setObjectName("Frame");
        Frame->setGeometry(QRect(250, 80, 670, 691));
        Frame->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"border-radius: 16px;"));
        Background = new QLabel(Form);
        Background->setObjectName("Background");
        Background->setGeometry(QRect(-20, -20, 1321, 871));
        Background->setPixmap(QPixmap(QString::fromUtf8(":/backgrounds/assets/backgrounds/login-background.png")));
        Background->setAlignment(Qt::AlignCenter);
        SignInLabel = new QLabel(Form);
        SignInLabel->setObjectName("SignInLabel");
        SignInLabel->setGeometry(QRect(290, 110, 261, 41));
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
        generalInfo = new QLabel(Form);
        generalInfo->setObjectName("generalInfo");
        generalInfo->setGeometry(QRect(290, 200, 141, 41));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Roboto Serif Medium")});
        font1.setPointSize(14);
        font1.setWeight(QFont::DemiBold);
        font1.setItalic(false);
        generalInfo->setFont(font1);
        generalInfo->setAutoFillBackground(false);
        generalInfo->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);\n"
"color: #909EC6;\n"
"font: 600 14pt \"Roboto Serif Medium\";"));
        generalInfo->setScaledContents(false);
        generalInfo->setAlignment(Qt::AlignCenter);
        EmailFrame = new QLabel(Form);
        EmailFrame->setObjectName("EmailFrame");
        EmailFrame->setGeometry(QRect(290, 290, 261, 71));
        EmailFrame->setStyleSheet(QString::fromUtf8("background-color: #F3F3FF;\n"
"border-radius: 16px;"));
        UserFirstName = new QLabel(Form);
        UserFirstName->setObjectName("UserFirstName");
        UserFirstName->setGeometry(QRect(310, 310, 81, 31));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Roboto Serif Medium")});
        font2.setPointSize(16);
        font2.setWeight(QFont::Medium);
        font2.setItalic(false);
        UserFirstName->setFont(font2);
        UserFirstName->setAutoFillBackground(false);
        UserFirstName->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);\n"
"color: rgb(68, 81, 120);\n"
"font: 500 16pt \"Roboto Serif Medium\";"));
        UserFirstName->setScaledContents(false);
        UserFirstName->setAlignment(Qt::AlignCenter);
        generalInfo_2 = new QLabel(Form);
        generalInfo_2->setObjectName("generalInfo_2");
        generalInfo_2->setGeometry(QRect(290, 250, 101, 41));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Roboto Serif Medium")});
        font3.setPointSize(12);
        font3.setBold(false);
        font3.setItalic(false);
        generalInfo_2->setFont(font3);
        generalInfo_2->setAutoFillBackground(false);
        generalInfo_2->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);\n"
"color: #AEB7D8;\n"
"font: 400 12pt \"Roboto Serif Medium\";"));
        generalInfo_2->setScaledContents(false);
        generalInfo_2->setAlignment(Qt::AlignCenter);
        EmailFrame_2 = new QLabel(Form);
        EmailFrame_2->setObjectName("EmailFrame_2");
        EmailFrame_2->setGeometry(QRect(600, 290, 261, 71));
        EmailFrame_2->setStyleSheet(QString::fromUtf8("background-color: #F3F3FF;\n"
"border-radius: 16px;"));
        UserLastName = new QLabel(Form);
        UserLastName->setObjectName("UserLastName");
        UserLastName->setGeometry(QRect(620, 310, 81, 31));
        UserLastName->setFont(font2);
        UserLastName->setAutoFillBackground(false);
        UserLastName->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);\n"
"color: rgb(68, 81, 120);\n"
"font: 500 16pt \"Roboto Serif Medium\";"));
        UserLastName->setScaledContents(false);
        UserLastName->setAlignment(Qt::AlignCenter);
        generalInfo_3 = new QLabel(Form);
        generalInfo_3->setObjectName("generalInfo_3");
        generalInfo_3->setGeometry(QRect(600, 250, 101, 41));
        generalInfo_3->setFont(font3);
        generalInfo_3->setAutoFillBackground(false);
        generalInfo_3->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);\n"
"color: #AEB7D8;\n"
"font: 400 12pt \"Roboto Serif Medium\";"));
        generalInfo_3->setScaledContents(false);
        generalInfo_3->setAlignment(Qt::AlignCenter);
        SignInLabel_4 = new QLabel(Form);
        SignInLabel_4->setObjectName("SignInLabel_4");
        SignInLabel_4->setGeometry(QRect(280, 150, 121, 41));
        QFont font4;
        font4.setFamilies({QString::fromUtf8("Roboto Serif Medium")});
        font4.setPointSize(16);
        font4.setWeight(QFont::DemiBold);
        font4.setItalic(false);
        SignInLabel_4->setFont(font4);
        SignInLabel_4->setAutoFillBackground(false);
        SignInLabel_4->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);\n"
"color: rgb(68, 81, 120);\n"
"font: 600 16pt \"Roboto Serif Medium\";"));
        SignInLabel_4->setScaledContents(false);
        SignInLabel_4->setAlignment(Qt::AlignCenter);
        UserEmail = new QLabel(Form);
        UserEmail->setObjectName("UserEmail");
        UserEmail->setGeometry(QRect(290, 420, 571, 71));
        UserEmail->setStyleSheet(QString::fromUtf8("background-color: #F3F3FF;\n"
"border-radius: 16px;"));
        SignInLabel_5 = new QLabel(Form);
        SignInLabel_5->setObjectName("SignInLabel_5");
        SignInLabel_5->setGeometry(QRect(310, 440, 401, 31));
        SignInLabel_5->setFont(font2);
        SignInLabel_5->setAutoFillBackground(false);
        SignInLabel_5->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);\n"
"color: rgb(68, 81, 120);\n"
"font: 500 16pt \"Roboto Serif Medium\";"));
        SignInLabel_5->setScaledContents(false);
        SignInLabel_5->setAlignment(Qt::AlignCenter);
        generalInfo_4 = new QLabel(Form);
        generalInfo_4->setObjectName("generalInfo_4");
        generalInfo_4->setGeometry(QRect(290, 380, 51, 41));
        generalInfo_4->setFont(font3);
        generalInfo_4->setAutoFillBackground(false);
        generalInfo_4->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);\n"
"color: #AEB7D8;\n"
"font: 400 12pt \"Roboto Serif Medium\";"));
        generalInfo_4->setScaledContents(false);
        generalInfo_4->setAlignment(Qt::AlignCenter);
        UserPassword = new QLabel(Form);
        UserPassword->setObjectName("UserPassword");
        UserPassword->setGeometry(QRect(320, 570, 221, 31));
        UserPassword->setFont(font2);
        UserPassword->setAutoFillBackground(false);
        UserPassword->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);\n"
"color: rgb(68, 81, 120);\n"
"font: 500 16pt \"Roboto Serif Medium\";"));
        UserPassword->setScaledContents(false);
        UserPassword->setAlignment(Qt::AlignCenter);
        EmailFrame_4 = new QLabel(Form);
        EmailFrame_4->setObjectName("EmailFrame_4");
        EmailFrame_4->setGeometry(QRect(290, 550, 571, 71));
        EmailFrame_4->setStyleSheet(QString::fromUtf8("background-color: #F3F3FF;\n"
"border-radius: 16px;"));
        generalInfo_5 = new QLabel(Form);
        generalInfo_5->setObjectName("generalInfo_5");
        generalInfo_5->setGeometry(QRect(290, 510, 91, 41));
        generalInfo_5->setFont(font3);
        generalInfo_5->setAutoFillBackground(false);
        generalInfo_5->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);\n"
"color: #AEB7D8;\n"
"font: 400 12pt \"Roboto Serif Medium\";"));
        generalInfo_5->setScaledContents(false);
        generalInfo_5->setAlignment(Qt::AlignCenter);
        SignOut = new QPushButton(Form);
        SignOut->setObjectName("SignOut");
        SignOut->setGeometry(QRect(290, 660, 161, 51));
        SignOut->setCursor(QCursor(Qt::PointingHandCursor));
        SignOut->setAutoFillBackground(false);
        SignOut->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        SignOut->setFlat(true);
        DeleteAccount = new QPushButton(Form);
        DeleteAccount->setObjectName("DeleteAccount");
        DeleteAccount->setGeometry(QRect(620, 660, 231, 51));
        DeleteAccount->setCursor(QCursor(Qt::PointingHandCursor));
        DeleteAccount->setAutoFillBackground(false);
        DeleteAccount->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"font: 600 16pt \"Roboto Serif SemiBold\";\n"
"background-color: #FF0000;\n"
"border-radius: 10px;\n"
"color:#ffffff;\n"
"}\n"
"QPushButton:hover {\n"
"font: 600 16pt \"Roboto Serif SemiBold\";\n"
"background-color: #E20505\n"
"border-radius: 10px;\n"
"color:#ffffff;\n"
" }\n"
"\n"
""));
        DeleteAccount->setFlat(true);
        SignInButton = new QPushButton(Form);
        SignInButton->setObjectName("SignInButton");
        SignInButton->setGeometry(QRect(770, 120, 91, 31));
        QFont font5;
        font5.setFamilies({QString::fromUtf8("Inter")});
        font5.setPointSize(12);
        font5.setBold(false);
        font5.setItalic(false);
        SignInButton->setFont(font5);
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
        Background->raise();
        Frame->raise();
        SignInLabel->raise();
        generalInfo->raise();
        EmailFrame->raise();
        UserFirstName->raise();
        generalInfo_2->raise();
        EmailFrame_2->raise();
        UserLastName->raise();
        generalInfo_3->raise();
        SignInLabel_4->raise();
        UserEmail->raise();
        SignInLabel_5->raise();
        generalInfo_4->raise();
        EmailFrame_4->raise();
        generalInfo_5->raise();
        UserPassword->raise();
        SignOut->raise();
        DeleteAccount->raise();
        SignInButton->raise();

        retranslateUi(Form);

        QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QWidget *Form)
    {
        Form->setWindowTitle(QCoreApplication::translate("Form", "Form", nullptr));
        Frame->setText(QString());
        Background->setText(QString());
        SignInLabel->setText(QCoreApplication::translate("Form", "Account settings", nullptr));
        generalInfo->setText(QCoreApplication::translate("Form", "General Info", nullptr));
        EmailFrame->setText(QString());
        UserFirstName->setText(QCoreApplication::translate("Form", "Denis", nullptr));
        generalInfo_2->setText(QCoreApplication::translate("Form", "First name", nullptr));
        EmailFrame_2->setText(QString());
        UserLastName->setText(QCoreApplication::translate("Form", "Yusein", nullptr));
        generalInfo_3->setText(QCoreApplication::translate("Form", "Last name", nullptr));
        SignInLabel_4->setText(QCoreApplication::translate("Form", "Student", nullptr));
        UserEmail->setText(QString());
        SignInLabel_5->setText(QCoreApplication::translate("Form", "DAYusein21@codingburgas.bg", nullptr));
        generalInfo_4->setText(QCoreApplication::translate("Form", "Email", nullptr));
        UserPassword->setText(QCoreApplication::translate("Form", "Denis121312!!@$", nullptr));
        EmailFrame_4->setText(QString());
        generalInfo_5->setText(QCoreApplication::translate("Form", "Password", nullptr));
        SignOut->setText(QCoreApplication::translate("Form", "Sign out", nullptr));
        DeleteAccount->setText(QCoreApplication::translate("Form", "Delete account", nullptr));
        SignInButton->setText(QCoreApplication::translate("Form", "Go back", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Form: public Ui_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ACCOUNT_H
