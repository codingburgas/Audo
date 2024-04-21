#ifndef REQUESTS_H
#define REQUESTS_H

#include <QMainWindow>
#include <QPushButton>

namespace Ui {
class requests;
}

class requests : public QMainWindow
{
    Q_OBJECT

public:
    explicit requests(QAction* switchAction, QWidget *parent = nullptr);
    ~requests();

private:
    Ui::requests *ui;
    QAction* switchAction;
};

#endif // REQUESTS_H
