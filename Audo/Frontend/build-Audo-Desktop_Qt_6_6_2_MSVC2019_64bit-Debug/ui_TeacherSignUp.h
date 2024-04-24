/********************************************************************************
** Form generated from reading UI file 'TeacherSignUp.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TEACHERSIGNUP_H
#define UI_TEACHERSIGNUP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TeacherSignUp
{
public:
    QTextEdit *Password;
    QTextEdit *FName;
    QTextEdit *LName;
    QLabel *PasswordFrame;
    QPushButton *SignInButton;
    QLabel *FNameFrame;
    QLabel *Background;
    QLabel *SignInLabel;
    QLabel *EmailFrame;
    QLabel *SignInType;
    QTextEdit *Email;
    QLabel *Frame;
    QLabel *LNameFrame;
    QLabel *SignInTitle;
    QPushButton *Continue;
    QLabel *SchoolFrame;
    QTextEdit *School;
    QLabel *Warning;

    void setupUi(QWidget *TeacherSignUp)
    {
        if (TeacherSignUp->objectName().isEmpty())
            TeacherSignUp->setObjectName("TeacherSignUp");
        TeacherSignUp->resize(1280, 832);
        TeacherSignUp->setMinimumSize(QSize(1280, 832));
        TeacherSignUp->setMaximumSize(QSize(1280, 832));
        TeacherSignUp->setBaseSize(QSize(1280, 832));
        TeacherSignUp->setStyleSheet(QString::fromUtf8("background-color: rgb(75, 76, 173);"));
        Password = new QTextEdit(TeacherSignUp);
        Password->setObjectName("Password");
        Password->setGeometry(QRect(350, 430, 571, 41));
        QFont font;
        font.setFamilies({QString::fromUtf8("Roboto Serif Medium")});
        font.setPointSize(16);
        font.setWeight(QFont::DemiBold);
        font.setItalic(false);
        Password->setFont(font);
        Password->viewport()->setProperty("cursor", QVariant(QCursor(Qt::PointingHandCursor)));
        Password->setAutoFillBackground(false);
        Password->setStyleSheet(QString::fromUtf8("background: none;\n"
"font: 600 16pt \"Roboto Serif Medium\";\n"
"background-color: rgba(255, 255, 255, 0);\n"
"border: none;\n"
"color: #777777;"));
        FName = new QTextEdit(TeacherSignUp);
        FName->setObjectName("FName");
        FName->setGeometry(QRect(350, 250, 271, 41));
        FName->setFont(font);
        FName->viewport()->setProperty("cursor", QVariant(QCursor(Qt::PointingHandCursor)));
        FName->setAutoFillBackground(false);
        FName->setStyleSheet(QString::fromUtf8("background: none;\n"
"font: 600 16pt \"Roboto Serif Medium\";\n"
"background-color: rgba(255, 255, 255, 0);\n"
"border: none;\n"
"color: #777777;"));
        LName = new QTextEdit(TeacherSignUp);
        LName->setObjectName("LName");
        LName->setGeometry(QRect(650, 250, 271, 41));
        LName->setFont(font);
        LName->viewport()->setProperty("cursor", QVariant(QCursor(Qt::PointingHandCursor)));
        LName->setAutoFillBackground(false);
        LName->setStyleSheet(QString::fromUtf8("background: none;\n"
"font: 600 16pt \"Roboto Serif Medium\";\n"
"background-color: rgba(255, 255, 255, 0);\n"
"border: none;\n"
"color: #777777;"));
        PasswordFrame = new QLabel(TeacherSignUp);
        PasswordFrame->setObjectName("PasswordFrame");
        PasswordFrame->setGeometry(QRect(340, 410, 581, 71));
        PasswordFrame->setStyleSheet(QString::fromUtf8("background-color: #EEEEEE;\n"
"border-radius: 16px;"));
        SignInButton = new QPushButton(TeacherSignUp);
        SignInButton->setObjectName("SignInButton");
        SignInButton->setGeometry(QRect(680, 680, 81, 31));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Inter")});
        font1.setPointSize(12);
        font1.setBold(true);
        SignInButton->setFont(font1);
        SignInButton->setCursor(QCursor(Qt::PointingHandCursor));
        SignInButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"background-color: rgba(255, 255, 255, 0);\n"
"color: #777777;\n"
"}\n"
"QPushButton:hover {\n"
"\n"
"background-color: rgba(255, 255, 255, 0);\n"
"color: #000000;\n"
" }\n"
""));
        SignInButton->setCheckable(false);
        SignInButton->setFlat(true);
        FNameFrame = new QLabel(TeacherSignUp);
        FNameFrame->setObjectName("FNameFrame");
        FNameFrame->setGeometry(QRect(340, 230, 281, 71));
        FNameFrame->setStyleSheet(QString::fromUtf8("background-color: #EEEEEE;\n"
"border-radius: 16px;"));
        Background = new QLabel(TeacherSignUp);
        Background->setObjectName("Background");
        Background->setGeometry(QRect(0, 0, 1280, 832));
        Background->setPixmap(QPixmap(QString::fromUtf8(":/backgrounds/assets/backgrounds/main-background.png")));
        Background->setAlignment(Qt::AlignCenter);
        SignInLabel = new QLabel(TeacherSignUp);
        SignInLabel->setObjectName("SignInLabel");
        SignInLabel->setGeometry(QRect(480, 680, 271, 31));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Inter SemiBold")});
        font2.setPointSize(12);
        font2.setBold(true);
        SignInLabel->setFont(font2);
        SignInLabel->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);\n"
"color: #AAAAAA;"));
        SignInLabel->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        EmailFrame = new QLabel(TeacherSignUp);
        EmailFrame->setObjectName("EmailFrame");
        EmailFrame->setGeometry(QRect(340, 320, 581, 71));
        EmailFrame->setStyleSheet(QString::fromUtf8("background-color: #EEEEEE;\n"
"border-radius: 16px;"));
        SignInType = new QLabel(TeacherSignUp);
        SignInType->setObjectName("SignInType");
        SignInType->setGeometry(QRect(330, 150, 101, 61));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Roboto Serif Medium")});
        font3.setPointSize(15);
        font3.setWeight(QFont::DemiBold);
        font3.setItalic(false);
        font3.setKerning(false);
        SignInType->setFont(font3);
        SignInType->setAutoFillBackground(false);
        SignInType->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);\n"
"color: #7F7F7F;\n"
"font: 600 15pt \"Roboto Serif Medium\";"));
        SignInType->setScaledContents(false);
        SignInType->setAlignment(Qt::AlignCenter);
        Email = new QTextEdit(TeacherSignUp);
        Email->setObjectName("Email");
        Email->setGeometry(QRect(350, 340, 571, 41));
        Email->setFont(font);
        Email->viewport()->setProperty("cursor", QVariant(QCursor(Qt::PointingHandCursor)));
        Email->setAutoFillBackground(false);
        Email->setStyleSheet(QString::fromUtf8("background: none;\n"
"font: 600 16pt \"Roboto Serif Medium\";\n"
"background-color: rgba(255, 255, 255, 0);\n"
"border: none;\n"
"color: #777777;"));
        Frame = new QLabel(TeacherSignUp);
        Frame->setObjectName("Frame");
        Frame->setGeometry(QRect(300, 100, 670, 631));
        Frame->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"border-radius: 16px;"));
        LNameFrame = new QLabel(TeacherSignUp);
        LNameFrame->setObjectName("LNameFrame");
        LNameFrame->setGeometry(QRect(640, 230, 281, 71));
        LNameFrame->setStyleSheet(QString::fromUtf8("background-color: #EEEEEE;\n"
"border-radius: 16px;"));
        SignInTitle = new QLabel(TeacherSignUp);
        SignInTitle->setObjectName("SignInTitle");
        SignInTitle->setGeometry(QRect(330, 120, 121, 61));
        QFont font4;
        font4.setFamilies({QString::fromUtf8("Roboto Serif Medium")});
        font4.setPointSize(20);
        font4.setWeight(QFont::DemiBold);
        font4.setItalic(false);
        font4.setKerning(false);
        SignInTitle->setFont(font4);
        SignInTitle->setAutoFillBackground(false);
        SignInTitle->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);\n"
"color: #000000;\n"
"font: 600 20pt \"Roboto Serif Medium\";"));
        SignInTitle->setScaledContents(false);
        SignInTitle->setAlignment(Qt::AlignCenter);
        Continue = new QPushButton(TeacherSignUp);
        Continue->setObjectName("Continue");
        Continue->setGeometry(QRect(550, 620, 161, 51));
        Continue->setCursor(QCursor(Qt::PointingHandCursor));
        Continue->setAutoFillBackground(false);
        Continue->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"font: 600 16pt \"Roboto Serif SemiBold\";\n"
"background-color: #4282FF;\n"
"border-radius: 10px;\n"
"color:#ffffff;\n"
"}\n"
"QPushButton:hover {\n"
"font: 600 16pt \"Roboto Serif SemiBold\";\n"
"background-color: #0057FF;\n"
"border-radius: 10px;\n"
"color:#ffffff;\n"
" }\n"
"\n"
""));
        Continue->setFlat(true);
        SchoolFrame = new QLabel(TeacherSignUp);
        SchoolFrame->setObjectName("SchoolFrame");
        SchoolFrame->setGeometry(QRect(340, 500, 581, 71));
        SchoolFrame->setStyleSheet(QString::fromUtf8("background-color: #EEEEEE;\n"
"border-radius: 16px;"));
        School = new QTextEdit(TeacherSignUp);
        School->setObjectName("School");
        School->setGeometry(QRect(350, 520, 571, 41));
        School->setFont(font);
        School->viewport()->setProperty("cursor", QVariant(QCursor(Qt::PointingHandCursor)));
        School->setAutoFillBackground(false);
        School->setStyleSheet(QString::fromUtf8("background: none;\n"
"font: 600 16pt \"Roboto Serif Medium\";\n"
"background-color: rgba(255, 255, 255, 0);\n"
"border: none;\n"
"color: #777777;"));
        Warning = new QLabel(TeacherSignUp);
        Warning->setObjectName("Warning");
        Warning->setGeometry(QRect(320, 200, 511, 31));
        Warning->setFont(font1);
        Warning->setAutoFillBackground(false);
        Warning->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);\n"
"color: rgb(170, 0, 0);"));
        Background->raise();
        Frame->raise();
        PasswordFrame->raise();
        FNameFrame->raise();
        EmailFrame->raise();
        LNameFrame->raise();
        Continue->raise();
        FName->raise();
        LName->raise();
        SignInLabel->raise();
        Email->raise();
        Password->raise();
        SignInTitle->raise();
        SignInType->raise();
        SchoolFrame->raise();
        School->raise();
        SignInButton->raise();
        Warning->raise();

        retranslateUi(TeacherSignUp);

        QMetaObject::connectSlotsByName(TeacherSignUp);
    } // setupUi

    void retranslateUi(QWidget *TeacherSignUp)
    {
        TeacherSignUp->setWindowTitle(QCoreApplication::translate("TeacherSignUp", "Form", nullptr));
        Password->setPlaceholderText(QCoreApplication::translate("TeacherSignUp", "Password", nullptr));
        FName->setPlaceholderText(QCoreApplication::translate("TeacherSignUp", "First Name", nullptr));
        LName->setPlaceholderText(QCoreApplication::translate("TeacherSignUp", "Last Name", nullptr));
        PasswordFrame->setText(QString());
        SignInButton->setText(QCoreApplication::translate("TeacherSignUp", "Sign In", nullptr));
        FNameFrame->setText(QString());
        Background->setText(QString());
        SignInLabel->setText(QCoreApplication::translate("TeacherSignUp", "Already have an account?", nullptr));
        EmailFrame->setText(QString());
        SignInType->setText(QCoreApplication::translate("TeacherSignUp", "Teacher", nullptr));
        Email->setPlaceholderText(QCoreApplication::translate("TeacherSignUp", "Email", nullptr));
        Frame->setText(QString());
        LNameFrame->setText(QString());
        SignInTitle->setText(QCoreApplication::translate("TeacherSignUp", "Sign up", nullptr));
        Continue->setText(QCoreApplication::translate("TeacherSignUp", "Continue", nullptr));
        SchoolFrame->setText(QString());
        School->setPlaceholderText(QCoreApplication::translate("TeacherSignUp", "School", nullptr));
        Warning->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class TeacherSignUp: public Ui_TeacherSignUp {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TEACHERSIGNUP_H
