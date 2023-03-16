#ifndef ENEMY_H
#define ENEMY_H

#include <stdlib.h>
#include "bullet.h"
#include "damageable.h"
#include "player.h"

class Enemy: public Damageable, public Bullet
{
public:
    Player* player;

    Enemy(Player* _player, int _speed = 2, QBrush _brush = Qt::darkRed, QBrush damageBrush = Qt::red, int size = 70, int _healthMax = 30, int _damage = 40);

    void applyStat(Bullet* object) override;
    void move() override;
private:
    QBrush damageBrush;

    void createHeal();
    void createAmmunition();
};

#endif // ENEMY_H
