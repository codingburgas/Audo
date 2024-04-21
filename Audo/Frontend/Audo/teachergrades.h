#ifndef TEACHERGRADES_H
#define TEACHERGRADES_H

#include <QWidget>

namespace Ui {
class Grades;
}

class TeacherGrades : public QWidget
{
    Q_OBJECT

public:
    explicit TeacherGrades(QAction* switchAction, QWidget *parent = nullptr);
    ~TeacherGrades();

private:
    Ui::Grades *ui;
    QAction* switchAction;
};

#endif // TEACHERGRADES_H
