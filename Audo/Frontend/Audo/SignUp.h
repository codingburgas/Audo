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
    explicit SignUp(QWidget *parent = nullptr);
    ~SignUp();

    QPushButton* GetSignInButton();
private slots:


private:
    Ui::SignUp *ui;
};

#endif // SIGNUP_H
