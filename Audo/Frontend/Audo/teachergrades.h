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

public:
    void FetchUI();

private:
    void FetchGrades();
    void AddGrade(const int&& grade, const std::string&& desc);

private:
    Ui::Grades *ui;
    QAction* switchAction;
};

#endif // TEACHERGRADES_H
