#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    setupMenu();
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    QMainWindow::keyPressEvent(event);
}

void MainWindow::keyReleaseEvent(QKeyEvent *event)
{
    QMainWindow::keyReleaseEvent(event);
}

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


void MainWindow::newGame()
{

}

void MainWindow::newEasy()
{
     m_level = LevelTypes::EASY;
     m_size = 8;
     m_mines = 10;
     newGame();
}

void MainWindow::newMedium()
{
     m_level = LevelTypes::MEDIUM;
     m_size = 8;
     m_mines = 10;
     newGame();
}
void MainWindow::newHard()
{
     m_level = LevelTypes::HARD;
     m_size = 8;
     m_mines = 10;
     newGame();
}
