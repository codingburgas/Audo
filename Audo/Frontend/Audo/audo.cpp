#include "audo.h"
#include <QLabel>
#include <QPixMap>
#include <QScrollBar>
#include "./ui_audo.h"
#include "user.h"
Audo::Audo(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Audo)
{
    ui->setupUi(this);

    User denis;
    QFont font("Segoe UI", 11);
    QPixmap closePng(":/public/close.svg");
    denis.joinedClasses.insert({"Geography", "Andreyana Stoyanova"});
    denis.joinedClasses.insert({"matenatuakj", "Adreyana Stoyanova"});

    this->scrollArea = new QScrollArea;
    auto scroll = this->ui->textEdit->verticalScrollBar();

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

    QGraphicsDropShadowEffect *navShadowEffect = new QGraphicsDropShadowEffect;
    navShadowEffect->setBlurRadius(20);
    navShadowEffect->setColor(QColor(0, 0, 0, 63)); // 0.25 opacity
    navShadowEffect->setOffset(0, 0);

    QGraphicsDropShadowEffect *heroShadowEffect = new QGraphicsDropShadowEffect;
    heroShadowEffect->setBlurRadius(20);
    heroShadowEffect->setColor(QColor(0, 0, 0, 63)); // 0.25 opacity
    heroShadowEffect->setOffset(0, 0);

    this->ui->nav->setGraphicsEffect(navShadowEffect);
    this->ui->hero->setGraphicsEffect(heroShadowEffect);
    connect(this->ui->notes, &QPushButton::clicked, this, &Audo::notesHeadClick);
    connect(this->ui->grades, &QPushButton::clicked, this, &Audo::gradesHeadClick);

    for (const auto &subject : denis.joinedClasses) {
        QString text = QString::fromStdString(subject.first + " - " + subject.second);
        QLabel *label = new QLabel(text, this);
        QLabel *close = new QLabel(this);
        close->setPixmap(closePng);
        label->setGeometry(this->xClass, this->yClass, widthClass, heightClass); //29, 300
        close->setGeometry(widthClass - 15, this->yClass + 10, 16, 20);
        label->setStyleSheet("color: #445178;"
                             "border: none;"
                             "padding-left: 20px;"
                             "border: 1px solid #9899FE;"
                             "border-top: 0px;"
                             "border-left: 0px;"
                             "border-radius: 0px;");
        label->setFont(font);
        label->show();
        this->yClass += 70;
    }
}

void Audo::notesHeadClick()
{
    if (!this->notesPage)
        this->notesPage = true;
}

void Audo::gradesHeadClick()
{
    if (!this->gradesPage)
        this->gradesPage = true;
}

Audo::~Audo()
{
    delete ui;
    delete this->shadowEffect;
    delete this->scrollArea;
}
