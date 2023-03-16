#include <QGraphicsScene>
#include "ammunition.h"
#include "heal.h"
#include "player.h"
#include "bullet.h"

#include<QDebug>

Player::Player()
{
    setBrush(Qt::darkBlue);
    healthMax = 100;
    curHealth = healthMax;
    bulletMax = 30;
    curBullet = bulletMax;
    canShoot = true;
    score = 0;
    isHidden = true;

    cooldownTimer = new QTimer(this);
    cooldownTimer->setSingleShot(true);

    colorTimer = new QTimer(this);
    colorTimer->setSingleShot(true);
    connect(colorTimer, &QTimer::timeout, [=]() {
        setBrush(Qt::darkBlue);
    });
}

void Player::keyPressEvent(QKeyEvent* event)
{
    if (event->key() == Qt::Key_Left)
    {
        if(pos().x()-10 > 0)
        {
            setPos(x()-10,y());
        }
    }

    else if (event->key() == Qt::Key_Right)
    {
        if(pos().x()+110 < scene()->width())
        {
            setPos(x()+10,y());
        }
    }

    else if (event->key() == Qt::Key_Space)
    {
        shoot();
    }
}

void Player::shoot(){
    //check cooldown
    if(cooldownTimer->isActive())
    {
        return;
    }

    //check if player has bullet
    if(curBullet > 0)
    {
        curBullet --;
        bulletCount->display(curBullet);
        //create bullet
        Bullet* bullet = new Bullet();
        bullet->setPos(x() + this->rect().width()/2 - bullet->rect().width()/2, y() - 1 - bullet->rect().height()); //-1 else bullet collide with player
        scene()->addItem(bullet);
        canShoot = false;

        cooldownTimer->start(200);
    }
}

void Player::setStartState()
{
    curBullet = bulletMax;
    bulletCount->display(curBullet);

    curHealth = healthMax;
    healthbar->setValue(curHealth);

    score = 0;
    label->setText(QString("Score : ") + QString::number(score));
}

void Player::applyStat(Bullet* object)
{
    qDebug() << typeid(*object).name();
    if (typeid(*object) == typeid(Heal))
    {
        //qDebug()<<"player is healed";
        curHealth += object->stat;

        if(curHealth > healthMax)
        {
            curHealth = healthMax;
        }

        healthbar->setValue(curHealth);
    }

    else if (typeid(*object) == typeid(Ammunition))
    {
        //qDebug()<<"player gained ammo";
        curBullet += object->stat;

        if(curBullet > bulletMax)
        {
            curBullet = bulletMax;
        }

        bulletCount->display(curBullet);
    }

    else
    {
        //qDebug()<<"player is damaged by " << typeid(*object).name();;
        curHealth -= object->stat;
        healthbar->setValue(curHealth);

        setBrush(Qt::blue);
        colorTimer->start(100);

        if(curHealth <= 0)
        {
            healthbar->setValue(0);

            this->hide();
            isHidden = true;



            frame_command->hide();
            frame_level->show();

        }
    }
}

