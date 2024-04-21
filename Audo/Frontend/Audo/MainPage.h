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
    MainPage(QAction* switchAction, QWidget *parent = nullptr);
    ~MainPage();

private slots:
    void on_SignIn_clicked();

    void on_SignUp_clicked();

public:
    Ui::MainPage *ui;
    QAction* switchAction;
};
#endif // MAINPAGE_H
