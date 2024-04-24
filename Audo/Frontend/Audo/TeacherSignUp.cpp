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
            { "first_name", ui->FName->toText() },
            { "last_name", ui->LName->toText() },
            { "email", ui->Email->toText() },
            { "password", ui->Password->toText() },
            { "status", "teacher" },
            { "school", "VSCPI" }
        };

    audoUtil::Response response = audoUtil::post("/api/register", body);

    if (response.status_code == audoUtil::OK) {

        audoCfg::authToken = audoUtil::post("/api/login", body).data["token"].toStr();

        audoCfg::firstName = body[0][1];
        audoCfg::lastName = body[1][1];
        audoCfg::email = body[2][1];
        audoCfg::status = body[4][1];
        audoCfg::school = body[5][1];

        switchAction->setText("TeacherGrades");
        switchAction->trigger();
    }
    else {

        ui->Warning->setText(response.data["data"].toString());
    }
}

