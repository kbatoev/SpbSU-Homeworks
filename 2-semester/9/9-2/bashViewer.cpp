#include "bashViewer.h"
#include "ui_bashViewer.h"
#include <iostream>

BashViewer::BashViewer(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::BashViewer),
    mainLayout(new QGridLayout),
    textEdit(new QTextEdit),
    nextButton(new QPushButton),
    loadButton(new QPushButton(tr("Load Next Page"))),
    ratingEdit(new QLineEdit),
    page(new QWebPage),
    currentPage(0)
{
    ui->setupUi(this);

    drawWindow();
    connect(loadButton, SIGNAL(clicked()), this, SLOT(loadQuotes()));
    connect(page, SIGNAL(loadFinished(bool)), this, SLOT(createQuotesList()));
    connect(nextButton, SIGNAL(clicked()), this, SLOT(showNextQuote()));
}

BashViewer::~BashViewer()
{
    delete page;
    delete nextButton;
    delete loadButton;
    delete mainLayout;
    delete textEdit;
    delete ratingEdit;
    delete ratingLabel;
    delete ui;
}

void BashViewer::loadQuotes()
{
    QString url = site;
    if (currentPage)
        url += QString("index/") + QString::number(currentPage--);
    page->mainFrame()->load(url);
}

void BashViewer::showNextQuote()
{
    if (currentQuote == numberOfQuotesOnPage)
        loadQuotes();
    else
    {
        textEdit->clear();
        textEdit->append(quotes[currentQuote].toPlainText());
        ratingEdit->clear();
        ratingEdit->setText(ratings[currentQuote++].toPlainText());
    }
}

void BashViewer::createQuotesList()
{
    nextButton->setEnabled(true);
    QWebFrame *frame = page->mainFrame();
    quotes = frame->findAllElements("div[class=text]").toList();
    ratings = frame->findAllElements("span[class=rating-o]").toList();
    currentQuote = 0;
    numberOfQuotesOnPage = quotes.size();
    if (!currentPage)
        currentPage = searchNumberOfPages() - 1;
    showNextQuote();
}

int BashViewer::searchNumberOfPages()
{
    QWebElement pager = page->mainFrame()->findFirstElement("div[class=pager]");
    for (int i = 0; i < 3; i++)
        pager = pager.firstChild();
    return pager.attribute("max").toInt();
}

void BashViewer::drawWindow()
{
    ratingLabel = new QLabel(tr("Rating:"));
    mainLayout->addWidget(ratingLabel, 1, 1, 1, 2);
    mainLayout->addWidget(loadButton, 0, 0, 1, 2);
    mainLayout->addWidget(nextButton, 0, 2, 1, 3);
    nextButton->setText("Next");
    nextButton->setEnabled(false);
    mainLayout->addWidget(ratingEdit, 1, 2, 1, 3);
    mainLayout->addWidget(textEdit, 2, 0, 5, 5);
    ui->centralWidget->setLayout(mainLayout);
}
