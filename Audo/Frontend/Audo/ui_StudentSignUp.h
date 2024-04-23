/********************************************************************************
** Form generated from reading UI file 'StudentSignUp.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STUDENTSIGNUP_H
#define UI_STUDENTSIGNUP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_StudentSignUp
{
public:
    QLabel *Background;
    QLabel *Frame;
    QLabel *SignInTitle;
    QLabel *SignInType;
    QLabel *FNameFrame;
    QTextEdit *FName;
    QLabel *LNameFrame;
    QTextEdit *LName;
    QLabel *EmailFrame;
    QTextEdit *Email;
    QLabel *PasswordFrame;
    QTextEdit *Password;
    QPushButton *Continue;
    QPushButton *SignInButton;
    QLabel *SignInLabel;
    QLabel *Warning;

    void setupUi(QWidget *StudentSignUp)
    {
        if (StudentSignUp->objectName().isEmpty())
            StudentSignUp->setObjectName("StudentSignUp");
        StudentSignUp->resize(1280, 832);
        StudentSignUp->setMinimumSize(QSize(1280, 832));
        StudentSignUp->setMaximumSize(QSize(1280, 832));
        StudentSignUp->setBaseSize(QSize(1280, 830));
        StudentSignUp->setStyleSheet(QString::fromUtf8("background-color: rgb(75, 76, 173);"));
        Background = new QLabel(StudentSignUp);
        Background->setObjectName("Background");
        Background->setGeometry(QRect(0, 0, 1280, 832));
        Background->setPixmap(QPixmap(QString::fromUtf8(":/backgrounds/assets/backgrounds/main-background.png")));
        Background->setAlignment(Qt::AlignCenter);
        Frame = new QLabel(StudentSignUp);
        Frame->setObjectName("Frame");
        Frame->setGeometry(QRect(300, 180, 670, 531));
        Frame->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"border-radius: 16px;"));
        SignInTitle = new QLabel(StudentSignUp);
        SignInTitle->setObjectName("SignInTitle");
        SignInTitle->setGeometry(QRect(320, 200, 121, 61));
        QFont font;
        font.setFamilies({QString::fromUtf8("Roboto Serif Medium")});
        font.setPointSize(20);
        font.setWeight(QFont::DemiBold);
        font.setItalic(false);
        font.setKerning(false);
        SignInTitle->setFont(font);
        SignInTitle->setAutoFillBackground(false);
        SignInTitle->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);\n"
"color: #000000;\n"
"font: 600 20pt \"Roboto Serif Medium\";"));
        SignInTitle->setScaledContents(false);
        SignInTitle->setAlignment(Qt::AlignCenter);
        SignInType = new QLabel(StudentSignUp);
        SignInType->setObjectName("SignInType");
        SignInType->setGeometry(QRect(320, 230, 101, 61));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Roboto Serif Medium")});
        font1.setPointSize(15);
        font1.setWeight(QFont::DemiBold);
        font1.setItalic(false);
        font1.setKerning(false);
        SignInType->setFont(font1);
        SignInType->setAutoFillBackground(false);
        SignInType->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);\n"
"color: #7F7F7F;\n"
"font: 600 15pt \"Roboto Serif Medium\";"));
        SignInType->setScaledContents(false);
        SignInType->setAlignment(Qt::AlignCenter);
        FNameFrame = new QLabel(StudentSignUp);
        FNameFrame->setObjectName("FNameFrame");
        FNameFrame->setGeometry(QRect(340, 300, 281, 71));
        FNameFrame->setStyleSheet(QString::fromUtf8("background-color: #EEEEEE;\n"
"border-radius: 16px;"));
        FName = new QTextEdit(StudentSignUp);
        FName->setObjectName("FName");
        FName->setGeometry(QRect(350, 320, 271, 41));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Roboto Serif Medium")});
        font2.setPointSize(16);
        font2.setWeight(QFont::DemiBold);
        font2.setItalic(false);
        FName->setFont(font2);
        FName->setAutoFillBackground(false);
        FName->setStyleSheet(QString::fromUtf8("background: none;\n"
"font: 600 16pt \"Roboto Serif Medium\";\n"
"background-color: rgba(255, 255, 255, 0);\n"
"border: none;\n"
"color: #777777;"));
        LNameFrame = new QLabel(StudentSignUp);
        LNameFrame->setObjectName("LNameFrame");
        LNameFrame->setGeometry(QRect(640, 300, 281, 71));
        LNameFrame->setStyleSheet(QString::fromUtf8("background-color: #EEEEEE;\n"
"border-radius: 16px;"));
        LName = new QTextEdit(StudentSignUp);
        LName->setObjectName("LName");
        LName->setGeometry(QRect(650, 320, 271, 41));
        LName->setFont(font2);
        LName->setAutoFillBackground(false);
        LName->setStyleSheet(QString::fromUtf8("background: none;\n"
"font: 600 16pt \"Roboto Serif Medium\";\n"
"background-color: rgba(255, 255, 255, 0);\n"
"border: none;\n"
"color: #777777;"));
        EmailFrame = new QLabel(StudentSignUp);
        EmailFrame->setObjectName("EmailFrame");
        EmailFrame->setGeometry(QRect(340, 390, 581, 71));
        EmailFrame->setStyleSheet(QString::fromUtf8("background-color: #EEEEEE;\n"
"border-radius: 16px;"));
        Email = new QTextEdit(StudentSignUp);
        Email->setObjectName("Email");
        Email->setGeometry(QRect(350, 410, 571, 41));
        Email->setFont(font2);
        Email->setAutoFillBackground(false);
        Email->setStyleSheet(QString::fromUtf8("background: none;\n"
"font: 600 16pt \"Roboto Serif Medium\";\n"
"background-color: rgba(255, 255, 255, 0);\n"
"border: none;\n"
"color: #777777;"));
        PasswordFrame = new QLabel(StudentSignUp);
        PasswordFrame->setObjectName("PasswordFrame");
        PasswordFrame->setGeometry(QRect(340, 480, 581, 71));
        PasswordFrame->setStyleSheet(QString::fromUtf8("background-color: #EEEEEE;\n"
"border-radius: 16px;"));
        Password = new QTextEdit(StudentSignUp);
        Password->setObjectName("Password");
        Password->setGeometry(QRect(350, 500, 571, 41));
        Password->setFont(font2);
        Password->setAutoFillBackground(false);
        Password->setStyleSheet(QString::fromUtf8("background: none;\n"
"font: 600 16pt \"Roboto Serif Medium\";\n"
"background-color: rgba(255, 255, 255, 0);\n"
"border: none;\n"
"color: #777777;"));
        Continue = new QPushButton(StudentSignUp);
        Continue->setObjectName("Continue");
        Continue->setGeometry(QRect(550, 590, 161, 51));
        Continue->setCursor(QCursor(Qt::PointingHandCursor));
        Continue->setAutoFillBackground(false);
        Continue->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"font: 600 16pt \"Roboto Serif SemiBold\";\n"
"background-color: #0047FF;\n"
"border-radius: 10px;\n"
"color:#ffffff;\n"
"}\n"
"QPushButton:hover {\n"
"font: 600 16pt \"Roboto Serif SemiBold\";\n"
"background-color: #003CD7;\n"
"border-radius: 10px;\n"
"color:#ffffff;\n"
" }\n"
"\n"
""));
        Continue->setFlat(true);
        SignInButton = new QPushButton(StudentSignUp);
        SignInButton->setObjectName("SignInButton");
        SignInButton->setGeometry(QRect(690, 670, 81, 31));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Inter")});
        font3.setPointSize(12);
        font3.setBold(true);
        SignInButton->setFont(font3);
        SignInButton->setCursor(QCursor(Qt::PointingHandCursor));
        SignInButton->setAutoFillBackground(false);
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
        SignInLabel = new QLabel(StudentSignUp);
        SignInLabel->setObjectName("SignInLabel");
        SignInLabel->setGeometry(QRect(480, 670, 261, 31));
        QFont font4;
        font4.setFamilies({QString::fromUtf8("Inter SemiBold")});
        font4.setPointSize(12);
        font4.setBold(true);
        SignInLabel->setFont(font4);
        SignInLabel->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);\n"
"color: #AAAAAA;"));
        SignInLabel->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        Warning = new QLabel(StudentSignUp);
        Warning->setObjectName("Warning");
        Warning->setGeometry(QRect(350, 270, 541, 31));
        Warning->setFont(font3);
        Warning->setAutoFillBackground(false);
        Warning->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);\n"
"color: rgb(170, 0, 0);"));
        Background->raise();
        Frame->raise();
        SignInTitle->raise();
        SignInType->raise();
        FNameFrame->raise();
        FName->raise();
        LNameFrame->raise();
        LName->raise();
        EmailFrame->raise();
        Email->raise();
        PasswordFrame->raise();
        Password->raise();
        Continue->raise();
        SignInLabel->raise();
        Warning->raise();
        SignInButton->raise();

        retranslateUi(StudentSignUp);

        QMetaObject::connectSlotsByName(StudentSignUp);
    } // setupUi

    void retranslateUi(QWidget *StudentSignUp)
    {
        StudentSignUp->setWindowTitle(QCoreApplication::translate("StudentSignUp", "Form", nullptr));
        Background->setText(QString());
        Frame->setText(QString());
        SignInTitle->setText(QCoreApplication::translate("StudentSignUp", "Sign up", nullptr));
        SignInType->setText(QCoreApplication::translate("StudentSignUp", "Student", nullptr));
        FNameFrame->setText(QString());
        FName->setPlaceholderText(QCoreApplication::translate("StudentSignUp", "First Name", nullptr));
        LNameFrame->setText(QString());
        LName->setPlaceholderText(QCoreApplication::translate("StudentSignUp", "Last Name", nullptr));
        EmailFrame->setText(QString());
        Email->setPlaceholderText(QCoreApplication::translate("StudentSignUp", "Email", nullptr));
        PasswordFrame->setText(QString());
        Password->setPlaceholderText(QCoreApplication::translate("StudentSignUp", "Password", nullptr));
        Continue->setText(QCoreApplication::translate("StudentSignUp", "Continue", nullptr));
        SignInButton->setText(QCoreApplication::translate("StudentSignUp", "Sign In", nullptr));
        SignInLabel->setText(QCoreApplication::translate("StudentSignUp", "Already have an account?", nullptr));
        Warning->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class StudentSignUp: public Ui_StudentSignUp {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STUDENTSIGNUP_H
