#ifndef LESSON_H
#define LESSON_H

#include <QWidget>
#include <QFile>
#include <QPushButton>

namespace Ui {
class Lesson;
}

class Lesson : public QWidget
{
    Q_OBJECT

public:
    explicit Lesson(QString _fileName, QString _filePath, QWidget *parent = nullptr);
    ~Lesson();

    QPushButton *btn;
    QFile *file;
    QFile *getFile();
    QString getText();

    void makeActive();
    void makeInactive();

private:
    Ui::Lesson *ui;
};

#endif // LESSON_H
