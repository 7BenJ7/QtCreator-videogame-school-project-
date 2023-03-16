#include "enemy.h"
#include "ammunition.h"
#include "heal.h"
#include "qdebug.h"

Enemy::Enemy(Player* _player, int _speed, QBrush _brush, QBrush _damageBrush, int size, int _healthMax, int _damage)
{
    //set rect
    int randomNumber = rand() % 700;
    setPos(randomNumber, 0);
    setRect(0,0,size,size);
    setBrush(_brush);
    qDebug() << "color : " << _brush.color() << "; style : " << _brush.style();

    //set parameter
    speed = -_speed;
    healthMax = _healthMax;
    curHealth = healthMax;
    stat = _damage;
    player = _player;
    damageBrush = _damageBrush;


    //connect
    QTimer* timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move(speed)));
    timer->start(50); //timeout toutes les 50ms

    colorTimer = new QTimer(this);
    colorTimer->setSingleShot(true);
    connect(colorTimer, &QTimer::timeout, [=]() {
        setBrush(_brush);
    });
}

void Enemy::applyStat(Bullet* object)
{
    if (typeid(object) == typeid(Heal) || typeid(object) == typeid(Ammunition))
    {
        return;
    }

    curHealth -= object->stat;

    setBrush(damageBrush);
    colorTimer->start(100);

    if(curHealth <= 0)
    {
        player->score ++;
        player->label->setText(QString("Score : ") + QString::number(player->score));
        //chance to create ammunition or heal
        int random = rand() % 6;
        if (random < 3)
        {
            createAmmunition();
        }
        else if (random == 3)
        {
            createHeal();
        }

        scene()->removeItem(this);
        delete this;
    }
}

void Enemy::move()
{
    //check collision
    if(player->isHidden)
    {
        scene()->removeItem(this);
        delete this;
        return;
    }
    else
    {
        QList<QGraphicsItem*> _collidingItems = collidingItems();
        foreach(QGraphicsItem* item, _collidingItems)
        {
            if((typeid(*item) != typeid(Bullet)) && (typeid(*item) != typeid(Heal)) && (typeid(*item) != typeid(Ammunition)))
            {
                if (typeid(*item) == typeid(Enemy))
                {
                    Enemy* enemy = dynamic_cast<Enemy*>(item);
                    if(enemy)
                    {

                        //enemy->applyStat(this);
                    }
                }

                else if (typeid(*item) == typeid(Player))
                {
                    Player* player_ = dynamic_cast<Player*>(item);
                    if(player_)
                    {
                        //qDebug() << "player apply stat";
                        stat /= 4;
                        player_->applyStat(this);

                        scene()->removeItem(this);
                        delete this;
                        return;
                    }
                }
/*
                scene()->removeItem(this);

                delete this;

                return;*/
            }
        }
    }

    //move ennemi
    setPos(x(), y() - speed);

    //destroy ennemi if it is outside the scene
    if(pos().y() < -5 - this->rect().height() || pos().y() > 5 + scene()->height())
    {
        if(pos().y() > 5 + scene()->height() && player)
        {
            player->applyStat(this);
        }
        scene()->removeItem(this);
        delete this;
    }
}

void Enemy::createHeal()
{
    Heal* heal = new Heal();
    heal->setPos(x() + this->rect().width()/2 - heal->rect().width()/2, y() + this->rect().height()/2 - heal->rect().height());
    scene()->addItem(heal);
}

void Enemy::createAmmunition()
{
    Ammunition* ammunition = new Ammunition();
    ammunition->setPos(x() + this->rect().width()/2 - ammunition->rect().width()/2, y() + this->rect().height()/2 - ammunition->rect().height());
    scene()->addItem(ammunition);
}

