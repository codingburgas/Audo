#ifndef TEACHERACCOUNT_H
#define TEACHERACCOUNT_H

#include <QWidget>

namespace Ui {
class teacherAccount;
}

class teacherAccount : public QWidget
{
    Q_OBJECT

public:
    explicit teacherAccount(QWidget *parent = nullptr);
    ~teacherAccount();

private:
    Ui::teacherAccount *ui;
};

#endif // TEACHERACCOUNT_H
