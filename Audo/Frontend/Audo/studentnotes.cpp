#include "studentnotes.h"
#include "ui_studentnotes.h"

StudentNotes::StudentNotes(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::StudentNotes)
{
    ui->setupUi(this);
}

StudentNotes::~StudentNotes()
{
    delete ui;
}
