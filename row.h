#ifndef ROW_H
#define ROW_H

#include <QWidget>
#include "digit.h"

namespace Ui {
class Row;
}

class Row : public QWidget
{
    Q_OBJECT

public:
    explicit Row(QString &text, QWidget *parent = nullptr);
    ~Row();

    QString rowsText;
    QVector<Digit *> digits;

    void newDigit();
    void clearDigits();

public slots:
    void testFunction();

private:
    Ui::Row *ui;
};

#endif // ROW_H
