#ifndef GAME_H
#define GAME_H

#include <QGraphicsScene>
#include <QObject>
#include "player.h"

class Game: public QObject
{
    Q_OBJECT

public:
    QGraphicsScene* scene;
    Player* player;
    QTimer* timer;

    Game();

    void start(int spawnTime);

public slots:
    void spawn();

};

#endif // GAME_H
