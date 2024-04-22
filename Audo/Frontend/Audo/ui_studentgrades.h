/********************************************************************************
** Form generated from reading UI file 'studentgrades.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STUDENTGRADES_H
#define UI_STUDENTGRADES_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_StudentGrades
{
public:
    QFrame *GradeTable;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout_6;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_6;
    QHBoxLayout *horizontalLayout_10;
    QLabel *Grade1;
    QSpacerItem *horizontalSpacer;
    QLabel *label_4;
    QSpacerItem *verticalSpacer;
    QLabel *Frame_2;
    QPushButton *SignOut_2;
    QLabel *Background_2;
    QPushButton *SignOut_3;
    QLabel *Background_3;
    QLabel *SignInLabel_2;
    QLabel *Name;
    QPushButton *SignOut_4;
    QLabel *Background;
    QLabel *Status;
    QLabel *Frame_3;
    QLabel *Frame_4;

    void setupUi(QWidget *StudentGrades)
    {
        if (StudentGrades->objectName().isEmpty())
            StudentGrades->setObjectName("StudentGrades");
        StudentGrades->resize(1280, 832);
        StudentGrades->setStyleSheet(QString::fromUtf8("background-color: rgb(249, 249, 249);"));
        GradeTable = new QFrame(StudentGrades);
        GradeTable->setObjectName("GradeTable");
        GradeTable->setGeometry(QRect(370, 160, 851, 501));
        GradeTable->setStyleSheet(QString::fromUtf8("background-color: #F3F3FF;\n"
"border-style: inset;\n"
"border-width: 2px;\n"
"border-color: rgba(68, 81, 120, 123);"));
        GradeTable->setFrameShape(QFrame::NoFrame);
        GradeTable->setFrameShadow(QFrame::Plain);
        gridLayoutWidget = new QWidget(GradeTable);
        gridLayoutWidget->setObjectName("gridLayoutWidget");
        gridLayoutWidget->setGeometry(QRect(0, 0, 851, 4067));
        gridLayout_6 = new QGridLayout(gridLayoutWidget);
        gridLayout_6->setSpacing(0);
        gridLayout_6->setObjectName("gridLayout_6");
        gridLayout_6->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(0);
        horizontalLayout_8->setObjectName("horizontalLayout_8");
        label_2 = new QLabel(gridLayoutWidget);
        label_2->setObjectName("label_2");
        label_2->setMinimumSize(QSize(300, 0));
        label_2->setMaximumSize(QSize(300, 16777215));
        QFont font;
        font.setFamilies({QString::fromUtf8("Inter")});
        font.setPointSize(16);
        font.setBold(true);
        font.setItalic(false);
        label_2->setFont(font);
        label_2->setStyleSheet(QString::fromUtf8("color: #445178;\n"
"font: bold 16pt \"Inter\";\n"
"border-width: 2px;\n"
"border-color: rgba(68, 81, 120, 123);"));
        label_2->setAlignment(Qt::AlignCenter);

        horizontalLayout_8->addWidget(label_2);

        label_3 = new QLabel(gridLayoutWidget);
        label_3->setObjectName("label_3");
        label_3->setStyleSheet(QString::fromUtf8("color: #445178;\n"
"font: bold 16pt \"Inter\";\n"
"border-width: 2px;\n"
"border-color: rgba(68, 81, 120, 123);"));
        label_3->setAlignment(Qt::AlignCenter);

        horizontalLayout_8->addWidget(label_3);

        label = new QLabel(gridLayoutWidget);
        label->setObjectName("label");
        label->setMinimumSize(QSize(100, 75));
        label->setMaximumSize(QSize(200, 16777215));
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("color: #445178;\n"
"font: bold 16pt \"Inter\";\n"
"border-width: 2px;\n"
"border-color: rgba(68, 81, 120, 123);"));
        label->setAlignment(Qt::AlignCenter);

        horizontalLayout_8->addWidget(label);


        gridLayout_6->addLayout(horizontalLayout_8, 0, 0, 1, 1);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(0);
        horizontalLayout_9->setObjectName("horizontalLayout_9");
        label_6 = new QLabel(gridLayoutWidget);
        label_6->setObjectName("label_6");
        label_6->setMinimumSize(QSize(300, 75));
        label_6->setMaximumSize(QSize(200, 16777215));
        label_6->setStyleSheet(QString::fromUtf8("color: #445178;\n"
"font: 600 16pt \"Inter\";\n"
"border-width: 2px;\n"
"border-color: rgba(68, 81, 120, 123);"));
        label_6->setAlignment(Qt::AlignCenter);

        horizontalLayout_9->addWidget(label_6);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName("horizontalLayout_10");
        Grade1 = new QLabel(gridLayoutWidget);
        Grade1->setObjectName("Grade1");
        Grade1->setMinimumSize(QSize(30, 30));
        Grade1->setMaximumSize(QSize(30, 30));
        Grade1->setBaseSize(QSize(30, 30));
        Grade1->setStyleSheet(QString::fromUtf8("color: #FFFFFF;\n"
"background-color: rgb(255, 82, 82);\n"
"border: none;\n"
"border-radius: 8px;\n"
"font: 500 12pt \"Inter\";"));
        Grade1->setAlignment(Qt::AlignCenter);

        horizontalLayout_10->addWidget(Grade1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer);


        horizontalLayout_9->addLayout(horizontalLayout_10);

        label_4 = new QLabel(gridLayoutWidget);
        label_4->setObjectName("label_4");
        label_4->setMinimumSize(QSize(200, 75));
        label_4->setMaximumSize(QSize(200, 16777215));
        label_4->setStyleSheet(QString::fromUtf8("color: #445178;\n"
"font: 600 16pt \"Inter\";\n"
"border-width: 2px;\n"
"border-color: rgba(68, 81, 120, 123);"));
        label_4->setAlignment(Qt::AlignCenter);

        horizontalLayout_9->addWidget(label_4);


        gridLayout_6->addLayout(horizontalLayout_9, 1, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout_6->addItem(verticalSpacer, 2, 0, 1, 1);

        Frame_2 = new QLabel(StudentGrades);
        Frame_2->setObjectName("Frame_2");
        Frame_2->setGeometry(QRect(329, 10, 931, 71));
        Frame_2->setStyleSheet(QString::fromUtf8("QFrame {\n"
"    background-color: #ffffff; \n"
"}"));
        SignOut_2 = new QPushButton(StudentGrades);
        SignOut_2->setObjectName("SignOut_2");
        SignOut_2->setGeometry(QRect(60, 130, 111, 51));
        SignOut_2->setCursor(QCursor(Qt::PointingHandCursor));
        SignOut_2->setAutoFillBackground(false);
        SignOut_2->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"font: 600 16pt \"Roboto Serif SemiBold\";\n"
"background:none;\n"
"border-radius: 10px;\n"
"color: rgb(68, 81, 120);\n"
"}\n"
"QPushButton:hover {\n"
"font: bold 16pt \"Roboto Serif SemiBold\";\n"
"border-radius: 10px;\n"
"color: rgb(68, 81, 120);\n"
" }\n"
"\n"
""));
        SignOut_2->setFlat(true);
        Background_2 = new QLabel(StudentGrades);
        Background_2->setObjectName("Background_2");
        Background_2->setGeometry(QRect(20, 190, 31, 31));
        Background_2->setAutoFillBackground(false);
        Background_2->setStyleSheet(QString::fromUtf8("background:none;"));
        Background_2->setPixmap(QPixmap(QString::fromUtf8(":/icons/assets/icons/grades-icon.png")));
        Background_2->setAlignment(Qt::AlignCenter);
        SignOut_3 = new QPushButton(StudentGrades);
        SignOut_3->setObjectName("SignOut_3");
        SignOut_3->setGeometry(QRect(60, 180, 91, 51));
        SignOut_3->setCursor(QCursor(Qt::PointingHandCursor));
        SignOut_3->setAutoFillBackground(false);
        SignOut_3->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"font: 600 16pt \"Roboto Serif SemiBold\";\n"
"background:none;\n"
"border-radius: 10px;\n"
"color: rgb(68, 81, 120);\n"
"}\n"
"QPushButton:hover {\n"
"font: bold 16pt \"Roboto Serif SemiBold\";\n"
"border-radius: 10px;\n"
"color: rgb(68, 81, 120);\n"
" }\n"
"\n"
""));
        SignOut_3->setFlat(true);
        Background_3 = new QLabel(StudentGrades);
        Background_3->setObjectName("Background_3");
        Background_3->setGeometry(QRect(20, 240, 31, 31));
        Background_3->setAutoFillBackground(false);
        Background_3->setStyleSheet(QString::fromUtf8("background:none;"));
        Background_3->setPixmap(QPixmap(QString::fromUtf8(":/icons/assets/icons/classes-icon.png")));
        Background_3->setAlignment(Qt::AlignCenter);
        SignInLabel_2 = new QLabel(StudentGrades);
        SignInLabel_2->setObjectName("SignInLabel_2");
        SignInLabel_2->setGeometry(QRect(20, 20, 81, 41));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Roboto Serif Medium")});
        font1.setPointSize(20);
        font1.setWeight(QFont::DemiBold);
        font1.setItalic(false);
        SignInLabel_2->setFont(font1);
        SignInLabel_2->setAutoFillBackground(false);
        SignInLabel_2->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);\n"
"color: rgb(68, 81, 120);\n"
"font: 600 20pt \"Roboto Serif Medium\";"));
        SignInLabel_2->setScaledContents(false);
        SignInLabel_2->setAlignment(Qt::AlignCenter);
        Name = new QLabel(StudentGrades);
        Name->setObjectName("Name");
        Name->setGeometry(QRect(1060, 10, 171, 41));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Roboto Serif")});
        font2.setPointSize(14);
        Name->setFont(font2);
        Name->setStyleSheet(QString::fromUtf8("background: none;\n"
"background-color: rgba(255, 255, 255, 0);\n"
"color: #445178;"));
        Name->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        SignOut_4 = new QPushButton(StudentGrades);
        SignOut_4->setObjectName("SignOut_4");
        SignOut_4->setGeometry(QRect(60, 230, 101, 51));
        SignOut_4->setCursor(QCursor(Qt::PointingHandCursor));
        SignOut_4->setAutoFillBackground(false);
        SignOut_4->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"font: 600 16pt \"Roboto Serif SemiBold\";\n"
"background:none;\n"
"border-radius: 10px;\n"
"color: rgb(68, 81, 120);\n"
"}\n"
"QPushButton:hover {\n"
"font: bold 16pt \"Roboto Serif SemiBold\";\n"
"border-radius: 10px;\n"
"color: rgb(68, 81, 120);\n"
" }\n"
"\n"
""));
        SignOut_4->setFlat(true);
        Background = new QLabel(StudentGrades);
        Background->setObjectName("Background");
        Background->setGeometry(QRect(20, 140, 31, 31));
        Background->setAutoFillBackground(false);
        Background->setStyleSheet(QString::fromUtf8("background:none;"));
        Background->setPixmap(QPixmap(QString::fromUtf8(":/icons/assets/icons/account-icon.png")));
        Background->setAlignment(Qt::AlignCenter);
        Status = new QLabel(StudentGrades);
        Status->setObjectName("Status");
        Status->setGeometry(QRect(1010, 30, 221, 41));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Roboto Serif")});
        font3.setPointSize(11);
        Status->setFont(font3);
        Status->setStyleSheet(QString::fromUtf8("background: none;\n"
"background-color: rgba(255, 255, 255, 0);\n"
"color: #445178;"));
        Status->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        Frame_3 = new QLabel(StudentGrades);
        Frame_3->setObjectName("Frame_3");
        Frame_3->setGeometry(QRect(0, 0, 311, 831));
        Frame_3->setStyleSheet(QString::fromUtf8("QFrame {\n"
"    background-color: #ffffff; \n"
"}"));
        Frame_4 = new QLabel(StudentGrades);
        Frame_4->setObjectName("Frame_4");
        Frame_4->setGeometry(QRect(330, 90, 931, 831));
        Frame_4->setStyleSheet(QString::fromUtf8("QFrame {\n"
"    background-color: #ffffff; \n"
"}"));
        Frame_4->raise();
        Frame_2->raise();
        Frame_3->raise();
        GradeTable->raise();
        SignInLabel_2->raise();
        SignOut_2->raise();
        SignOut_4->raise();
        SignOut_3->raise();
        Status->raise();
        Background->raise();
        Background_2->raise();
        Background_3->raise();
        Name->raise();

        retranslateUi(StudentGrades);

        QMetaObject::connectSlotsByName(StudentGrades);
    } // setupUi

    void retranslateUi(QWidget *StudentGrades)
    {
        StudentGrades->setWindowTitle(QCoreApplication::translate("StudentGrades", "Form", nullptr));
        label_2->setText(QCoreApplication::translate("StudentGrades", "Subject", nullptr));
        label_3->setText(QCoreApplication::translate("StudentGrades", "Grades", nullptr));
        label->setText(QCoreApplication::translate("StudentGrades", "Average", nullptr));
        label_6->setText(QCoreApplication::translate("StudentGrades", "TextLabel", nullptr));
        Grade1->setText(QCoreApplication::translate("StudentGrades", "2", nullptr));
        label_4->setText(QCoreApplication::translate("StudentGrades", "TextLabel", nullptr));
        Frame_2->setText(QString());
        SignOut_2->setText(QCoreApplication::translate("StudentGrades", "Account", nullptr));
        Background_2->setText(QString());
        SignOut_3->setText(QCoreApplication::translate("StudentGrades", "Grades", nullptr));
        Background_3->setText(QString());
        SignInLabel_2->setText(QCoreApplication::translate("StudentGrades", "Audo", nullptr));
        Name->setText(QCoreApplication::translate("StudentGrades", "Name", nullptr));
        SignOut_4->setText(QCoreApplication::translate("StudentGrades", "Classes", nullptr));
        Background->setText(QString());
        Status->setText(QCoreApplication::translate("StudentGrades", "status", nullptr));
        Frame_3->setText(QString());
        Frame_4->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class StudentGrades: public Ui_StudentGrades {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STUDENTGRADES_H
