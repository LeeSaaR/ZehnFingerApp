#include "lesson.h"
#include "ui_lesson.h"

Lesson::Lesson(QString _fileName, QString _filePath, QWidget *parent) :
    QWidget(parent),
    file(new QFile(_filePath)),
    ui(new Ui::Lesson)
{
    ui->setupUi(this);
    this->btn = ui->btn;
    ui->btn->setText(_fileName);
}

Lesson::~Lesson()
{
    delete ui;
}

QFile * Lesson::getFile()
{
    return this->file;
}

QString Lesson::getText()
{
    return ui->btn->text();
}

void Lesson::makeActive()
{
    ui->btn->setStyleSheet(
                "QPushButton {"
                "border: none;"
                "background-color: #c0c0c0;"
                "color: #000000;"
                "text-align: left;"
                "padding-left: 10px;}"

                "QPushButton::hover {"
                "border: none;"
                "background-color: #c0c0c0;"
                "color: #000000;"
                "text-align: left;"
                "padding-left: 10px;}"
                );
}

void Lesson::makeInactive()
{
    ui->btn->setStyleSheet(
                "QPushButton {"
                "border: none;"
                "background-color: #e0e0e0;"
                "color: #000000;"
                "text-align: left;"
                "padding-left: 10px;}"

                "QPushButton::hover {"
                "border: none;"
                "background-color: #c0c0c0;"
                "color: #000000;"
                "text-align: left;"
                "padding-left: 10px;}"
                );
}


