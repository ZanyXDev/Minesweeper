#include "gameboardview.h"

GameBoardView::GameBoardView(QGraphicsView *parent)
    : QGraphicsView(parent)
{

}

void GameBoardView::mousePressEvent(QMouseEvent *event)
{
    qDebug() << "Custom view clicked at :" << event->pos();
    if(event->button() == Qt::LeftButton) {
         qDebug() << "Left button click";
    }
    if(event->button() == Qt::RightButton) {
         qDebug() << "Right button click";
    }
    QGraphicsView::mousePressEvent(event);
}
