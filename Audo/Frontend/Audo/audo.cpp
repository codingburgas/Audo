#include "audo.h"
#include "ui_audo.h"
#include <QGraphicsDropShadowEffect>
#include <QScrollBar>
#include <QScrollArea>
Audo::Audo(QAction* switcher, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Audo)
    , switchAction(switcher)
{
    ui->setupUi(this);
    QGraphicsDropShadowEffect *shadowEffect = new QGraphicsDropShadowEffect();
    shadowEffect->setColor(QColor(0, 0, 0, 255 * 0.24)); // RGBA(0, 0, 0, 0.24)
    shadowEffect->setOffset(0, 3);
    shadowEffect->setBlurRadius(8);
    this->ui->nav->setGraphicsEffect(shadowEffect);

    QScrollArea* scrollArea = new QScrollArea;
    auto scroll = this->ui->notes->verticalScrollBar();

    scroll->setStyleSheet("QScrollBar:vertical {"
                          "border: none;"
                          "background: #F3F3FF;"
                          "width: 2.5px;"
                          "margin: 0px 0px 0px 0px;"
                          "}"
                          "QScrollBar::handle:vertical {"
                          "min-height: 20px;"
                          "background: #121212;"
                          "margin: 0px;"
                          "padding: 0px;"
                          "border: none;"
                          "}"
                          "QScrollBar::add-line:vertical, QScrollBar::sub-line:vertical {"
                          "border: none;"
                          "background: none;"
                          "}"
                          "QScrollBar::add-page:vertical, QScrollBar::sub-page:vertical {"
                          "background: none;"
                          "}");
}

Audo::~Audo()
{
    delete ui;
}
