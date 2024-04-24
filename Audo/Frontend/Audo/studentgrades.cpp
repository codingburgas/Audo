#include "studentgrades.h"
#include "ui_studentgrades.h"

StudentGrades::StudentGrades(QAction* switcher, QWidget *parent)
    : QWidget(parent), ui(new Ui::StudentGrades), switchAction(switcher)
{
    ui->setupUi(this);
}

StudentGrades::~StudentGrades()
{
    delete ui;
}
