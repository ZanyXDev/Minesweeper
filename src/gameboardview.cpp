#include "gameboardview.h"

GameBoardView::GameBoardView(QGraphicsView *parent)
    : QGraphicsView(parent)
{

}

void GameBoardView::mousePressEvent(QMouseEvent *event)
{
    if (QGraphicsItem *item = itemAt(event->pos())) {
        qDebug() << "item type:" << item->type();
        TileItem *cell = qgraphicsitem_cast<TileItem *>( item );
        if ( cell ){
//            qDebug() << "You clicked on TileItem" <<  cell
//                     << " at :" << event->pos()
//                     << " position:" << cell->getPosition();
            if(event->button() == Qt::LeftButton) {
                emit itemClicked( cell->getPosition(), 0 );
            }
            if(event->button() == Qt::RightButton) {
                 emit itemClicked( cell->getPosition(), 1 );
            }
        }
    }

    QGraphicsView::mousePressEvent(event);
}
