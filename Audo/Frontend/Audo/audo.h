#ifndef AUDO_H
#define AUDO_H

#include <QFont>
#include <QGraphicsDropShadowEffect>
#include <QMainWindow>
#include <QScrollArea>
#include <QtNetwork/QNetworkRequest>

constexpr int widthClass = 331;
constexpr int heightClass = 41;

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
    QGraphicsDropShadowEffect *shadowEffect;
    QScrollArea *scrollArea = nullptr;
    ~Audo();

    int xClass = 29;  //base x for classes
    int yClass = 230; // 130
    bool notesPage = true;
    bool gradesPage = false;

    void retrieveUserInfo();

public slots:
    void notesHeadClick();
    void gradesHeadClick();

private:
    Ui::Audo *ui;
};
#endif // AUDO_H
