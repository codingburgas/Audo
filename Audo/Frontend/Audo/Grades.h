#ifndef GRADES_H
#define GRADES_H

#include <QWidget>
#include <QLabel>

namespace Ui {
class Grades;
}

class Grades : public QWidget
{
    Q_OBJECT

public:
    explicit Grades(QWidget *parent = nullptr);
    ~Grades();

private:

    Ui::Grades *ui;
    std::vector<QLabel> grades;

    float average;
};

#endif // GRADES_H
