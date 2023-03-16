#ifndef HEAL_H
#define HEAL_H

#include "bullet.h"

class Heal : public Bullet
{
public:
    Heal(int _speed = 2, int _heal = 30, QBrush _brush = Qt::green);
};

#endif // HEAL_H
