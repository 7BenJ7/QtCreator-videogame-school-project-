#include "game.h"
#include "enemy.h"
#include "player.h"
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QDebug>

Game::Game()
{
    player = new Player();
    scene = new QGraphicsScene();
    timer = new QTimer();
}

void Game::start(int spawnTime)
{
    timer->stop();
    timer = new QTimer();

    //Clear scene
    //scene->clear();
    qDebug() << "scene clear";
    //add player to the scene
    player->show();
    player->isHidden = false;
    qDebug() << "show player";

    scene->addItem(player);
    //qDebug() << "add player to the scene";

    //set Player
    player->setRect(0,0,100,100);
    qDebug() << "set player size";
    player->setStartState();
    qDebug() << "set player";

    //make hitBox focusable
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();

    // add view
    QGraphicsView* view = new QGraphicsView(scene);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    //show the view, scale the scene and set the player at its start position
    //view->show();
    view->setFixedSize(800,600);
    scene->setSceneRect(0,0,800,600);
    player->setPos(view->width()/2 - player->rect().width()/2, 480);

    //spawn enemies
    QObject::connect(timer,SIGNAL(timeout()),this,SLOT(spawn()));
    timer->start(spawnTime);
}

void Game::spawn()
{
    //create enemy
    if(player->isHidden)
    {
        return;
    }

    int speed = (player->score)/5 + 1;
    if (speed > 11)
    {
        speed = 11;
    }

    int random = rand() % 10;
    if(random < 7)
    {
        //ennemi de base
        QColor* color = new QColor(200 - ((speed - 1) * 20), 0, 0,255);
        qDebug() << "color : " << color->red();
        QBrush* brush = new QBrush(*color);
        qDebug() << "brushColor : " << brush->color().red();
        Enemy* enemy = new Enemy(player,speed, *brush);
        scene->addItem(enemy);
    }
    else
    {
        //petit ennemi
        QColor* color = new QColor(200 - ((speed - 1) * 20), 0, 200 - ((speed - 1) * 20),255);
        qDebug() << "color : " << color->red();
        QBrush* brush = new QBrush(*color);
        qDebug() << "brushColor : " << brush->color().red();
        Enemy* enemy = new Enemy(player,speed + 3, *brush, Qt::magenta, 40, 20, 20);
        scene->addItem(enemy);
    }

}
