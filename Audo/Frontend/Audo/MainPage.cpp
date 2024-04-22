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
    cpr::Response r = cpr::Get(cpr::Url{"https://api.github.com/repos/whoshuu/cpr/contributors"},
                               cpr::Authentication{"user", "pass", cpr::AuthMode::BASIC},
                               cpr::Parameters{{"anon", "true"}, {"key", "value"}});
    qDebug() << r.status_code;                  // 200
    qDebug() << r.header["content-type"];       // application/json; charset=utf-8
    qDebug() << r.text;
    switchAction->setText("SignIn");
    switchAction->trigger();
}


void MainPage::on_SignUp_clicked()
{
    switchAction->setText("SignUp");
    switchAction->trigger();
}

