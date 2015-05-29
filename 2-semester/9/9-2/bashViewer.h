#pragma once

#include <QMainWindow>
#include <QWebElement>
#include <QWebPage>
#include <QWebFrame>

#include <QTextEdit>
#include <QLineEdit>
#include <QGridLayout>
#include <QPushButton>
#include <QLabel>

namespace Ui {
class BashViewer;
}

class BashViewer : public QMainWindow
{
    Q_OBJECT

public:
    explicit BashViewer(QWidget *parent = 0);
    ~BashViewer();

private slots:

    /// at the beginning downloads site-page
    /// and then page at index of currentPage
    void loadQuotes();

    /// shows a quote if it's possible
    /// otherwise downloals new Page
    void showNextQuote();

    ///after downloading creates lists of Quotes and Ratings
    /// at first call - finds number of pages available
    void createQuotesList();

private:
    int searchNumberOfPages();
    void drawWindow();

    Ui::BashViewer *ui;
    const QString site = "http://bash.im/";

    QGridLayout *mainLayout;
    QTextEdit *textEdit;
    QPushButton *nextButton;
    QPushButton *loadButton;
    QLineEdit *ratingEdit;
    QLabel *ratingLabel;

    QWebPage *page;
    QList<QWebElement> quotes;
    QList<QWebElement> ratings;

    int currentPage;
    int currentQuote;
    int numberOfQuotesOnPage;
};
