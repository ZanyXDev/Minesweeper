#ifndef GAMEBOARDVIEW_H
#define GAMEBOARDVIEW_H

#include <QGraphicsView>
#include <QDebug>
#include <QMouseEvent>

class GameBoardView : public QGraphicsView
{
    Q_OBJECT
public:
    explicit GameBoardView(QGraphicsView *parent = nullptr);

signals:

public slots:

protected:
    virtual  void mousePressEvent(QMouseEvent *event) override;

};

#endif // GAMEBOARDVIEW_H
