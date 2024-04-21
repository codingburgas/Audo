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
    explicit SignIn(QAction* switchAction, QWidget *parent = nullptr);
    ~SignIn();

private slots:
    void on_Continue_clicked();

    void on_SignUpButton_clicked();

private:
    Ui::SignIn *ui;
    QAction* switchAction;
};

#endif // SIGNIN_H
