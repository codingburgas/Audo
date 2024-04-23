/********************************************************************************
** Form generated from reading UI file 'studentnotes.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STUDENTNOTES_H
#define UI_STUDENTNOTES_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_StudentNotes
{
public:
    QLabel *Frame;
    QLabel *Frame_2;
    QLabel *Frame_3;
    QLabel *Background_4;
    QPushButton *SignOut_2;
    QLabel *Background;
    QPushButton *SignOut_3;
    QLabel *Background_3;
    QPushButton *SignOut_4;
    QLabel *Background_2;
    QLabel *Status;
    QLabel *Name;
    QPushButton *JoinClass;
    QFrame *DescriptionFrame;
    QTextEdit *ClassCode;
    QLabel *StudentName;
    QLabel *StudentName_2;
    QLabel *Frame_4;
    QLabel *StudentName_3;
    QLabel *Frame_5;
    QLabel *StudentName_4;
    QLabel *Background_7;
    QLabel *Frame_6;
    QWidget *verticalLayoutWidget_3;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QSpacerItem *verticalSpacer;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QSpacerItem *verticalSpacer_3;

    void setupUi(QWidget *StudentNotes)
    {
        if (StudentNotes->objectName().isEmpty())
            StudentNotes->setObjectName("StudentNotes");
        StudentNotes->resize(1280, 832);
        Frame = new QLabel(StudentNotes);
        Frame->setObjectName("Frame");
        Frame->setGeometry(QRect(329, 110, 711, 761));
        Frame->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
""));
        Frame_2 = new QLabel(StudentNotes);
        Frame_2->setObjectName("Frame_2");
        Frame_2->setGeometry(QRect(329, 10, 941, 71));
        Frame_2->setStyleSheet(QString::fromUtf8("QFrame {\n"
"    background-color: #ffffff; \n"
"}"));
        Frame_3 = new QLabel(StudentNotes);
        Frame_3->setObjectName("Frame_3");
        Frame_3->setGeometry(QRect(0, 0, 310, 832));
        Frame_3->setStyleSheet(QString::fromUtf8("QFrame {\n"
"    background-color: #ffffff; \n"
"}"));
        Background_4 = new QLabel(StudentNotes);
        Background_4->setObjectName("Background_4");
        Background_4->setGeometry(QRect(0, 20, 311, 51));
        Background_4->setAutoFillBackground(false);
        Background_4->setStyleSheet(QString::fromUtf8("background:none;"));
        Background_4->setPixmap(QPixmap(QString::fromUtf8(":/icons/assets/icons/logo.png")));
        Background_4->setAlignment(Qt::AlignCenter);
        SignOut_2 = new QPushButton(StudentNotes);
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
        Background = new QLabel(StudentNotes);
        Background->setObjectName("Background");
        Background->setGeometry(QRect(40, 140, 31, 31));
        Background->setAutoFillBackground(false);
        Background->setStyleSheet(QString::fromUtf8("background:none;"));
        Background->setPixmap(QPixmap(QString::fromUtf8(":/icons/assets/icons/account-icon.png")));
        Background->setAlignment(Qt::AlignCenter);
        SignOut_3 = new QPushButton(StudentNotes);
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
        Background_3 = new QLabel(StudentNotes);
        Background_3->setObjectName("Background_3");
        Background_3->setGeometry(QRect(40, 240, 31, 31));
        Background_3->setAutoFillBackground(false);
        Background_3->setStyleSheet(QString::fromUtf8("background:none;"));
        Background_3->setPixmap(QPixmap(QString::fromUtf8(":/icons/assets/icons/classes-icon.png")));
        Background_3->setAlignment(Qt::AlignCenter);
        SignOut_4 = new QPushButton(StudentNotes);
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
        Background_2 = new QLabel(StudentNotes);
        Background_2->setObjectName("Background_2");
        Background_2->setGeometry(QRect(40, 190, 31, 31));
        Background_2->setAutoFillBackground(false);
        Background_2->setStyleSheet(QString::fromUtf8("background:none;"));
        Background_2->setPixmap(QPixmap(QString::fromUtf8(":/icons/assets/icons/grades-icon.png")));
        Background_2->setAlignment(Qt::AlignCenter);
        Status = new QLabel(StudentNotes);
        Status->setObjectName("Status");
        Status->setGeometry(QRect(1030, 40, 221, 41));
        QFont font;
        font.setFamilies({QString::fromUtf8("Roboto Serif")});
        font.setPointSize(11);
        Status->setFont(font);
        Status->setStyleSheet(QString::fromUtf8("background: none;\n"
"background-color: rgba(255, 255, 255, 0);\n"
"color: #777777;"));
        Status->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        Name = new QLabel(StudentNotes);
        Name->setObjectName("Name");
        Name->setGeometry(QRect(1080, 10, 171, 41));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Roboto Serif")});
        font1.setPointSize(14);
        Name->setFont(font1);
        Name->setStyleSheet(QString::fromUtf8("background: none;\n"
"background-color: rgba(255, 255, 255, 0);\n"
"color: #000000;"));
        Name->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        JoinClass = new QPushButton(StudentNotes);
        JoinClass->setObjectName("JoinClass");
        JoinClass->setGeometry(QRect(170, 790, 101, 31));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Roboto Serif SemiBold")});
        font2.setPointSize(8);
        font2.setWeight(QFont::DemiBold);
        font2.setItalic(false);
        font2.setKerning(true);
        JoinClass->setFont(font2);
        JoinClass->setCursor(QCursor(Qt::PointingHandCursor));
        JoinClass->setMouseTracking(true);
        JoinClass->setAutoFillBackground(false);
        JoinClass->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"font: 600 8pt \"Roboto Serif SemiBold\";\n"
"background-color: #F06B0A;\n"
"border-radius: 10px;\n"
"color:#ffffff;\n"
"}\n"
"QPushButton:hover {\n"
"font: 600 8pt \"Roboto Serif SemiBold\";\n"
"background-color: #E94600;\n"
"border-radius: 10px;\n"
"color:#ffffff;\n"
" }\n"
"\n"
""));
        JoinClass->setFlat(true);
        DescriptionFrame = new QFrame(StudentNotes);
        DescriptionFrame->setObjectName("DescriptionFrame");
        DescriptionFrame->setGeometry(QRect(40, 790, 111, 31));
        DescriptionFrame->setStyleSheet(QString::fromUtf8("background-color: #EEEEEE;\n"
"border: none;\n"
"border-radius:10px;"));
        DescriptionFrame->setFrameShape(QFrame::NoFrame);
        DescriptionFrame->setFrameShadow(QFrame::Plain);
        DescriptionFrame->setLineWidth(0);
        ClassCode = new QTextEdit(DescriptionFrame);
        ClassCode->setObjectName("ClassCode");
        ClassCode->setGeometry(QRect(0, 0, 111, 31));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Roboto Serif Medium")});
        font3.setPointSize(10);
        font3.setWeight(QFont::Medium);
        font3.setItalic(false);
        ClassCode->setFont(font3);
        ClassCode->viewport()->setProperty("cursor", QVariant(QCursor(Qt::PointingHandCursor)));
        ClassCode->setAutoFillBackground(false);
        ClassCode->setStyleSheet(QString::fromUtf8("background-color:rgba(1,1,1,0);\n"
"color: 777777;\n"
"font: 500 10pt \"Roboto Serif Medium\";"));
        StudentName = new QLabel(StudentNotes);
        StudentName->setObjectName("StudentName");
        StudentName->setGeometry(QRect(330, 140, 711, 51));
        QFont font4;
        font4.setFamilies({QString::fromUtf8("Inter")});
        font4.setPointSize(16);
        font4.setWeight(QFont::Black);
        font4.setItalic(false);
        StudentName->setFont(font4);
        StudentName->setStyleSheet(QString::fromUtf8("background: none;\n"
"background-color: rgba(255, 255, 255, 0);\n"
"color: #000000;\n"
"font: 650 16pt \"Inter\";"));
        StudentName->setAlignment(Qt::AlignCenter);
        StudentName_2 = new QLabel(StudentNotes);
        StudentName_2->setObjectName("StudentName_2");
        StudentName_2->setGeometry(QRect(330, 180, 711, 51));
        QFont font5;
        font5.setFamilies({QString::fromUtf8("Inter")});
        font5.setPointSize(14);
        font5.setWeight(QFont::DemiBold);
        font5.setItalic(false);
        StudentName_2->setFont(font5);
        StudentName_2->setStyleSheet(QString::fromUtf8("background: none;\n"
"background-color: rgba(255, 255, 255, 0);\n"
"color: #000000;\n"
"font: 600 14pt \"Inter\";"));
        StudentName_2->setAlignment(Qt::AlignCenter);
        Frame_4 = new QLabel(StudentNotes);
        Frame_4->setObjectName("Frame_4");
        Frame_4->setGeometry(QRect(360, 240, 641, 571));
        Frame_4->setStyleSheet(QString::fromUtf8("background-color: #EEEEEE;\n"
"border-radius:5px;"));
        StudentName_3 = new QLabel(StudentNotes);
        StudentName_3->setObjectName("StudentName_3");
        StudentName_3->setGeometry(QRect(370, 250, 621, 551));
        QFont font6;
        font6.setFamilies({QString::fromUtf8("Inter")});
        font6.setPointSize(12);
        font6.setWeight(QFont::Medium);
        font6.setItalic(false);
        StudentName_3->setFont(font6);
        StudentName_3->setStyleSheet(QString::fromUtf8("background: none;\n"
"background-color: rgba(255, 255, 255, 0);\n"
"color: #000000;\n"
"font: 500 12pt \"Inter\";"));
        StudentName_3->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        Frame_5 = new QLabel(StudentNotes);
        Frame_5->setObjectName("Frame_5");
        Frame_5->setGeometry(QRect(1060, 110, 211, 761));
        Frame_5->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
""));
        StudentName_4 = new QLabel(StudentNotes);
        StudentName_4->setObjectName("StudentName_4");
        StudentName_4->setGeometry(QRect(1080, 130, 151, 51));
        StudentName_4->setFont(font5);
        StudentName_4->setStyleSheet(QString::fromUtf8("background: none;\n"
"background-color: rgba(255, 255, 255, 0);\n"
"color: #000000;\n"
"font: 600 14pt \"Inter\";"));
        StudentName_4->setAlignment(Qt::AlignCenter);
        Background_7 = new QLabel(StudentNotes);
        Background_7->setObjectName("Background_7");
        Background_7->setGeometry(QRect(1080, 140, 31, 31));
        Background_7->setAutoFillBackground(false);
        Background_7->setStyleSheet(QString::fromUtf8("background:none;"));
        Background_7->setPixmap(QPixmap(QString::fromUtf8(":/icons/assets/icons/classes-icon.png")));
        Background_7->setAlignment(Qt::AlignCenter);
        Frame_6 = new QLabel(StudentNotes);
        Frame_6->setObjectName("Frame_6");
        Frame_6->setGeometry(QRect(1070, 130, 191, 51));
        Frame_6->setStyleSheet(QString::fromUtf8("background-color: #EEEEEE;\n"
"border-radius:10px;"));
        verticalLayoutWidget_3 = new QWidget(StudentNotes);
        verticalLayoutWidget_3->setObjectName("verticalLayoutWidget_3");
        verticalLayoutWidget_3->setGeometry(QRect(1070, 190, 191, 631));
        verticalLayout_3 = new QVBoxLayout(verticalLayoutWidget_3);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(verticalLayoutWidget_3);
        label_3->setObjectName("label_3");

        verticalLayout_3->addWidget(label_3);

        label_4 = new QLabel(verticalLayoutWidget_3);
        label_4->setObjectName("label_4");

        verticalLayout_3->addWidget(label_4);

        label_5 = new QLabel(verticalLayoutWidget_3);
        label_5->setObjectName("label_5");

        verticalLayout_3->addWidget(label_5);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_3->addItem(verticalSpacer);

        horizontalLayoutWidget = new QWidget(StudentNotes);
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

        Frame_5->raise();
        Frame_6->raise();
        Frame->raise();
        Frame_2->raise();
        Frame_3->raise();
        Background_4->raise();
        SignOut_2->raise();
        SignOut_3->raise();
        SignOut_4->raise();
        Status->raise();
        Name->raise();
        JoinClass->raise();
        DescriptionFrame->raise();
        StudentName->raise();
        StudentName_2->raise();
        Frame_4->raise();
        StudentName_3->raise();
        StudentName_4->raise();
        Background_7->raise();
        verticalLayoutWidget_3->raise();
        Background->raise();
        horizontalLayoutWidget->raise();
        Background_2->raise();
        Background_3->raise();

        retranslateUi(StudentNotes);

        JoinClass->setDefault(false);


        QMetaObject::connectSlotsByName(StudentNotes);
    } // setupUi

    void retranslateUi(QWidget *StudentNotes)
    {
        StudentNotes->setWindowTitle(QCoreApplication::translate("StudentNotes", "Form", nullptr));
        Frame->setText(QString());
        Frame_2->setText(QString());
        Frame_3->setText(QString());
        Background_4->setText(QString());
        SignOut_2->setText(QCoreApplication::translate("StudentNotes", "Account", nullptr));
        Background->setText(QString());
        SignOut_3->setText(QCoreApplication::translate("StudentNotes", "Grades", nullptr));
        Background_3->setText(QString());
        SignOut_4->setText(QCoreApplication::translate("StudentNotes", "Classes", nullptr));
        Background_2->setText(QString());
        Status->setText(QCoreApplication::translate("StudentNotes", "status", nullptr));
        Name->setText(QCoreApplication::translate("StudentNotes", "Name", nullptr));
        JoinClass->setText(QCoreApplication::translate("StudentNotes", "Join class", nullptr));
        ClassCode->setPlaceholderText(QCoreApplication::translate("StudentNotes", "Class code...", nullptr));
        StudentName->setText(QCoreApplication::translate("StudentNotes", "Subject name", nullptr));
        StudentName_2->setText(QCoreApplication::translate("StudentNotes", "Topic", nullptr));
        Frame_4->setText(QString());
        StudentName_3->setText(QCoreApplication::translate("StudentNotes", "Topic", nullptr));
        Frame_5->setText(QString());
        StudentName_4->setText(QCoreApplication::translate("StudentNotes", "Topics", nullptr));
        Background_7->setText(QString());
        Frame_6->setText(QString());
        label_3->setText(QCoreApplication::translate("StudentNotes", "TextLabel", nullptr));
        label_4->setText(QCoreApplication::translate("StudentNotes", "TextLabel", nullptr));
        label_5->setText(QCoreApplication::translate("StudentNotes", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class StudentNotes: public Ui_StudentNotes {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STUDENTNOTES_H
