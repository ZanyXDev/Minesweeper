#ifndef TILEITEM_H
#define TILEITEM_H

#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QGraphicsBlurEffect>
#include <QGraphicsEffect>
#include <QCursor>
#include <QDebug>
#include <QEvent>

class TileItem : public QGraphicsPixmapItem
{

public:
    TileItem(const QPixmap &pixmap,
                   QGraphicsEffect *effect= nullptr,
                   QGraphicsItem *parent = nullptr);


private:
    QGraphicsEffect *m_effect;
protected:
    virtual void hoverMoveEvent (QGraphicsSceneHoverEvent *event) override;
    virtual void hoverEnterEvent (QGraphicsSceneHoverEvent *event) override;
    virtual void hoverLeaveEvent (QGraphicsSceneHoverEvent *event) override;
};

#endif // TILEITEM_H
