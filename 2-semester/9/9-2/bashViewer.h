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
    void loadQuotes();
    void showNextQuote();
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
