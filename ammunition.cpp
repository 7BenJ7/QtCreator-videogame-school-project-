#include "ammunition.h"

Ammunition::Ammunition(int _speed, int _ammo, QBrush _brush)
{
    setRect(0,0,15,5);
    setBrush(_brush);

    //set parameter
    speed = -_speed;
    stat = _ammo;

    //connect
    QTimer* timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));

    timer->start(50); //timeout toutes les 50ms
}
