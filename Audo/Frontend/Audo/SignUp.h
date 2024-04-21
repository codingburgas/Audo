#ifndef SIGNUP_H
#define SIGNUP_H

#include <QWidget>
#include <QPushButton>

namespace Ui {
class SignUp;
}

class SignUp : public QWidget
{
    Q_OBJECT

public:
    explicit SignUp(QAction* switchAction, QWidget *parent = nullptr);
    ~SignUp();

private slots:


    void on_pushButton_clicked();

    void on_SignInButton_clicked();

    void on_Teacher_clicked();

private:
    Ui::SignUp *ui;
    QAction* switchAction;
};

#endif // SIGNUP_H
