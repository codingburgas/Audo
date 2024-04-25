#ifndef TEACHERGRADES_H
#define TEACHERGRADES_H

#include <QWidget>
#include <QPushButton>

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
    void FetchUI(bool shouldReset = true);

private slots:
    void on_Add2_clicked();

    void on_Add3_clicked();

    void on_Add4_clicked();

    void on_Add5_clicked();

    void on_Add6_clicked();

    void on_AddGradeButton_clicked();

private:
    void FetchParticipants(bool shouldReset = true);
    void FetchGrades();

    void AddGrade(const int&& grade, const std::string&& desc);
    void AddClass(QJsonObject&& classInfo);
    void AddParticipant(QJsonObject&& participantInfo);

    void SetClass(QPushButton* classButton);
    void SetParticipant(QPushButton* participantButton);

private:
    Ui::Grades *ui;
    QAction* switchAction;

    int currentStudentId;
    int currentGrade;

    QString currentStudentName;
    QPushButton* lastGrade = nullptr;
};

#endif // TEACHERGRADES_H
