#ifndef STUDENTGRADES_H
#define STUDENTGRADES_H

#include <QWidget>
#include <QAction>

#include <QPushButton>

namespace Ui {
class StudentGrades;
}

class StudentGrades : public QWidget
{
    Q_OBJECT

public:
    explicit StudentGrades(QAction* switchAction, QWidget *parent = nullptr);
    ~StudentGrades();

public:
    void FetchUI(bool shouldReset = true);

private slots:
    void on_SignOut_4_clicked();

private:
    void FetchGrades();

    void AddGrade(const int&& grade, const std::string&& desc);
    void AddClass(QJsonObject&& classInfo);

    void SetClass(QPushButton* classButton);

private:
    Ui::StudentGrades *ui;
    QAction* switchAction;
};

#endif // STUDENTGRADES_H
