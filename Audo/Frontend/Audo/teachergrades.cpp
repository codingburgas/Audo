#include "teachergrades.h"
#include "ui_teachergrades.h"

#include <QJsonArray>

#include "utils.h"

#define ButtonStyle "QPushButton { color: #FFFFFF; background-color: rgba(%s); font: 500 12pt \"Inter\"; border-radius:5px; } QPushButton:hover { color: #FFFFFF; background-color: rgba(%s, 255); font: 500 12pt \"Inter\"; border-radius:5px;}"

TeacherGrades::TeacherGrades(QAction* switcher, QWidget *parent)
    : QWidget(parent), ui(new Ui::Grades), switchAction(switcher)
{
    ui->setupUi(this);
}

void TeacherGrades::FetchUI(bool shouldReset)
{
    ui->Name->setText(audoCfg::firstName);
    ui->Status->setText(audoCfg::status);

    {
        int count = ui->ClassLayout->count() - 1;
        for(int i = 0; i < count; i++)
        {
            QWidget* item = ui->ClassLayout->itemAt(0)->widget();
            ui->ClassLayout->removeItem(ui->ClassLayout->itemAt(0));
            delete item;
        }
    }

    audoUtil::Response rooms = audoUtil::get("/api/get/user/rooms", audoUtil::ResponseType::ARRAY);

    if (rooms.array->isEmpty()) return;

    if (shouldReset) audoCfg::currentClassId = (*rooms.array)[0].toObject()["id"].toInt();

    for(const auto& room : *rooms.array)
    {
        AddClass(room.toObject());
    }

    FetchParticipants();

    ui->StudentName->setText(currentStudentName);

    FetchGrades();
}

void TeacherGrades::FetchParticipants(bool shouldReset)
{

    int count = ui->ParticipantLayout->count() - 1;
    for(int i = 0; i < count; i++)
    {
        QWidget* item = ui->ParticipantLayout->itemAt(i)->widget();
        ui->ParticipantLayout->removeItem(ui->ParticipantLayout->itemAt(0));
        delete item;
    }

    audoUtil::Body participantFetchBody
    {
        { "classroom_id", audoCfg::currentClassId }
    };

    audoUtil::Response room = audoUtil::post("/api/get/room", participantFetchBody, true, audoUtil::ResponseType::OBJECT);

    QJsonArray studentArray = QJsonArray(room.data["users"].toArray());

    if(shouldReset)
    {
        currentStudentId = studentArray[0].toObject()["user_id"].toInt();
        currentStudentName = studentArray[0].toObject()["fname"].toString() + " " + studentArray[0].toObject()["lname"].toString();
    }

    for(const auto& student : studentArray)
    {
        if(room.data["owner_id"] != student.toObject()["user_id"])
            AddParticipant(student.toObject());
    }

}

void TeacherGrades::FetchGrades()
{
    {
        int count = ui->GradesDescVertical->count() - 1;
        for(int i = 0; i < count; i++)
        {
            QWidget* item = ui->GradesDescVertical->itemAt(0)->widget();
            ui->GradesDescVertical->removeItem(ui->GradesDescVertical->itemAt(0));
            delete item;
        }
    }

    {
        int count = ui->GradesIconVertical->count() - 1;
        for(int i = 0; i < count; i++)
        {
            QWidget* item = ui->GradesIconVertical->itemAt(0)->widget();
            ui->GradesIconVertical->removeItem(ui->GradesIconVertical->itemAt(0));
            delete item;
        }
    }


    audoUtil::Body gradesBody
    {
        { "student_id", currentStudentId },
        { "room_id", audoCfg::currentClassId }
    };

    audoUtil::Body currentGradeBody
    {
        { "grade_id", 0 }
    };

    audoUtil::Response grades = audoUtil::post("/api/get/student/grades", gradesBody, true, audoUtil::ResponseType::ARRAY);

    for(const auto& grade : *grades.array)
    {
        std::get<1>(currentGradeBody[0]) = grade.toObject()["id"].toInt();
        audoUtil::Response currentGrade = audoUtil::post("/api/get/grade", currentGradeBody, true, audoUtil::ResponseType::OBJECT);

        AddGrade(currentGrade.data["score"].toInt(), currentGrade.data["description"].toStr());
    }
}

void TeacherGrades::AddGrade(const int&& grade, const std::string&& desc)
{
    int trueGrade = std::ceil(grade / 20) + 1;

    static QVBoxLayout* gradeIcons = ui->GradesIconVertical;
    static QVBoxLayout* gradeDesc = ui->GradesDescVertical;
    static QString baseStyleSheet = "color:#ffffff; border-radius:5px; font: 500 16pt \"Inter Medium\";";

    QLabel* newGrade = new QLabel;
    newGrade->setText(QString::fromStdString(std::to_string(trueGrade)));

    newGrade->setMinimumSize(QSize(35, 35));
    newGrade->setMaximumSize(QSize(35, 35));
    newGrade->setBaseSize(QSize(35, 35));

    newGrade->setAlignment(Qt::Alignment::enum_type::AlignCenter);

    QString newStyleSheet = baseStyleSheet;

    switch(trueGrade)
    {
    case 2:
        newStyleSheet += "background-color: #FF0000;";
        break;

    case 3:
        newStyleSheet += "background-color: #FF7A00;";
        break;

    case 4:
        newStyleSheet += "background-color: #FFD600;";
        break;

    case 5:
        newStyleSheet += "background-color: #D5F31C;";
        break;

    case 6:
        newStyleSheet += "background-color: #00BF08;";
        break;

    default:
        newStyleSheet += "background-color: #000000;";
    }
    newGrade->setStyleSheet(newStyleSheet);

    QLabel* newDesc = new QLabel;

    newDesc->setText(QString::fromStdString("Description: " + desc));
    newDesc->setStyleSheet("background:none; font: 500 10pt \"Inter Medium\"; color: rgba(0, 0, 0, 200);");

    newDesc->setMinimumSize(QSize(450, 35));
    newDesc->setMaximumSize(QSize(450, 35));
    newDesc->setBaseSize(QSize(450, 35));

    gradeIcons->insertWidget(gradeIcons->count() - 1, newGrade);
    gradeDesc->insertWidget(gradeDesc->count() - 1, newDesc);
}

void TeacherGrades::AddClass(QJsonObject&& classInfo)
{
    QVBoxLayout* classLayout = ui->ClassLayout;

    QPushButton* classButton = new QPushButton(classInfo["name"].toString());

    classButton->setMaximumHeight(26);
    classButton->setMinimumHeight(26);

    classButton->setObjectName(std::to_string(classInfo["id"].toInt()) + "Button");
    classButton->setAccessibleDescription(QString::fromStdString(std::to_string(classInfo["id"].toInt())));

    if(classInfo["id"].toInt() == audoCfg::currentClassId)
    {
        classButton->setStyleSheet("QPushButton{ background-color: rgba(255, 255, 255, 0); font: 500 14pt \"Inter\"; color: rgba(0, 0, 0, 255);}");
    }
    else
    {
        classButton->setStyleSheet("QPushButton{ background-color: rgba(255, 255, 255, 0); font: 500 14pt \"Inter\"; color: rgba(0, 0, 0, 123);} QPushButton:hover{ color: rgba(0, 0, 0, 255); }");
        classButton->setCursor(Qt::CursorShape::PointingHandCursor);
        connect(classButton, &QPushButton::clicked, [this, classButton]() { SetClass(classButton); });
    }

    classButton->setFlat(true);
    classButton->setAutoFillBackground(true);

    classLayout->insertWidget(classLayout->count() - 1, classButton);

}

void TeacherGrades::AddParticipant(QJsonObject&& participantInfo)
{
    QVBoxLayout* participantLayout = ui->ParticipantLayout;

    QPushButton* participantButton = new QPushButton(participantInfo["fname"].toString() + " " + participantInfo["lname"].toString());

    participantButton->setMaximumHeight(26);
    participantButton->setMinimumHeight(26);

    participantButton->setObjectName(std::to_string(participantInfo["user_id"].toInt()) + "PButton");
    participantButton->setAccessibleDescription(QString::fromStdString(std::to_string(participantInfo["user_id"].toInt())));

    if(participantInfo["user_id"].toInt() == currentStudentId)
    {
        participantButton->setStyleSheet("QPushButton{ background-color: rgba(255, 255, 255, 0); font: 500 14pt \"Inter\"; color: rgba(0, 0, 0, 255);}");
    }
    else
    {
        participantButton->setStyleSheet("QPushButton{ background-color: rgba(255, 255, 255, 0); font: 500 14pt \"Inter\"; color: rgba(0, 0, 0, 123);} QPushButton:hover{ color: rgba(0, 0, 0, 255); }");
        participantButton->setCursor(Qt::CursorShape::PointingHandCursor);
        connect(participantButton, &QPushButton::clicked, [this, participantButton]() { SetParticipant(participantButton); });
    }

    participantButton->setFlat(true);
    participantButton->setAutoFillBackground(true);

    participantLayout->insertWidget(participantLayout->count() - 1, participantButton);
}

void TeacherGrades::SetClass(QPushButton* classButton)
{
    audoCfg::currentClassId = std::stoi(classButton->accessibleDescription().toStdString());

    FetchUI(false);
}

void TeacherGrades::SetParticipant(QPushButton* participantButton)
{
    currentStudentId = std::stoi(participantButton->accessibleDescription().toStdString());
    currentStudentName = participantButton->text();

    ui->StudentName->setText(currentStudentName);

    FetchParticipants(false);

    FetchGrades();
}

TeacherGrades::~TeacherGrades()
{
    delete ui;
}

void TeacherGrades::on_Add2_clicked()
{
    currentGrade = 2;
}


void TeacherGrades::on_Add3_clicked()
{
    currentGrade = 3;
}


void TeacherGrades::on_Add4_clicked()
{
    currentGrade = 4;
}


void TeacherGrades::on_Add5_clicked()
{
    currentGrade = 5;
}


void TeacherGrades::on_Add6_clicked()
{
    currentGrade = 6;
}


void TeacherGrades::on_AddGradeButton_clicked()
{
    audoUtil::Body gradeBody
    {
        { "subject", "nil" },
        { "score", (currentGrade - 1) * 20 },
        { "description", ui->Description->toPlainText()},
        { "student_id", currentStudentId },
        { "room_id", audoCfg::currentClassId }
    };

    audoUtil::post("/api/create/grade", gradeBody, true);

    FetchUI(false);
}

