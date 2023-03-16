#include <QList>
#include "ammunition.h"
#include "bullet.h"
#include "enemy.h"
#include "heal.h"
#include "player.h"

#include "qdebug.h"

Bullet::Bullet(int _speed, int _damage, QBrush brush)
{
    //draw rect
    setRect(0,0,10,20);
    setBrush(brush);

    //set parameter
    speed = _speed;
    stat = _damage;

    //connect
    QTimer* timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));

    timer->start(50); //timeout toutes les 50ms
}


void Bullet::move()
{
    //check collision
    QList<QGraphicsItem*> _collidingItems = collidingItems();
    foreach(QGraphicsItem* item, _collidingItems)
    {
        if((typeid(*item) != typeid(Bullet)) && (typeid(*item) != typeid(Heal)) && (typeid(*item) != typeid(Ammunition)))
        {
            if (typeid(*item) == typeid(Enemy))
            {
                //qDebug() << "Enemy";
                Enemy* enemy = dynamic_cast<Enemy*>(item);
                if(enemy)
                {
                    //qDebug() << "enemy apply stat";
                    enemy->applyStat(this);
                }
            }

            else if (typeid(*item) == typeid(Player))
            {
                //qDebug() << "player";
                Player* player = dynamic_cast<Player*>(item);
                if(player)
                {
                    //qDebug() << "player apply stat";
                    player->applyStat(this);
                }
            }

            scene()->removeItem(this);

            delete this;

            return;
        }
    }


    //move bullet
    setPos(x(), y() - speed);

    //destroy bullet if it is outside the scene
    if(pos().y() < -5 - this->rect().height() || pos().y() > 5 + scene()->height())
    {
        scene()->removeItem(this);
        delete this;
    }
}


