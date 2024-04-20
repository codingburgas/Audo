/********************************************************************************
** Form generated from reading UI file 'MainPage.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINPAGE_H
#define UI_MAINPAGE_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainPage
{
public:
    QWidget *centralwidget;
    QLabel *Background;
    QLabel *Welcome;
    QPushButton *SignIn;
    QPushButton *SignUp;

    void setupUi(QMainWindow *MainPage)
    {
        if (MainPage->objectName().isEmpty())
            MainPage->setObjectName("MainPage");
        MainPage->resize(1280, 832);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainPage->sizePolicy().hasHeightForWidth());
        MainPage->setSizePolicy(sizePolicy);
        MainPage->setMinimumSize(QSize(1280, 832));
        MainPage->setMaximumSize(QSize(1280, 832));
        QFont font;
        font.setFamilies({QString::fromUtf8("Roboto Serif")});
        font.setPointSize(64);
        MainPage->setFont(font);
        MainPage->setAutoFillBackground(false);
        MainPage->setStyleSheet(QString::fromUtf8("background-color: rgb(75, 76, 173);"));
        MainPage->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        MainPage->setTabShape(QTabWidget::Rounded);
        centralwidget = new QWidget(MainPage);
        centralwidget->setObjectName("centralwidget");
        Background = new QLabel(centralwidget);
        Background->setObjectName("Background");
        Background->setGeometry(QRect(0, 0, 1280, 832));
        sizePolicy.setHeightForWidth(Background->sizePolicy().hasHeightForWidth());
        Background->setSizePolicy(sizePolicy);
        Background->setFocusPolicy(Qt::NoFocus);
        Background->setAcceptDrops(false);
        Background->setToolTipDuration(-1);
        Background->setLayoutDirection(Qt::LeftToRight);
        Background->setAutoFillBackground(false);
        Background->setPixmap(QPixmap(QString::fromUtf8(":/backgrounds/assets/backgrounds/login-background.png")));
        Background->setScaledContents(false);
        Background->setAlignment(Qt::AlignCenter);
        Background->setWordWrap(false);
        Welcome = new QLabel(centralwidget);
        Welcome->setObjectName("Welcome");
        Welcome->setGeometry(QRect(0, 350, 1281, 75));
        sizePolicy.setHeightForWidth(Welcome->sizePolicy().hasHeightForWidth());
        Welcome->setSizePolicy(sizePolicy);
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Roboto Serif")});
        font1.setPointSize(60);
        font1.setWeight(QFont::Medium);
        font1.setItalic(false);
        Welcome->setFont(font1);
        Welcome->setLayoutDirection(Qt::LeftToRight);
        Welcome->setAutoFillBackground(false);
        Welcome->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);\n"
"font: 500 60pt \"Roboto Serif\";\n"
"color: rgb(255, 255, 255);"));
        Welcome->setFrameShadow(QFrame::Plain);
        Welcome->setScaledContents(false);
        Welcome->setAlignment(Qt::AlignCenter);
        Welcome->setIndent(0);
        SignIn = new QPushButton(centralwidget);
        SignIn->setObjectName("SignIn");
        SignIn->setGeometry(QRect(450, 470, 180, 60));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Roboto Serif SemiBold")});
        font2.setPointSize(20);
        font2.setWeight(QFont::DemiBold);
        font2.setItalic(false);
        SignIn->setFont(font2);
        SignIn->setCursor(QCursor(Qt::PointingHandCursor));
        SignIn->setMouseTracking(true);
        SignIn->setAutoFillBackground(false);
        SignIn->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"border-radius: 15px;\n"
"background-color: #986BF6;\n"
"color:#ffffff;\n"
"font: 600 20pt;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"border-radius: 15px;\n"
"background-color: #7E56D2;\n"
"color:#ffffff;\n"
"font: 600 20pt;\n"
" }"));
        SignIn->setFlat(true);
        SignUp = new QPushButton(centralwidget);
        SignUp->setObjectName("SignUp");
        SignUp->setGeometry(QRect(680, 470, 180, 60));
        SignUp->setFont(font2);
        SignUp->setCursor(QCursor(Qt::PointingHandCursor));
        SignUp->setMouseTracking(true);
        SignUp->setAutoFillBackground(false);
        SignUp->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"border-radius: 15px;\n"
"background-color: #ffffff;\n"
"color:#8C99BC;\n"
"font: 600 20pt;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"border-radius: 15px;\n"
"background-color: #EDE7FF;\n"
"color:#7580A0;\n"
"font: 600 20pt;\n"
" }"));
        SignUp->setFlat(true);
        MainPage->setCentralWidget(centralwidget);

        retranslateUi(MainPage);

        QMetaObject::connectSlotsByName(MainPage);
    } // setupUi

    void retranslateUi(QMainWindow *MainPage)
    {
        MainPage->setWindowTitle(QCoreApplication::translate("MainPage", "Audo", nullptr));
        Background->setText(QString());
        Welcome->setText(QCoreApplication::translate("MainPage", "Welcome to Audo", nullptr));
        SignIn->setText(QCoreApplication::translate("MainPage", "Sign In", nullptr));
        SignUp->setText(QCoreApplication::translate("MainPage", "Sign Up", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainPage: public Ui_MainPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINPAGE_H
