#ifndef GAMEBOARDVIEW_H
#define GAMEBOARDVIEW_H

#include <QGraphicsView>
#include <QDebug>
#include <QMouseEvent>
#include "tileitem.h"

class GameBoardView : public QGraphicsView
{
    Q_OBJECT
public:
    explicit GameBoardView(QGraphicsView *parent = nullptr);

signals:
    /**
     * @brief itemClicked user click in the elemenet item, need recalc game matrix
     * @param index Position cliked element in the matrix
     * @param mouseButton 0 click LeftButton 1 click RightButton
     */
    void itemClicked(int index, int mouseButton );
public slots:

protected:
    virtual  void mousePressEvent(QMouseEvent *event) override;

};

#endif // GAMEBOARDVIEW_H
