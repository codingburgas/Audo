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
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Audo
{
public:
    QWidget *centralwidget;
    QFrame *frame;
    QLabel *logo;
    QLabel *label_5;
    QLabel *label_7;
    QLabel *confirmButton;
    QLabel *Background_3;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QSpacerItem *verticalSpacer_3;
    QPushButton *SignOut_2;
    QPushButton *SignOut_4;
    QLabel *Background;
    QPushButton *SignOut_3;
    QLabel *Background_2;
    QFrame *ClassCodeFrame;
    QTextEdit *ClassCode;
    QPushButton *JoinClass;
    QFrame *frame_3;
    QLabel *classCodeText;
    QLabel *classCode;
    QLineEdit *topicInput;
    QTextEdit *notes;
    QLabel *deleteButton;
    QLabel *editButton;
    QLabel *Subject;
    QLabel *Topic;
    QLabel *Topic_2;
    QFrame *frame_4;
    QLabel *label_12;
    QLabel *TopicsTitleFrame;
    QLabel *TopicsIcon;
    QLabel *TopicsTitle;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout_3;
    QSpacerItem *verticalSpacer;
    QPushButton *JoinClass_2;
    QLabel *nav;
    QLabel *Name;
    QLabel *Status;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Audo)
    {
        if (Audo->objectName().isEmpty())
            Audo->setObjectName("Audo");
        Audo->resize(1280, 832);
        Audo->setMinimumSize(QSize(1280, 832));
        Audo->setMaximumSize(QSize(1280, 832));
        Audo->setStyleSheet(QString::fromUtf8("background: #EEEEEE;\n"
""));
        centralwidget = new QWidget(Audo);
        centralwidget->setObjectName("centralwidget");
        frame = new QFrame(centralwidget);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(0, 0, 310, 832));
        frame->setStyleSheet(QString::fromUtf8("background: #fefefe;\n"
"border: none;"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        logo = new QLabel(frame);
        logo->setObjectName("logo");
        logo->setGeometry(QRect(0, 20, 311, 51));
        logo->setPixmap(QPixmap(QString::fromUtf8(":/icons/assets/icons/logo-black.svg")));
        logo->setAlignment(Qt::AlignCenter);
        label_5 = new QLabel(frame);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(30, 190, 31, 41));
        label_5->setPixmap(QPixmap(QString::fromUtf8(":/icons/assets/users.svg")));
        label_7 = new QLabel(frame);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(30, 250, 31, 41));
        label_7->setPixmap(QPixmap(QString::fromUtf8(":/icons/assets/bookmark.svg")));
        confirmButton = new QLabel(frame);
        confirmButton->setObjectName("confirmButton");
        confirmButton->setGeometry(QRect(390, 420, 121, 41));
        QFont font;
        font.setPointSize(11);
        font.setBold(true);
        confirmButton->setFont(font);
        confirmButton->setCursor(QCursor(Qt::PointingHandCursor));
        confirmButton->setStyleSheet(QString::fromUtf8("color: #fefefe;\n"
"padding-left: 3px;\n"
"background: #F06B0A;\n"
"border-radius: 8px;"));
        confirmButton->setAlignment(Qt::AlignCenter);
        Background_3 = new QLabel(frame);
        Background_3->setObjectName("Background_3");
        Background_3->setGeometry(QRect(40, 210, 31, 31));
        Background_3->setAutoFillBackground(false);
        Background_3->setStyleSheet(QString::fromUtf8("background:none;"));
        Background_3->setPixmap(QPixmap(QString::fromUtf8(":/icons/assets/icons/classes-icon.png")));
        Background_3->setAlignment(Qt::AlignCenter);
        horizontalLayoutWidget = new QWidget(frame);
        horizontalLayoutWidget->setObjectName("horizontalLayoutWidget");
        horizontalLayoutWidget->setGeometry(QRect(30, 260, 241, 461));
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

        SignOut_2 = new QPushButton(frame);
        SignOut_2->setObjectName("SignOut_2");
        SignOut_2->setGeometry(QRect(30, 100, 241, 51));
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
        SignOut_4 = new QPushButton(frame);
        SignOut_4->setObjectName("SignOut_4");
        SignOut_4->setGeometry(QRect(30, 200, 241, 51));
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
        Background = new QLabel(frame);
        Background->setObjectName("Background");
        Background->setGeometry(QRect(40, 110, 31, 31));
        Background->setAutoFillBackground(false);
        Background->setStyleSheet(QString::fromUtf8("background:none;"));
        Background->setPixmap(QPixmap(QString::fromUtf8(":/icons/assets/icons/account-icon.png")));
        Background->setAlignment(Qt::AlignCenter);
        SignOut_3 = new QPushButton(frame);
        SignOut_3->setObjectName("SignOut_3");
        SignOut_3->setGeometry(QRect(30, 150, 241, 51));
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
        Background_2 = new QLabel(frame);
        Background_2->setObjectName("Background_2");
        Background_2->setGeometry(QRect(40, 160, 31, 31));
        Background_2->setAutoFillBackground(false);
        Background_2->setStyleSheet(QString::fromUtf8("background:none;"));
        Background_2->setPixmap(QPixmap(QString::fromUtf8(":/icons/assets/icons/participants-icon.png")));
        Background_2->setAlignment(Qt::AlignCenter);
        ClassCodeFrame = new QFrame(frame);
        ClassCodeFrame->setObjectName("ClassCodeFrame");
        ClassCodeFrame->setGeometry(QRect(30, 740, 111, 31));
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
        JoinClass = new QPushButton(frame);
        JoinClass->setObjectName("JoinClass");
        JoinClass->setGeometry(QRect(170, 740, 101, 31));
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
        logo->raise();
        label_5->raise();
        label_7->raise();
        confirmButton->raise();
        horizontalLayoutWidget->raise();
        SignOut_2->raise();
        Background->raise();
        SignOut_3->raise();
        Background_2->raise();
        ClassCodeFrame->raise();
        JoinClass->raise();
        SignOut_4->raise();
        Background_3->raise();
        frame_3 = new QFrame(centralwidget);
        frame_3->setObjectName("frame_3");
        frame_3->setGeometry(QRect(330, 100, 710, 681));
        frame_3->setStyleSheet(QString::fromUtf8("border: none;\n"
"background: #fefefe;\n"
"border-radius: 5px;"));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        classCodeText = new QLabel(frame_3);
        classCodeText->setObjectName("classCodeText");
        classCodeText->setGeometry(QRect(220, 80, 141, 31));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Segoe UI Semibold")});
        font3.setPointSize(12);
        font3.setBold(true);
        classCodeText->setFont(font3);
        classCodeText->setStyleSheet(QString::fromUtf8("color: rgba(18, 18, 18, 0.5);"));
        classCodeText->setAlignment(Qt::AlignCenter);
        classCode = new QLabel(frame_3);
        classCode->setObjectName("classCode");
        classCode->setGeometry(QRect(350, 80, 131, 31));
        classCode->setFont(font3);
        classCode->setStyleSheet(QString::fromUtf8("color: rgba(18, 18, 18, 0.5);\n"
"background:none;"));
        classCode->setAlignment(Qt::AlignCenter);
        topicInput = new QLineEdit(frame_3);
        topicInput->setObjectName("topicInput");
        topicInput->setGeometry(QRect(50, 190, 621, 41));
        QFont font4;
        font4.setFamilies({QString::fromUtf8("Segoe UI Semibold")});
        font4.setPointSize(16);
        font4.setBold(true);
        topicInput->setFont(font4);
        topicInput->setStyleSheet(QString::fromUtf8("background: #eee;\n"
"border-radius: 5px;\n"
"padding-left: 30px;\n"
"color: #121212;"));
        notes = new QTextEdit(frame_3);
        notes->setObjectName("notes");
        notes->setGeometry(QRect(50, 300, 621, 321));
        notes->setFont(font4);
        notes->viewport()->setProperty("cursor", QVariant(QCursor(Qt::IBeamCursor)));
        notes->setStyleSheet(QString::fromUtf8("border: none;\n"
"border-radius: 5px;\n"
"background: #eee;\n"
"color: #121212;"));
        deleteButton = new QLabel(frame_3);
        deleteButton->setObjectName("deleteButton");
        deleteButton->setGeometry(QRect(640, 630, 31, 41));
        deleteButton->setCursor(QCursor(Qt::PointingHandCursor));
        deleteButton->setPixmap(QPixmap(QString::fromUtf8(":/icons/assets/icons/go away.svg")));
        editButton = new QLabel(frame_3);
        editButton->setObjectName("editButton");
        editButton->setGeometry(QRect(590, 635, 31, 31));
        editButton->setCursor(QCursor(Qt::PointingHandCursor));
        editButton->setPixmap(QPixmap(QString::fromUtf8(":/icons/assets/icons/edit.svg")));
        Subject = new QLabel(frame_3);
        Subject->setObjectName("Subject");
        Subject->setGeometry(QRect(0, 30, 711, 61));
        QFont font5;
        font5.setFamilies({QString::fromUtf8("Inter")});
        font5.setPointSize(16);
        font5.setBold(true);
        font5.setItalic(false);
        Subject->setFont(font5);
        Subject->setStyleSheet(QString::fromUtf8("background: none;\n"
"background-color: rgba(255, 255, 255, 0);\n"
"color: #000000;\n"
"font: 700 16pt \"Inter\";"));
        Subject->setAlignment(Qt::AlignCenter);
        Topic = new QLabel(frame_3);
        Topic->setObjectName("Topic");
        Topic->setGeometry(QRect(50, 130, 61, 51));
        QFont font6;
        font6.setFamilies({QString::fromUtf8("Inter")});
        font6.setPointSize(14);
        font6.setWeight(QFont::DemiBold);
        font6.setItalic(false);
        Topic->setFont(font6);
        Topic->setStyleSheet(QString::fromUtf8("background: none;\n"
"background-color: rgba(255, 255, 255, 0);\n"
"color: #000000;\n"
"font: 600 14pt \"Inter\";"));
        Topic->setAlignment(Qt::AlignCenter);
        Topic_2 = new QLabel(frame_3);
        Topic_2->setObjectName("Topic_2");
        Topic_2->setGeometry(QRect(50, 240, 61, 51));
        Topic_2->setFont(font6);
        Topic_2->setStyleSheet(QString::fromUtf8("background: none;\n"
"background-color: rgba(255, 255, 255, 0);\n"
"color: #000000;\n"
"font: 600 14pt \"Inter\";"));
        Topic_2->setAlignment(Qt::AlignCenter);
        frame_4 = new QFrame(centralwidget);
        frame_4->setObjectName("frame_4");
        frame_4->setGeometry(QRect(1060, 100, 211, 691));
        frame_4->setStyleSheet(QString::fromUtf8("background: #fefefe;\n"
"border: none;\n"
"border-radius: 5px;"));
        frame_4->setFrameShape(QFrame::StyledPanel);
        frame_4->setFrameShadow(QFrame::Raised);
        label_12 = new QLabel(frame_4);
        label_12->setObjectName("label_12");
        label_12->setGeometry(QRect(43, 41, 31, 41));
        label_12->setPixmap(QPixmap(QString::fromUtf8(":/icons/assets/bookmark.svg")));
        TopicsTitleFrame = new QLabel(frame_4);
        TopicsTitleFrame->setObjectName("TopicsTitleFrame");
        TopicsTitleFrame->setGeometry(QRect(10, 20, 191, 51));
        TopicsTitleFrame->setStyleSheet(QString::fromUtf8("background-color: #EEEEEE;\n"
"border-radius:10px;"));
        TopicsIcon = new QLabel(frame_4);
        TopicsIcon->setObjectName("TopicsIcon");
        TopicsIcon->setGeometry(QRect(20, 30, 31, 31));
        TopicsIcon->setAutoFillBackground(false);
        TopicsIcon->setStyleSheet(QString::fromUtf8("background:none;"));
        TopicsIcon->setPixmap(QPixmap(QString::fromUtf8(":/icons/assets/icons/classes-icon.png")));
        TopicsIcon->setAlignment(Qt::AlignCenter);
        TopicsTitle = new QLabel(frame_4);
        TopicsTitle->setObjectName("TopicsTitle");
        TopicsTitle->setGeometry(QRect(20, 20, 151, 51));
        TopicsTitle->setFont(font6);
        TopicsTitle->setStyleSheet(QString::fromUtf8("background: none;\n"
"background-color: rgba(255, 255, 255, 0);\n"
"color: #000000;\n"
"font: 600 14pt \"Inter\";"));
        TopicsTitle->setAlignment(Qt::AlignCenter);
        verticalLayoutWidget = new QWidget(frame_4);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(10, 80, 191, 171));
        verticalLayout_3 = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_3->addItem(verticalSpacer);

        JoinClass_2 = new QPushButton(frame_4);
        JoinClass_2->setObjectName("JoinClass_2");
        JoinClass_2->setGeometry(QRect(20, 270, 101, 31));
        JoinClass_2->setFont(font2);
        JoinClass_2->setCursor(QCursor(Qt::PointingHandCursor));
        JoinClass_2->setMouseTracking(true);
        JoinClass_2->setAutoFillBackground(false);
        JoinClass_2->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        JoinClass_2->setFlat(true);
        label_12->raise();
        TopicsTitleFrame->raise();
        TopicsTitle->raise();
        TopicsIcon->raise();
        verticalLayoutWidget->raise();
        JoinClass_2->raise();
        nav = new QLabel(centralwidget);
        nav->setObjectName("nav");
        nav->setGeometry(QRect(329, 10, 941, 71));
        nav->setStyleSheet(QString::fromUtf8("QFrame {\n"
"    background-color: #ffffff; \n"
"}"));
        Name = new QLabel(centralwidget);
        Name->setObjectName("Name");
        Name->setGeometry(QRect(1070, 10, 171, 41));
        QFont font7;
        font7.setFamilies({QString::fromUtf8("Roboto Serif")});
        font7.setPointSize(14);
        Name->setFont(font7);
        Name->setStyleSheet(QString::fromUtf8("background: none;\n"
"background-color: rgba(255, 255, 255, 0);\n"
"color: #000000;"));
        Name->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        Status = new QLabel(centralwidget);
        Status->setObjectName("Status");
        Status->setGeometry(QRect(1020, 40, 221, 41));
        QFont font8;
        font8.setFamilies({QString::fromUtf8("Roboto Serif")});
        font8.setPointSize(11);
        Status->setFont(font8);
        Status->setStyleSheet(QString::fromUtf8("background: none;\n"
"background-color: rgba(255, 255, 255, 0);\n"
"color: #777777;"));
        Status->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        Audo->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Audo);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1280, 25));
        Audo->setMenuBar(menubar);
        statusbar = new QStatusBar(Audo);
        statusbar->setObjectName("statusbar");
        Audo->setStatusBar(statusbar);

        retranslateUi(Audo);

        JoinClass->setDefault(false);
        JoinClass_2->setDefault(false);


        QMetaObject::connectSlotsByName(Audo);
    } // setupUi

    void retranslateUi(QMainWindow *Audo)
    {
        Audo->setWindowTitle(QCoreApplication::translate("Audo", "MainWindow", nullptr));
        logo->setText(QString());
        label_5->setText(QString());
        label_7->setText(QString());
        confirmButton->setText(QCoreApplication::translate("Audo", "Confirm", nullptr));
        Background_3->setText(QString());
        SignOut_2->setText(QCoreApplication::translate("Audo", "Account", nullptr));
        SignOut_4->setText(QCoreApplication::translate("Audo", "Classes", nullptr));
        Background->setText(QString());
        SignOut_3->setText(QCoreApplication::translate("Audo", "Participants", nullptr));
        Background_2->setText(QString());
        ClassCode->setPlaceholderText(QCoreApplication::translate("Audo", "Class name...", nullptr));
        JoinClass->setText(QCoreApplication::translate("Audo", "Create class", nullptr));
        classCodeText->setText(QCoreApplication::translate("Audo", "Class code:", nullptr));
        classCode->setText(QCoreApplication::translate("Audo", "QHERADO12D", nullptr));
        notes->setPlaceholderText(QString());
        deleteButton->setText(QString());
        editButton->setText(QString());
        Subject->setText(QCoreApplication::translate("Audo", "Subject name", nullptr));
        Topic->setText(QCoreApplication::translate("Audo", "Topic", nullptr));
        Topic_2->setText(QCoreApplication::translate("Audo", "Note", nullptr));
        label_12->setText(QString());
        TopicsTitleFrame->setText(QString());
        TopicsIcon->setText(QString());
        TopicsTitle->setText(QCoreApplication::translate("Audo", "Notes", nullptr));
        JoinClass_2->setText(QCoreApplication::translate("Audo", "Add note", nullptr));
        nav->setText(QString());
        Name->setText(QCoreApplication::translate("Audo", "Name", nullptr));
        Status->setText(QCoreApplication::translate("Audo", "status", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Audo: public Ui_Audo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AUDO_H
