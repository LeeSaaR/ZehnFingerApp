#ifndef TYPINGSTATISTICS_H
#define TYPINGSTATISTICS_H


#include <QWidget>

namespace Ui {
class TypingStatistics;
}

class TypingStatistics : public QWidget
{
    Q_OBJECT

public:
    explicit TypingStatistics(double fails, int wpm, QString time, QWidget *parent = nullptr);
    ~TypingStatistics();

private:
    Ui::TypingStatistics *ui;
};

#endif // TYPINGSTATISTICS_H
