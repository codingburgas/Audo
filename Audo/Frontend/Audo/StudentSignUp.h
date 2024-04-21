#ifndef STUDENTSIGNUP_H
#define STUDENTSIGNUP_H

#include <QWidget>

namespace Ui {
class StudentSignUp;
}

class StudentSignUp : public QWidget
{
    Q_OBJECT

public:
    explicit StudentSignUp(QAction* switcher, QWidget *parent = nullptr);
    ~StudentSignUp();

private slots:
    void on_SignInButton_clicked();

    void on_Continue_clicked();

private:
    Ui::StudentSignUp *ui;
    QAction* switchAction;
};

#endif // STUDENTSIGNUP_H
