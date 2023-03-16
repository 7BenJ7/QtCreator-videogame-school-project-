#include "heal.h"

Heal::Heal(int _speed, int _heal, QBrush _brush)
{
    setRect(0,0,10,10);
    setBrush(_brush);

    //set parameter
    speed = -_speed;
    stat = _heal;

    //connect
    QTimer* timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));

    timer->start(50); //timeout toutes les 50ms
}
