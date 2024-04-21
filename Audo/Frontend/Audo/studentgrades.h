#ifndef STUDENTGRADES_H
#define STUDENTGRADES_H

#include <QWidget>

namespace Ui {
class StudentGrades;
}

class StudentGrades : public QWidget
{
    Q_OBJECT

public:
    explicit StudentGrades(QWidget *parent = nullptr);
    ~StudentGrades();

private:
    Ui::StudentGrades *ui;
};

#endif // STUDENTGRADES_H
