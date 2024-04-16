#ifndef AUDO_H
#define AUDO_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class Audo;
}
QT_END_NAMESPACE

class Audo : public QMainWindow
{
    Q_OBJECT

public:
    Audo(QWidget *parent = nullptr);
    ~Audo();

private:
    Ui::Audo *ui;
};
#endif // AUDO_H
