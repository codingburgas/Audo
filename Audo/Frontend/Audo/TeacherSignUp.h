#ifndef TEACHERSIGNUP_H
#define TEACHERSIGNUP_H

#include <QWidget>

namespace Ui {
class TeacherSignUp;
}

class TeacherSignUp : public QWidget
{
    Q_OBJECT

public:
    explicit TeacherSignUp(QAction* switcher, QWidget *parent = nullptr);
    ~TeacherSignUp();

private slots:
    void on_SignInButton_clicked();

    void on_Continue_clicked();

private:
    Ui::TeacherSignUp *ui;
    QAction* switchAction;
};

#endif // TEACHERSIGNUP_H
