#ifndef SIGNIN_H
#define SIGNIN_H

#include <QWidget>

namespace Ui {
class SignIn;
}

class SignIn : public QWidget
{
    Q_OBJECT

public:
    explicit SignIn(QWidget *parent = nullptr);
    ~SignIn();

private:
    Ui::SignIn *ui;
};

#endif // SIGNIN_H
