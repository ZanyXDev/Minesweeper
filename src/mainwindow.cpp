#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , round_mines_count(0)
    , round_time_count(0)
{    
    roundTimer = new QTimer();
    setupMenu();
    initGUI();
    initConnection();
}

/// @note Public slots
void MainWindow::startNewGame()
{
    round_time_count = 0;
    round_mines_count = 0;
    roundTimer->start( 1000 );
}

void MainWindow::gameOver()
{
    roundTimer->stop();
    QMessageBox::information(this, "Game over","Sorry you lose");
}

/// @note Private functions
void MainWindow::setupMenu()
{
    QToolBar *tb = addToolBar(tr("Games toolbar"));
    QMenu *menu = menuBar()->addMenu(tr("&Game"));

    //const QIcon openIcon = QIcon::fromTheme("document-new", QIcon(rsrcPath + "/fileopen.png"));
    QAction *a = menu->addAction(tr("&EASY"), this, &MainWindow::newEasy);
    //a->setShortcut(Qt::Key_E);
    tb->addAction(a);

    a = menu->addAction(tr("&MEDIUM"), this, &MainWindow::newMedium);
    //a->setShortcut(Qt::Key_E);
    tb->addAction(a);

    a = menu->addAction(tr("&HARD"), this, &MainWindow::newHard);
    //a->setShortcut(Qt::Key_E);
    tb->addAction(a);

    menu->addSeparator();

    a = menu->addAction(tr("&Quit"), this, &QWidget::close);
    a->setShortcut(Qt::CTRL + Qt::Key_Q);
}

void MainWindow::initGUI()
{
    auto central = new QWidget;
    auto mainFrameLayout = new QVBoxLayout();
    auto infoFrameLayout = new QHBoxLayout();
    auto watchLabel = new QLabel();
    auto minesLabel = new QLabel();
    timerLcd = new QLCDNumber();
    minesLcd = new QLCDNumber();
    newGameBtn = new QPushButton();


    /// @note setup new game Pushbutton
    newGameBtn->setMinimumSize(PICTURE_SIZE, PICTURE_SIZE);
    newGameBtn->setIconSize(QSize(PICTURE_SIZE, PICTURE_SIZE));
    newGameBtn->setIcon(QIcon(":/emoji/smile"));

    /// @note setup Pixmap labels
    /// @note need find or resize exist picture from 512 to 48 pixel
    QPixmap timerCounterPix(QPixmap(":/watch"));
    QPixmap minesCounterPix(QPixmap(":/mine"));
    watchLabel->setPixmap(timerCounterPix.scaled(PICTURE_SIZE,PICTURE_SIZE,Qt::KeepAspectRatio));
    minesLabel->setPixmap(minesCounterPix.scaled(PICTURE_SIZE,PICTURE_SIZE,Qt::KeepAspectRatio));

    /// @note setup LCD widgets
    timerLcd->setDigitCount(3);
    timerLcd->display(0);
    timerLcd->setStyleSheet(".QLCDNumber { border: 2px inset gray; background-color: black; color: green; }");
    timerLcd->setSegmentStyle(QLCDNumber::Flat);
    timerLcd->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    timerLcd->setFixedSize(QSize(72,48));


    minesLcd->setDigitCount(3);
    minesLcd->display(0);
    minesLcd->setStyleSheet(".QLCDNumber { border: 2px inset gray; background-color: black; color: red; }");
    minesLcd->setSegmentStyle(QLCDNumber::Flat);
    minesLcd->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    minesLcd->setFixedSize(QSize(72,48));

    /// @note setup gui element to form
    infoFrameLayout->addWidget(watchLabel);
    infoFrameLayout->addWidget(timerLcd);
    infoFrameLayout->addSpacerItem(new QSpacerItem(0, 0, QSizePolicy::MinimumExpanding));
    infoFrameLayout->addWidget(newGameBtn);
    infoFrameLayout->addSpacerItem(new QSpacerItem(0, 0, QSizePolicy::MinimumExpanding));
    infoFrameLayout->addWidget(minesLabel);
    infoFrameLayout->addWidget(minesLcd);
    mainFrameLayout->addLayout(infoFrameLayout);
    mainFrameLayout->addSpacerItem(new QSpacerItem(0, 0, QSizePolicy::Fixed, QSizePolicy::Expanding));

    central->setLayout(mainFrameLayout);
    setCentralWidget(central);
}

void MainWindow::initConnection()
{
    connect(newGameBtn, &QPushButton::clicked, this, &MainWindow::startNewGame);
    connect(this, &MainWindow::timeChanged,  timerLcd, QOverload<int>::of(&QLCDNumber::display));
    connect(this, &MainWindow::minesChanged,  minesLcd, QOverload<int>::of(&QLCDNumber::display));

    connect(roundTimer, &QTimer::timeout, this, &MainWindow::updateTime);

    connect(timerLcd, &QLCDNumber::overflow,this, &MainWindow::gameOver);
}

void MainWindow::newGame()
{

}

void MainWindow::newEasy()
{
    m_level = LevelTypes::EASY;
    m_size = 8;
    round_mines_count = 10;
    newGame();
}

void MainWindow::newMedium()
{
    m_level = LevelTypes::MEDIUM;
    m_size = 8;
    round_mines_count = 10;
    newGame();
}

void MainWindow::newHard()
{
    m_level = LevelTypes::HARD;
    m_size = 8;
    round_mines_count = 10;
    newGame();
}

/// @note Protected functions
void MainWindow::keyPressEvent(QKeyEvent *event)
{
    QMainWindow::keyPressEvent(event);
}

void MainWindow::keyReleaseEvent(QKeyEvent *event)
{
    QMainWindow::keyReleaseEvent(event);
}

/// @note Private slots
void MainWindow::updateTime()
{
    round_time_count++;
    emit timeChanged(round_time_count);
}

