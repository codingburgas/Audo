#ifndef STUDENTNOTES_H
#define STUDENTNOTES_H

#include <QWidget>
#include <QAction>

#include <QPushButton>

namespace Ui {
class StudentNotes;
}

struct Note
{
    int id;
    QString subject;
    QString topic;
    QString content;
};


class StudentNotes : public QWidget
{
    Q_OBJECT

public:
    explicit StudentNotes(QAction* switchAction, QWidget *parent = nullptr);
    ~StudentNotes();

public:
    void FetchUI();

private:
    void AddClass(QJsonObject&& classInfo);
    void AddNote(const Note& noteInfo);

    void SetClass(QPushButton* classButton);
    void SetNote(QPushButton* noteButton);

    void LoadNotes();

private slots:
    void on_JoinClass_clicked();

private:
    Ui::StudentNotes *ui;
    QAction* switchAction;

    std::vector<Note> loadedNotes;
};

#endif // STUDENTNOTES_H
