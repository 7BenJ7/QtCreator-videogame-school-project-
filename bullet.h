#ifndef BULLET_H
#define BULLET_H

#include <QGraphicsScene>
#include <QTimer>
#include <QObject>
#include "hitbox.h"

class Bullet: public QObject, public HitBox
{
    Q_OBJECT

private:
    void collide(QGraphicsItem* item);

protected:
    float speed;

public:
    int stat;

    Bullet(int _speed = 10, int _damage = 10, QBrush _brush = QColor::fromRgbF(0.9,0.9,0));

public slots:
    virtual void move();
};

#endif // BULLET_H
