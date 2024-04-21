#ifndef REQUESTS_H
#define REQUESTS_H

#include <QMainWindow>

namespace Ui {
class requests;
}

class requests : public QMainWindow
{
    Q_OBJECT

public:
    explicit requests(QWidget *parent = nullptr);
    ~requests();

private:
    Ui::requests *ui;
};

#endif // REQUESTS_H
