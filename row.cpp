#include "row.h"
#include "ui_row.h"

Row::Row(QString &text, QWidget *parent) :
    QWidget(parent),
    rowsText(text),
    ui(new Ui::Row)

{
    ui->setupUi(this);
    this->newDigit();
}

Row::~Row()
{
    delete ui;
}

void Row::newDigit()
{
    for(QString _digit : this->rowsText) {
        this->digits.append(new Digit(_digit, this));
        ui->frame_row->layout()->removeItem(ui->hSpacer);
        ui->frame_row->layout()->addWidget(this->digits.last());
        ui->frame_row->layout()->addItem(ui->hSpacer);
    }
    QString _keyReturn = "\r";
    this->digits.append(new Digit(_keyReturn, this));
    ui->frame_row->layout()->removeItem(ui->hSpacer);
    ui->frame_row->layout()->addWidget(this->digits.last());
    ui->frame_row->layout()->addItem(ui->hSpacer);
}

void Row::clearDigits()
{
    while (this->digits.size() != 0)
    {
        ui->frame_row->layout()->removeWidget(this->digits.last());
        delete this->digits.last();
        this->digits.removeLast();
    }
}

void Row::testFunction()
{
    this->clearDigits();
}
