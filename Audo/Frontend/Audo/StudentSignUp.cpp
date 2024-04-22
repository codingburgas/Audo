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
        { "first_name", ui->FName->toText() },
        { "last_name", ui->LName->toText() },
        { "email", ui->Email->toText() },
        { "password", ui->Password->toText() },
        { "status", "student" },
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

        switchAction->setText("Audo");
        switchAction->trigger();
    }
    else {

        ui->Warning->setText(response.data["data"].toString());
    }
}

