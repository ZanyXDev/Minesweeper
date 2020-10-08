#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QKeyEvent>
#include <QToolBar>
#include <QMenu>
#include <QMenuBar>
#include <QAction>
#include <QDebug>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPixmap>
#include <QPushButton>
#include <QLabel>
#include <QLCDNumber>
#include <QTimer>
#include <QDebug>
#include <QMessageBox>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>

#define PICTURE_SIZE 48

class MainWindow : public QMainWindow
{
    Q_OBJECT
    Q_ENUMS(LevelTypes)
public:
    explicit MainWindow(QWidget *parent = nullptr);
    enum LevelTypes{
        EASY,
        MEDIUM,
        HARD
    };
signals:
    void timeChanged(int m_time);
    void minesChanged(int m_time);

public slots:  
    void startNewGame();
    void gameOver();

private slots:
    void newEasy();
    void newMedium();
    void newHard();
    void updateTime();

protected:
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);

private:
    void newGame();
    void setupMenu();
    void initGUI();
    void initConnection();
    void setupScene(quint8 size_x, quint8 size_y, quint16 mines_count);

    LevelTypes m_level;
    quint8 m_size;
    quint16 round_mines_count;
    quint16 round_time_count;

    quint8 gameFieldSizeX;
    quint8 gameFieldSizeY;
    quint16 minesCount;

    QTimer *roundTimer;
    QPushButton *newGameBtn;

    QLCDNumber *timerLcd;
    QLCDNumber *minesLcd;

    QGraphicsView *boardView;
    QGraphicsScene *boardScene;

};



#endif // MAINWINDOW_H
