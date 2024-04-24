#ifndef STUDENTNOTES_H
#define STUDENTNOTES_H

#include <QWidget>
#include <QAction>

namespace Ui {
class StudentNotes;
}

class StudentNotes : public QWidget
{
    Q_OBJECT

public:
    explicit StudentNotes(QAction* switchAction, QWidget *parent = nullptr);
    ~StudentNotes();

public:
    void FetchUI();

private:
    void AddNote();

private slots:
    void on_JoinClass_clicked();

private:
    Ui::StudentNotes *ui;
    QAction* switchAction;
};

#endif // STUDENTNOTES_H
