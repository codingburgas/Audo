#include "MainPage.h"
#include "ui_MainPage.h"
#include <QFontDatabase>

MainPage::MainPage(QAction* switcher, QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainPage), switchAction(switcher)
{
    ui->setupUi(this);
}

MainPage::~MainPage()
{
    delete ui;
}

void MainPage::on_SignIn_clicked()
{
    switchAction->setText("SignIn");
    switchAction->trigger();
}


void MainPage::on_SignUp_clicked()
{
    switchAction->setText("SignUp");
    switchAction->trigger();
}

