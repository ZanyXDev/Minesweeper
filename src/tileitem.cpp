#include "tileitem.h"

TileItem::TileItem(const QPixmap &pixmap, QGraphicsEffect *effect, QGraphicsItem *parent )
    : QGraphicsPixmapItem(pixmap,parent)
    , m_position(-1)
{
    m_effect = effect;
}

int TileItem::getPosition() const
{
    return m_position;
}

void TileItem::setPosition(int position)
{
    m_position = position;
}

void TileItem::hoverMoveEvent(QGraphicsSceneHoverEvent *event)
{
    QGraphicsItem::hoverMoveEvent(event);
}

void TileItem::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{
    setGraphicsEffect( m_effect );
    QGraphicsItem::hoverEnterEvent(event);
}

void TileItem::hoverLeaveEvent(QGraphicsSceneHoverEvent *event)
{
    QGraphicsItem::hoverLeaveEvent(event);
}


