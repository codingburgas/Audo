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
#include <QtGui/QIcon>
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
    QLabel *Background;
    QLabel *Status;
    QPushButton *pushButton;
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
    QLabel *Name;
    QLabel *UserIcon;
    QLabel *AccountFrame;
    QLabel *GradeFrame;
    QPushButton *grades;
    QPushButton *notes;

    void setupUi(QWidget *StudentGrades)
    {
        if (StudentGrades->objectName().isEmpty())
            StudentGrades->setObjectName("StudentGrades");
        StudentGrades->resize(1280, 832);
        Background = new QLabel(StudentGrades);
        Background->setObjectName("Background");
        Background->setGeometry(QRect(0, 0, 1280, 832));
        Background->setPixmap(QPixmap(QString::fromUtf8(":/backgrounds/assets/backgrounds/login-background.png")));
        Background->setAlignment(Qt::AlignCenter);
        Status = new QLabel(StudentGrades);
        Status->setObjectName("Status");
        Status->setGeometry(QRect(940, 50, 221, 41));
        QFont font;
        font.setFamilies({QString::fromUtf8("Roboto Serif")});
        font.setPointSize(11);
        Status->setFont(font);
        Status->setStyleSheet(QString::fromUtf8("background: none;\n"
"background-color: rgba(255, 255, 255, 0);\n"
"color: #445178;"));
        Status->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        pushButton = new QPushButton(StudentGrades);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(40, 150, 51, 61));
        pushButton->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/assets/icons/back-arrow.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton->setIcon(icon);
        pushButton->setIconSize(QSize(48, 48));
        GradeTable = new QFrame(StudentGrades);
        GradeTable->setObjectName("GradeTable");
        GradeTable->setGeometry(QRect(200, 240, 851, 501));
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
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Inter")});
        font1.setPointSize(16);
        font1.setWeight(QFont::DemiBold);
        font1.setItalic(false);
        label_2->setFont(font1);
        label_2->setStyleSheet(QString::fromUtf8("color: #445178;\n"
"font: 600 16pt \"Inter\";\n"
"border-width: 2px;\n"
"border-color: rgba(68, 81, 120, 123);"));
        label_2->setAlignment(Qt::AlignCenter);

        horizontalLayout_8->addWidget(label_2);

        label_3 = new QLabel(gridLayoutWidget);
        label_3->setObjectName("label_3");
        label_3->setStyleSheet(QString::fromUtf8("color: #445178;\n"
"font: 600 16pt \"Inter\";\n"
"border-width: 2px;\n"
"border-color: rgba(68, 81, 120, 123);"));
        label_3->setAlignment(Qt::AlignCenter);

        horizontalLayout_8->addWidget(label_3);

        label = new QLabel(gridLayoutWidget);
        label->setObjectName("label");
        label->setMinimumSize(QSize(100, 75));
        label->setMaximumSize(QSize(200, 16777215));
        label->setFont(font1);
        label->setStyleSheet(QString::fromUtf8("color: #445178;\n"
"font: 600 16pt \"Inter\";\n"
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

        Name = new QLabel(StudentGrades);
        Name->setObjectName("Name");
        Name->setGeometry(QRect(940, 30, 221, 41));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Roboto Serif")});
        font2.setPointSize(14);
        Name->setFont(font2);
        Name->setStyleSheet(QString::fromUtf8("background: none;\n"
"background-color: rgba(255, 255, 255, 0);\n"
"color: #445178;"));
        Name->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        UserIcon = new QLabel(StudentGrades);
        UserIcon->setObjectName("UserIcon");
        UserIcon->setGeometry(QRect(1180, 26, 61, 71));
        UserIcon->setStyleSheet(QString::fromUtf8("background: none;\n"
"background-color: rgba(255, 255, 255, 0);"));
        UserIcon->setPixmap(QPixmap(QString::fromUtf8(":/icons/assets/icons/user.png")));
        AccountFrame = new QLabel(StudentGrades);
        AccountFrame->setObjectName("AccountFrame");
        AccountFrame->setGeometry(QRect(20, 20, 1241, 81));
        AccountFrame->setStyleSheet(QString::fromUtf8("background-color: #FFFFFF;\n"
"box-shadow: 10px 10px 5px 12px black;"));
        AccountFrame->setFrameShadow(QFrame::Plain);
        GradeFrame = new QLabel(StudentGrades);
        GradeFrame->setObjectName("GradeFrame");
        GradeFrame->setGeometry(QRect(20, 130, 1241, 681));
        GradeFrame->setStyleSheet(QString::fromUtf8("background-color: #FFFFFF;"));
        grades = new QPushButton(StudentGrades);
        grades->setObjectName("grades");
        grades->setGeometry(QRect(630, 180, 101, 24));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Segoe UI Semibold")});
        font3.setPointSize(18);
        font3.setBold(true);
        grades->setFont(font3);
        grades->setCursor(QCursor(Qt::PointingHandCursor));
        grades->setAutoFillBackground(false);
        grades->setStyleSheet(QString::fromUtf8("color: #445178;\n"
"background:#ffffff;\n"
"border:none;"));
        notes = new QPushButton(StudentGrades);
        notes->setObjectName("notes");
        notes->setGeometry(QRect(531, 180, 80, 24));
        notes->setFont(font3);
        notes->setCursor(QCursor(Qt::PointingHandCursor));
        notes->setAutoFillBackground(false);
        notes->setStyleSheet(QString::fromUtf8("color: #445178;\n"
"background:#ffffff;\n"
"border:none;"));
        Background->raise();
        AccountFrame->raise();
        pushButton->raise();
        GradeFrame->raise();
        UserIcon->raise();
        GradeTable->raise();
        Name->raise();
        Status->raise();
        grades->raise();
        notes->raise();

        retranslateUi(StudentGrades);

        QMetaObject::connectSlotsByName(StudentGrades);
    } // setupUi

    void retranslateUi(QWidget *StudentGrades)
    {
        StudentGrades->setWindowTitle(QCoreApplication::translate("StudentGrades", "Form", nullptr));
        Background->setText(QString());
        Status->setText(QCoreApplication::translate("StudentGrades", "Teacher", nullptr));
        pushButton->setText(QString());
        label_2->setText(QCoreApplication::translate("StudentGrades", "Subject", nullptr));
        label_3->setText(QCoreApplication::translate("StudentGrades", "Grades", nullptr));
        label->setText(QCoreApplication::translate("StudentGrades", "Average", nullptr));
        label_6->setText(QCoreApplication::translate("StudentGrades", "TextLabel", nullptr));
        Grade1->setText(QCoreApplication::translate("StudentGrades", "2", nullptr));
        label_4->setText(QCoreApplication::translate("StudentGrades", "TextLabel", nullptr));
        Name->setText(QCoreApplication::translate("StudentGrades", "Name", nullptr));
        UserIcon->setText(QString());
        AccountFrame->setText(QString());
        GradeFrame->setText(QString());
        grades->setText(QCoreApplication::translate("StudentGrades", "Grades", nullptr));
        notes->setText(QCoreApplication::translate("StudentGrades", "Notes", nullptr));
    } // retranslateUi

};

namespace Ui {
    class StudentGrades: public Ui_StudentGrades {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STUDENTGRADES_H
