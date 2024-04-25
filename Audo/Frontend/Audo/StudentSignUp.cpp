#include "StudentSignUp.h"
#include "ui_StudentSignUp.h"
#include "utils.h"
#include "cpr/cpr.h"


StudentSignUp::StudentSignUp(QAction* switcher, QWidget *parent)
    : QWidget(parent), ui(new Ui::StudentSignUp), switchAction(switcher)
{
    ui->setupUi(this);
}

StudentSignUp::~StudentSignUp()
{
    delete ui;
}

void StudentSignUp::on_SignInButton_clicked()
{
    switchAction->setText("SignIn");
    switchAction->trigger();
}


void StudentSignUp::on_Continue_clicked()
{
    audoUtil::Body body =
    {
        { "first_name", ui->FName->toPlainText() },
        { "last_name", ui->LName->toPlainText() },
        { "email", ui->Email->toPlainText() },
        { "password", ui->Password->text() },
        { "status", "student" },
        { "school", ui->School->toPlainText() }
    };

    audoUtil::Response response = audoUtil::post("/api/register", body);

    if (response.status_code == audoUtil::OK) {

        audoCfg::authToken = audoUtil::post("/api/login", body).data["token"].toStr();

        audoCfg::firstName = ui->FName->toPlainText();
        audoCfg::lastName = ui->LName->toPlainText();
        audoCfg::email = ui->Email->toPlainText();
        audoCfg::status = "Student";
        audoCfg::school = ui->School->toPlainText();

        switchAction->setText("StudentNotes");
        switchAction->trigger();
    }
    else {

        ui->Warning->setText(response.data["data"].toString());
    }
}

