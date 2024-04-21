#include "TeacherGrades.h"
#include "ui_teachergrades.h"

TeacherGrades::TeacherGrades(QAction* switcher, QWidget *parent)
    : QWidget(parent), ui(new Ui::Grades), switchAction(switcher)
{
    ui->setupUi(this);
}


TeacherGrades::~TeacherGrades()
{
    delete ui;
}
