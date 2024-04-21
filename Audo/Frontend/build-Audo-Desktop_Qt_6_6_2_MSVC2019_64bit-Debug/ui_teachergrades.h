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
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TeacherGrades
{
public:
    QLabel *AccountFrame;
    QLabel *Background;
    QLabel *Name;
    QLabel *Status;
    QLabel *UserIcon;
    QLabel *GradeFrame;
    QLabel *StudentName;
    QFrame *GradeTable;
    QFrame *AverageFullFrame;
    QFrame *AverageFrame;
    QLabel *AverageGrade;
    QLabel *Average;
    QLabel *GradesLabel;
    QFrame *GradeList;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *GradeLayout;
    QLabel *Grade1;
    QSpacerItem *GradeSpacer;
    QFrame *AddGradesFrame;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *AddGradesLayout;
    QPushButton *Add2;
    QPushButton *Add6;
    QPushButton *Add5;
    QPushButton *Add4;
    QPushButton *Add3;
    QTextEdit *Description;
    QLabel *DescriptionFrame;
    QPushButton *AddGradeButton;
    QPushButton *pushButton;

    void setupUi(QWidget *TeacherGrades)
    {
        if (TeacherGrades->objectName().isEmpty())
            TeacherGrades->setObjectName("TeacherGrades");
        TeacherGrades->resize(1280, 832);
        TeacherGrades->setMinimumSize(QSize(1280, 832));
        TeacherGrades->setMaximumSize(QSize(1280, 832));
        TeacherGrades->setBaseSize(QSize(1280, 832));
        TeacherGrades->setStyleSheet(QString::fromUtf8("background-color: #4B4CAD;\n"
""));
        AccountFrame = new QLabel(TeacherGrades);
        AccountFrame->setObjectName("AccountFrame");
        AccountFrame->setGeometry(QRect(20, 20, 1241, 81));
        AccountFrame->setStyleSheet(QString::fromUtf8("background-color: #FFFFFF;\n"
"box-shadow: 10px 10px 5px 12px black;"));
        AccountFrame->setFrameShadow(QFrame::Plain);
        Background = new QLabel(TeacherGrades);
        Background->setObjectName("Background");
        Background->setGeometry(QRect(0, 0, 1280, 832));
        Background->setPixmap(QPixmap(QString::fromUtf8(":/backgrounds/assets/backgrounds/login-background.png")));
        Background->setAlignment(Qt::AlignCenter);
        Name = new QLabel(TeacherGrades);
        Name->setObjectName("Name");
        Name->setGeometry(QRect(940, 30, 221, 41));
        QFont font;
        font.setFamilies({QString::fromUtf8("Roboto Serif")});
        font.setPointSize(14);
        Name->setFont(font);
        Name->setStyleSheet(QString::fromUtf8("background: none;\n"
"background-color: rgba(255, 255, 255, 0);\n"
"color: #445178;"));
        Name->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        Status = new QLabel(TeacherGrades);
        Status->setObjectName("Status");
        Status->setGeometry(QRect(940, 50, 221, 41));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Roboto Serif")});
        font1.setPointSize(11);
        Status->setFont(font1);
        Status->setStyleSheet(QString::fromUtf8("background: none;\n"
"background-color: rgba(255, 255, 255, 0);\n"
"color: #445178;"));
        Status->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        UserIcon = new QLabel(TeacherGrades);
        UserIcon->setObjectName("UserIcon");
        UserIcon->setGeometry(QRect(1180, 26, 61, 71));
        UserIcon->setStyleSheet(QString::fromUtf8("background: none;\n"
"background-color: rgba(255, 255, 255, 0);"));
        UserIcon->setPixmap(QPixmap(QString::fromUtf8(":/icons/assets/icons/user.png")));
        GradeFrame = new QLabel(TeacherGrades);
        GradeFrame->setObjectName("GradeFrame");
        GradeFrame->setGeometry(QRect(20, 130, 1241, 681));
        GradeFrame->setStyleSheet(QString::fromUtf8("background-color: #FFFFFF;"));
        StudentName = new QLabel(TeacherGrades);
        StudentName->setObjectName("StudentName");
        StudentName->setGeometry(QRect(210, 140, 851, 51));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Roboto Serif")});
        font2.setPointSize(20);
        font2.setWeight(QFont::Medium);
        font2.setItalic(false);
        StudentName->setFont(font2);
        StudentName->setStyleSheet(QString::fromUtf8("background: none;\n"
"background-color: rgba(255, 255, 255, 0);\n"
"color: #3D4460;\n"
"font: 500 20pt \"Roboto Serif\";"));
        StudentName->setAlignment(Qt::AlignCenter);
        GradeTable = new QFrame(TeacherGrades);
        GradeTable->setObjectName("GradeTable");
        GradeTable->setGeometry(QRect(210, 250, 851, 181));
        GradeTable->setStyleSheet(QString::fromUtf8("background-color: #F3F3FF;\n"
"border-style: inset;\n"
"border-width: 2px;\n"
"border-color: rgba(68, 81, 120, 123);"));
        GradeTable->setFrameShape(QFrame::NoFrame);
        GradeTable->setFrameShadow(QFrame::Plain);
        AverageFullFrame = new QFrame(GradeTable);
        AverageFullFrame->setObjectName("AverageFullFrame");
        AverageFullFrame->setGeometry(QRect(620, 0, 231, 181));
        AverageFullFrame->setStyleSheet(QString::fromUtf8("background-color: #F3F3FF;\n"
"border-style: inset;\n"
"border-width: 2px;\n"
"border-color: rgba(68, 81, 120, 123);"));
        AverageFullFrame->setFrameShape(QFrame::NoFrame);
        AverageFullFrame->setFrameShadow(QFrame::Plain);
        AverageFrame = new QFrame(AverageFullFrame);
        AverageFrame->setObjectName("AverageFrame");
        AverageFrame->setGeometry(QRect(0, 100, 231, 81));
        AverageFrame->setStyleSheet(QString::fromUtf8("background-color: #F3F3FF;\n"
"border-style: inset;\n"
"border-width: 2px;\n"
"border-color: rgba(68, 81, 120, 123);"));
        AverageFrame->setFrameShape(QFrame::NoFrame);
        AverageFrame->setFrameShadow(QFrame::Plain);
        AverageGrade = new QLabel(AverageFrame);
        AverageGrade->setObjectName("AverageGrade");
        AverageGrade->setGeometry(QRect(0, 0, 231, 81));
        AverageGrade->setStyleSheet(QString::fromUtf8("font: 500 16pt \"Inter\";\n"
"color: #445178;"));
        AverageGrade->setAlignment(Qt::AlignCenter);
        Average = new QLabel(AverageFullFrame);
        Average->setObjectName("Average");
        Average->setGeometry(QRect(0, 0, 231, 101));
        Average->setStyleSheet(QString::fromUtf8("color: #445178;\n"
"font: 600 16pt \"Inter\";"));
        Average->setAlignment(Qt::AlignCenter);
        GradesLabel = new QLabel(GradeTable);
        GradesLabel->setObjectName("GradesLabel");
        GradesLabel->setGeometry(QRect(0, 0, 621, 101));
        GradesLabel->setStyleSheet(QString::fromUtf8("color: #445178;\n"
"font: 600 16pt \"Inter\";"));
        GradesLabel->setAlignment(Qt::AlignCenter);
        GradeList = new QFrame(GradeTable);
        GradeList->setObjectName("GradeList");
        GradeList->setGeometry(QRect(0, 100, 621, 81));
        GradeList->setStyleSheet(QString::fromUtf8("background-color: #F3F3FF;\n"
"border-style: inset;\n"
"border-width: 2px;\n"
"border-color: rgba(68, 81, 120, 123);"));
        GradeList->setFrameShape(QFrame::NoFrame);
        GradeList->setFrameShadow(QFrame::Plain);
        horizontalLayoutWidget_2 = new QWidget(GradeList);
        horizontalLayoutWidget_2->setObjectName("horizontalLayoutWidget_2");
        horizontalLayoutWidget_2->setGeometry(QRect(0, 0, 621, 81));
        GradeLayout = new QHBoxLayout(horizontalLayoutWidget_2);
        GradeLayout->setSpacing(10);
        GradeLayout->setObjectName("GradeLayout");
        GradeLayout->setContentsMargins(20, 0, 20, 0);
        Grade1 = new QLabel(horizontalLayoutWidget_2);
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

        GradeLayout->addWidget(Grade1);

        GradeSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        GradeLayout->addItem(GradeSpacer);

        AddGradesFrame = new QFrame(TeacherGrades);
        AddGradesFrame->setObjectName("AddGradesFrame");
        AddGradesFrame->setGeometry(QRect(500, 450, 211, 41));
        AddGradesFrame->setStyleSheet(QString::fromUtf8("background-color: #F3F3FF;\n"
"border-radius: 10px;"));
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
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Inter")});
        font3.setPointSize(12);
        font3.setWeight(QFont::Medium);
        font3.setItalic(false);
        Add2->setFont(font3);
        Add2->setStyleSheet(QString::fromUtf8("color: #FFFFFF;\n"
"background-color: rgb(255, 82, 82);\n"
"font: 500 12pt \"Inter\";"));

        AddGradesLayout->addWidget(Add2);

        Add6 = new QPushButton(horizontalLayoutWidget);
        Add6->setObjectName("Add6");
        Add6->setMinimumSize(QSize(30, 30));
        Add6->setMaximumSize(QSize(30, 30));
        Add6->setFont(font3);
        Add6->setStyleSheet(QString::fromUtf8("color: #FFFFFF;\n"
"background-color: rgba(255, 141, 93, 123);\n"
"font: 500 12pt \"Inter\";"));

        AddGradesLayout->addWidget(Add6);

        Add5 = new QPushButton(horizontalLayoutWidget);
        Add5->setObjectName("Add5");
        Add5->setMinimumSize(QSize(30, 30));
        Add5->setMaximumSize(QSize(30, 30));
        Add5->setFont(font3);
        Add5->setStyleSheet(QString::fromUtf8("color: #FFFFFF;\n"
"background-color: rgba(255, 197, 48, 123);\n"
"font: 500 12pt \"Inter\";"));

        AddGradesLayout->addWidget(Add5);

        Add4 = new QPushButton(horizontalLayoutWidget);
        Add4->setObjectName("Add4");
        Add4->setMinimumSize(QSize(30, 30));
        Add4->setMaximumSize(QSize(30, 30));
        Add4->setFont(font3);
        Add4->setStyleSheet(QString::fromUtf8("color: #FFFFFF;\n"
"background-color: rgba(70, 142, 227, 123);\n"
"font: 500 12pt \"Inter\";"));

        AddGradesLayout->addWidget(Add4);

        Add3 = new QPushButton(horizontalLayoutWidget);
        Add3->setObjectName("Add3");
        Add3->setMinimumSize(QSize(30, 30));
        Add3->setMaximumSize(QSize(30, 30));
        Add3->setFont(font3);
        Add3->setStyleSheet(QString::fromUtf8("color: #FFFFFF;\n"
"background-color: rgba(63, 198, 109, 123);\n"
"font: 500 12pt \"Inter\";"));

        AddGradesLayout->addWidget(Add3);

        Description = new QTextEdit(TeacherGrades);
        Description->setObjectName("Description");
        Description->setGeometry(QRect(740, 453, 191, 31));
        QFont font4;
        font4.setFamilies({QString::fromUtf8("Roboto Serif Medium")});
        font4.setPointSize(14);
        font4.setWeight(QFont::Medium);
        font4.setItalic(false);
        Description->setFont(font4);
        Description->setAutoFillBackground(false);
        Description->setStyleSheet(QString::fromUtf8("background: none;\n"
"background-color: rgba(255, 255, 255, 0);\n"
"border: none;\n"
"color: rgba(107, 125, 179, 255);\n"
"font: 500 14pt \"Roboto Serif Medium\";"));
        DescriptionFrame = new QLabel(TeacherGrades);
        DescriptionFrame->setObjectName("DescriptionFrame");
        DescriptionFrame->setGeometry(QRect(730, 449, 211, 41));
        DescriptionFrame->setStyleSheet(QString::fromUtf8("background-color: #F3F3FF;\n"
"border-radius: 16px;"));
        AddGradeButton = new QPushButton(TeacherGrades);
        AddGradeButton->setObjectName("AddGradeButton");
        AddGradeButton->setGeometry(QRect(950, 450, 111, 41));
        QFont font5;
        font5.setFamilies({QString::fromUtf8("Roboto Serif")});
        font5.setPointSize(12);
        font5.setBold(true);
        font5.setKerning(true);
        AddGradeButton->setFont(font5);
        AddGradeButton->setCursor(QCursor(Qt::PointingHandCursor));
        AddGradeButton->setMouseTracking(true);
        AddGradeButton->setAutoFillBackground(false);
        AddGradeButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"border-radius: 10px;\n"
"background-color: #986BF6;\n"
"color:#ffffff;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"\n"
"background-color: #7E56D2;\n"
"color:#ffffff;\n"
" }"));
        AddGradeButton->setFlat(true);
        pushButton = new QPushButton(TeacherGrades);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(40, 150, 51, 61));
        pushButton->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/assets/icons/back-arrow.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton->setIcon(icon);
        pushButton->setIconSize(QSize(48, 48));
        Background->raise();
        AccountFrame->raise();
        Name->raise();
        Status->raise();
        UserIcon->raise();
        GradeFrame->raise();
        GradeTable->raise();
        StudentName->raise();
        AddGradesFrame->raise();
        DescriptionFrame->raise();
        Description->raise();
        AddGradeButton->raise();
        pushButton->raise();

        retranslateUi(TeacherGrades);

        AddGradeButton->setDefault(false);


        QMetaObject::connectSlotsByName(TeacherGrades);
    } // setupUi

    void retranslateUi(QWidget *TeacherGrades)
    {
        TeacherGrades->setWindowTitle(QCoreApplication::translate("TeacherGrades", "Form", nullptr));
        AccountFrame->setText(QString());
        Background->setText(QString());
        Name->setText(QCoreApplication::translate("TeacherGrades", "Name", nullptr));
        Status->setText(QCoreApplication::translate("TeacherGrades", "Teacher", nullptr));
        UserIcon->setText(QString());
        GradeFrame->setText(QString());
        StudentName->setText(QCoreApplication::translate("TeacherGrades", "Student Name", nullptr));
        AverageGrade->setText(QCoreApplication::translate("TeacherGrades", "?", nullptr));
        Average->setText(QCoreApplication::translate("TeacherGrades", "Average", nullptr));
        GradesLabel->setText(QCoreApplication::translate("TeacherGrades", "Grades", nullptr));
        Grade1->setText(QCoreApplication::translate("TeacherGrades", "2", nullptr));
        Add2->setText(QCoreApplication::translate("TeacherGrades", "2", nullptr));
        Add6->setText(QCoreApplication::translate("TeacherGrades", "3", nullptr));
        Add5->setText(QCoreApplication::translate("TeacherGrades", "4", nullptr));
        Add4->setText(QCoreApplication::translate("TeacherGrades", "5", nullptr));
        Add3->setText(QCoreApplication::translate("TeacherGrades", "6", nullptr));
        Description->setPlaceholderText(QCoreApplication::translate("TeacherGrades", "Description...", nullptr));
        DescriptionFrame->setText(QString());
        AddGradeButton->setText(QCoreApplication::translate("TeacherGrades", "Add Grade", nullptr));
        pushButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class TeacherGrades: public Ui_TeacherGrades {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TEACHERGRADES_H
