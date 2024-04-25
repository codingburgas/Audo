#include "TeacherSignUp.h"
#include "ui_TeacherSignUp.h"

#include "utils.h"

TeacherSignUp::TeacherSignUp(QAction* switcher, QWidget *parent)
    : QWidget(parent), ui(new Ui::TeacherSignUp), switchAction(switcher)
{
    ui->setupUi(this);
}

TeacherSignUp::~TeacherSignUp()
{
    delete ui;
}

void TeacherSignUp::on_SignInButton_clicked()
{
    switchAction->setText("SignIn");
    switchAction->trigger();
}


void TeacherSignUp::on_Continue_clicked()
{
    audoUtil::Body body =
        {
            { "first_name", ui->FName->toPlainText() },
            { "last_name", ui->LName->toPlainText() },
            { "email", ui->Email->toPlainText() },
            { "password", ui->Password->text() },
            { "status", "teacher" },
            { "school", ui->School->toPlainText() }
        };

    audoUtil::Response response = audoUtil::post("/api/register", body);

    if (response.status_code == audoUtil::OK) {

        audoCfg::authToken = audoUtil::post("/api/login", body).data["token"].toStr();

        audoCfg::firstName = ui->FName->toPlainText();
        audoCfg::lastName = ui->LName->toPlainText();
        audoCfg::email = ui->Email->toPlainText();
        audoCfg::status = "Teacher";
        audoCfg::school = ui->School->toPlainText();

        switchAction->setText("TeacherNotes");
        switchAction->trigger();
    }
    else {

        ui->Warning->setText(response.data["data"].toString());
    }
}

