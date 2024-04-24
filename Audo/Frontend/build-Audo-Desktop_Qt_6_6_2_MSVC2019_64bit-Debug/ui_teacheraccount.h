/********************************************************************************
** Form generated from reading UI file 'teacheraccount.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TEACHERACCOUNT_H
#define UI_TEACHERACCOUNT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_teacherAccount
{
public:
    QLabel *UserFirstName;
    QLabel *EmailFrame_4;
    QLabel *EmailFrame;
    QLabel *EmailFrame_2;
    QPushButton *SignOut_4;
    QLabel *Background_3;
    QPushButton *SignOut_2;
    QLabel *Background_4;
    QLabel *Frame_3;
    QPushButton *SignOut_3;
    QLabel *Background_2;
    QLabel *Background;
    QLabel *generalInfo_2;
    QLabel *SignInLabel_4;
    QLabel *EmailFrame_3;
    QLabel *EmailFrame_5;
    QLabel *UserEmail_2;
    QLabel *UserLastName;
    QLabel *generalInfo_5;
    QLabel *generalInfo_6;
    QLabel *UserPassword;
    QPushButton *SignOut;
    QLabel *EmailFrame_6;
    QLabel *generalInfo_3;
    QLabel *Frame;
    QLabel *generalInfo;
    QLabel *UserEmail;
    QPushButton *DeleteAccount;
    QLabel *UserFirstName_2;
    QLabel *EmailFrame_7;
    QLabel *generalInfo_4;
    QLabel *SignInLabel;
    QLabel *UserOrganisation;
    QLabel *Frame_2;
    QLabel *Name;
    QLabel *Status;

    void setupUi(QWidget *teacherAccount)
    {
        if (teacherAccount->objectName().isEmpty())
            teacherAccount->setObjectName("teacherAccount");
        teacherAccount->resize(1280, 832);
        teacherAccount->setMinimumSize(QSize(1280, 832));
        teacherAccount->setMaximumSize(QSize(1280, 832));
        UserFirstName = new QLabel(teacherAccount);
        UserFirstName->setObjectName("UserFirstName");
        UserFirstName->setGeometry(QRect(430, 340, 71, 31));
        QFont font;
        font.setFamilies({QString::fromUtf8("Roboto Serif Medium")});
        font.setPointSize(16);
        font.setWeight(QFont::DemiBold);
        font.setItalic(false);
        UserFirstName->setFont(font);
        UserFirstName->setAutoFillBackground(false);
        UserFirstName->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);\n"
"color: #000000;\n"
"font: 600 16pt \"Roboto Serif Medium\";"));
        UserFirstName->setScaledContents(false);
        UserFirstName->setAlignment(Qt::AlignCenter);
        EmailFrame_4 = new QLabel(teacherAccount);
        EmailFrame_4->setObjectName("EmailFrame_4");
        EmailFrame_4->setGeometry(QRect(410, 540, 781, 61));
        EmailFrame_4->setStyleSheet(QString::fromUtf8("background-color: #EEEEEE;\n"
"border-radius: 16px;"));
        EmailFrame = new QLabel(teacherAccount);
        EmailFrame->setObjectName("EmailFrame");
        EmailFrame->setGeometry(QRect(410, 320, 351, 61));
        EmailFrame->setStyleSheet(QString::fromUtf8("background-color: #EEEEEE;\n"
"border-radius: 16px;"));
        EmailFrame_2 = new QLabel(teacherAccount);
        EmailFrame_2->setObjectName("EmailFrame_2");
        EmailFrame_2->setGeometry(QRect(830, 320, 361, 61));
        EmailFrame_2->setStyleSheet(QString::fromUtf8("background-color: #EEEEEE;\n"
"border-radius: 16px;"));
        SignOut_4 = new QPushButton(teacherAccount);
        SignOut_4->setObjectName("SignOut_4");
        SignOut_4->setGeometry(QRect(30, 230, 241, 51));
        SignOut_4->setCursor(QCursor(Qt::PointingHandCursor));
        SignOut_4->setAutoFillBackground(false);
        SignOut_4->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"font: 600 14pt \"Roboto Serif SemiBold\";\n"
"background:none;\n"
"border-radius: 10px;\n"
"color: #777777;\n"
"}\n"
"QPushButton:hover {\n"
"font: 600 14pt \"Roboto Serif SemiBold\";\n"
"border-radius: 10px;\n"
"color: #000000;\n"
"background-color: #EEEEEE;\n"
" }\n"
"\n"
""));
        SignOut_4->setFlat(true);
        Background_3 = new QLabel(teacherAccount);
        Background_3->setObjectName("Background_3");
        Background_3->setGeometry(QRect(40, 240, 31, 31));
        Background_3->setAutoFillBackground(false);
        Background_3->setStyleSheet(QString::fromUtf8("background:none;"));
        Background_3->setPixmap(QPixmap(QString::fromUtf8(":/icons/assets/icons/classes-icon.png")));
        Background_3->setAlignment(Qt::AlignCenter);
        SignOut_2 = new QPushButton(teacherAccount);
        SignOut_2->setObjectName("SignOut_2");
        SignOut_2->setGeometry(QRect(30, 130, 241, 51));
        SignOut_2->setCursor(QCursor(Qt::PointingHandCursor));
        SignOut_2->setAutoFillBackground(false);
        SignOut_2->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"font: 600 14pt \"Roboto Serif SemiBold\";\n"
"background:none;\n"
"border-radius: 10px;\n"
"color: #777777;\n"
"}\n"
"QPushButton:hover {\n"
"font: 600 14pt \"Roboto Serif SemiBold\";\n"
"border-radius: 10px;\n"
"color: #000000;\n"
"background-color: #EEEEEE;\n"
" }\n"
"\n"
""));
        SignOut_2->setFlat(true);
        Background_4 = new QLabel(teacherAccount);
        Background_4->setObjectName("Background_4");
        Background_4->setGeometry(QRect(0, 20, 311, 51));
        Background_4->setAutoFillBackground(false);
        Background_4->setStyleSheet(QString::fromUtf8("background:none;"));
        Background_4->setPixmap(QPixmap(QString::fromUtf8(":/icons/assets/icons/logo.png")));
        Background_4->setAlignment(Qt::AlignCenter);
        Frame_3 = new QLabel(teacherAccount);
        Frame_3->setObjectName("Frame_3");
        Frame_3->setGeometry(QRect(0, 0, 310, 832));
        Frame_3->setStyleSheet(QString::fromUtf8("QFrame {\n"
"    background-color: #ffffff; \n"
"}"));
        SignOut_3 = new QPushButton(teacherAccount);
        SignOut_3->setObjectName("SignOut_3");
        SignOut_3->setGeometry(QRect(30, 180, 241, 51));
        SignOut_3->setCursor(QCursor(Qt::PointingHandCursor));
        SignOut_3->setAutoFillBackground(false);
        SignOut_3->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"font: 600 14pt \"Roboto Serif SemiBold\";\n"
"background:none;\n"
"border-radius: 10px;\n"
"color: #777777;\n"
"}\n"
"QPushButton:hover {\n"
"font: 600 14pt \"Roboto Serif SemiBold\";\n"
"border-radius: 10px;\n"
"color: #000000;\n"
"background-color: #EEEEEE;\n"
" }\n"
"\n"
""));
        SignOut_3->setFlat(true);
        Background_2 = new QLabel(teacherAccount);
        Background_2->setObjectName("Background_2");
        Background_2->setGeometry(QRect(40, 190, 31, 31));
        Background_2->setAutoFillBackground(false);
        Background_2->setStyleSheet(QString::fromUtf8("background:none;"));
        Background_2->setPixmap(QPixmap(QString::fromUtf8(":/icons/assets/icons/participants-icon.png")));
        Background_2->setAlignment(Qt::AlignCenter);
        Background = new QLabel(teacherAccount);
        Background->setObjectName("Background");
        Background->setGeometry(QRect(40, 140, 31, 31));
        Background->setAutoFillBackground(false);
        Background->setStyleSheet(QString::fromUtf8("background:none;"));
        Background->setPixmap(QPixmap(QString::fromUtf8(":/icons/assets/icons/account-icon.png")));
        Background->setAlignment(Qt::AlignCenter);
        generalInfo_2 = new QLabel(teacherAccount);
        generalInfo_2->setObjectName("generalInfo_2");
        generalInfo_2->setGeometry(QRect(400, 280, 81, 41));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Roboto Serif Medium")});
        font1.setPointSize(10);
        font1.setBold(false);
        font1.setItalic(false);
        generalInfo_2->setFont(font1);
        generalInfo_2->setAutoFillBackground(false);
        generalInfo_2->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);\n"
"color: #BFBFBF;\n"
"font: 400 10pt \"Roboto Serif Medium\";"));
        generalInfo_2->setScaledContents(false);
        generalInfo_2->setAlignment(Qt::AlignCenter);
        SignInLabel_4 = new QLabel(teacherAccount);
        SignInLabel_4->setObjectName("SignInLabel_4");
        SignInLabel_4->setGeometry(QRect(400, 160, 91, 41));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Roboto Serif Medium")});
        font2.setPointSize(14);
        font2.setWeight(QFont::DemiBold);
        font2.setItalic(false);
        SignInLabel_4->setFont(font2);
        SignInLabel_4->setAutoFillBackground(false);
        SignInLabel_4->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);\n"
"color: #404040;;\n"
"font: 600 14pt \"Roboto Serif Medium\";"));
        SignInLabel_4->setScaledContents(false);
        SignInLabel_4->setAlignment(Qt::AlignCenter);
        EmailFrame_3 = new QLabel(teacherAccount);
        EmailFrame_3->setObjectName("EmailFrame_3");
        EmailFrame_3->setGeometry(QRect(820, 320, 361, 61));
        EmailFrame_3->setStyleSheet(QString::fromUtf8("background-color: #EEEEEE;\n"
"border-radius: 16px;"));
        EmailFrame_5 = new QLabel(teacherAccount);
        EmailFrame_5->setObjectName("EmailFrame_5");
        EmailFrame_5->setGeometry(QRect(400, 540, 781, 61));
        EmailFrame_5->setStyleSheet(QString::fromUtf8("background-color: #EEEEEE;\n"
"border-radius: 16px;"));
        UserEmail_2 = new QLabel(teacherAccount);
        UserEmail_2->setObjectName("UserEmail_2");
        UserEmail_2->setGeometry(QRect(420, 440, 341, 41));
        UserEmail_2->setFont(font2);
        UserEmail_2->setAutoFillBackground(false);
        UserEmail_2->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);\n"
"color: #000000;\n"
"font: 600 14pt \"Roboto Serif Medium\";"));
        UserEmail_2->setScaledContents(false);
        UserEmail_2->setAlignment(Qt::AlignCenter);
        UserLastName = new QLabel(teacherAccount);
        UserLastName->setObjectName("UserLastName");
        UserLastName->setGeometry(QRect(840, 330, 71, 41));
        UserLastName->setFont(font2);
        UserLastName->setAutoFillBackground(false);
        UserLastName->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);\n"
"color: #000000;\n"
"font: 600 14pt \"Roboto Serif Medium\";"));
        UserLastName->setScaledContents(false);
        UserLastName->setAlignment(Qt::AlignCenter);
        generalInfo_5 = new QLabel(teacherAccount);
        generalInfo_5->setObjectName("generalInfo_5");
        generalInfo_5->setGeometry(QRect(400, 500, 71, 41));
        generalInfo_5->setFont(font1);
        generalInfo_5->setAutoFillBackground(false);
        generalInfo_5->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);\n"
"color: #BFBFBF;\n"
"font: 400 10pt \"Roboto Serif Medium\";"));
        generalInfo_5->setScaledContents(false);
        generalInfo_5->setAlignment(Qt::AlignCenter);
        generalInfo_6 = new QLabel(teacherAccount);
        generalInfo_6->setObjectName("generalInfo_6");
        generalInfo_6->setGeometry(QRect(400, 610, 101, 41));
        generalInfo_6->setFont(font1);
        generalInfo_6->setAutoFillBackground(false);
        generalInfo_6->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);\n"
"color: #BFBFBF;\n"
"font: 400 10pt \"Roboto Serif Medium\";"));
        generalInfo_6->setScaledContents(false);
        generalInfo_6->setAlignment(Qt::AlignCenter);
        UserPassword = new QLabel(teacherAccount);
        UserPassword->setObjectName("UserPassword");
        UserPassword->setGeometry(QRect(420, 550, 201, 41));
        UserPassword->setFont(font2);
        UserPassword->setAutoFillBackground(false);
        UserPassword->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);\n"
"color: #000000;\n"
"font: 600 14pt \"Roboto Serif Medium\";"));
        UserPassword->setScaledContents(false);
        UserPassword->setAlignment(Qt::AlignCenter);
        SignOut = new QPushButton(teacherAccount);
        SignOut->setObjectName("SignOut");
        SignOut->setGeometry(QRect(720, 750, 161, 51));
        SignOut->setCursor(QCursor(Qt::PointingHandCursor));
        SignOut->setAutoFillBackground(false);
        SignOut->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"font: 600 14pt \"Roboto Serif SemiBold\";\n"
"background-color: #4282FF;\n"
"border-radius: 10px;\n"
"color:#ffffff;\n"
"}\n"
"QPushButton:hover {\n"
"font: 600 14pt \"Roboto Serif SemiBold\";\n"
"background-color: #0057FF;\n"
"border-radius: 10px;\n"
"color:#ffffff;\n"
" }\n"
"\n"
""));
        SignOut->setFlat(true);
        EmailFrame_6 = new QLabel(teacherAccount);
        EmailFrame_6->setObjectName("EmailFrame_6");
        EmailFrame_6->setGeometry(QRect(400, 320, 351, 61));
        EmailFrame_6->setStyleSheet(QString::fromUtf8("background-color: #EEEEEE;\n"
"border-radius: 16px;"));
        generalInfo_3 = new QLabel(teacherAccount);
        generalInfo_3->setObjectName("generalInfo_3");
        generalInfo_3->setGeometry(QRect(820, 280, 81, 41));
        generalInfo_3->setFont(font1);
        generalInfo_3->setAutoFillBackground(false);
        generalInfo_3->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);\n"
"color: #BFBFBF;\n"
"font: 400 10pt \"Roboto Serif Medium\";"));
        generalInfo_3->setScaledContents(false);
        generalInfo_3->setAlignment(Qt::AlignCenter);
        Frame = new QLabel(teacherAccount);
        Frame->setObjectName("Frame");
        Frame->setGeometry(QRect(329, 100, 941, 771));
        Frame->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
""));
        generalInfo = new QLabel(teacherAccount);
        generalInfo->setObjectName("generalInfo");
        generalInfo->setGeometry(QRect(400, 220, 141, 41));
        generalInfo->setFont(font2);
        generalInfo->setAutoFillBackground(false);
        generalInfo->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);\n"
"color: #7F7F7F;\n"
"font: 600 14pt \"Roboto Serif Medium\";"));
        generalInfo->setScaledContents(false);
        generalInfo->setAlignment(Qt::AlignCenter);
        UserEmail = new QLabel(teacherAccount);
        UserEmail->setObjectName("UserEmail");
        UserEmail->setGeometry(QRect(400, 430, 781, 61));
        UserEmail->setStyleSheet(QString::fromUtf8("background-color: #EEEEEE;\n"
"border-radius: 16px;"));
        DeleteAccount = new QPushButton(teacherAccount);
        DeleteAccount->setObjectName("DeleteAccount");
        DeleteAccount->setGeometry(QRect(950, 750, 231, 51));
        DeleteAccount->setCursor(QCursor(Qt::PointingHandCursor));
        DeleteAccount->setAutoFillBackground(false);
        DeleteAccount->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"font: 600 14pt \"Roboto Serif SemiBold\";\n"
"background-color: #FF0000;\n"
"border-radius: 10px;\n"
"color:#ffffff;\n"
"}\n"
"QPushButton:hover {\n"
"font: 600 14pt \"Roboto Serif SemiBold\";\n"
"background-color: #E20505\n"
"border-radius: 10px;\n"
"color:#ffffff;\n"
" }\n"
"\n"
""));
        DeleteAccount->setFlat(true);
        UserFirstName_2 = new QLabel(teacherAccount);
        UserFirstName_2->setObjectName("UserFirstName_2");
        UserFirstName_2->setGeometry(QRect(420, 330, 61, 41));
        UserFirstName_2->setFont(font2);
        UserFirstName_2->setAutoFillBackground(false);
        UserFirstName_2->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);\n"
"color: #000000;\n"
"font: 600 14pt \"Roboto Serif Medium\";"));
        UserFirstName_2->setScaledContents(false);
        UserFirstName_2->setAlignment(Qt::AlignCenter);
        EmailFrame_7 = new QLabel(teacherAccount);
        EmailFrame_7->setObjectName("EmailFrame_7");
        EmailFrame_7->setGeometry(QRect(400, 650, 781, 61));
        EmailFrame_7->setStyleSheet(QString::fromUtf8("background-color: #EEEEEE;\n"
"border-radius: 16px;"));
        generalInfo_4 = new QLabel(teacherAccount);
        generalInfo_4->setObjectName("generalInfo_4");
        generalInfo_4->setGeometry(QRect(400, 390, 41, 41));
        generalInfo_4->setFont(font1);
        generalInfo_4->setAutoFillBackground(false);
        generalInfo_4->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);\n"
"color: #BFBFBF;\n"
"font: 400 10pt \"Roboto Serif Medium\";"));
        generalInfo_4->setScaledContents(false);
        generalInfo_4->setAlignment(Qt::AlignCenter);
        SignInLabel = new QLabel(teacherAccount);
        SignInLabel->setObjectName("SignInLabel");
        SignInLabel->setGeometry(QRect(400, 130, 241, 41));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Roboto Serif Medium")});
        font3.setPointSize(18);
        font3.setWeight(QFont::DemiBold);
        font3.setItalic(false);
        SignInLabel->setFont(font3);
        SignInLabel->setAutoFillBackground(false);
        SignInLabel->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);\n"
"color: #000000;\n"
"font: 600 18pt \"Roboto Serif Medium\";"));
        SignInLabel->setScaledContents(false);
        SignInLabel->setAlignment(Qt::AlignCenter);
        UserOrganisation = new QLabel(teacherAccount);
        UserOrganisation->setObjectName("UserOrganisation");
        UserOrganisation->setGeometry(QRect(420, 660, 71, 41));
        UserOrganisation->setFont(font2);
        UserOrganisation->setAutoFillBackground(false);
        UserOrganisation->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);\n"
"color: #000000;\n"
"font: 600 14pt \"Roboto Serif Medium\";"));
        UserOrganisation->setScaledContents(false);
        UserOrganisation->setAlignment(Qt::AlignCenter);
        Frame_2 = new QLabel(teacherAccount);
        Frame_2->setObjectName("Frame_2");
        Frame_2->setGeometry(QRect(329, 10, 941, 71));
        Frame_2->setStyleSheet(QString::fromUtf8("QFrame {\n"
"    background-color: #ffffff; \n"
"}"));
        Name = new QLabel(teacherAccount);
        Name->setObjectName("Name");
        Name->setGeometry(QRect(1080, 10, 171, 41));
        QFont font4;
        font4.setFamilies({QString::fromUtf8("Roboto Serif")});
        font4.setPointSize(14);
        Name->setFont(font4);
        Name->setStyleSheet(QString::fromUtf8("background: none;\n"
"background-color: rgba(255, 255, 255, 0);\n"
"color: #000000;"));
        Name->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        Status = new QLabel(teacherAccount);
        Status->setObjectName("Status");
        Status->setGeometry(QRect(1030, 40, 221, 41));
        QFont font5;
        font5.setFamilies({QString::fromUtf8("Roboto Serif")});
        font5.setPointSize(11);
        Status->setFont(font5);
        Status->setStyleSheet(QString::fromUtf8("background: none;\n"
"background-color: rgba(255, 255, 255, 0);\n"
"color: #777777;"));
        Status->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        Frame->raise();
        Frame_3->raise();
        UserFirstName->raise();
        EmailFrame_4->raise();
        EmailFrame->raise();
        EmailFrame_2->raise();
        SignOut_4->raise();
        SignOut_2->raise();
        Background_4->raise();
        SignOut_3->raise();
        Background->raise();
        Background_2->raise();
        Background_3->raise();
        generalInfo_2->raise();
        SignInLabel_4->raise();
        EmailFrame_3->raise();
        EmailFrame_5->raise();
        UserLastName->raise();
        generalInfo_5->raise();
        generalInfo_6->raise();
        UserPassword->raise();
        SignOut->raise();
        EmailFrame_6->raise();
        generalInfo_3->raise();
        generalInfo->raise();
        UserEmail->raise();
        DeleteAccount->raise();
        UserFirstName_2->raise();
        EmailFrame_7->raise();
        generalInfo_4->raise();
        SignInLabel->raise();
        UserEmail_2->raise();
        UserOrganisation->raise();
        Frame_2->raise();
        Name->raise();
        Status->raise();

        retranslateUi(teacherAccount);

        QMetaObject::connectSlotsByName(teacherAccount);
    } // setupUi

    void retranslateUi(QWidget *teacherAccount)
    {
        teacherAccount->setWindowTitle(QCoreApplication::translate("teacherAccount", "Form", nullptr));
        UserFirstName->setText(QCoreApplication::translate("teacherAccount", "Denis", nullptr));
        EmailFrame_4->setText(QString());
        EmailFrame->setText(QString());
        EmailFrame_2->setText(QString());
        SignOut_4->setText(QCoreApplication::translate("teacherAccount", "Classes", nullptr));
        Background_3->setText(QString());
        SignOut_2->setText(QCoreApplication::translate("teacherAccount", "Account", nullptr));
        Background_4->setText(QString());
        Frame_3->setText(QString());
        SignOut_3->setText(QCoreApplication::translate("teacherAccount", "Participants", nullptr));
        Background_2->setText(QString());
        Background->setText(QString());
        generalInfo_2->setText(QCoreApplication::translate("teacherAccount", "First name", nullptr));
        SignInLabel_4->setText(QCoreApplication::translate("teacherAccount", "Teacher", nullptr));
        EmailFrame_3->setText(QString());
        EmailFrame_5->setText(QString());
        UserEmail_2->setText(QCoreApplication::translate("teacherAccount", "DAYusein21@codingburgas.bg", nullptr));
        UserLastName->setText(QCoreApplication::translate("teacherAccount", "Yusein", nullptr));
        generalInfo_5->setText(QCoreApplication::translate("teacherAccount", "Password", nullptr));
        generalInfo_6->setText(QCoreApplication::translate("teacherAccount", "Organisation", nullptr));
        UserPassword->setText(QCoreApplication::translate("teacherAccount", "Denis121312!!@$", nullptr));
        SignOut->setText(QCoreApplication::translate("teacherAccount", "Sign out", nullptr));
        EmailFrame_6->setText(QString());
        generalInfo_3->setText(QCoreApplication::translate("teacherAccount", "Last name", nullptr));
        Frame->setText(QString());
        generalInfo->setText(QCoreApplication::translate("teacherAccount", "General Info", nullptr));
        UserEmail->setText(QString());
        DeleteAccount->setText(QCoreApplication::translate("teacherAccount", "Delete account", nullptr));
        UserFirstName_2->setText(QCoreApplication::translate("teacherAccount", "Denis", nullptr));
        EmailFrame_7->setText(QString());
        generalInfo_4->setText(QCoreApplication::translate("teacherAccount", "Email", nullptr));
        SignInLabel->setText(QCoreApplication::translate("teacherAccount", "Account settings", nullptr));
        UserOrganisation->setText(QCoreApplication::translate("teacherAccount", "VSCPI", nullptr));
        Frame_2->setText(QString());
        Name->setText(QCoreApplication::translate("teacherAccount", "Name", nullptr));
        Status->setText(QCoreApplication::translate("teacherAccount", "status", nullptr));
    } // retranslateUi

};

namespace Ui {
    class teacherAccount: public Ui_teacherAccount {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TEACHERACCOUNT_H
