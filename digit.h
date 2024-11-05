#ifndef DIGIT_H
#define DIGIT_H

#include <QDebug>
#include <QWidget>
#include <QIcon>

namespace Ui {
class Digit;
}

class Digit : public QWidget
{
    Q_OBJECT

public:
    explicit Digit(QString &_digit, QWidget *parent = nullptr);
    ~Digit();

    QString text;
    QIcon returnIcon;

    QString colorCursor  = "#a0a0a0";
    QString colorFail    = "#ffaaaa";
    QString colorSucces  = "#aaffaa";
    QString colorMistake = "#ffffaa";
    bool wasError = false;

    QString colorNone    = "none";

    void setColor(int _case);
    void setColorBackground(QString _color);

    QString digit();



private:
    Ui::Digit *ui;
};

#endif // DIGIT_H
