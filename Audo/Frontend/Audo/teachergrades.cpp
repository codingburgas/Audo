#include "teachergrades.h"
#include "ui_teachergrades.h"

#include "utils.h"

TeacherGrades::TeacherGrades(QAction* switcher, QWidget *parent)
    : QWidget(parent), ui(new Ui::Grades), switchAction(switcher)
{
    ui->setupUi(this);
}

void TeacherGrades::FetchUI()
{
    FetchGrades();
}


void TeacherGrades::FetchGrades()
{
    AddGrade(3, "student is slow");
    AddGrade(2, "student became even slower");

}

void TeacherGrades::AddGrade(const int&& grade, const std::string&& desc)
{
    static QVBoxLayout* gradeIcons = ui->GradesIconVertical;
    static QVBoxLayout* gradeDesc = ui->GradesDescVertical;
    static QString baseStyleSheet = "color:#ffffff; border-radius:5px; font: 500 16pt \"Inter Medium\";";

    QLabel* newGrade = new QLabel;
    newGrade->setText(QString::fromStdString(std::to_string(grade)));

    newGrade->setMinimumSize(QSize(35, 35));
    newGrade->setMaximumSize(QSize(35, 35));
    newGrade->setBaseSize(QSize(35, 35));

    newGrade->setAlignment(Qt::Alignment::enum_type::AlignCenter);

    QString newStyleSheet = baseStyleSheet;

    switch(grade)
    {
    case 2:
        newStyleSheet += "background-color: #FF7A00;";
        break;

    case 3:
        newStyleSheet += "background-color: #FF7A00;";
        break;

    case 4:
        newStyleSheet += "background-color: #FFD600;";
        break;

    case 5:
        newStyleSheet += "background-color: #D5F31C;";
        break;

    case 6:
        newStyleSheet += "background-color: #00BF08;";
        break;
    }

    QLabel* newDesc = new QLabel;

    newDesc->setText(QString::fromStdString("Description: " + desc));
    newDesc->setStyleSheet("background:none; font: 500 10pt \"Inter Medium\"; color: rgba(0, 0, 0, 200);");

    newDesc->setMinimumSize(QSize(450, 35));
    newDesc->setMaximumSize(QSize(450, 35));
    newDesc->setBaseSize(QSize(450, 35));

    gradeIcons->insertWidget(gradeIcons->count() - 1, newGrade);
    gradeDesc->insertWidget(gradeDesc->count() - 1, newDesc);
}

TeacherGrades::~TeacherGrades()
{
    delete ui;
}
