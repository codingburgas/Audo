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
    QLabel *Sidebar;
    QLabel *Logo;
    QPushButton *AccountButton;
    QLabel *AccountIcon;
    QPushButton *GradesButton;
    QLabel *ClassesIcon;
    QPushButton *ClassesButton;
    QLabel *GradesIcon;
    QPushButton *JoinClass;
    QFrame *ClassCodeFrame;
    QTextEdit *ClassCode;
    QLabel *Subject;
    QLabel *Topic;
    QLabel *TopicFrame;
    QLabel *TopicText;
    QLabel *TopicsFrame;
    QLabel *TopicsTitle;
    QLabel *TopicsIcon;
    QLabel *TopicsTitleFrame;
    QWidget *verticalLayoutWidget_3;
    QVBoxLayout *TopicLayout;
    QSpacerItem *TopicSpacer;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *ClassLayout;
    QVBoxLayout *ClassLeaveLayout;
    QSpacerItem *ClassLeaveSpacer;
    QVBoxLayout *ClassNameLayout;
    QSpacerItem *ClassNameSpacer;
    QLabel *Warning;
    QLabel *Name;
    QLabel *Status;
    QLabel *Frame_2;

    void setupUi(QWidget *StudentNotes)
    {
        if (StudentNotes->objectName().isEmpty())
            StudentNotes->setObjectName("StudentNotes");
        StudentNotes->resize(1280, 832);
        StudentNotes->setMinimumSize(QSize(1280, 832));
        StudentNotes->setMaximumSize(QSize(1280, 832));
        Frame = new QLabel(StudentNotes);
        Frame->setObjectName("Frame");
        Frame->setGeometry(QRect(329, 100, 710, 771));
        Frame->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
""));
        Sidebar = new QLabel(StudentNotes);
        Sidebar->setObjectName("Sidebar");
        Sidebar->setGeometry(QRect(0, 0, 310, 832));
        Sidebar->setStyleSheet(QString::fromUtf8("QFrame {\n"
"    background-color: #ffffff; \n"
"}"));
        Logo = new QLabel(StudentNotes);
        Logo->setObjectName("Logo");
        Logo->setGeometry(QRect(0, 20, 311, 51));
        Logo->setAutoFillBackground(false);
        Logo->setStyleSheet(QString::fromUtf8("background:none;"));
        Logo->setPixmap(QPixmap(QString::fromUtf8(":/icons/assets/icons/logo.png")));
        Logo->setAlignment(Qt::AlignCenter);
        AccountButton = new QPushButton(StudentNotes);
        AccountButton->setObjectName("AccountButton");
        AccountButton->setGeometry(QRect(30, 130, 241, 51));
        AccountButton->setCursor(QCursor(Qt::PointingHandCursor));
        AccountButton->setAutoFillBackground(false);
        AccountButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        AccountButton->setFlat(true);
        AccountIcon = new QLabel(StudentNotes);
        AccountIcon->setObjectName("AccountIcon");
        AccountIcon->setGeometry(QRect(40, 140, 31, 31));
        AccountIcon->setAutoFillBackground(false);
        AccountIcon->setStyleSheet(QString::fromUtf8("background:none;"));
        AccountIcon->setPixmap(QPixmap(QString::fromUtf8(":/icons/assets/icons/account-icon.png")));
        AccountIcon->setAlignment(Qt::AlignCenter);
        GradesButton = new QPushButton(StudentNotes);
        GradesButton->setObjectName("GradesButton");
        GradesButton->setGeometry(QRect(30, 180, 241, 51));
        GradesButton->setCursor(QCursor(Qt::PointingHandCursor));
        GradesButton->setAutoFillBackground(false);
        GradesButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        GradesButton->setFlat(true);
        ClassesIcon = new QLabel(StudentNotes);
        ClassesIcon->setObjectName("ClassesIcon");
        ClassesIcon->setGeometry(QRect(40, 240, 31, 31));
        ClassesIcon->setAutoFillBackground(false);
        ClassesIcon->setStyleSheet(QString::fromUtf8("background:none;"));
        ClassesIcon->setPixmap(QPixmap(QString::fromUtf8(":/icons/assets/icons/classes-icon.png")));
        ClassesIcon->setAlignment(Qt::AlignCenter);
        ClassesButton = new QPushButton(StudentNotes);
        ClassesButton->setObjectName("ClassesButton");
        ClassesButton->setGeometry(QRect(30, 230, 241, 51));
        ClassesButton->setCursor(QCursor(Qt::PointingHandCursor));
        ClassesButton->setAutoFillBackground(false);
        ClassesButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        ClassesButton->setFlat(true);
        GradesIcon = new QLabel(StudentNotes);
        GradesIcon->setObjectName("GradesIcon");
        GradesIcon->setGeometry(QRect(40, 190, 31, 31));
        GradesIcon->setAutoFillBackground(false);
        GradesIcon->setStyleSheet(QString::fromUtf8("background:none;"));
        GradesIcon->setPixmap(QPixmap(QString::fromUtf8(":/icons/assets/icons/grades-icon.png")));
        GradesIcon->setAlignment(Qt::AlignCenter);
        JoinClass = new QPushButton(StudentNotes);
        JoinClass->setObjectName("JoinClass");
        JoinClass->setGeometry(QRect(170, 790, 101, 31));
        QFont font;
        font.setFamilies({QString::fromUtf8("Roboto Serif SemiBold")});
        font.setPointSize(8);
        font.setWeight(QFont::DemiBold);
        font.setItalic(false);
        font.setKerning(true);
        JoinClass->setFont(font);
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
        ClassCodeFrame = new QFrame(StudentNotes);
        ClassCodeFrame->setObjectName("ClassCodeFrame");
        ClassCodeFrame->setGeometry(QRect(30, 790, 111, 31));
        ClassCodeFrame->setStyleSheet(QString::fromUtf8("background-color: #EEEEEE;\n"
"border: none;\n"
"border-radius:10px;"));
        ClassCodeFrame->setFrameShape(QFrame::NoFrame);
        ClassCodeFrame->setFrameShadow(QFrame::Plain);
        ClassCodeFrame->setLineWidth(0);
        ClassCode = new QTextEdit(ClassCodeFrame);
        ClassCode->setObjectName("ClassCode");
        ClassCode->setGeometry(QRect(0, 0, 111, 31));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Roboto Serif Medium")});
        font1.setPointSize(10);
        font1.setWeight(QFont::Medium);
        font1.setItalic(false);
        ClassCode->setFont(font1);
        ClassCode->viewport()->setProperty("cursor", QVariant(QCursor(Qt::PointingHandCursor)));
        ClassCode->setAutoFillBackground(false);
        ClassCode->setStyleSheet(QString::fromUtf8("background-color:rgba(1,1,1,0);\n"
"color: 777777;\n"
"font: 500 10pt \"Roboto Serif Medium\";"));
        Subject = new QLabel(StudentNotes);
        Subject->setObjectName("Subject");
        Subject->setGeometry(QRect(330, 140, 711, 51));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Inter")});
        font2.setPointSize(16);
        font2.setBold(true);
        font2.setItalic(false);
        Subject->setFont(font2);
        Subject->setStyleSheet(QString::fromUtf8("background: none;\n"
"background-color: rgba(255, 255, 255, 0);\n"
"color: #000000;\n"
"font: 700 16pt \"Inter\";"));
        Subject->setAlignment(Qt::AlignCenter);
        Topic = new QLabel(StudentNotes);
        Topic->setObjectName("Topic");
        Topic->setGeometry(QRect(330, 180, 711, 51));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Inter")});
        font3.setPointSize(14);
        font3.setWeight(QFont::DemiBold);
        font3.setItalic(false);
        Topic->setFont(font3);
        Topic->setStyleSheet(QString::fromUtf8("background: none;\n"
"background-color: rgba(255, 255, 255, 0);\n"
"color: #000000;\n"
"font: 600 14pt \"Inter\";"));
        Topic->setAlignment(Qt::AlignCenter);
        TopicFrame = new QLabel(StudentNotes);
        TopicFrame->setObjectName("TopicFrame");
        TopicFrame->setGeometry(QRect(360, 240, 641, 571));
        TopicFrame->setStyleSheet(QString::fromUtf8("background-color: #EEEEEE;\n"
"border-radius:5px;"));
        TopicText = new QLabel(StudentNotes);
        TopicText->setObjectName("TopicText");
        TopicText->setGeometry(QRect(370, 250, 621, 551));
        QFont font4;
        font4.setFamilies({QString::fromUtf8("Inter")});
        font4.setPointSize(12);
        font4.setWeight(QFont::Medium);
        font4.setItalic(false);
        TopicText->setFont(font4);
        TopicText->setStyleSheet(QString::fromUtf8("background: none;\n"
"background-color: rgba(255, 255, 255, 0);\n"
"color: #000000;\n"
"font: 500 12pt \"Inter\";"));
        TopicText->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        TopicsFrame = new QLabel(StudentNotes);
        TopicsFrame->setObjectName("TopicsFrame");
        TopicsFrame->setGeometry(QRect(1060, 100, 211, 771));
        TopicsFrame->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
""));
        TopicsTitle = new QLabel(StudentNotes);
        TopicsTitle->setObjectName("TopicsTitle");
        TopicsTitle->setGeometry(QRect(1090, 130, 151, 51));
        TopicsTitle->setFont(font3);
        TopicsTitle->setStyleSheet(QString::fromUtf8("background: none;\n"
"background-color: rgba(255, 255, 255, 0);\n"
"color: #000000;\n"
"font: 600 14pt \"Inter\";"));
        TopicsTitle->setAlignment(Qt::AlignCenter);
        TopicsIcon = new QLabel(StudentNotes);
        TopicsIcon->setObjectName("TopicsIcon");
        TopicsIcon->setGeometry(QRect(1090, 140, 31, 31));
        TopicsIcon->setAutoFillBackground(false);
        TopicsIcon->setStyleSheet(QString::fromUtf8("background:none;"));
        TopicsIcon->setPixmap(QPixmap(QString::fromUtf8(":/icons/assets/icons/classes-icon.png")));
        TopicsIcon->setAlignment(Qt::AlignCenter);
        TopicsTitleFrame = new QLabel(StudentNotes);
        TopicsTitleFrame->setObjectName("TopicsTitleFrame");
        TopicsTitleFrame->setGeometry(QRect(1080, 130, 181, 51));
        TopicsTitleFrame->setStyleSheet(QString::fromUtf8("background-color: #EEEEEE;\n"
"border-radius:10px;"));
        verticalLayoutWidget_3 = new QWidget(StudentNotes);
        verticalLayoutWidget_3->setObjectName("verticalLayoutWidget_3");
        verticalLayoutWidget_3->setGeometry(QRect(1080, 190, 181, 631));
        TopicLayout = new QVBoxLayout(verticalLayoutWidget_3);
        TopicLayout->setSpacing(0);
        TopicLayout->setObjectName("TopicLayout");
        TopicLayout->setContentsMargins(0, 0, 0, 0);
        TopicSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        TopicLayout->addItem(TopicSpacer);

        horizontalLayoutWidget = new QWidget(StudentNotes);
        horizontalLayoutWidget->setObjectName("horizontalLayoutWidget");
        horizontalLayoutWidget->setGeometry(QRect(30, 300, 241, 461));
        ClassLayout = new QHBoxLayout(horizontalLayoutWidget);
        ClassLayout->setObjectName("ClassLayout");
        ClassLayout->setContentsMargins(0, 0, 0, 0);
        ClassLeaveLayout = new QVBoxLayout();
        ClassLeaveLayout->setObjectName("ClassLeaveLayout");
        ClassLeaveSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        ClassLeaveLayout->addItem(ClassLeaveSpacer);


        ClassLayout->addLayout(ClassLeaveLayout);

        ClassNameLayout = new QVBoxLayout();
        ClassNameLayout->setObjectName("ClassNameLayout");
        ClassNameSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        ClassNameLayout->addItem(ClassNameSpacer);


        ClassLayout->addLayout(ClassNameLayout);

        Warning = new QLabel(StudentNotes);
        Warning->setObjectName("Warning");
        Warning->setGeometry(QRect(40, 760, 241, 31));
        QFont font5;
        font5.setFamilies({QString::fromUtf8("Inter")});
        font5.setPointSize(8);
        font5.setBold(true);
        Warning->setFont(font5);
        Warning->setAutoFillBackground(false);
        Warning->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);\n"
"color: rgb(170, 0, 0);"));
        Name = new QLabel(StudentNotes);
        Name->setObjectName("Name");
        Name->setGeometry(QRect(1070, 10, 171, 41));
        QFont font6;
        font6.setFamilies({QString::fromUtf8("Roboto Serif")});
        font6.setPointSize(14);
        Name->setFont(font6);
        Name->setStyleSheet(QString::fromUtf8("background: none;\n"
"background-color: rgba(255, 255, 255, 0);\n"
"color: #000000;"));
        Name->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        Status = new QLabel(StudentNotes);
        Status->setObjectName("Status");
        Status->setGeometry(QRect(1020, 40, 221, 41));
        QFont font7;
        font7.setFamilies({QString::fromUtf8("Roboto Serif")});
        font7.setPointSize(11);
        Status->setFont(font7);
        Status->setStyleSheet(QString::fromUtf8("background: none;\n"
"background-color: rgba(255, 255, 255, 0);\n"
"color: #777777;"));
        Status->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        Frame_2 = new QLabel(StudentNotes);
        Frame_2->setObjectName("Frame_2");
        Frame_2->setGeometry(QRect(329, 10, 941, 71));
        Frame_2->setStyleSheet(QString::fromUtf8("QFrame {\n"
"    background-color: #ffffff; \n"
"}"));
        TopicsFrame->raise();
        TopicsTitleFrame->raise();
        Frame->raise();
        Sidebar->raise();
        Logo->raise();
        AccountButton->raise();
        GradesButton->raise();
        ClassesButton->raise();
        JoinClass->raise();
        ClassCodeFrame->raise();
        Subject->raise();
        Topic->raise();
        TopicFrame->raise();
        TopicText->raise();
        TopicsTitle->raise();
        TopicsIcon->raise();
        verticalLayoutWidget_3->raise();
        AccountIcon->raise();
        horizontalLayoutWidget->raise();
        GradesIcon->raise();
        ClassesIcon->raise();
        Warning->raise();
        Name->raise();
        Status->raise();
        Frame_2->raise();

        retranslateUi(StudentNotes);

        JoinClass->setDefault(false);


        QMetaObject::connectSlotsByName(StudentNotes);
    } // setupUi

    void retranslateUi(QWidget *StudentNotes)
    {
        StudentNotes->setWindowTitle(QCoreApplication::translate("StudentNotes", "Form", nullptr));
        Frame->setText(QString());
        Sidebar->setText(QString());
        Logo->setText(QString());
        AccountButton->setText(QCoreApplication::translate("StudentNotes", "Account", nullptr));
        AccountIcon->setText(QString());
        GradesButton->setText(QCoreApplication::translate("StudentNotes", "Grades", nullptr));
        ClassesIcon->setText(QString());
        ClassesButton->setText(QCoreApplication::translate("StudentNotes", "Classes", nullptr));
        GradesIcon->setText(QString());
        JoinClass->setText(QCoreApplication::translate("StudentNotes", "Join class", nullptr));
        ClassCode->setPlaceholderText(QCoreApplication::translate("StudentNotes", "Class code...", nullptr));
        Subject->setText(QCoreApplication::translate("StudentNotes", "Subject name", nullptr));
        Topic->setText(QCoreApplication::translate("StudentNotes", "Topic", nullptr));
        TopicFrame->setText(QString());
        TopicText->setText(QCoreApplication::translate("StudentNotes", "Topic", nullptr));
        TopicsFrame->setText(QString());
        TopicsTitle->setText(QCoreApplication::translate("StudentNotes", "Topics", nullptr));
        TopicsIcon->setText(QString());
        TopicsTitleFrame->setText(QString());
        Warning->setText(QString());
        Name->setText(QCoreApplication::translate("StudentNotes", "Name", nullptr));
        Status->setText(QCoreApplication::translate("StudentNotes", "status", nullptr));
        Frame_2->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class StudentNotes: public Ui_StudentNotes {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STUDENTNOTES_H
