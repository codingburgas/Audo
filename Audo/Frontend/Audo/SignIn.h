#ifndef SIGNIN_H
#define SIGNIN_H

#include <QWidget>
#include <QPushButton>

namespace Ui {
class SignIn;
}

class SignIn : public QWidget
{
    Q_OBJECT

public:
    explicit SignIn(QWidget *parent = nullptr);
    ~SignIn();

    QPushButton* GetSignUpButton();

private slots:
    void on_Continue_clicked();

private:
    Ui::SignIn *ui;
};

#endif // SIGNIN_H
