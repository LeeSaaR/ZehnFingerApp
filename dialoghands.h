#ifndef DIALOGHANDS_H
#define DIALOGHANDS_H

#include <QDialog>

namespace Ui {
class DialogHands;
}

class DialogHands : public QDialog
{
    Q_OBJECT

public:
    explicit DialogHands(QWidget *parent = nullptr);
    ~DialogHands();

private:
    Ui::DialogHands *ui;
};

#endif // DIALOGHANDS_H
