#include "digit.h"
#include "ui_digit.h"

#include <QDir>

Digit::Digit(QString &_digit, QWidget *parent) :
    QWidget(parent),
    text(_digit),
    ui(new Ui::Digit)
{
    ui->setupUi(this);
    ui->label->setText(this->text);
    if(this->text == "\r") {
        ui->label->hide();
        ui->label_2->show();
        QDir pwd;
        pwd.cdUp();
        const QString file_path = pwd.absolutePath() + "/ZehnFingerApp/data";
        ui->label_2->clear();
        ui->label_2->setPixmap(QPixmap(file_path+"/ReturnSign.png"));
    }
    else {
        ui->label_2->hide();
        ui->label->show();
    }

}

Digit::~Digit()
{
    delete ui;
}

void Digit::setColor(int _case)
{
    switch (_case) {
    case 0:
        this->setColorBackground(this->colorCursor);
        break;
    case 1:
        this->setColorBackground(this->colorFail);
        this->wasError = true;
        break;
    case 2:

        if (this->wasError)
        {
            this->setColorBackground(this->colorMistake);
        }
        else {
            this->setColorBackground(this->colorSucces);
        }
        break;
    case 3:
        this->setColorBackground(this->colorNone);
        break;
    }
}

void Digit::setColorBackground(QString _color)
{
    ui->label->setStyleSheet(QString("QLabel{background-color: %0; color: #222222;  font-family: \"Monospace\";font-size: 32pt;}").arg(_color));
    ui->label_2->setStyleSheet(QString("QLabel{background-color: %0; color: #222222;  font-family: \"Monospace\";font-size: 32pt;}").arg(_color));
}


QString Digit::digit()
{
    return this->text;
}
