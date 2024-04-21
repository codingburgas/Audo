/********************************************************************************
** Form generated from reading UI file 'audo.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AUDO_H
#define UI_AUDO_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Audo
{
public:
    QWidget *centralwidget;
    QFrame *nav;
    QLabel *username;
    QLabel *status;
    QFrame *hero;
    QFrame *classes;
    QLabel *head;
    QPushButton *join;
    QTextEdit *room_code;
    QLabel *error;
    QPushButton *notes;
    QPushButton *grades;
    QTextEdit *textEdit;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Audo)
    {
        if (Audo->objectName().isEmpty())
            Audo->setObjectName("Audo");
        Audo->resize(1920, 1080);
        Audo->setMouseTracking(false);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/public/logo.svg"), QSize(), QIcon::Normal, QIcon::Off);
        Audo->setWindowIcon(icon);
        Audo->setLayoutDirection(Qt::LeftToRight);
        Audo->setAutoFillBackground(false);
        Audo->setStyleSheet(QString::fromUtf8("background-color: #fefefe;\n"
""));
        centralwidget = new QWidget(Audo);
        centralwidget->setObjectName("centralwidget");
        nav = new QFrame(centralwidget);
        nav->setObjectName("nav");
        nav->setGeometry(QRect(31, 21, 1851, 91));
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(nav->sizePolicy().hasHeightForWidth());
        nav->setSizePolicy(sizePolicy);
        nav->setStyleSheet(QString::fromUtf8("background: #fefefe;\n"
"border-radius: 3px;\n"
"box-shadow: 0px 0px 20px 0px rgba(0, 0, 0, 0.25); \n"
""));
        nav->setFrameShape(QFrame::StyledPanel);
        nav->setFrameShadow(QFrame::Plain);
        nav->setLineWidth(0);
        username = new QLabel(nav);
        username->setObjectName("username");
        username->setGeometry(QRect(1640, 0, 181, 71));
        sizePolicy.setHeightForWidth(username->sizePolicy().hasHeightForWidth());
        username->setSizePolicy(sizePolicy);
        QFont font;
        font.setPointSize(18);
        username->setFont(font);
        username->setLayoutDirection(Qt::RightToLeft);
        username->setStyleSheet(QString::fromUtf8("color: rgb(68, 81, 120);\n"
"border: none;\n"
"background: transparent;"));
        username->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        status = new QLabel(nav);
        status->setObjectName("status");
        status->setGeometry(QRect(1720, 50, 71, 16));
        QFont font1;
        font1.setPointSize(12);
        status->setFont(font1);
        status->setStyleSheet(QString::fromUtf8("color: #6B7DB3;\n"
"background: none;\n"
"opacity: 0.75;\n"
"border: none;"));
        hero = new QFrame(centralwidget);
        hero->setObjectName("hero");
        hero->setGeometry(QRect(30, 140, 1851, 831));
        hero->setStyleSheet(QString::fromUtf8("border-radius: 3px;\n"
"border-left: 0px;\n"
"border-right: 0px;\n"
"border-top: 0px;\n"
"background: #fefefe;"));
        hero->setFrameShape(QFrame::StyledPanel);
        hero->setFrameShadow(QFrame::Raised);
        classes = new QFrame(hero);
        classes->setObjectName("classes");
        classes->setGeometry(QRect(9, 0, 321, 841));
        classes->setStyleSheet(QString::fromUtf8("border: 1px solid  #9899FE;\n"
"border-bottom: 1px;\n"
"border-top: 0px;\n"
"border-left: 0px;\n"
"\n"
""));
        classes->setFrameShape(QFrame::StyledPanel);
        classes->setFrameShadow(QFrame::Raised);
        head = new QLabel(classes);
        head->setObjectName("head");
        head->setGeometry(QRect(10, 20, 301, 41));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Segoe UI Semibold")});
        font2.setPointSize(20);
        font2.setBold(true);
        head->setFont(font2);
        head->setStyleSheet(QString::fromUtf8("color: #6B7DB3;\n"
"border: none;"));
        head->setTextFormat(Qt::RichText);
        head->setAlignment(Qt::AlignCenter);
        join = new QPushButton(classes);
        join->setObjectName("join");
        join->setGeometry(QRect(180, 780, 111, 35));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Segoe UI Semibold")});
        font3.setPointSize(11);
        font3.setBold(true);
        join->setFont(font3);
        join->setCursor(QCursor(Qt::PointingHandCursor));
        join->setStyleSheet(QString::fromUtf8("border: none;\n"
"border-radius: 5px;\n"
"background: #9899FE;\n"
"color: #fefefe;"));
        room_code = new QTextEdit(classes);
        room_code->setObjectName("room_code");
        room_code->setGeometry(QRect(10, 780, 151, 35));
        QFont font4;
        font4.setPointSize(11);
        font4.setBold(true);
        room_code->setFont(font4);
        room_code->setStyleSheet(QString::fromUtf8("border: none;\n"
"border-radius: 5px;\n"
"background: #F3F3FF;\n"
"color: #AEB7D8;\n"
"padding-left:5px;\n"
"padding-top: 2px;"));
        room_code->setInputMethodHints(Qt::ImhDigitsOnly|Qt::ImhLatinOnly|Qt::ImhLowercaseOnly|Qt::ImhMultiLine|Qt::ImhUppercaseOnly);
        room_code->setSizeAdjustPolicy(QAbstractScrollArea::AdjustIgnored);
        room_code->setLineWrapMode(QTextEdit::NoWrap);
        room_code->setCursorWidth(1);
        error = new QLabel(classes);
        error->setObjectName("error");
        error->setGeometry(QRect(20, 750, 151, 21));
        error->setStyleSheet(QString::fromUtf8("border: none;\n"
"color: #121212;\n"
""));
        notes = new QPushButton(hero);
        notes->setObjectName("notes");
        notes->setGeometry(QRect(1000, 50, 80, 24));
        QFont font5;
        font5.setFamilies({QString::fromUtf8("Segoe UI Semibold")});
        font5.setPointSize(18);
        font5.setBold(true);
        notes->setFont(font5);
        notes->setCursor(QCursor(Qt::PointingHandCursor));
        notes->setStyleSheet(QString::fromUtf8("color: #445178"));
        grades = new QPushButton(hero);
        grades->setObjectName("grades");
        grades->setGeometry(QRect(1110, 50, 80, 24));
        grades->setFont(font5);
        grades->setCursor(QCursor(Qt::PointingHandCursor));
        grades->setStyleSheet(QString::fromUtf8("color: rgba(68, 81, 120, 0.5)"));
        textEdit = new QTextEdit(hero);
        textEdit->setObjectName("textEdit");
        textEdit->setGeometry(QRect(380, 120, 1431, 671));
        textEdit->setFont(font1);
        textEdit->setStyleSheet(QString::fromUtf8("background: #F3F3FF;\n"
"border: 2px solid rgba(107, 125, 179, 0.5);\n"
"color: #121212;"));
        Audo->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Audo);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1920, 21));
        Audo->setMenuBar(menubar);
        statusbar = new QStatusBar(Audo);
        statusbar->setObjectName("statusbar");
        Audo->setStatusBar(statusbar);

        retranslateUi(Audo);

        QMetaObject::connectSlotsByName(Audo);
    } // setupUi

    void retranslateUi(QMainWindow *Audo)
    {
        Audo->setWindowTitle(QCoreApplication::translate("Audo", "Audo", nullptr));
        username->setText(QString());
        status->setText(QCoreApplication::translate("Audo", "Student", nullptr));
        head->setText(QCoreApplication::translate("Audo", "Classes", nullptr));
        join->setText(QCoreApplication::translate("Audo", "Join Class", nullptr));
        room_code->setPlaceholderText(QCoreApplication::translate("Audo", "Class code", nullptr));
        error->setText(QString());
        notes->setText(QCoreApplication::translate("Audo", "Notes", nullptr));
        grades->setText(QCoreApplication::translate("Audo", "Grades", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Audo: public Ui_Audo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AUDO_H
