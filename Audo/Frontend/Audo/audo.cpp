#include "audo.h"
#include "ui_audo.h"

#include "utils.h"

#include <QVBoxLayout>
#include <QPushButton>

Audo::Audo(QAction* switcher, QWidget *parent)
    : QMainWindow(parent), ui(new Ui::Audo), switchAction(switcher)
{
    ui->setupUi(this);
}

void Audo::LoadNotes()
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

void Audo::FetchUI()
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
        int count = ui->TopicLayout->count() - 2;
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

    ui->ClassCodeLabel->setText((*rooms.array)[0].toObject()["unique_code"].toString());

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

void Audo::AddClass(QJsonObject&& classInfo)
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

    QPushButton* deleteButton = new QPushButton("X");

    deleteButton->setMaximumSize(QSize(26, 26));
    deleteButton->setMinimumSize(QSize(26, 26));

    deleteButton->setObjectName(std::to_string(classInfo["id"].toInt()) + "deleteButton");
    deleteButton->setStyleSheet("QPushButton{ background-color: rgba(255, 0, 0, 123); border-radius: 6px; font: 500 14pt \"Inter\"; color: rgba(255, 255, 255, 255);} QPushButton:hover{ background-color: rgba(255, 0, 0, 255); }");
    deleteButton->setCursor(Qt::CursorShape::PointingHandCursor);

    deleteButton->setAccessibleDescription(QString::fromStdString(std::to_string(classInfo["id"].toInt())));

    deleteButton->setFlat(true);
    deleteButton->setAutoFillBackground(true);

    connect(deleteButton, &QPushButton::clicked, [this, deleteButton]() { DeleteClass(deleteButton); });

    classNameLayout->insertWidget(classNameLayout->count() - 1, classButton);
    classLeaveLayout->insertWidget(classLeaveLayout->count() - 1, deleteButton);

}

void Audo::AddNote(const Note& noteInfo)
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

    topicLayout->insertWidget(topicLayout->count() - 2, topicButton);
}

void Audo::SetNote(QPushButton* noteButton)
{
    audoCfg::currentNoteId = std::stoi(noteButton->accessibleDescription().toStdString());

    int count = ui->TopicLayout->count() - 2;
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

void Audo::SetClass(QPushButton* classButton)
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
        int count = ui->TopicLayout->count() - 2;
        for(int i = 0; i < count; i++)
        {
            QWidget* item = ui->TopicLayout->itemAt(0)->widget();
            ui->TopicLayout->removeItem(ui->TopicLayout->itemAt(0));
            delete item;
        }
    }

    audoUtil::Response rooms = audoUtil::get("/api/get/user/rooms", audoUtil::ResponseType::ARRAY);

    ui->ClassCodeLabel->setText((*rooms.array)[0].toObject()["unique_code"].toString());

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

void Audo::DeleteClass(QPushButton* deleteButton)
{
    audoUtil::Body classBody
    {
        { "classroom_id", std::stoi(deleteButton->accessibleDescription().toStdString()) }
    };

    audoUtil::del("/api/delete/room", classBody, true);

    FetchUI();
}

Audo::~Audo()
{
    delete ui;
}

void Audo::on_JoinClass_clicked()
{
    audoUtil::Body classBody
    {
        { "name", ui->ClassName->toPlainText() }
    };

    audoUtil::post("/api/create/room", classBody, true, audoUtil::ResponseType::OBJECT);

    FetchUI();
}


void Audo::on_AddNote_clicked()
{
    audoUtil::Body noteBody
    {
        { "subject", "Subject" },
        { "topic", "Topic" },
        { "room_id", audoCfg::currentClassId },
        { "content", "Content" }
    };

    audoUtil::post("/api/create/note", noteBody, true, audoUtil::ResponseType::OBJECT);

    FetchUI();
}


void Audo::on_EditButton_clicked()
{
    audoUtil::Body noteBody
    {
        { "note_id", audoCfg::currentNoteId },
        { "subject", ui->Subject->text() },
        { "topic", ui->Topic->text() },
        { "content", ui->Note->toPlainText() }
    };

    audoUtil::put("/api/update/note", noteBody, true);

    FetchUI();
}


void Audo::on_DeleteButton_clicked()
{
    audoUtil::Body noteBody
        {
            { "note_id", audoCfg::currentNoteId },
        };

    audoUtil::del("/api/delete/note", noteBody, true);

    FetchUI();
}

