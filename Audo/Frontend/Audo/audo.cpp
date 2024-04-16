#include "audo.h"
#include "./ui_audo.h"

Audo::Audo(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Audo)
{
    ui->setupUi(this);
}

Audo::~Audo()
{
    delete ui;
}
