#include "textfinder.h"
#include "ui_textfinder.h"

#include <QFile>
#include <QTextStream>

TextFinder::TextFinder(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::TextFinder)
{
    ui->setupUi(this);
    loadTextFile();

}

TextFinder::~TextFinder()
{
    delete ui;
}


void TextFinder::loadTextFile(){
    QFile inputfile(":/input.txt");
    inputfile.open(QIODevice::ReadOnly);

    QTextStream in(&inputfile);
    QString line = in.readAll();
    inputfile.close();

    ui->textEdit->setPlainText(line);
    QTextCursor cursor = ui->textEdit->textCursor();
    cursor.movePosition(QTextCursor::Start, QTextCursor::MoveAnchor, 1);

}

void TextFinder::on_findButton_clicked()
{
QString searchString = ui->lineEdit->text();
ui->textEdit->find(searchString,QTextDocument::FindWholeWords);

}

