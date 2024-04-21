#include "studentgrades.h"
#include "ui_studentgrades.h"

StudentGrades::StudentGrades(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::StudentGrades)
{
    ui->setupUi(this);
}

StudentGrades::~StudentGrades()
{
    delete ui;
}
