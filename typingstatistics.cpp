#include "typingstatistics.h"
#include "ui_typingstatistics.h"

TypingStatistics::TypingStatistics(double fails, int wpm, QString time, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TypingStatistics)
{
    ui->setupUi(this);
    if (fails == 1.0) {
        ui->label_fails->setText(QString("%0 \% Fehlerfreiheit").arg(QString::number(static_cast<int>((fails ) * 100))));
    } else
    {
        ui->label_fails->setText(QString("%0 \% Fehlerfreiheit").arg(QString::number(static_cast<int>((1-fails ) * 100))));
    }
    ui->label_wpm->setText(QString("%0 WpM").arg(wpm));
    ui->label_time->setText(QString("Zeit: %0").arg(time));
}

TypingStatistics::~TypingStatistics()
{
    delete ui;
}
