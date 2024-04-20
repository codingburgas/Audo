#ifndef MAINPAGE_H
#define MAINPAGE_H

#include <QMainWindow>
#include <QPushButton>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainPage;
}
QT_END_NAMESPACE

class MainPage : public QMainWindow
{
    Q_OBJECT

public:
    MainPage(QWidget *parent = nullptr);
    ~MainPage();

    QPushButton* GetSignInButton();
    QPushButton* GetSignUpButton();

private:
    Ui::MainPage *ui;
};
#endif // MAINPAGE_H
