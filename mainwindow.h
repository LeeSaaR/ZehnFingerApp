#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QFile>
#include <QDir>
#include <QTextStream>
#include <QKeySequence>
#include <QKeyEvent>
#include <QTimer>
#include <QtMath>
#include <QAudioOutput>
#include <QMediaPlayer>
#include <QStandardItemModel>
#include <QStandardItem>
#include "row.h"
#include "lesson.h"
#include "typingstatistics.h"
#include <QMap>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    int lesson = 1;

    // Calculation Statistics
    int CpS = 0; // chars per second
    int CpM = 0; // chars per minute
    int WpM = 0; // words per minute
    QList<int> listWpM;

    double errorDezimal = 1.00;
    int errorCount = 0;
    int longTermWpM = 0;

    void setDefaultStatistics();

    void countCpS();
    void resetCpS();
    void countErrors();
    void calcWpM();

    QList<Row *> rows;
    QList<Digit*> digits;
    Digit * digitCursor;
    int cursorIndex = 0;
    Row *currentRow = nullptr;


    void keyPressEvent(QKeyEvent *event);
    void cursorNext(int _case);
    void cursorBack();
    void setDigitCursor(int _case);

    // METHODS: Timers
    QTimer *shortTimer;
    QTimer *longTimer;
    int longTimerSeconds = 0;
    int shortTimerCount;

    void startTimers();
    void stopTimers();
    bool isStart();
    bool isContinue();
    void startShortTimer();
    void stopAtTypingInactivity();
    void startLongTimer();

    // METHODS: Lesson List

    int lessonIndex;
    QFile *_currentFile;
    QList<Lesson *> listLessonItems;
    void getFileNames();
    void lessonComplete();
    void showStatistics();
    void clearStatistics();
    QString getTime();

    // METHODS: Images


private:
    void initApp();
    void setImgKeys();

public slots:
    void shortTimerSlot();
    void longTimerSlot();
    void loadLesson(QFile *_File);
    void clearLesson();
    void nextLesson();
    void previousLesson();
    void selectLesson();
    void repeatLesson();

private:
    Ui::MainWindow *ui;
    TypingStatistics *m_statistics = nullptr;
    QMap<QString, QString> imgFingers;
    QMap<QString, QString> imgKeys;

    QMediaPlayer *player;
    QAudioOutput *audio;

    // SOUNDS
    QString m_sound_type_writer;
    QString m_sound_error;
    QString m_sound_backspace;

};
#endif // MAINWINDOW_H
