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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_StudentGrades
{
public:
    QLabel *Frame_4;
    QFrame *frame;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *GradesHorizontal;
    QVBoxLayout *GradesIconVertical;
    QSpacerItem *IconSpacer;
    QVBoxLayout *GradesDescVertical;
    QSpacerItem *DescriptionSpacer;
    QLabel *StudentName;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label;
    QLabel *StudentName_2;
    QPushButton *SignOut_4;
    QLabel *Background_3;
    QPushButton *SignOut_2;
    QLabel *Background_4;
    QLabel *Frame_3;
    QPushButton *SignOut_3;
    QLabel *Background_2;
    QLabel *Background;
    QLabel *Frame_2;
    QLabel *Name;
    QLabel *Status;

    void setupUi(QWidget *StudentGrades)
    {
        if (StudentGrades->objectName().isEmpty())
            StudentGrades->setObjectName("StudentGrades");
        StudentGrades->resize(1280, 832);
        StudentGrades->setMinimumSize(QSize(1280, 832));
        StudentGrades->setMaximumSize(QSize(1280, 832));
        StudentGrades->setStyleSheet(QString::fromUtf8("background-color: rgb(249, 249, 249);"));
        Frame_4 = new QLabel(StudentGrades);
        Frame_4->setObjectName("Frame_4");
        Frame_4->setGeometry(QRect(330, 100, 941, 821));
        Frame_4->setStyleSheet(QString::fromUtf8("QFrame {\n"
"    background-color: #ffffff; \n"
"}"));
        frame = new QFrame(StudentGrades);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(690, 190, 501, 471));
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

        StudentName = new QLabel(StudentGrades);
        StudentName->setObjectName("StudentName");
        StudentName->setGeometry(QRect(370, 120, 131, 51));
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
        verticalLayoutWidget = new QWidget(StudentGrades);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(370, 190, 231, 471));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(verticalLayoutWidget);
        label_2->setObjectName("label_2");

        verticalLayout->addWidget(label_2);

        label_3 = new QLabel(verticalLayoutWidget);
        label_3->setObjectName("label_3");

        verticalLayout->addWidget(label_3);

        label = new QLabel(verticalLayoutWidget);
        label->setObjectName("label");

        verticalLayout->addWidget(label);

        StudentName_2 = new QLabel(StudentGrades);
        StudentName_2->setObjectName("StudentName_2");
        StudentName_2->setGeometry(QRect(690, 120, 131, 51));
        StudentName_2->setFont(font);
        StudentName_2->setStyleSheet(QString::fromUtf8("background: none;\n"
"background-color: rgba(255, 255, 255, 0);\n"
"color: #000000;\n"
"font: 600 20pt \"Inter\";"));
        StudentName_2->setAlignment(Qt::AlignCenter);
        SignOut_4 = new QPushButton(StudentGrades);
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
        Background_3 = new QLabel(StudentGrades);
        Background_3->setObjectName("Background_3");
        Background_3->setGeometry(QRect(40, 240, 31, 31));
        Background_3->setAutoFillBackground(false);
        Background_3->setStyleSheet(QString::fromUtf8("background:none;"));
        Background_3->setPixmap(QPixmap(QString::fromUtf8(":/icons/assets/icons/classes-icon.png")));
        Background_3->setAlignment(Qt::AlignCenter);
        SignOut_2 = new QPushButton(StudentGrades);
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
        Background_4 = new QLabel(StudentGrades);
        Background_4->setObjectName("Background_4");
        Background_4->setGeometry(QRect(0, 20, 311, 51));
        Background_4->setAutoFillBackground(false);
        Background_4->setStyleSheet(QString::fromUtf8("background:none;"));
        Background_4->setPixmap(QPixmap(QString::fromUtf8(":/icons/assets/icons/logo.png")));
        Background_4->setAlignment(Qt::AlignCenter);
        Frame_3 = new QLabel(StudentGrades);
        Frame_3->setObjectName("Frame_3");
        Frame_3->setGeometry(QRect(0, 0, 310, 832));
        Frame_3->setStyleSheet(QString::fromUtf8("QFrame {\n"
"    background-color: #ffffff; \n"
"}"));
        SignOut_3 = new QPushButton(StudentGrades);
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
        Background_2 = new QLabel(StudentGrades);
        Background_2->setObjectName("Background_2");
        Background_2->setGeometry(QRect(40, 190, 31, 31));
        Background_2->setAutoFillBackground(false);
        Background_2->setStyleSheet(QString::fromUtf8("background:none;"));
        Background_2->setPixmap(QPixmap(QString::fromUtf8(":/icons/assets/icons/grades-icon.png")));
        Background_2->setAlignment(Qt::AlignCenter);
        Background = new QLabel(StudentGrades);
        Background->setObjectName("Background");
        Background->setGeometry(QRect(40, 140, 31, 31));
        Background->setAutoFillBackground(false);
        Background->setStyleSheet(QString::fromUtf8("background:none;"));
        Background->setPixmap(QPixmap(QString::fromUtf8(":/icons/assets/icons/account-icon.png")));
        Background->setAlignment(Qt::AlignCenter);
        Frame_2 = new QLabel(StudentGrades);
        Frame_2->setObjectName("Frame_2");
        Frame_2->setGeometry(QRect(330, 10, 941, 71));
        Frame_2->setStyleSheet(QString::fromUtf8("QFrame {\n"
"    background-color: #ffffff; \n"
"}"));
        Name = new QLabel(StudentGrades);
        Name->setObjectName("Name");
        Name->setGeometry(QRect(1071, 10, 171, 41));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Roboto Serif")});
        font1.setPointSize(14);
        Name->setFont(font1);
        Name->setStyleSheet(QString::fromUtf8("background: none;\n"
"background-color: rgba(255, 255, 255, 0);\n"
"color: #000000;"));
        Name->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        Status = new QLabel(StudentGrades);
        Status->setObjectName("Status");
        Status->setGeometry(QRect(1021, 40, 221, 41));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Roboto Serif")});
        font2.setPointSize(11);
        Status->setFont(font2);
        Status->setStyleSheet(QString::fromUtf8("background: none;\n"
"background-color: rgba(255, 255, 255, 0);\n"
"color: #777777;"));
        Status->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        Frame_3->raise();
        Frame_4->raise();
        frame->raise();
        StudentName->raise();
        verticalLayoutWidget->raise();
        StudentName_2->raise();
        SignOut_4->raise();
        SignOut_2->raise();
        Background_4->raise();
        SignOut_3->raise();
        Background->raise();
        Background_2->raise();
        Background_3->raise();
        Frame_2->raise();
        Name->raise();
        Status->raise();

        retranslateUi(StudentGrades);

        QMetaObject::connectSlotsByName(StudentGrades);
    } // setupUi

    void retranslateUi(QWidget *StudentGrades)
    {
        StudentGrades->setWindowTitle(QCoreApplication::translate("StudentGrades", "Form", nullptr));
        Frame_4->setText(QString());
        StudentName->setText(QCoreApplication::translate("StudentGrades", "Subject", nullptr));
        label_2->setText(QCoreApplication::translate("StudentGrades", "TextLabel", nullptr));
        label_3->setText(QCoreApplication::translate("StudentGrades", "TextLabel", nullptr));
        label->setText(QCoreApplication::translate("StudentGrades", "TextLabel", nullptr));
        StudentName_2->setText(QCoreApplication::translate("StudentGrades", "Grades", nullptr));
        SignOut_4->setText(QCoreApplication::translate("StudentGrades", "Classes", nullptr));
        Background_3->setText(QString());
        SignOut_2->setText(QCoreApplication::translate("StudentGrades", "Account", nullptr));
        Background_4->setText(QString());
        Frame_3->setText(QString());
        SignOut_3->setText(QCoreApplication::translate("StudentGrades", "Grades", nullptr));
        Background_2->setText(QString());
        Background->setText(QString());
        Frame_2->setText(QString());
        Name->setText(QCoreApplication::translate("StudentGrades", "Name", nullptr));
        Status->setText(QCoreApplication::translate("StudentGrades", "status", nullptr));
    } // retranslateUi

};

namespace Ui {
    class StudentGrades: public Ui_StudentGrades {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STUDENTGRADES_H