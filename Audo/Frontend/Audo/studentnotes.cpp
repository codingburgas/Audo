#include "studentnotes.h"
#include "ui_studentnotes.h"

#include "utils.h"

#include <QVBoxLayout>
#include <QPushButton>

StudentNotes::StudentNotes(QAction* switcher, QWidget *parent)
    : QWidget(parent), ui(new Ui::StudentNotes), switchAction(switcher)
{
    ui->setupUi(this);
}

void StudentNotes::LoadNotes()
{
    loadedNotes.clear();

    audoUtil::Body notesBody
    {
        { "room_id", audoCfg::currentClassId }
    };

    audoUtil::Body currentNoteBody
    {
        { "note_id", 0 }
    };

    audoUtil::Response notes = audoUtil::post("/api/get/notes", notesBody, true, audoUtil::ResponseType::ARRAY);

    if (notes.array->isEmpty()) return;

    audoCfg::currentNoteId = (*notes.array)[0].toObject()["id"].toInt();

    for(const auto& note : *notes.array)
    {
        std::get<1>(currentNoteBody[0]) = note.toObject()["id"].toInt();
        audoUtil::Response currentNote = audoUtil::post("/api/get/note", currentNoteBody, true, audoUtil::ResponseType::OBJECT);

        loadedNotes.push_back(Note({currentNote.data["id"].toInt(),
                                    currentNote.data["subject"].toString(),
                                    currentNote.data["topic"].toString(),
                                    currentNote.data["content"].toString()}));
    }
}

void StudentNotes::FetchUI()
{   

    ui->Name->setText(audoCfg::firstName);
    ui->Status->setText(audoCfg::status);

    {
        int count = ui->ClassNameLayout->count() - 1;
        for(int i = 0; i < count; i++)
        {
            QWidget* item = ui->ClassNameLayout->itemAt(0)->widget();
            ui->ClassNameLayout->removeItem(ui->ClassNameLayout->itemAt(0));
            delete item;
        }
    }

    {
        int count = ui->ClassLeaveLayout->count() - 1;
        for(int i = 0; i < count; i++)
        {
            QWidget* item = ui->ClassLeaveLayout->itemAt(0)->widget();
            ui->ClassLeaveLayout->removeItem(ui->ClassLeaveLayout->itemAt(0));
            delete item;
        }
    }

    {
        int count = ui->TopicLayout->count() - 1;
        for(int i = 0; i < count; i++)
        {
            QWidget* item = ui->TopicLayout->itemAt(0)->widget();
            ui->TopicLayout->removeItem(ui->TopicLayout->itemAt(0));
            delete item;
        }
    }

    audoUtil::Response rooms = audoUtil::get("/api/get/user/rooms", audoUtil::ResponseType::ARRAY);

    if (rooms.array->isEmpty()) return;

    audoCfg::currentClassId = (*rooms.array)[0].toObject()["id"].toInt();

    for(const auto& room : *rooms.array)
    {
        AddClass(room.toObject());
    }

    LoadNotes();

    for(const Note& note : loadedNotes)
    {
        if (note.id == audoCfg::currentNoteId)
        {
            ui->Note->setText(note.content);
            ui->Subject->setText(note.subject);
            ui->Topic->setText(note.topic);
        }
    }

    for(const auto& note : loadedNotes)
    {
        AddNote(note);
    }
}

void StudentNotes::AddClass(QJsonObject&& classInfo)
{
    QVBoxLayout* classNameLayout = ui->ClassNameLayout;
    QVBoxLayout* classLeaveLayout = ui->ClassLeaveLayout;

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

    // QPushButton* leaveButton = new QPushButton("X");

    // leaveButton->setMaximumSize(QSize(26, 26));
    // leaveButton->setMinimumSize(QSize(26, 26));

    // leaveButton->setObjectName(std::to_string(classInfo["id"].toInt()) + "LeaveButton");
    // leaveButton->setStyleSheet("QPushButton{ background-color: rgba(255, 0, 0, 123); border-radius: 10px; font: 500 14pt \"Inter\"; color: rgba(255, 255, 255, 255);} QPushButton:hover{ background-color: rgba(255, 0, 0, 255); }");
    // leaveButton->setCursor(Qt::CursorShape::PointingHandCursor);

    // leaveButton->setFlat(true);
    // leaveButton->setAutoFillBackground(true);

    classNameLayout->insertWidget(classNameLayout->count() - 1, classButton);
    // classLeaveLayout->insertWidget(classLeaveLayout->count() - 1, leaveButton);

}

void StudentNotes::AddNote(const Note& noteInfo)
{
    QVBoxLayout* topicLayout = ui->TopicLayout;

    QPushButton* topicButton = new QPushButton(noteInfo.topic);

    topicButton->setMaximumHeight(26);
    topicButton->setMinimumHeight(26);

    topicButton->setObjectName(std::to_string(noteInfo.id) + "Button");
    topicButton->setAccessibleDescription(QString::fromStdString(std::to_string(noteInfo.id)));

    if(noteInfo.id == audoCfg::currentNoteId)
    {
        topicButton->setStyleSheet("QPushButton{ background-color: rgba(255, 255, 255, 0); font: 500 14pt \"Inter\"; color: rgba(0, 0, 0, 255);}");
    }
    else
    {
        topicButton->setStyleSheet("QPushButton{ background-color: rgba(255, 255, 255, 0); font: 500 14pt \"Inter\"; color: rgba(0, 0, 0, 123);} QPushButton:hover{ color: rgba(0, 0, 0, 255); }");
        topicButton->setCursor(Qt::CursorShape::PointingHandCursor);
        connect(topicButton, &QPushButton::clicked, [this, topicButton]() { SetNote(topicButton); });
    }

    topicButton->setFlat(true);
    topicButton->setAutoFillBackground(true);

    topicLayout->insertWidget(topicLayout->count() - 1, topicButton);
}

void StudentNotes::SetNote(QPushButton* noteButton)
{
    audoCfg::currentNoteId = std::stoi(noteButton->accessibleDescription().toStdString());

    int count = ui->TopicLayout->count() - 1;
    for(int i = 0; i < count; i++)
    {
        QWidget* item = ui->TopicLayout->itemAt(0)->widget();
        ui->TopicLayout->removeItem(ui->TopicLayout->itemAt(0));
        delete item;
    }

    for(const auto& note : loadedNotes)
    {
        if(note.id == audoCfg::currentNoteId)
        {
            ui->Note->setText(note.content);
            ui->Subject->setText(note.subject);
            ui->Topic->setText(note.topic);
        }

        AddNote(note);
    }
}

void StudentNotes::SetClass(QPushButton* classButton)
{
    audoCfg::currentClassId = std::stoi(classButton->accessibleDescription().toStdString());

    ui->Note->setText("Content");
    ui->Subject->setText("Subject");
    ui->Topic->setText("Topic");

    LoadNotes();

    {
        int count = ui->ClassNameLayout->count() - 1;
        for(int i = 0; i < count; i++)
        {
            QWidget* item = ui->ClassNameLayout->itemAt(0)->widget();
            ui->ClassNameLayout->removeItem(ui->ClassNameLayout->itemAt(0));
            delete item;
        }
    }

    {
        int count = ui->ClassLeaveLayout->count() - 1;
        for(int i = 0; i < count; i++)
        {
            QWidget* item = ui->ClassLeaveLayout->itemAt(0)->widget();
            ui->ClassLeaveLayout->removeItem(ui->ClassLeaveLayout->itemAt(0));
            delete item;
        }
    }

    {
        int count = ui->TopicLayout->count() - 1;
        for(int i = 0; i < count; i++)
        {
            QWidget* item = ui->TopicLayout->itemAt(0)->widget();
            ui->TopicLayout->removeItem(ui->TopicLayout->itemAt(0));
            delete item;
        }
    }

    audoUtil::Response rooms = audoUtil::get("/api/get/user/rooms", audoUtil::ResponseType::ARRAY);

    if (rooms.array->isEmpty()) return;

    for(const auto& room : *rooms.array)
    {
        AddClass(room.toObject());
    }

    for(const auto& note : loadedNotes)
    {
        if(note.id == audoCfg::currentNoteId)
        {
            ui->Note->setText(note.content);
            ui->Subject->setText(note.subject);
            ui->Topic->setText(note.topic);
        }

        AddNote(note);
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
        { "room_code", ui->ClassCode->toPlainText() }
    };

    audoUtil::Response response = audoUtil::post("/api/join/room", body, true);

    if(response.status_code == audoUtil::OK)
    {
        audoCfg::currentClassId = response.data["id"].toInt();

        FetchUI();
    }
    else
    {
        ui->Warning->setText(response.data["data"].toString());
    }
}

