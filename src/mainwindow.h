#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QKeyEvent>
#include <QToolBar>
#include <QMenu>
#include <QMenuBar>
#include <QAction>
#include <QDebug>

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

public slots:  

private slots:
    void newEasy();
    void newMedium();
    void newHard();

protected:
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);

private:
    void newGame();
    void setupMenu();

    LevelTypes m_level;
    quint8 m_size;
    quint8 m_mines;
};



#endif // MAINWINDOW_H
