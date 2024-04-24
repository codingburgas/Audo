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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form
{
public:
    QLabel *Frame;
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
    QLabel *UserEmail_2;
    QLabel *generalInfo_4;
    QLabel *UserPassword;
    QLabel *EmailFrame_4;
    QLabel *generalInfo_5;
    QPushButton *SignOut;
    QPushButton *DeleteAccount;
    QLabel *Frame_2;
    QLabel *Name;
    QLabel *Status;
    QLabel *EmailFrame_5;
    QLabel *UserOrganisation;
    QLabel *generalInfo_6;
    QLabel *Background_4;
    QPushButton *SignOut_4;
    QLabel *Background_3;
    QPushButton *SignOut_2;
    QLabel *Background_2;
    QLabel *Background;
    QLabel *Frame_3;
    QPushButton *SignOut_3;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QSpacerItem *verticalSpacer_3;

    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName("Form");
        Form->resize(1280, 832);
        Form->setMinimumSize(QSize(1280, 832));
        Form->setMaximumSize(QSize(1280, 832));
        Form->setAutoFillBackground(false);
        Form->setStyleSheet(QString::fromUtf8("background-color:#F9F9F9;\n"
""));
        Frame = new QLabel(Form);
        Frame->setObjectName("Frame");
        Frame->setGeometry(QRect(329, 100, 941, 771));
        Frame->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
""));
        SignInLabel = new QLabel(Form);
        SignInLabel->setObjectName("SignInLabel");
        SignInLabel->setGeometry(QRect(400, 130, 241, 41));
        QFont font;
        font.setFamilies({QString::fromUtf8("Roboto Serif Medium")});
        font.setPointSize(18);
        font.setWeight(QFont::DemiBold);
        font.setItalic(false);
        SignInLabel->setFont(font);
        SignInLabel->setAutoFillBackground(false);
        SignInLabel->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);\n"
"color: #000000;\n"
"font: 600 18pt \"Roboto Serif Medium\";"));
        SignInLabel->setScaledContents(false);
        SignInLabel->setAlignment(Qt::AlignCenter);
        generalInfo = new QLabel(Form);
        generalInfo->setObjectName("generalInfo");
        generalInfo->setGeometry(QRect(400, 220, 141, 41));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Roboto Serif Medium")});
        font1.setPointSize(14);
        font1.setWeight(QFont::DemiBold);
        font1.setItalic(false);
        generalInfo->setFont(font1);
        generalInfo->setAutoFillBackground(false);
        generalInfo->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);\n"
"color: #7F7F7F;\n"
"font: 600 14pt \"Roboto Serif Medium\";"));
        generalInfo->setScaledContents(false);
        generalInfo->setAlignment(Qt::AlignCenter);
        EmailFrame = new QLabel(Form);
        EmailFrame->setObjectName("EmailFrame");
        EmailFrame->setGeometry(QRect(400, 320, 351, 61));
        EmailFrame->setStyleSheet(QString::fromUtf8("background-color: #EEEEEE;\n"
"border-radius: 16px;"));
        UserFirstName = new QLabel(Form);
        UserFirstName->setObjectName("UserFirstName");
        UserFirstName->setGeometry(QRect(420, 330, 61, 41));
        UserFirstName->setFont(font1);
        UserFirstName->setAutoFillBackground(false);
        UserFirstName->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);\n"
"color: #000000;\n"
"font: 600 14pt \"Roboto Serif Medium\";"));
        UserFirstName->setScaledContents(false);
        UserFirstName->setAlignment(Qt::AlignCenter);
        generalInfo_2 = new QLabel(Form);
        generalInfo_2->setObjectName("generalInfo_2");
        generalInfo_2->setGeometry(QRect(400, 280, 81, 41));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Roboto Serif Medium")});
        font2.setPointSize(10);
        font2.setBold(false);
        font2.setItalic(false);
        generalInfo_2->setFont(font2);
        generalInfo_2->setAutoFillBackground(false);
        generalInfo_2->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);\n"
"color: #BFBFBF;\n"
"font: 400 10pt \"Roboto Serif Medium\";"));
        generalInfo_2->setScaledContents(false);
        generalInfo_2->setAlignment(Qt::AlignCenter);
        EmailFrame_2 = new QLabel(Form);
        EmailFrame_2->setObjectName("EmailFrame_2");
        EmailFrame_2->setGeometry(QRect(820, 320, 361, 61));
        EmailFrame_2->setStyleSheet(QString::fromUtf8("background-color: #EEEEEE;\n"
"border-radius: 16px;"));
        UserLastName = new QLabel(Form);
        UserLastName->setObjectName("UserLastName");
        UserLastName->setGeometry(QRect(840, 330, 71, 41));
        UserLastName->setFont(font1);
        UserLastName->setAutoFillBackground(false);
        UserLastName->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);\n"
"color: #000000;\n"
"font: 600 14pt \"Roboto Serif Medium\";"));
        UserLastName->setScaledContents(false);
        UserLastName->setAlignment(Qt::AlignCenter);
        generalInfo_3 = new QLabel(Form);
        generalInfo_3->setObjectName("generalInfo_3");
        generalInfo_3->setGeometry(QRect(820, 280, 81, 41));
        generalInfo_3->setFont(font2);
        generalInfo_3->setAutoFillBackground(false);
        generalInfo_3->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);\n"
"color: #BFBFBF;\n"
"font: 400 10pt \"Roboto Serif Medium\";"));
        generalInfo_3->setScaledContents(false);
        generalInfo_3->setAlignment(Qt::AlignCenter);
        SignInLabel_4 = new QLabel(Form);
        SignInLabel_4->setObjectName("SignInLabel_4");
        SignInLabel_4->setGeometry(QRect(400, 160, 91, 41));
        SignInLabel_4->setFont(font1);
        SignInLabel_4->setAutoFillBackground(false);
        SignInLabel_4->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);\n"
"color: #404040;;\n"
"font: 600 14pt \"Roboto Serif Medium\";"));
        SignInLabel_4->setScaledContents(false);
        SignInLabel_4->setAlignment(Qt::AlignCenter);
        UserEmail = new QLabel(Form);
        UserEmail->setObjectName("UserEmail");
        UserEmail->setGeometry(QRect(400, 430, 781, 61));
        UserEmail->setStyleSheet(QString::fromUtf8("background-color: #EEEEEE;\n"
"border-radius: 16px;"));
        UserEmail_2 = new QLabel(Form);
        UserEmail_2->setObjectName("UserEmail_2");
        UserEmail_2->setGeometry(QRect(420, 440, 341, 41));
        UserEmail_2->setFont(font1);
        UserEmail_2->setAutoFillBackground(false);
        UserEmail_2->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);\n"
"color: #000000;\n"
"font: 600 14pt \"Roboto Serif Medium\";"));
        UserEmail_2->setScaledContents(false);
        UserEmail_2->setAlignment(Qt::AlignCenter);
        generalInfo_4 = new QLabel(Form);
        generalInfo_4->setObjectName("generalInfo_4");
        generalInfo_4->setGeometry(QRect(400, 390, 41, 41));
        generalInfo_4->setFont(font2);
        generalInfo_4->setAutoFillBackground(false);
        generalInfo_4->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);\n"
"color: #BFBFBF;\n"
"font: 400 10pt \"Roboto Serif Medium\";"));
        generalInfo_4->setScaledContents(false);
        generalInfo_4->setAlignment(Qt::AlignCenter);
        UserPassword = new QLabel(Form);
        UserPassword->setObjectName("UserPassword");
        UserPassword->setGeometry(QRect(420, 560, 201, 31));
        UserPassword->setFont(font1);
        UserPassword->setAutoFillBackground(false);
        UserPassword->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);\n"
"color: #000000;\n"
"font: 600 14pt \"Roboto Serif Medium\";"));
        UserPassword->setScaledContents(false);
        UserPassword->setAlignment(Qt::AlignCenter);
        EmailFrame_4 = new QLabel(Form);
        EmailFrame_4->setObjectName("EmailFrame_4");
        EmailFrame_4->setGeometry(QRect(400, 540, 781, 61));
        EmailFrame_4->setStyleSheet(QString::fromUtf8("background-color: #EEEEEE;\n"
"border-radius: 16px;"));
        generalInfo_5 = new QLabel(Form);
        generalInfo_5->setObjectName("generalInfo_5");
        generalInfo_5->setGeometry(QRect(400, 500, 71, 41));
        generalInfo_5->setFont(font2);
        generalInfo_5->setAutoFillBackground(false);
        generalInfo_5->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);\n"
"color: #BFBFBF;\n"
"font: 400 10pt \"Roboto Serif Medium\";"));
        generalInfo_5->setScaledContents(false);
        generalInfo_5->setAlignment(Qt::AlignCenter);
        SignOut = new QPushButton(Form);
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
        DeleteAccount = new QPushButton(Form);
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
        Frame_2 = new QLabel(Form);
        Frame_2->setObjectName("Frame_2");
        Frame_2->setGeometry(QRect(329, 10, 941, 71));
        Frame_2->setStyleSheet(QString::fromUtf8("QFrame {\n"
"    background-color: #ffffff; \n"
"}"));
        Name = new QLabel(Form);
        Name->setObjectName("Name");
        Name->setGeometry(QRect(1080, 10, 171, 41));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Roboto Serif")});
        font3.setPointSize(14);
        Name->setFont(font3);
        Name->setStyleSheet(QString::fromUtf8("background: none;\n"
"background-color: rgba(255, 255, 255, 0);\n"
"color: #000000;"));
        Name->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        Status = new QLabel(Form);
        Status->setObjectName("Status");
        Status->setGeometry(QRect(1030, 40, 221, 41));
        QFont font4;
        font4.setFamilies({QString::fromUtf8("Roboto Serif")});
        font4.setPointSize(11);
        Status->setFont(font4);
        Status->setStyleSheet(QString::fromUtf8("background: none;\n"
"background-color: rgba(255, 255, 255, 0);\n"
"color: #777777;"));
        Status->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        EmailFrame_5 = new QLabel(Form);
        EmailFrame_5->setObjectName("EmailFrame_5");
        EmailFrame_5->setGeometry(QRect(400, 650, 781, 61));
        EmailFrame_5->setStyleSheet(QString::fromUtf8("background-color: #EEEEEE;\n"
"border-radius: 16px;"));
        UserOrganisation = new QLabel(Form);
        UserOrganisation->setObjectName("UserOrganisation");
        UserOrganisation->setGeometry(QRect(420, 670, 71, 31));
        UserOrganisation->setFont(font1);
        UserOrganisation->setAutoFillBackground(false);
        UserOrganisation->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);\n"
"color: #000000;\n"
"font: 600 14pt \"Roboto Serif Medium\";"));
        UserOrganisation->setScaledContents(false);
        UserOrganisation->setAlignment(Qt::AlignCenter);
        generalInfo_6 = new QLabel(Form);
        generalInfo_6->setObjectName("generalInfo_6");
        generalInfo_6->setGeometry(QRect(400, 610, 101, 41));
        generalInfo_6->setFont(font2);
        generalInfo_6->setAutoFillBackground(false);
        generalInfo_6->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);\n"
"color: #BFBFBF;\n"
"font: 400 10pt \"Roboto Serif Medium\";"));
        generalInfo_6->setScaledContents(false);
        generalInfo_6->setAlignment(Qt::AlignCenter);
        Background_4 = new QLabel(Form);
        Background_4->setObjectName("Background_4");
        Background_4->setGeometry(QRect(0, 20, 311, 51));
        Background_4->setAutoFillBackground(false);
        Background_4->setStyleSheet(QString::fromUtf8("background:none;"));
        Background_4->setPixmap(QPixmap(QString::fromUtf8(":/icons/assets/icons/logo.png")));
        Background_4->setAlignment(Qt::AlignCenter);
        SignOut_4 = new QPushButton(Form);
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
        Background_3 = new QLabel(Form);
        Background_3->setObjectName("Background_3");
        Background_3->setGeometry(QRect(40, 240, 31, 31));
        Background_3->setAutoFillBackground(false);
        Background_3->setStyleSheet(QString::fromUtf8("background:none;"));
        Background_3->setPixmap(QPixmap(QString::fromUtf8(":/icons/assets/icons/classes-icon.png")));
        Background_3->setAlignment(Qt::AlignCenter);
        SignOut_2 = new QPushButton(Form);
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
        Background_2 = new QLabel(Form);
        Background_2->setObjectName("Background_2");
        Background_2->setGeometry(QRect(40, 190, 31, 31));
        Background_2->setAutoFillBackground(false);
        Background_2->setStyleSheet(QString::fromUtf8("background:none;"));
        Background_2->setPixmap(QPixmap(QString::fromUtf8(":/icons/assets/icons/grades-icon.png")));
        Background_2->setAlignment(Qt::AlignCenter);
        Background = new QLabel(Form);
        Background->setObjectName("Background");
        Background->setGeometry(QRect(40, 140, 31, 31));
        Background->setAutoFillBackground(false);
        Background->setStyleSheet(QString::fromUtf8("background:none;"));
        Background->setPixmap(QPixmap(QString::fromUtf8(":/icons/assets/icons/account-icon.png")));
        Background->setAlignment(Qt::AlignCenter);
        Frame_3 = new QLabel(Form);
        Frame_3->setObjectName("Frame_3");
        Frame_3->setGeometry(QRect(0, 0, 310, 832));
        Frame_3->setStyleSheet(QString::fromUtf8("QFrame {\n"
"    background-color: #ffffff; \n"
"}"));
        SignOut_3 = new QPushButton(Form);
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
        horizontalLayoutWidget = new QWidget(Form);
        horizontalLayoutWidget->setObjectName("horizontalLayoutWidget");
        horizontalLayoutWidget->setGeometry(QRect(30, 300, 241, 461));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);


        horizontalLayout_2->addLayout(verticalLayout);


        horizontalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_3);


        horizontalLayout_3->addLayout(verticalLayout_2);


        horizontalLayout->addLayout(horizontalLayout_3);

        Frame_3->raise();
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
        UserEmail_2->raise();
        generalInfo_4->raise();
        EmailFrame_4->raise();
        generalInfo_5->raise();
        UserPassword->raise();
        SignOut->raise();
        Frame_2->raise();
        Name->raise();
        Status->raise();
        EmailFrame_5->raise();
        UserOrganisation->raise();
        generalInfo_6->raise();
        SignOut_4->raise();
        SignOut_2->raise();
        SignOut_3->raise();
        Background->raise();
        Background_4->raise();
        DeleteAccount->raise();
        horizontalLayoutWidget->raise();
        Background_2->raise();
        Background_3->raise();

        retranslateUi(Form);

        QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QWidget *Form)
    {
        Form->setWindowTitle(QCoreApplication::translate("Form", "Form", nullptr));
        Frame->setText(QString());
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
        UserEmail_2->setText(QCoreApplication::translate("Form", "DAYusein21@codingburgas.bg", nullptr));
        generalInfo_4->setText(QCoreApplication::translate("Form", "Email", nullptr));
        UserPassword->setText(QCoreApplication::translate("Form", "Denis121312!!@$", nullptr));
        EmailFrame_4->setText(QString());
        generalInfo_5->setText(QCoreApplication::translate("Form", "Password", nullptr));
        SignOut->setText(QCoreApplication::translate("Form", "Sign out", nullptr));
        DeleteAccount->setText(QCoreApplication::translate("Form", "Delete account", nullptr));
        Frame_2->setText(QString());
        Name->setText(QCoreApplication::translate("Form", "Name", nullptr));
        Status->setText(QCoreApplication::translate("Form", "status", nullptr));
        EmailFrame_5->setText(QString());
        UserOrganisation->setText(QCoreApplication::translate("Form", "VSCPI", nullptr));
        generalInfo_6->setText(QCoreApplication::translate("Form", "Organisation", nullptr));
        Background_4->setText(QString());
        SignOut_4->setText(QCoreApplication::translate("Form", "Classes", nullptr));
        Background_3->setText(QString());
        SignOut_2->setText(QCoreApplication::translate("Form", "Account", nullptr));
        Background_2->setText(QString());
        Background->setText(QString());
        Frame_3->setText(QString());
        SignOut_3->setText(QCoreApplication::translate("Form", "Grades", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Form: public Ui_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ACCOUNT_H
