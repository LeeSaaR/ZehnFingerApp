#include "dialoghands.h"
#include "ui_dialoghands.h"

DialogHands::DialogHands(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogHands)
{
    ui->setupUi(this);
    QPixmap pxm(":/data/hands/Hands.png");
    ui->label->setPixmap(pxm.scaled(250, 169));
}

DialogHands::~DialogHands()
{
    delete ui;
}
