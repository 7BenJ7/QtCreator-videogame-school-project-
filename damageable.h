#ifndef DAMAGEABLE_H
#define DAMAGEABLE_H

#include "bullet.h"

class Damageable
{
public:
    int healthMax;
    int curHealth;
    QTimer* colorTimer;

    Damageable();

    virtual void applyStat(Bullet* object)=0;
};

#endif // DAMAGEABLE_H
