#include "Grades.h"
#include "ui_Grades.h"

Grades::Grades(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Grades)
{
    ui->setupUi(this);
}

Grades::~Grades()
{
    delete ui;
}
