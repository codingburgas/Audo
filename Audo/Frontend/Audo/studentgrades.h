#ifndef STUDENTGRADES_H
#define STUDENTGRADES_H

#include <QWidget>
#include <QAction>

namespace Ui {
class StudentGrades;
}

class StudentGrades : public QWidget
{
    Q_OBJECT

public:
    explicit StudentGrades(QAction* switchAction, QWidget *parent = nullptr);
    ~StudentGrades();

private:
    Ui::StudentGrades *ui;
    QAction* switchAction;
};

#endif // STUDENTGRADES_H
