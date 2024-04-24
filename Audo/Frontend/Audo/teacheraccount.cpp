#include "teacheraccount.h"
#include "ui_teacheraccount.h"

teacherAccount::teacherAccount(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::teacherAccount)
{
    ui->setupUi(this);
}

teacherAccount::~teacherAccount()
{
    delete ui;
}
