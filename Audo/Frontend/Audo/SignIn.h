#ifndef SIGNIN_H
#define SIGNIN_H

#include <QWidget>
#include <QPushButton>
#include <QVector>
namespace Ui {
class SignIn;
}

class SignIn : public QWidget
{
    Q_OBJECT

public:
    explicit SignIn(QAction* switchAction, QWidget *parent = nullptr);
    ~SignIn();

    QVector<std::string> userInfo;
public slots:
    void on_Pedalite_azsumgei();
    void on_Pedalite_azsumgeiFinished();
private slots:
    void on_Continue_clicked();
    void on_SignUpButton_clicked();

private:
    Ui::SignIn *ui;
    QAction* switchAction;

signals:
    void userInfoReady(QVector<std::string> userInfo);
};

#endif // SIGNIN_H
