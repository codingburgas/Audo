#ifndef AUDO_H
#define AUDO_H

#include <QMainWindow>
#include <QAction>

#include "studentnotes.h"

#include <QPushButton>

namespace Ui {
class Audo;
}

class Audo : public QMainWindow
{
    Q_OBJECT

public:
    explicit Audo(QAction* switchAction, QWidget *parent = nullptr);
    ~Audo();

public:
    void FetchUI();

private slots:
    void on_JoinClass_clicked();

    void on_AddNote_clicked();

    void on_EditButton_clicked();

    void on_DeleteButton_clicked();

private:
    void AddClass(QJsonObject&& classInfo);
    void AddNote(const Note& noteInfo);

    void SetClass(QPushButton* classButton);
    void SetNote(QPushButton* noteButton);

    void DeleteClass(QPushButton* deleteButton);

    void LoadNotes();

private:
    Ui::Audo *ui;
    QAction* switchAction;

    std::vector<Note> loadedNotes;
};

#endif // AUDO_H
