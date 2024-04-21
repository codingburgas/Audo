#include "requests.h"
#include "ui_requests.h"

requests::requests(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::requests)
{
    ui->setupUi(this);
}

requests::~requests()
{
    delete ui;
}
