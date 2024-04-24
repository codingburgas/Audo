/********************************************************************************
** Form generated from reading UI file 'teachergrades.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TEACHERGRADES_H
#define UI_TEACHERGRADES_H

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

class Ui_Grades
{
public:
    QLabel *AccountFrame;
    QLabel *GradeFrame;
    QLabel *StudentName;
    QFrame *AddGradesFrame;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *AddGradesLayout;
    QPushButton *Add2;
    QPushButton *Add6;
    QPushButton *Add5;
    QPushButton *Add4;
    QPushButton *Add3;
    QPushButton *AddGradeButton;
    QLabel *GradesTitle;
    QLabel *AddGradesTitle;
    QFrame *DescriptionFrame;
    QTextEdit *Description;
    QFrame *frame;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *GradesHorizontal;
    QVBoxLayout *GradesIconVertical;
    QSpacerItem *IconSpacer;
    QVBoxLayout *GradesDescVertical;
    QSpacerItem *DescriptionSpacer;
    QLabel *Background_4;
    QPushButton *SignOut_4;
    QLabel *Background_3;
    QPushButton *SignOut_2;
    QLabel *Background_2;
    QLabel *Background;
    QLabel *Frame_3;
    QPushButton *SignOut_3;
    QLabel *Status;
    QLabel *Name;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *Grades)
    {
        if (Grades->objectName().isEmpty())
            Grades->setObjectName("Grades");
        Grades->resize(1280, 832);
        Grades->setMinimumSize(QSize(1280, 832));
        Grades->setMaximumSize(QSize(1280, 832));
        Grades->setBaseSize(QSize(1280, 832));
        Grades->setStyleSheet(QString::fromUtf8("background-color: #F9F9F9;\n"
""));
        AccountFrame = new QLabel(Grades);
        AccountFrame->setObjectName("AccountFrame");
        AccountFrame->setGeometry(QRect(330, 10, 941, 81));
        AccountFrame->setStyleSheet(QString::fromUtf8("background-color: #FFFFFF;\n"
"box-shadow: 10px 10px 5px 12px black;"));
        AccountFrame->setFrameShadow(QFrame::Plain);
        GradeFrame = new QLabel(Grades);
        GradeFrame->setObjectName("GradeFrame");
        GradeFrame->setGeometry(QRect(330, 110, 941, 701));
        GradeFrame->setStyleSheet(QString::fromUtf8("background-color: #FFFFFF;"));
        StudentName = new QLabel(Grades);
        StudentName->setObjectName("StudentName");
        StudentName->setGeometry(QRect(360, 130, 221, 51));
        QFont font;
        font.setFamilies({QString::fromUtf8("Inter")});
        font.setPointSize(20);
        font.setWeight(QFont::DemiBold);
        font.setItalic(false);
        StudentName->setFont(font);
        StudentName->setStyleSheet(QString::fromUtf8("background: none;\n"
"background-color: rgba(255, 255, 255, 0);\n"
"color: #000000;\n"
"font: 600 20pt \"Inter\";"));
        StudentName->setAlignment(Qt::AlignCenter);
        AddGradesFrame = new QFrame(Grades);
        AddGradesFrame->setObjectName("AddGradesFrame");
        AddGradesFrame->setGeometry(QRect(890, 280, 211, 41));
        AddGradesFrame->setStyleSheet(QString::fromUtf8("QFrame\n"
"{ \n"
"     border-radius:5px;\n"
"}\n"
"QPushButton\n"
"{\n"
"color: #FFFFFF;\n"
"background-color: rgba(255, 122, 0, 120);\n"
"font: 500 12pt \"Inter\";\n"
"border-radius: 5px;\n"
"}\n"
"QPushButton:hover\n"
"{\n"
"color: #FFFFFF;\n"
"background-color: rgba(255, 122, 0, 255);\n"
"font: 500 12pt \"Inter\";\n"
"border-radius: 5px;\n"
"}"));
        AddGradesFrame->setFrameShape(QFrame::NoFrame);
        AddGradesFrame->setFrameShadow(QFrame::Plain);
        AddGradesFrame->setLineWidth(0);
        horizontalLayoutWidget = new QWidget(AddGradesFrame);
        horizontalLayoutWidget->setObjectName("horizontalLayoutWidget");
        horizontalLayoutWidget->setGeometry(QRect(0, 0, 211, 41));
        AddGradesLayout = new QHBoxLayout(horizontalLayoutWidget);
        AddGradesLayout->setObjectName("AddGradesLayout");
        AddGradesLayout->setContentsMargins(10, 0, 10, 0);
        Add2 = new QPushButton(horizontalLayoutWidget);
        Add2->setObjectName("Add2");
        Add2->setMinimumSize(QSize(30, 30));
        Add2->setMaximumSize(QSize(30, 30));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Inter")});
        font1.setPointSize(12);
        font1.setWeight(QFont::Medium);
        font1.setItalic(false);
        Add2->setFont(font1);
        Add2->setCursor(QCursor(Qt::PointingHandCursor));
        Add2->setAutoFillBackground(false);
        Add2->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"color: #FFFFFF;\n"
"background-color: rgba(255, 0, 0, 120);\n"
"font: 500 12pt \"Inter\";\n"
"border-radius:5px;\n"
"}\n"
"QPushButton:hover\n"
"{\n"
"color: #FFFFFF;\n"
"background-color: rgba(255, 0, 0, 255);\n"
"font: 500 12pt \"Inter\";\n"
"border-radius:5px;\n"
"}"));
        Add2->setFlat(true);

        AddGradesLayout->addWidget(Add2);

        Add6 = new QPushButton(horizontalLayoutWidget);
        Add6->setObjectName("Add6");
        Add6->setMinimumSize(QSize(30, 30));
        Add6->setMaximumSize(QSize(30, 30));
        Add6->setFont(font1);
        Add6->setCursor(QCursor(Qt::PointingHandCursor));
        Add6->setAutoFillBackground(false);
        Add6->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"color: #FFFFFF;\n"
"background-color: rgba(255, 122, 0, 120);\n"
"font: 500 12pt \"Inter\";\n"
"border-radius: 5px;\n"
"}\n"
"QPushButton:hover\n"
"{\n"
"color: #FFFFFF;\n"
"background-color: rgba(255, 122, 0, 255);\n"
"font: 500 12pt \"Inter\";\n"
"border-radius: 5px;\n"
"}"));
        Add6->setFlat(true);

        AddGradesLayout->addWidget(Add6);

        Add5 = new QPushButton(horizontalLayoutWidget);
        Add5->setObjectName("Add5");
        Add5->setMinimumSize(QSize(30, 30));
        Add5->setMaximumSize(QSize(30, 30));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Inter")});
        font2.setPointSize(12);
        font2.setBold(false);
        font2.setItalic(false);
        Add5->setFont(font2);
        Add5->setCursor(QCursor(Qt::PointingHandCursor));
        Add5->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"background-color: rgba(255, 214, 0, 120);\n"
"font: 12pt;\n"
"color:#ffffff;\n"
"border-radius:5px;\n"
"}\n"
"QPushButton:hover\n"
"{\n"
"color: #FFFFFF;\n"
"background-color: rgba(255, 214, 0, 255);\n"
"font: 500 12pt \"Inter\";\n"
"border-radius: 5px;\n"
"}"));

        AddGradesLayout->addWidget(Add5);

        Add4 = new QPushButton(horizontalLayoutWidget);
        Add4->setObjectName("Add4");
        Add4->setMinimumSize(QSize(30, 30));
        Add4->setMaximumSize(QSize(30, 30));
        Add4->setFont(font1);
        Add4->setCursor(QCursor(Qt::PointingHandCursor));
        Add4->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"color: #FFFFFF;\n"
"background-color: rgba(70, 142, 227, 123);\n"
"font: 500 12pt \"Inter\";\n"
"border-radius:5px;\n"
"}\n"
"QPushButton:hover\n"
"{\n"
"color: #FFFFFF;\n"
"background-color: rgba(70, 142, 227, 255);\n"
"font: 500 12pt \"Inter\";\n"
"border-radius: 5px;\n"
"}\n"
""));

        AddGradesLayout->addWidget(Add4);

        Add3 = new QPushButton(horizontalLayoutWidget);
        Add3->setObjectName("Add3");
        Add3->setMinimumSize(QSize(30, 30));
        Add3->setMaximumSize(QSize(30, 30));
        Add3->setFont(font1);
        Add3->setCursor(QCursor(Qt::PointingHandCursor));
        Add3->setStyleSheet(QString::fromUtf8("\n"
"QPushButton\n"
"{\n"
"color: #FFFFFF;\n"
"background-color: rgba(63, 198, 109, 123);\n"
"font: 500 12pt \"Inter\";\n"
"border-radius:5px;\n"
"}\n"
"QPushButton:hover\n"
"{\n"
"color: #FFFFFF;\n"
"background-color: rgba(63, 198, 109, 255);\n"
"font: 500 12pt \"Inter\";\n"
"border-radius: 5px;\n"
"}"));

        AddGradesLayout->addWidget(Add3);

        AddGradeButton = new QPushButton(Grades);
        AddGradeButton->setObjectName("AddGradeButton");
        AddGradeButton->setGeometry(QRect(1120, 340, 111, 41));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Roboto Serif SemiBold")});
        font3.setPointSize(10);
        font3.setWeight(QFont::DemiBold);
        font3.setItalic(false);
        font3.setKerning(true);
        AddGradeButton->setFont(font3);
        AddGradeButton->setCursor(QCursor(Qt::PointingHandCursor));
        AddGradeButton->setMouseTracking(true);
        AddGradeButton->setAutoFillBackground(false);
        AddGradeButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"font: 600 10pt \"Roboto Serif SemiBold\";\n"
"background-color: #F06B0A;\n"
"border-radius: 10px;\n"
"color:#ffffff;\n"
"}\n"
"QPushButton:hover {\n"
"font: 600 10pt \"Roboto Serif SemiBold\";\n"
"background-color: #E94600;\n"
"border-radius: 10px;\n"
"color:#ffffff;\n"
" }\n"
"\n"
""));
        AddGradeButton->setFlat(true);
        GradesTitle = new QLabel(Grades);
        GradesTitle->setObjectName("GradesTitle");
        GradesTitle->setGeometry(QRect(360, 200, 91, 51));
        QFont font4;
        font4.setFamilies({QString::fromUtf8("Inter")});
        font4.setPointSize(16);
        font4.setWeight(QFont::DemiBold);
        font4.setItalic(false);
        GradesTitle->setFont(font4);
        GradesTitle->setStyleSheet(QString::fromUtf8("background: none;\n"
"background-color: rgba(255, 255, 255, 0);\n"
"color: #000000;\n"
"font: 600 16pt \"Inter\";"));
        GradesTitle->setAlignment(Qt::AlignCenter);
        AddGradesTitle = new QLabel(Grades);
        AddGradesTitle->setObjectName("AddGradesTitle");
        AddGradesTitle->setGeometry(QRect(890, 200, 151, 51));
        AddGradesTitle->setFont(font4);
        AddGradesTitle->setStyleSheet(QString::fromUtf8("background: none;\n"
"background-color: rgba(255, 255, 255, 0);\n"
"color: #000000;\n"
"font: 600 16pt \"Inter\";"));
        AddGradesTitle->setAlignment(Qt::AlignCenter);
        DescriptionFrame = new QFrame(Grades);
        DescriptionFrame->setObjectName("DescriptionFrame");
        DescriptionFrame->setGeometry(QRect(890, 340, 211, 41));
        DescriptionFrame->setStyleSheet(QString::fromUtf8("border-radius:10px;"));
        DescriptionFrame->setFrameShape(QFrame::NoFrame);
        DescriptionFrame->setFrameShadow(QFrame::Plain);
        DescriptionFrame->setLineWidth(0);
        Description = new QTextEdit(DescriptionFrame);
        Description->setObjectName("Description");
        Description->setGeometry(QRect(0, 0, 191, 41));
        QFont font5;
        font5.setFamilies({QString::fromUtf8("Roboto Serif Medium")});
        font5.setPointSize(14);
        font5.setWeight(QFont::Medium);
        font5.setItalic(false);
        Description->setFont(font5);
        Description->viewport()->setProperty("cursor", QVariant(QCursor(Qt::PointingHandCursor)));
        Description->setAutoFillBackground(false);
        Description->setStyleSheet(QString::fromUtf8("background: none;\n"
"background-color: rgba(255, 255, 255, 0);\n"
"border: none;\n"
"color: rgba(107, 125, 179, 255);\n"
"font: 500 14pt \"Roboto Serif Medium\";"));
        frame = new QFrame(Grades);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(359, 289, 501, 471));
        frame->setAutoFillBackground(false);
        frame->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        frame->setFrameShape(QFrame::NoFrame);
        frame->setFrameShadow(QFrame::Plain);
        frame->setLineWidth(0);
        horizontalLayoutWidget_2 = new QWidget(frame);
        horizontalLayoutWidget_2->setObjectName("horizontalLayoutWidget_2");
        horizontalLayoutWidget_2->setGeometry(QRect(0, 0, 497, 471));
        GradesHorizontal = new QHBoxLayout(horizontalLayoutWidget_2);
        GradesHorizontal->setObjectName("GradesHorizontal");
        GradesHorizontal->setContentsMargins(0, 0, 0, 0);
        GradesIconVertical = new QVBoxLayout();
        GradesIconVertical->setSpacing(7);
        GradesIconVertical->setObjectName("GradesIconVertical");
        IconSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        GradesIconVertical->addItem(IconSpacer);


        GradesHorizontal->addLayout(GradesIconVertical);

        GradesDescVertical = new QVBoxLayout();
        GradesDescVertical->setObjectName("GradesDescVertical");
        DescriptionSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        GradesDescVertical->addItem(DescriptionSpacer);


        GradesHorizontal->addLayout(GradesDescVertical);

        Background_4 = new QLabel(Grades);
        Background_4->setObjectName("Background_4");
        Background_4->setGeometry(QRect(0, 20, 311, 51));
        Background_4->setAutoFillBackground(false);
        Background_4->setStyleSheet(QString::fromUtf8("background:none;"));
        Background_4->setPixmap(QPixmap(QString::fromUtf8(":/icons/assets/icons/logo.png")));
        Background_4->setAlignment(Qt::AlignCenter);
        SignOut_4 = new QPushButton(Grades);
        SignOut_4->setObjectName("SignOut_4");
        SignOut_4->setGeometry(QRect(30, 400, 241, 51));
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
        Background_3 = new QLabel(Grades);
        Background_3->setObjectName("Background_3");
        Background_3->setGeometry(QRect(40, 410, 31, 31));
        Background_3->setAutoFillBackground(false);
        Background_3->setStyleSheet(QString::fromUtf8("background:none;"));
        Background_3->setPixmap(QPixmap(QString::fromUtf8(":/icons/assets/icons/classes-icon.png")));
        Background_3->setAlignment(Qt::AlignCenter);
        SignOut_2 = new QPushButton(Grades);
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
        Background_2 = new QLabel(Grades);
        Background_2->setObjectName("Background_2");
        Background_2->setGeometry(QRect(40, 190, 31, 31));
        Background_2->setAutoFillBackground(false);
        Background_2->setStyleSheet(QString::fromUtf8("background:none;"));
        Background_2->setPixmap(QPixmap(QString::fromUtf8(":/icons/assets/icons/participants-icon.png")));
        Background_2->setAlignment(Qt::AlignCenter);
        Background = new QLabel(Grades);
        Background->setObjectName("Background");
        Background->setGeometry(QRect(40, 140, 31, 31));
        Background->setAutoFillBackground(false);
        Background->setStyleSheet(QString::fromUtf8("background:none;"));
        Background->setPixmap(QPixmap(QString::fromUtf8(":/icons/assets/icons/account-icon.png")));
        Background->setAlignment(Qt::AlignCenter);
        Frame_3 = new QLabel(Grades);
        Frame_3->setObjectName("Frame_3");
        Frame_3->setGeometry(QRect(0, 0, 310, 832));
        Frame_3->setStyleSheet(QString::fromUtf8("QFrame {\n"
"    background-color: #ffffff; \n"
"}"));
        SignOut_3 = new QPushButton(Grades);
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
        Status = new QLabel(Grades);
        Status->setObjectName("Status");
        Status->setGeometry(QRect(1040, 40, 221, 41));
        QFont font6;
        font6.setFamilies({QString::fromUtf8("Roboto Serif")});
        font6.setPointSize(11);
        Status->setFont(font6);
        Status->setStyleSheet(QString::fromUtf8("background: none;\n"
"background-color: rgba(255, 255, 255, 0);\n"
"color: #777777;"));
        Status->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        Name = new QLabel(Grades);
        Name->setObjectName("Name");
        Name->setGeometry(QRect(1090, 10, 171, 41));
        QFont font7;
        font7.setFamilies({QString::fromUtf8("Roboto Serif")});
        font7.setPointSize(14);
        Name->setFont(font7);
        Name->setStyleSheet(QString::fromUtf8("background: none;\n"
"background-color: rgba(255, 255, 255, 0);\n"
"color: #000000;"));
        Name->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        verticalLayoutWidget = new QWidget(Grades);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(30, 240, 241, 161));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        Frame_3->raise();
        AccountFrame->raise();
        GradeFrame->raise();
        StudentName->raise();
        AddGradesFrame->raise();
        AddGradeButton->raise();
        GradesTitle->raise();
        AddGradesTitle->raise();
        DescriptionFrame->raise();
        frame->raise();
        Background_4->raise();
        SignOut_4->raise();
        SignOut_2->raise();
        Background->raise();
        SignOut_3->raise();
        Background_3->raise();
        Background_2->raise();
        Status->raise();
        Name->raise();
        verticalLayoutWidget->raise();

        retranslateUi(Grades);

        AddGradeButton->setDefault(false);


        QMetaObject::connectSlotsByName(Grades);
    } // setupUi

    void retranslateUi(QWidget *Grades)
    {
        Grades->setWindowTitle(QCoreApplication::translate("Grades", "Form", nullptr));
        AccountFrame->setText(QString());
        GradeFrame->setText(QString());
        StudentName->setText(QCoreApplication::translate("Grades", "Student Name", nullptr));
        Add2->setText(QCoreApplication::translate("Grades", "2", nullptr));
        Add6->setText(QCoreApplication::translate("Grades", "3", nullptr));
        Add5->setText(QCoreApplication::translate("Grades", "4", nullptr));
        Add4->setText(QCoreApplication::translate("Grades", "5", nullptr));
        Add3->setText(QCoreApplication::translate("Grades", "6", nullptr));
        AddGradeButton->setText(QCoreApplication::translate("Grades", "Add Grade", nullptr));
        GradesTitle->setText(QCoreApplication::translate("Grades", "Grades", nullptr));
        AddGradesTitle->setText(QCoreApplication::translate("Grades", "Add grades", nullptr));
        Description->setPlaceholderText(QCoreApplication::translate("Grades", "Description...", nullptr));
        Background_4->setText(QString());
        SignOut_4->setText(QCoreApplication::translate("Grades", "Classes", nullptr));
        Background_3->setText(QString());
        SignOut_2->setText(QCoreApplication::translate("Grades", "Account", nullptr));
        Background_2->setText(QString());
        Background->setText(QString());
        Frame_3->setText(QString());
        SignOut_3->setText(QCoreApplication::translate("Grades", "Participants", nullptr));
        Status->setText(QCoreApplication::translate("Grades", "status", nullptr));
        Name->setText(QCoreApplication::translate("Grades", "Name", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Grades: public Ui_Grades {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TEACHERGRADES_H
