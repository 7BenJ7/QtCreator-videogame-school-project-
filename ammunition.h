#ifndef AMMUNITION_H
#define AMMUNITION_H

#include "bullet.h"

class Ammunition: public Bullet
{
public:
    Ammunition(int _speed = 1, int _ammo = 6, QBrush _brush = Qt::yellow);
};

#endif // AMMUNITION_H
