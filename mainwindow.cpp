#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDir>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    initApp();

    player = new QMediaPlayer;
    audio = new QAudioOutput;
    player->setAudioOutput(audio);
    audio->setVolume(100);

    QDir pwd;
    pwd.cdUp();
    const QString file_path = pwd.absolutePath() + "/ZehnFingerApp/data/";

    m_sound_type_writer = file_path+"TypeWriter.wav";
    m_sound_error = file_path+"ErrorSound.wav";
    m_sound_backspace = file_path+"Backspace.wav";

    // timer global                    = time for whole text (started at begin : stopped at end)
    // intervall                       = 1000 ms (stop after 8 intervalls without typing)
    // keys pressed / intervall        = Chars per Second
    // pressed keys * Chars per Second = Chars per Minute
    // Chars per Minute / 5            = Words per Minute
    // errors                          = error count
    // length                          = text length
    // errors / length                  = errors percentage total

}

MainWindow::~MainWindow()
{
    if (player) delete player;
    if (audio) delete audio;
    if (m_statistics) delete m_statistics;
    delete ui;
}

void MainWindow::initApp()
{
    QDir pwd;
    pwd.cdUp();
    const QString file_path = pwd.absolutePath() + "/ZehnFingerApp/data";

    imgKeys.insert("1", file_path+"/sign_n1.png");
    imgKeys.insert("2", file_path+"/sign_n2.png");
    imgKeys.insert("3", file_path+"/sign_n3.png");
    imgKeys.insert("4", file_path+"/number_4.png");
    imgKeys.insert("5", file_path+"/number_5.png");
    imgKeys.insert("6", file_path+"/number_6.png");
    imgKeys.insert("7", file_path+"/number_7.png");
    imgKeys.insert("8", file_path+"/number_8.png");
    imgKeys.insert("9", file_path+"/number_9.png");
    imgKeys.insert("0", file_path+"/number_0.png");


    imgKeys.insert("a", file_path+"/lower_A.png");
    imgKeys.insert("b", file_path+"/lower_B.png");
    imgKeys.insert("c", file_path+"/lower_C.png");
    imgKeys.insert("d", file_path+"/lower_D.png");
    imgKeys.insert("e", file_path+"/lower_E.png");
    imgKeys.insert("f", file_path+"/lower_F.png");
    imgKeys.insert("g", file_path+"/lower_G.png");
    imgKeys.insert("h", file_path+"/lower_H.png");
    imgKeys.insert("i", file_path+"/lower_I.png");
    imgKeys.insert("j", file_path+"/lower_J.png");
    imgKeys.insert("k", file_path+"/lower_K.png");
    imgKeys.insert("l", file_path+"/lower_L.png");
    imgKeys.insert("m", file_path+"/lower_M.png");
    imgKeys.insert("n", file_path+"/lower_N.png");
    imgKeys.insert("o", file_path+"/lower_O.png");
    imgKeys.insert("p", file_path+"/lower_P.png");
    imgKeys.insert("q", file_path+"/lower_Q.png");
    imgKeys.insert("r", file_path+"/lower_R.png");
    imgKeys.insert("s", file_path+"/lower_S.png");
    imgKeys.insert("t", file_path+"/lower_T.png");
    imgKeys.insert("u", file_path+"/lower_U.png");
    imgKeys.insert("v", file_path+"/lower_V.png");
    imgKeys.insert("w", file_path+"/lower_W.png");
    imgKeys.insert("x", file_path+"/lower_X.png");
    imgKeys.insert("y", file_path+"/lower_Y.png");
    imgKeys.insert("z", file_path+"/lower_Z.png");

    imgKeys.insert("A", file_path+"/upper_A.png");
    imgKeys.insert("B", file_path+"/upper_B.png");
    imgKeys.insert("C", file_path+"/upper_C.png");
    imgKeys.insert("D", file_path+"/upper_D.png");
    imgKeys.insert("E", file_path+"/upper_E.png");
    imgKeys.insert("F", file_path+"/upper_F.png");
    imgKeys.insert("G", file_path+"/upper_G.png");
    imgKeys.insert("H", file_path+"/upper_H.png");
    imgKeys.insert("I", file_path+"/upper_I.png");
    imgKeys.insert("J", file_path+"/upper_J.png");
    imgKeys.insert("K", file_path+"/upper_K.png");
    imgKeys.insert("L", file_path+"/upper_L.png");
    imgKeys.insert("M", file_path+"/upper_M.png");
    imgKeys.insert("N", file_path+"/upper_N.png");
    imgKeys.insert("O", file_path+"/upper_O.png");
    imgKeys.insert("P", file_path+"/upper_P.png");
    imgKeys.insert("Q", file_path+"/upper_Q.png");
    imgKeys.insert("R", file_path+"/upper_R.png");
    imgKeys.insert("S", file_path+"/upper_S.png");
    imgKeys.insert("T", file_path+"/upper_T.png");
    imgKeys.insert("U", file_path+"/upper_U.png");
    imgKeys.insert("V", file_path+"/upper_V.png");
    imgKeys.insert("W", file_path+"/upper_W.png");
    imgKeys.insert("X", file_path+"/upper_X.png");
    imgKeys.insert("Y", file_path+"/upper_Y.png");
    imgKeys.insert("Z", file_path+"/upper_Z.png");

    imgKeys.insert("ä", file_path+"/lower_Ä.png");
    imgKeys.insert("ö", file_path+"/lower_Ö.png");
    imgKeys.insert("ü", file_path+"/lower_Ü.png");

    imgKeys.insert("Ä", file_path+"/upper_Ä.png");
    imgKeys.insert("Ö", file_path+"/upper_Ö.png");
    imgKeys.insert("Ü", file_path+"/upper_Ü.png");

    imgKeys.insert("ß", file_path+"/sign_sz.png");
    imgKeys.insert(".", file_path+"/sign_dot.png");
    imgKeys.insert(",", file_path+"/sign_comma.png");
    imgKeys.insert(":", file_path+"/sign_colon.png");
    imgKeys.insert(";", file_path+"/sign_semicolon.png");
    imgKeys.insert("-", file_path+"/sign_minus.png");
    imgKeys.insert("_", file_path+"/sign_underscore.png");
    imgKeys.insert("+", file_path+"/sign_plus.png");
    imgKeys.insert("#", file_path+"/sign_hash.png");
    imgKeys.insert("\'", file_path+"/sign_single_quote.png");
    imgKeys.insert("\"", file_path+"/sign_double_quote.png");
    imgKeys.insert("!", file_path+"/sign_emark.png");
    imgKeys.insert("?", file_path+"/sign_qmark.png");
    imgKeys.insert("§", file_path+"/sign_paragraph.png");
    imgKeys.insert("$", file_path+"/sign_dollar.png");
    imgKeys.insert("%", file_path+"/sign_percent.png");
    imgKeys.insert("&", file_path+"/sign_ampersand.png");
    imgKeys.insert("/", file_path+"/sign_slash.png");
    imgKeys.insert("\\", file_path+"/sign_backslash.png");
    imgKeys.insert("(", file_path+"/sign_bracket_open.png");
    imgKeys.insert(")", file_path+"/sign_bracket_close.png");
    imgKeys.insert("[", file_path+"/sign_bracket_square_open.png");
    imgKeys.insert("]", file_path+"/sign_bracket_square_close.png");
    imgKeys.insert("{", file_path+"/sign_bracket_curly_open.png");
    imgKeys.insert("}", file_path+"/sign_bracket_curly_close.png");
    imgKeys.insert("=", file_path+"/sign_equal.png");
    imgKeys.insert("*", file_path+"/sign_asterix.png");
    imgKeys.insert("~", file_path+"/sign_tilde.svg");
    imgKeys.insert("\r", file_path+"/key_return.png");
    imgKeys.insert(" ", file_path+"/key_space.png");

    getFileNames();

    lessonIndex = 0;
    loadLesson(listLessonItems[0]->getFile());
    listLessonItems[lessonIndex]->makeActive();


    shortTimer = new QTimer(this);
    longTimer  = new QTimer(this);
    connect(shortTimer, &QTimer::timeout, this, &MainWindow::shortTimerSlot);
    connect(longTimer,  &QTimer::timeout, this, &MainWindow::longTimerSlot);
    connect(ui->btn_next, &QPushButton::clicked, this, &MainWindow::nextLesson);
    connect(ui->btn_previous, &QPushButton::clicked, this, &MainWindow::previousLesson);
    connect(ui->btn_repeat, &QPushButton::clicked, this, &MainWindow::repeatLesson);

}

void MainWindow::setDefaultStatistics()
{
    // Set default Statistics
    ui->label_ErrorsTotal->setText(QString::number(errorCount)+"/"+QString::number(digits.size()-1));
    ui->label_ErrorsPercent->setText(QString::number(errorDezimal, 'f', 2));
    ui->label_time->setText(QString("00:00"));
    ui->label_WPM->setText(QString("%0 WpM").arg(longTermWpM));
}

void MainWindow::loadLesson(QFile *_File)
{
    //Clear Current Lesson if it exists

    _currentFile = _File;
    if (!_currentFile->open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "file not found!";
        return;
    }
    QTextStream in(_currentFile);
    QString textAll = in.readAll();
    _currentFile->close();

    // Get Lines
    QStringList textList;
    textList.append(textAll.split("\n"));
    for (QString _row : textList) {
        rows.append(new Row(_row, this));
        for(Digit *_digit : rows.last()->digits) {
            digits.append(_digit);
        }
        ui->frame->layout()->removeItem(ui->vSpacer);
        ui->frame->layout()->addWidget(rows.last());
        ui->frame->layout()->addItem(ui->vSpacer);
        rows.last()->hide();
    }
    currentRow = rows.first();
    currentRow->show();

    while (!listWpM.isEmpty()) {
        listWpM.removeLast();
    }
    errorCount = 0;
    errorDezimal = 1.0;
    cursorIndex = 0;
    longTimerSeconds = 0;
    longTermWpM = 0;


    setDigitCursor(0);
    setDefaultStatistics();
}

void MainWindow::setDigitCursor(int _case)
{
    digitCursor = digits[cursorIndex];
    if (currentRow != qobject_cast<Row *>(digitCursor->parent()->parent())) {
        currentRow->hide();
        currentRow = qobject_cast<Row *>(digitCursor->parent()->parent());
        currentRow->show();
    }
    digitCursor->setColor(_case);
    setImgKeys();

}

void MainWindow::cursorNext(int _case)
{
    digitCursor->setColor(_case);
    if (!(digits.isEmpty())) {
        if (!(digitCursor == digits.last())) {
            cursorIndex++;
            digitCursor = digits[cursorIndex];
            setDigitCursor(0);
        } else {
            lessonComplete();
        }
    }
}

void MainWindow::cursorBack()
{
    digitCursor->setColor(3);
    cursorIndex--;
    digitCursor = digits[cursorIndex];
    setDigitCursor(0);

}

void MainWindow::calcWpM()
{
    int _sum = 0;
    for (int _value : listWpM) {
        _sum += _value;
    }
    longTermWpM = _sum / listWpM.size();
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if (digits.isEmpty()) {
        if (event->text() == "\r") {
            nextLesson();
            return;
        } else {
            return;
        }
    }
    if (event->key() == Qt::Key_Backspace) {
        if (cursorIndex == 0) {
            return;
        } else {
            // backspace
            player->setSource(QUrl::fromLocalFile(m_sound_backspace));
            player->play();
            player->setPosition(0);
            cursorBack();
        }
    }
    else {
        if (((event->key() == Qt::Key_Shift) || (event->key() == Qt::Key_AltGr)))
        {
            // key modifier triggered
            // ignore keys
            return;
        }
        else {
            if (
                       (event->key() == Qt::Key_Control)
                    || (event->key() == Qt::Key_Up)
                    || (event->key() == Qt::Key_Down)
                    || (event->key() == Qt::Key_Right)
                    || (event->key() == Qt::Key_Left)
                    || (event->key() == Qt::Key_Alt)
                    || (event->key() == Qt::Key_F1)
                    || (event->key() == Qt::Key_F2)
                    || (event->key() == Qt::Key_F3)
                    || (event->key() == Qt::Key_F4)
                    || (event->key() == Qt::Key_F5)
                    || (event->key() == Qt::Key_F6)
                    || (event->key() == Qt::Key_F7)
                    || (event->key() == Qt::Key_F8)
                    || (event->key() == Qt::Key_F9)
                    || (event->key() == Qt::Key_F10)
                    || (event->key() == Qt::Key_F11)
                    || (event->key() == Qt::Key_F12)
                    || (event->key() == Qt::Key_CapsLock)
                    || (event->key() == Qt::Key_NumLock)
                    || (event->key() == Qt::Key_PageUp)
                    || (event->key() == Qt::Key_PageDown)
                    || (event->key() == Qt::Key_Delete)
                    || (event->key() == Qt::Key_Paste)
               )
            {
                // ignore keys
                return;
            }
            else {
                startTimers();
                if (event->text() == digitCursor->digit())
                {
                    // typewriter
                    player->setSource(QUrl::fromLocalFile(m_sound_type_writer));
                    player->play();
                    player->setPosition(0);
                    cursorNext(2);
                    countCpS();
                    //CpS++;
                }
                else {
                    // error
                    //qDebug() << event->text() << "!=" << digitCursor->digit();
                    player->setSource(QUrl::fromLocalFile(m_sound_error));
                    player->play();
                    player->setPosition(0);
                    cursorNext(1);
                    countCpS();
                    //CpS++;
                    countErrors();
                }
            }
        }
    }
}

void MainWindow::countCpS()
{
    CpS++;
}

void MainWindow::resetCpS()
{
    CpS = 0;
}

void MainWindow::countErrors()
{
    errorCount++;
    errorDezimal = errorCount/(double)digits.size();
    ui->label_ErrorsTotal->setText(QString("%0/%1").arg(errorCount).arg(digits.size()-1));
    ui->label_ErrorsPercent->setText(QString("%0").arg(QString::number(1-errorDezimal, 'f', 2)));
}

void MainWindow::startTimers()
{
    // Timer Start Handling
    if (isStart()) {
        startShortTimer();
        startLongTimer();
    }
    else if (isContinue()) {
        startShortTimer();
    }
}

void MainWindow::stopTimers()
{
    if (longTimer->isActive()) {
        shortTimer->stop();
        longTimer->stop();
    }
}

bool MainWindow::isStart()
{
    return (digitCursor == digits.first()) && !(longTimer->isActive());
}

bool MainWindow::isContinue()
{
    return !shortTimer->isActive();
}

void MainWindow::startShortTimer()
{
    shortTimer->start(1000);
    shortTimerCount = 0;
}

void MainWindow::stopAtTypingInactivity()
{
    if (CpS == 0) {
        shortTimer->stop();
        shortTimerCount = 0;
        resetCpS();
    }
}

void MainWindow::startLongTimer()
{
    longTimer->start(1000);
}

void MainWindow::lessonComplete()
{
    shortTimer->stop();
    longTimer->stop();
    showStatistics();
}

void MainWindow::showStatistics()
{
    ui->frame_2->hide();
    m_statistics = new TypingStatistics(errorDezimal, longTermWpM, getTime(), this);
    clearLesson();
    ui->frame->layout()->removeItem(ui->vSpacer);
    ui->frame->layout()->addWidget(m_statistics);
}

void MainWindow::clearStatistics()
{
    ui->frame_2->show();
    if (!(m_statistics == nullptr)) {
        m_statistics->close();
        ui->frame->layout()->addItem(ui->vSpacer);
    }
    m_statistics = nullptr;
}

QString MainWindow::getTime()
{
    if (((longTimerSeconds / 60) < 10) && ((longTimerSeconds % 60) < 10)) {
        return QString("0%0:0%1").arg(longTimerSeconds / 60).arg(longTimerSeconds % 60);
    }
    if (((longTimerSeconds / 60) >= 10) && ((longTimerSeconds % 60) >= 10)) {
        return QString("%0:%1").arg(longTimerSeconds / 60).arg(longTimerSeconds % 60);
    }
    if (((longTimerSeconds / 60) >= 10) && ((longTimerSeconds % 60) < 10)) {
        return QString("%0:0%1").arg(longTimerSeconds / 60).arg(longTimerSeconds % 60);
    }
    if (((longTimerSeconds / 60) < 10) && ((longTimerSeconds % 60) >= 10)) {
        return QString("0%0:%1").arg(longTimerSeconds / 60).arg(longTimerSeconds % 60);
    }
    return "";
}

void MainWindow::setImgKeys()
{
    QPixmap imgKey(imgKeys[digitCursor->text]);
    ui->keys->setPixmap(imgKey.scaled(QSize(1323, 375)));
}



void MainWindow::clearLesson()
{
    while (digits.size() != 0) {
        digits.removeLast();
    }
    for (Row *_row : rows) {
        _row->clearDigits();
    }
    while (rows.size() != 0) {
        ui->frame->layout()->removeWidget(rows.last());
        delete rows.last();
        rows.removeLast();
    }
}

void MainWindow::nextLesson()
{
    stopTimers();
    clearStatistics();
    if (lessonIndex < listLessonItems.size() - 1) {
        listLessonItems[lessonIndex]->makeInactive();
        clearLesson();
        lessonIndex++;
        loadLesson(listLessonItems[lessonIndex]->getFile());
        listLessonItems[lessonIndex]->makeActive();
    }
}

void MainWindow::previousLesson()
{
    stopTimers();
    clearStatistics();
    if (lessonIndex > 0) {
        listLessonItems[lessonIndex]->makeInactive();
        clearLesson();
        lessonIndex--;
        loadLesson(listLessonItems[lessonIndex]->getFile());
        listLessonItems[lessonIndex]->makeActive();
    }
}

void MainWindow::selectLesson()
{
    stopTimers();
    clearStatistics();
    listLessonItems[lessonIndex]->makeInactive();
    clearLesson();
    lessonIndex = listLessonItems.indexOf(qobject_cast<Lesson *>(sender()->parent()));
    loadLesson(listLessonItems[lessonIndex]->getFile());
    listLessonItems[lessonIndex]->makeActive();

}

void MainWindow::repeatLesson()
{
    stopTimers();
    clearStatistics();
    clearLesson();
    loadLesson(listLessonItems[lessonIndex]->getFile());
}


void MainWindow::getFileNames()
{
    QDir dirLessons;
    dirLessons.cdUp();
    dirLessons.cd("ZehnFingerApp/lessons/");
    // List all Files
    for (QFileInfo _file : dirLessons.entryInfoList()) {
        // Filter lessons
        if (!(_file.filePath()[_file.filePath().size()-1] == '.')) {
            listLessonItems.append(new Lesson(_file.fileName().replace("_", " "), _file.filePath(), this));
            ui->listLessons->layout()->removeItem(ui->vSpacer_List);
            ui->listLessons->layout()->addWidget(listLessonItems.last());
            ui->listLessons->layout()->addItem(ui->vSpacer_List);
            connect(listLessonItems.last()->btn, &QPushButton::clicked, this, &MainWindow::selectLesson);
        }
    }
}

void MainWindow::shortTimerSlot()
{
    CpM = CpS * 60;
    WpM = CpM / 5;
    listWpM.append(WpM);
    calcWpM();
    ui->label_WPM->setText(QString("%0 WpM").arg(longTermWpM));
    shortTimerCount++;
    resetCpS();
}

void MainWindow::longTimerSlot()
{
    longTimerSeconds++;
    ui->label_time->setText(getTime());
}


