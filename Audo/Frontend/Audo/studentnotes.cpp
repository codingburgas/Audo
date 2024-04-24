#include "studentnotes.h"
#include "ui_studentnotes.h"

#include "utils.h"

StudentNotes::StudentNotes(QAction* switcher, QWidget *parent)
    : QWidget(parent), ui(new Ui::StudentNotes), switchAction(switcher)
{
    ui->setupUi(this);
}

void StudentNotes::FetchUI()
{
    ui->Name->setText(audoCfg::firstName);
    ui->Status->setText(audoCfg::status);

    audoUtil::Response rooms = audoUtil::get("/api/get/user/rooms");

    if (!rooms.data.isEmpty())
    {
        audoUtil::Body topicsBody
        {
                { "room_id", audoCfg::currentClassId.toStdString() }
        };

        audoUtil::Response topics = audoUtil::post("/api/get/notes", topicsBody, true);
    }


}

StudentNotes::~StudentNotes()
{
    delete ui;
}

void StudentNotes::on_JoinClass_clicked()
{
    audoUtil::Body body
    {
        { "room_code", ui->ClassCode->toText() }
    };

    audoUtil::Response response = audoUtil::post("/api/join/room", body, true);

    if(response.status_code == audoUtil::OK)
    {
        audoCfg::currentClassId = response.data["id"].toString();
        audoCfg::currentClassName = response.data["name"].toString();

        FetchUI();
    }
    else
    {
        ui->Warning->setText(response.data["data"].toString());

        FetchUI();
    }
}

