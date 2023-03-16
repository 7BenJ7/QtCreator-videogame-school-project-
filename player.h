#ifndef PLAYER_H
#define PLAYER_H

#include <QKeyEvent>
#include <QProgressBar>
#include <QLCDNumber>
#include <QTimer>
#include <QObject>
#include <QPushButton>
#include <QLabel>
#include "damageable.h"
#include "hitbox.h"


class Player: public QObject, public HitBox, public Damageable
{
    Q_OBJECT

public:
    QProgressBar* healthbar;
    QLCDNumber* bulletCount;

    QFrame* frame_command;
    QFrame* frame_level;
    QLabel* label;
    int score;
    int bulletMax;
    int curBullet;
    bool canShoot;
    QTimer* cooldownTimer;
    bool isHidden;

    Player();

    void keyPressEvent(QKeyEvent *event) override;
    void applyStat(Bullet* object) override;
    void shoot();
    void setStartState();
};

#endif // PLAYER_H
