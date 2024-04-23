#ifndef STUDENTNOTES_H
#define STUDENTNOTES_H

#include <QWidget>

namespace Ui {
class StudentNotes;
}

class StudentNotes : public QWidget
{
    Q_OBJECT

public:
    explicit StudentNotes(QWidget *parent = nullptr);
    ~StudentNotes();

private:
    Ui::StudentNotes *ui;
};

#endif // STUDENTNOTES_H
